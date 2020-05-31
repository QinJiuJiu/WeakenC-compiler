#! /usr/bin/python

# coding=utf-8

import os
import re
import io
from reg import Regs

def translate(regs,line):
    if line[0]=='LABEL':
        return line[1]+':'
    if line[1]==':=':
        if len(line)==3:
            if line[2][0]=='#':
                return '\tli %s,%s'%(regs.GetRegName(line[0]),line[-1].replace('#',''))
            else:
                return '\tmove %s,%s'%(regs.GetRegName(line[0]),regs.GetRegName(line[2]))
        if len(line)==5:
            if line[3]=='+':
                if line[-1][0]=='#':
                    return '\taddi %s,%s,%s'%(regs.GetRegName(line[0]),regs.GetRegName(line[2]),line[-1].replace('#',''))
                else:
                    return '\tadd %s,%s,%s'%(regs.GetRegName(line[0]),regs.GetRegName(line[2]),regs.GetRegName(line[-1]))
            elif line[3]=='-':
                if line[-1][0]=='#':
                    return '\taddi %s,%s,-%s'%(regs.GetRegName(line[0]),regs.GetRegName(line[2]),line[-1].replace('#',''))
                else:
                    return '\tsub %s,%s,%s'%(regs.GetRegName(line[0]),regs.GetRegName(line[2]),regs.GetRegName(line[-1]))
            elif line[3]=='*':
                return '\tmul %s,%s,%s'%(regs.GetRegName(line[0]),regs.GetRegName(line[2]),regs.GetRegName(line[-1]))
            elif line[3]=='/':
                return '\tdiv %s,%s\n\tmflo %s'%(regs.GetRegName(line[2]),regs.GetRegName(line[-1]),regs.GetRegName(line[0]))
            elif line[3]=='<':
                return '\tslt %s,%s,%s'%(regs.GetRegName(line[0]),regs.GetRegName(line[2]),regs.GetRegName(line[-1]))
            elif line[3]=='>':
                return '\tslt %s,%s,%s'%(regs.GetRegName(line[0]),regs.GetRegName(line[-1]),regs.GetRegName(line[2]))    
        if line[2]=='CALL':
            if line[3]=='read' or line[3]=='print':
                return '\taddi $sp,$sp,-4\n\tsw $ra,0($sp)\n\tjal %s\n\tlw $ra,0($sp)\n\tmove %s,$v0\n\taddi $sp,$sp,4'%(line[-1],regs.GetRegName(line[0]))
            else:
                return '\taddi $sp,$sp,-24\n\tsw $t0,0($sp)\n\tsw $ra,4($sp)\n\tsw $t1,8($sp)\n\tsw $t2,12($sp)\n\tsw $t3,16($sp)\n\tsw $t4,20($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $ra,4($sp)\n\tlw $t1,8($sp)\n\tlw $t2,12($sp)\n\tlw $t3,16($sp)\n\tlw $t4,20($sp)\n\taddi $sp,$sp,24\n\tmove %s $v0'%(line[-1],regs.GetRegName(line[0]))
    if line[0]=='GOTO':
        return '\tj %s'%line[1]
    if line[0]=='RETURN':
            return '\tmove $v0,%s\n\tjr $ra'%regs.GetRegName(line[1])
    if line[0]=='IF':
        if line[2]=='==':
            return '\tbeq %s,%s,%s'%(regs.GetRegName(line[1]),regs.GetRegName(line[3]),line[-1])
        if line[2]=='!=':
            return '\tbne %s,%s,%s'%(regs.GetRegName(line[1]),regs.GetRegName(line[3]),line[-1])
        if line[2]=='>':
            return '\tbgt %s,%s,%s'%(regs.GetRegName(line[1]),regs.GetRegName(line[3]),line[-1])
        if line[2]=='<':
            return '\tblt %s,%s,%s'%(regs.GetRegName(line[1]),regs.GetRegName(line[3]),line[-1])
        if line[2]=='>=':
            return '\tbge %s,%s,%s'%(regs.GetRegName(line[1]),regs.GetRegName(line[3]),line[-1])
        if line[2]=='<=':
            return '\tble %s,%s,%s'%(regs.GetRegName(line[1]),regs.GetRegName(line[3]),line[-1])
    if line[0]=='FUNCTION':
        return '%s:'%line[1]
    if line[0]=='CALL':
        if line[-1]=='read' or line[-1]=='print':
            return '\taddi $sp,$sp,-4\n\tsw $ra,0($sp)\n\tjal %s\n\tlw $ra,0($sp)\n\taddi $sp,$sp,4'%(line[-1])
        else:
            return '\taddi $sp,$sp,-24\n\tsw $t0,0($sp)\n\tsw $ra,4($sp)\n\tsw $t1,8($sp)\n\tsw $t2,12($sp)\n\tsw $t3,16($sp)\n\tsw $t4,20($sp)\n\tjal %s\n\tlw $a0,0($sp)\n\tlw $ra,4($sp)\n\tlw $t1,8($sp)\n\tlw $t2,12($sp)\n\tlw $t3,16($sp)\n\tlw $t4,20($sp)\n\taddi $sp,$sp,24\n\tmove %s $v0'%(line[-1],regs.GetRegName(line[0]))
    if line[0]=='ARG':
        return '\tmove $t0,$a0\n\tmove $a0,%s'%regs.GetRegName(line[-1])
    if line[0]=='PARAM':
        regs.used_regs[line[-1]]='a0'
    return ''



fin = open('inner.txt', 'rb')

fout = open('result.asm', 'w')

template='''
.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\\n"
.globl main
.text
read:
    li $v0,4
    la $a0,_prompt
    syscall
    li $v0,5
    syscall
    jr $ra

print:
    li $v0,1
    syscall
    li $v0,4
    la $a0,_ret
    syscall
    move $v0,$0
    jr $ra
'''

fout.write(template)

regs=Regs()

inner=[]

while True:

    lines = fin.readline()

    if len(lines) == 0:

        break

    str = lines.split()

    inner.append(str)

    temp_re='(temp\d+)'
    
    obj=[]
for line in inner:
    temps=re.findall(temp_re,' '.join(line))
    regs.variables.append(temps)
    print"*******"
    print line
        
for line in inner:
    obj_line=translate(regs,line) 
    if obj_line=='':
        continue
    obj.append(obj_line)
    print"========="
    print obj_line
    fout.write(obj_line+"\n")  
#for line in obj:   
	#fout.write(line+"\n")
