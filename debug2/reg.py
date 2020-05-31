#! /usr/bin/python

# coding=utf-8
class Regs:
    def  __init__(self):
        self.regs=['t1','t2','t3','t4','t5','t6','t7','t8','t9','s0','s1','s2','s3','s4','s5','s6','s7']
        self.used_regs={}
        self.variables=[]
        
        
    def GetRegName(self,name):
        if name in self.variables:
            self.variables.remove(name)
       
        if self.used_regs.has_key(name):
            return '$'+self.used_regs[name]  
        
        else:
            has_reg=[]
            for key in self.used_regs:          
                has_reg.append(key)
            
            for var in has_reg:          
                if 'temp' in  var and var not in self.variables: #
                    del self.used_regs[var]
            
            new_dict = {v : k for k, v in self.used_regs.items()}
            
            for reg in self.regs:          
                if new_dict.has_key(reg) == False:     
                    self.used_regs[name]=reg   
