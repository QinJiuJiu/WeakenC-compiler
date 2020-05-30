#! /usr/bin/python

# coding=utf-8

import os

fin = open('quadruples.txt','rb')

fout = open('inner.txt', 'w')

while True:

    lines = fin.readline()

    if len(lines)==0:
        break
        
    print(lines)
    
    str = lines.split()
    
    if str[2]=="func":
    
        fout.write("FUNCTION "+str[4]+" :")


        fout.write('\n') 
        
    elif str[2]=="asn":
    
        fout.write(str[6]+" := " + str[4])


        fout.write('\n')
    
    elif str[2]=="par":
    
        fout.write("PARAM "+str[4])


        fout.write('\n') 
        

     
    elif str[2]=="lt":
    
        fout.write(str[8]+" := " + str[4] + " <= " + str[6])


        fout.write('\n') 
        
    elif str[2]=="gt":
    
        fout.write(str[8]+" := " + str[4] + " >= " + str[6])


        fout.write('\n')

    elif str[2]=="if_t":
    
        fout.write("IF "+str[4]+" GOTO " + str[6] )


        fout.write('\n')
    
    elif str[2]=="goto":
    
        fout.write("GOTO "+str[2])


        fout.write('\n')
        
    elif str[2]=="lab":
    
        fout.write("LABEL "+str[2]+" :"  )


        fout.write('\n')
    
    elif str[2]=="ret":
    
        if str[4]=="_":
            fout.write("RETURN")
        else:
            fout.write("RETURN "+str[4])

        fout.write('\n')
        
        
       
        
    elif str[2]=="sub":
    
        fout.write(str[8]+" := "+str[4]+" - " +str[6] )


        fout.write('\n')
        
    elif str[2]=="add":
    
        fout.write(str[8]+" := "+str[4]+" + " +str[6] )


        fout.write('\n')
        
    elif str[2]=="mul":
    
        fout.write(str[8]+" := "+str[4]+" * " +str[6] )


        fout.write('\n')
        
    elif str[2]=="div":
    
        fout.write(str[8]+" := "+str[4]+" / " +str[6] )


        fout.write('\n')
        
    elif str[2]=="arg":
    
        fout.write("ARG "+str[4])


        fout.write('\n')
        

    elif str[2]=="call":
    
        if str[6]=="_":
            fout.write("CALL "+str[4])
    
        else:
            fout.write(str[6]+" := "+"CALL "+str[4])


        fout.write('\n')
    elif str[2]=="arg":
    
        fout.write("ARG "+str[4])


        fout.write('\n') 
    
    if not lines:

       break

       pass
       
