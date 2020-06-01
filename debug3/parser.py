

#! /usr/bin/python

# coding=utf-8


from block import varNode


from block import funcNode


from block import arrayNode


from block import Block


from quadruples import Quadruples


import os


class Parser:
    funcPool = None

    blockStack = None

    root = None

    def __init__(self, root):

        self.linenum = 0

        self.tempNum = 0

        self.varNum = 0

        self.labelNum = 0

        self.arrayNum = 0

        self.quadruplesList = []

        self.funcPool = {}

        self.blockStack = []

        self.root = root

        self.ParserInit()
        
        self.optimize_quadruplesList()

        self.print_quadruplesList()
        
    def optimize_quadruplesList(self):

        listlen=len(self.quadruplesList)
        i=-1
        while(i<len):
            i+=1
            if i >= len(self.quadruplesList):
                break
            print(self.quadruplesList[i].op)
            if self.quadruplesList[i].op=="asn" and self.quadruplesList[i].arg1==self.quadruplesList[i].arg2:
                del self.quadruplesList[i]
                i-=1
            elif i<len(self.quadruplesList)-1 and self.quadruplesList[i].op=="call" and  self.quadruplesList[i].arg2==self.quadruplesList[i+1].arg1 and self.quadruplesList[i+1].op=="asn":
                self.quadruplesList[i].arg2=self.quadruplesList[i+1].arg2
                del self.quadruplesList[i+1]
            
            elif i<len(self.quadruplesList)-2 and self.quadruplesList[i].op=="asn" and self.quadruplesList[i].arg1[0]=="#" and self.quadruplesList[i].arg2==self.quadruplesList[i+2].arg1:
                if self.quadruplesList[i+1].op=="asn":
                    if self.quadruplesList[i+1].arg1[0]=="#" and self.quadruplesList[i+1].arg2==self.quadruplesList[i+2].arg2:
                        
                        op=self.quadruplesList[i+2].op
                        if op=="add":
                            self.quadruplesList[i+2].op="asn"
                            tstr=self.quadruplesList[i].arg1[1:]
                            if tstr[0]=="F":
                                num1=float(tstr[1:])
                                num2=float(self.quadruplesList[i+1].arg1[2:])
                                num3=num1+num2
                                self.quadruplesList[i+2].arg1="#F"+str(num3)
                                self.quadruplesList[i+2].arg2==self.quadruplesList[i+2].result
                                self.quadruplesList[i+2].result=""
                            else:
                                num1=int(tstr)
                                num2=int(self.quadruplesList[i+1].arg1[1:])
                                num3=num1+num2
                                self.quadruplesList[i+2].arg1="#"+str(num3)
                                self.quadruplesList[i+2].arg2==self.quadruplesList[i+2].result
                                self.quadruplesList[i+2].result=""
                        elif op=="sub":
                            self.quadruplesList[i+2].op="asn"
                            tstr=self.quadruplesList[i].arg1[1:]
                            if tstr[0]=="F":
                                num1=float(tstr[1:])
                                num2=float(self.quadruplesList[i+1].arg1[2:])
                                num3=num1-num2
                                self.quadruplesList[i+2].arg1="#F"+str(num3)
                                self.quadruplesList[i+2].arg2==self.quadruplesList[i+2].result
                                self.quadruplesList[i+2].result=""
                            else:
                                num1=int(tstr)
                                num2=int(self.quadruplesList[i+1].arg1[1:])
                                num3=num1-num2
                                self.quadruplesList[i+2].arg1="#"+str(num3)
                                self.quadruplesList[i+2].arg2==self.quadruplesList[i+2].result
                                self.quadruplesList[i+2].result=""                              
                        elif op=="mul":
                            self.quadruplesList[i+2].op="asn"
                            tstr=self.quadruplesList[i].arg1[1:]
                            if tstr[0]=="F":
                                num1=float(tstr[1:])
                                num2=float(self.quadruplesList[i+1].arg1[2:])
                                num3=num1*num2
                                self.quadruplesList[i+2].arg1="#F"+str(num3)
                                self.quadruplesList[i+2].arg2==self.quadruplesList[i+2].result
                                self.quadruplesList[i+2].result=""
                            else:
                                num1=int(tstr)
                                num2=int(self.quadruplesList[i+1].arg1[1:])
                                num3=num1*num2
                                self.quadruplesList[i+2].arg1="#"+str(num3)
                                self.quadruplesList[i+2].arg2==self.quadruplesList[i+2].result
                                self.quadruplesList[i+2].result=""          
                        if op=="div":
                            self.quadruplesList[i+2].op="asn"
                            tstr=self.quadruplesList[i].arg1[1:]
                            if tstr[0]=="F":
                                num1=float(tstr[1:])
                                num2=float(self.quadruplesList[i+1].arg1[2:])
                                num3=num1/num2
                                self.quadruplesList[i+2].arg1="#F"+str(num3)
                                self.quadruplesList[i+2].arg2==self.quadruplesList[i+2].result
                                self.quadruplesList[i+2].result=""
                            else:
                                num1=int(tstr)
                                num2=int(self.quadruplesList[i+1].arg1[1:])
                                num3=num1/num2
                                self.quadruplesList[i+2].arg1="#"+str(num3)
                                self.quadruplesList[i+2].arg2==self.quadruplesList[i+2].result
                                self.quadruplesList[i+2].result=""
                        del self.quadruplesList[i]
                        del self.quadruplesList[i+1]

            
                                
    def print_quadruplesList(self):

        out = open('quadruples.txt', 'w')

        for i in self.quadruplesList:
            t0 = i.num
            t1 = i.op
            if(i.arg1 == ""):
                t2 = "_"
            else:
                t2 = i.arg1
            if(i.arg2 == ""):
                t3 = "_"
            else:
                t3 = i.arg2
            if(i.result == ""):
                t4 = "_"
            else:
                t4 = i.result

            final_quadruples = str(
                t0) + "  ( " + t1+" , " + t2+" , " + t3+" , " + t4+" ) "

            print final_quadruples

            out.write(final_quadruples)
        
            out.write('\n')
        out.write(str(self.linenum+1) + "  ( asn , #0 , temp100 , _ ) ")
        out.write('\n')
        out.write(str(self.linenum+2) + "  ( ret , temp100 , _ , _ ) ")
        out.write('\n')
        
    def ParserInit(self):

        wholeBlock = Block()

        self.blockStack.append(wholeBlock)

        writeNode = funcNode()

        writeNode.name = "print"

        writeNode.re_type = "void"

        pnode = varNode()

        pnode.type = "int"

        writeNode.para_list.append(pnode)

        self.funcPool["print"] = writeNode

        readNode = funcNode()

        readNode.name = "read"

        readNode.re_type = "int"

        self.funcPool["read"] = readNode

        self.ParserSyntaxTree(self.root)

    def ParserSyntaxTree(self, node):

        if node == None or node.line == -1:

            return

        if node.name == "declaration":

            node = self.Parser_declaration(node)

        elif node.name == "function_definition":

            node = self.Parser_function_definition(node)

        elif node.name == "statement":

            node = self.Parser_statement(node)

        if node is not None:

            self.ParserSyntaxTree(node.child)

            self.ParserSyntaxTree(node.sibling)

    def Parser_statement(self, node):

        if node == None:

            return

        temp = node.child


        if node.child.name == "compound_statement":

            self.Parser_compound_statement(node.child)

        if node.child.name == "expression_statement":

            self.Parser_expression_statement(node.child)

        if node.child.name == "selection_statement":

            self.Parser_selection_statement(node.child)

        if node.child.name == "iteration_statement":

            self.Parser_iteration_statement(node.child)

        if node.child.name == "jump_statement":

            self.Parser_jump_statement(node.child)

        return node.sibling

    def Parser_jump_statement(self, node):

        if node == None:

            return

        if node.child.name == "GOTO":

            node.child.name = "GOTO"

        elif node.child.name == "CONTINUE":

            node.child.name == "CONTINUE"

        elif node.child.name == "BREAK":

            num = self.getBreakBlockNumber()

            if num < 0:

                self.error(node.child.line, "This scope doesn't support break.")

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "goto"
            q.arg1 = self.blockStack[num].label_bk
            self.quadruplesList.append(q)

        elif node.child.name == "RETURN":

            funcType = self.getFuncRType()

            if node.child.sibling.name == "expression":

                rnode = self.Parser_expression(node.child.sibling)

                q = Quadruples()

                q.num = self.linenum
                self.linenum += 1

                q.op = "ret"
                q.SetArgName(1, rnode)

                self.quadruplesList.append(q)

                if rnode.type != funcType:

                    self.error(
                        node.child.sibling.line, "return type doesn't equal to function return type.")

            elif node.child.sibling.name == ";":

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "ret"
                self.quadruplesList.append(q)

                #if funcType != "void":

                    #self.error(
                        #node.child.sibling.line, "You should return " + self.blockStack[-1].func.re_type)

    def Parser_expression_statement(self, node):

        if node == None:

            return

        if node.child.name == "expression":

            self.Parser_expression(node.child)

    def Parser_expression(self, node):

        if node == None:

            return

        if node.child.name == "expression":

            return self.Parser_expression(node.child)

        elif node.child.name == "assignment_expression":

            return self.Parser_assignment_expression(node.child)

        if node.sibling.name == ",":

            return self.Parser_assignment_expression(node.sibling.sibling)

    def Parser_compound_statement(self, node):

        if node == None:

            return

        self.ParserSyntaxTree(node)

    def Parser_selection_statement(self, node):

        if node == None:

            return

        if node.child.name == "IF":

            if node.child.sibling.sibling.sibling.sibling.sibling == None:

                newblock = Block()

                self.blockStack.append(newblock)

                expression = node.child.sibling.sibling

                exp_rnode = self.Parser_expression(expression)

                statement = node.child.sibling.sibling.sibling.sibling

                label1 = 'label' + str(self.labelNum)

                self.labelNum += 1

                label2 = 'label' + str(self.labelNum)

                self.labelNum += 1

                if exp_rnode.type == "bool":

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "if_t"
                    str_no_blank=exp_rnode.bool_exp.split()
                    i=0
                    exp_str=""
                    for single in str_no_blank:
                        exp_str+=single
                    q.arg1 = exp_str
                    q.arg2 = label1
                    self.quadruplesList.append(q)

                else:

                    tempzeroname = "temp" + str(self.tempNum)

                    self.tempNum += 1

                    newznode = self.createTempVar(tempzeroname, "int")

                    q = Quadruples()
                    q.op = "asn"
                    q.arg2 = "tempzeroname"
                    q.arg1 = "#0"
                    q.num = self.linenum
                    self.linenum += 1
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "if_ne"
                    q.SetArgName(1, exp_rnode)

                    q.arg2 = tempzeroname
                    q.result = label1
                    self.quadruplesList.append(q)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "goto"
                q.arg1 = label2
                self.quadruplesList.append(q)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "lab"
                q.arg1 = label1
                self.quadruplesList.append(q)

                self.Parser_statement(statement)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "lab"
                q.arg1 = label2
                self.quadruplesList.append(q)

                self.blockStack.pop()

            elif node.child.sibling.sibling.sibling.sibling.sibling.name == "ELSE":

                newblock1 = Block()

                self.blockStack.append(newblock1)

                expression = node.child.sibling.sibling

                exp_rnode = self.Parser_expression(expression)

                statement1 = node.child.sibling.sibling.sibling.sibling

                statement2 = node.child.sibling.sibling.sibling.sibling.sibling.sibling

                label1 = 'label' + str(self.labelNum)
                self.labelNum += 1

                label2 = 'label' + str(self.labelNum)
                self.labelNum += 1

                label3 = 'label' + str(self.labelNum)
                self.labelNum += 1

                if exp_rnode.type == "bool":

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "if_t"
                  
                    str_no_blank=exp_rnode.bool_exp.split()
                    i=0
                    exp_str=""
                    for single in str_no_blank:
                        exp_str+=single
                    q.arg1 = exp_str
                    
                    q.arg2 = label1
                    self.quadruplesList.append(q)

                else:

                    tempzeroname = "temp" + str(self.tempNum)

                    self.tempNum += 1

                    newznode = self.createTempVar(tempzeroname, "int")

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "asn"
                    q.arg1 = "#0"
                    q.arg2 = tempzeroname
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "if_ne"
                    q.SetArgName(1, exp_rnode)

                    q.arg2 = tempzeroname
                    q.result = label1
                    self.quadruplesList.append(q)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "goto"
                q.arg1 = label2
                self.quadruplesList.append(q)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "lab"
                q.arg1 = label1
                self.quadruplesList.append(q)

                self.Parser_statement(statement1)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "goto"
                q.arg1 = label3
                self.quadruplesList.append(q)

                self.blockStack.pop()

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "lab"
                q.arg1 = label2
                self.quadruplesList.append(q)

                newblock2 = Block()

                self.blockStack.append(newblock2)

                self.Parser_statement(statement2)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "lab"
                q.arg1 = label3
                self.quadruplesList.append(q)

                self.blockStack.pop()

        # elif node.child.name == "SWITCH":

    def Parser_iteration_statement(self, node):

        if node == None:

            return

        if node.child.name == "WHILE":

            newblock = Block()

            newblock.can_bk = True

            self.blockStack.append(newblock)

            expression = node.child.sibling.sibling

            statement = node.child.sibling.sibling.sibling.sibling

            label1 = 'label' + str(self.labelNum)
            self.labelNum += 1

            label2 = 'label' + str(self.labelNum)
            self.labelNum += 1

            label3 = 'label' + str(self.labelNum)
            self.labelNum += 1

            self.blockStack[-1].label_bk = label3

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "lab"
            q.arg1 = label1
            self.quadruplesList.append(q)

            var = self.Parser_expression(expression)

            if var.type == "bool":

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "if_t"
                str_no_blank=var.bool_exp.split()
                i=0
                exp_str=""
                for single in str_no_blank:
                    exp_str+=single
                q.arg1 = exp_str

                q.arg2 = label2
                self.quadruplesList.append(q)

            else:

                tempzeroname = "temp" + str(self.tempNum)

                self.tempNum = self.tempNum + 1

                newznode = self.createTempVar(tempzeroname, "int")

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "asn"
                q.arg2 = tempzeroname
                q.arg1 = "#0"
                self.quadruplesList.append(q)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "if_ne"
                q.SetArgName(1, var)

                q.arg2 = tempzeroname
                q.result = label2
                self.quadruplesList.append(q)

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "goto"
            q.arg1 = label3
            self.quadruplesList.append(q)

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "lab"
            q.arg1 = label2
            self.quadruplesList.append(q)

            self.Parser_statement(statement)

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "goto"
            q.arg1 = label1
            self.quadruplesList.append(q)

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "lab"
            q.arg1 = label3
            self.quadruplesList.append(q)

            self.blockStack.pop()

        elif node.child.name == "DO":

            newblock = Block()

            newblock.can_bk = True

            self.blockStack.append(newblock)

            expression = node.child.sibling

            statement = node.child.sibling.sibling.sibling.sibling

            label1 = 'label' + str(self.labelNum)
            self.labelNum += 1

            label2 = 'label' + str(self.labelNum)
            self.labelNum += 1

            self.blockStack[-1].label_bk = label2

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "lab"
            q.arg1 = label1
            self.quadruplesList.append(q)

            self.Parser_statement(statement)

            var = self.Parser_expression(expression)

            if var.type == "bool":

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "if_t"
                
                  
                str_no_blank=exp_rnode.bool_exp.split()
                i=0
                exp_str=""
                for single in str_no_blank:
                    exp_str+=single
                q.arg1 = exp_str
                
                q.arg2 = label1
                self.quadruplesList.append(q)

            else:

                tempzeroname = "temp" + str(self.tempNum)

                self.tempNum = self.tempNum + 1

                newznode = self.createTempVar(tempzeroname, "int")

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "asn"
                q.arg2 = tempzeroname
                q.arg1 = "#0"
                self.quadruplesList.append(q)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "if_ne"
                q.SetArgName(1, var)

                q.arg2 = tempzeroname
                q.result = label1
                self.quadruplesList.append(q)

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "lab"
            q.arg1 = label2
            self.quadruplesList.append(q)

            self.blockStack.pop()

        elif node.child.name == "FOR":

            if node.child.sibling.sibling.name == "expression_statement":

                if node.child.sibling.sibling.sibling.sibling.name == ")":

                    newblock = Block()

                    newblock.can_bk = True

                    self.blockStack.append(newblock)

                    exp_state1 = node.child.sibling.sibling

                    exp_state2 = exp_state1.sibling

                    statement = exp_state2.sibling.sibling

                    label1 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label2 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label3 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    self.blockStack[-1].label_bk = label3

                    if exp_state1.child.name == "expression":

                        self.Parser_expression(exp_state1.child)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    if exp_state2.child.name == "expression":

                        var = self.Parser_expression(exp_state2.child)

                        if var.type == "bool":

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_t"
                           
                  
                            str_no_blank=exp_rnode.bool_exp.split()
                            i=0
                            exp_str=""
                            for single in str_no_blank:
                                exp_str+=single
                            q.arg1 = exp_str
                            q.arg2 = label2
                            self.quadruplesList.append(q)

                        else:

                            tempzeroname = "temp" + str(self.tempNum)

                            self.tempNum = self.tempNum + 1

                            newznode = self.createTempVar(tempzeroname, "int")

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "asn"
                            q.arg2 = tempzeroname
                            q.arg1 = "#0"
                            self.quadruplesList.append(q)

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_ne"
                            q.SetArgName(1, var)

                            q.arg2 = tempzeroname
                            q.result = label2
                            self.quadruplesList.append(q)

                    else:

                        q = Quadruples()
                        q.num = self.linenum
                        self.linenum += 1
                        q.op = "goto"
                        q.arg1 = label2
                        self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "goto"
                    q.arg1 = label3
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label2
                    self.quadruplesList.append(q)

                    self.Parser_statement(statement)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "goto"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label3
                    self.quadruplesList.append(q)

                    self.blockStack.pop()

                elif node.child.sibling.sibling.sibling.sibling.name == "expression":

                    newblock = Block()

                    newblock.can_bk = True

                    self.blockStack.append(newblock)

                    exp_state1 = node.child.sibling.sibling

                    exp_state2 = exp_state1.sibling

                    exp = exp_state2.sibling

                    statement = exp.sibling.sibling

                    label1 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label2 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label3 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    self.blockStack[-1].label_bk = label3

                    if exp_state1.child.name == "expression":

                        self.Parser_expression(exp_state1.child)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    if exp_state2.child.name == "expression":

                        var = self.Parser_expression(exp_state2.child)

                        if var.type == "bool":

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_t"
                            
                  
                            str_no_blank=var.bool_exp.split()
                            i=0
                            exp_str=""
                            for single in str_no_blank:
                                exp_str+=single
                            q.arg1 = exp_str
                          
                            q.arg2 = label2
                            self.quadruplesList.append(q)

                        else:

                            tempzeroname = "temp" + str(self.tempNum)

                            self.tempNum += 1

                            newznode = self.createTempVar(tempzeroname, "int")

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "asn"
                            q.arg2 = tempzeroname
                            q.arg1 = "#0"
                            self.quadruplesList.append(q)

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_ne"
                            q.SetArgName(1, var)

                            q.arg2 = tempzeroname
                            q.result = label2
                            self.quadruplesList.append(q)

                    else:

                        q = Quadruples()
                        q.num = self.linenum
                        self.linenum += 1
                        q.op = "goto"
                        q.arg1 = label2
                        self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "goto"
                    q.arg1 = label3
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label2
                    self.quadruplesList.append(q)

                    self.Parser_statement(statement)
                    self.Parser_expression(exp)
                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "goto"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label3
                    self.quadruplesList.append(q)

                    self.blockStack.pop()

            if node.child.sibling.sibling.name == "declaration":

                if node.child.sibling.sibling.sibling.sibling.name == ")":

                    newblock = Block()

                    newblock.can_bk = True

                    self.blockStack.append(newblock)

                    declaration = node.child.sibling.sibling

                    expression_statement = declaration.sibling

                    statement = expression_statement.sibling.sibling

                    label1 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label2 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label3 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    self.blockStack[-1].label_bk = label3

                    self.Parser_declaration(declaration)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    if expression_statement.child.name == "expression":

                        var = self.Parser_expression(expression_statement.child)

                        if var.type == "bool":

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_t"
                            
                  
                            str_no_blank=exp_rnode.bool_exp.split()
                            i=0
                            exp_str=""
                            for single in str_no_blank:
                                exp_str+=single
                            q.arg1 = exp_str
                           
                            q.arg2 = label2
                            self.quadruplesList.append(q)

                        else:

                            tempzeroname = "temp" + str(self.tempNum)

                            self.tempNum = self.tempNum + 1

                            newznode = self.createTempVar(tempzeroname, "int")

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "asn"
                            q.arg2 = tempzeroname
                            q.arg1 = "#0"
                            self.quadruplesList.append(q)

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_ne"
                            q.SetArgName(1, var)

                            q.arg2 = tempzeroname
                            q.result = label2
                            self.quadruplesList.append(q)

                    else:

                        q = Quadruples()
                        q.num = self.linenum
                        self.linenum += 1
                        q.op = "goto"
                        q.arg1 = label2
                        self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "goto"
                    q.arg1 = label3
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label2
                    self.quadruplesList.append(q)

                    self.Parser_statement(statement)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "goto"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label3
                    self.quadruplesList.append(q)

                    self.blockStack.pop()

                elif node.child.sibling.sibling.sibling.sibling.name == "expression":

                    newblock = Block()

                    newblock.can_bk = True

                    self.blockStack.append(newblock)

                    declaration = node.child.sibling.sibling

                    expression_statement = declaration.sibling

                    expression = expression_statement.sibling

                    statement = expression.sibling.sibling

                    label1 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label2 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label3 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    self.blockStack[-1].label_bk = label3

                    self.Parser_declaration(declaration)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    if expression_statement.child.name == "expression":

                        var = self.Parser_expression(expression_statement.child)

                        if var.type == "bool":

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_t"
                             
                  
                            str_no_blank=exp_rnode.bool_exp.split()
                            i=0
                            exp_str=""
                            for single in str_no_blank:
                                exp_str+=single
                            q.arg1 = exp_str
                             
                            q.arg2 = label2
                            self.quadruplesList.append(q)

                        else:

                            tempzeroname = "temp" + str(self.tempNum)

                            self.tempNum = self.tempNum + 1

                            newznode = self.createTempVar(tempzeroname, "int")

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "asn"
                            q.arg2 = tempzeroname
                            q.arg1 = "#0"
                            self.quadruplesList.append(q)

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_ne"
                            q.SetArgName(1, var)

                            q.arg2 = tempzeroname
                            q.result = label2
                            self.quadruplesList.append(q)

                    else:

                        q = Quadruples()
                        q.num = self.linenum
                        self.linenum += 1
                        q.op = "goto"
                        q.arg1 = label2
                        self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "goto"
                    q.arg1 = label3
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label2
                    self.quadruplesList.append(q)

                    self.Parser_statement(statement)

                    self.Parser_expression(expression)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "goto"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label3
                    self.quadruplesList.append(q)

                    self.blockStack.pop()

    def Parser_function_definition(self, node):

        if node == None:

            return

        type_definition = node.child

        declarator = node.child.sibling

        compound_statement = declarator.sibling

        funcType = type_definition.child.content

        funcName = declarator.child.child.content

        isdeclared = False

        if funcName in self.funcPool.keys():

            if self.funcPool[funcName].isdefinied:

                self.error(declarator.child.child.line, "Function " +
                           funcName + " is duplicated definition.")

            else:

                isdeclared = True

                declarFunc = self.funcPool[funcName]

                self.funcPool.pop(funcName)

        funBlock = Block()

        funBlock.is_func = True

        funBlock.func.name = funcName

        funBlock.func.re_type = funcType

        funBlock.func.isdefinied = True

        self.blockStack.append(funBlock)

        self.funcPool[funcName] = funBlock.func

        q = Quadruples()
        q.num = self.linenum
        self.linenum += 1
        q.op = "func"
        q.arg1 = funcName
        self.quadruplesList.append(q)

        if declarator.child.sibling.sibling.name == "parameter_list":

            self.Parser_parameter_list(
                declarator.child.sibling.sibling, funcName, True)

        func = self.funcPool[funcName]

        if isdeclared:

            if func.re_type != declarFunc.re_type:

                self.error(type_definition.child.line,
                           "Function return type doesn't equal to the function declared before.")

            print(len(funBlock.func.para_list))

            if len(func.para_list) != len(declarFunc.para_list):

                self.error(declarator.child.sibling.sibling.line,
                           "The number of function parameters doesn't equal to the function declared before.")

            for i in range(len((funBlock.func.para_list))):

                if func.para_list[i].type != declarFunc.para_list[i].type:

                    self.error(declarator.child.sibling.sibling.line, "The parameter " +
                               funBlock.func.para_list[i].name + "'s type doesn't equal to the function declared before.")

        funBlock.func = func

        self.Parser_compound_statement(compound_statement)

        self.blockStack.pop()

        return node.sibling

    def Parser_parameter_list(self, node, funcName, definite):

        if node == None:

            return

        if node.child.name == "parameter_list":

            self.Parser_parameter_list(node.child, funcName, definite)

        elif node.child.name == "parameter_declaration":

            self.Parser_parameter_declaration(node.child, funcName, definite)

        if node.sibling.name == ",":

            self.Parser_parameter_declaration(
                node.sibling.sibling, funcName, definite)

    def Parser_parameter_declaration(self, node, funcName, definite):

        if node == None:

            return

        type_definition = node.child

        declarator = node.child.sibling

        typeName = type_definition.child.content

        if typeName == "void":

            self.error(type_definition.line, "Void can't definite parameter.")

        varName = declarator.child.content

        newnode = varNode()

        newnode.name = varName

        newnode.type = typeName

        if definite:

            self.blockStack[-1].func.para_list.append(newnode)

            newnode.num = self.varNum

            self.varNum = self.varNum + 1

            self.blockStack[-1].func.para_list.append(newnode)

        if newnode not in self.funcPool[funcName].para_list:

            self.funcPool[funcName].para_list.append(newnode)

        self.blockStack[-1].varMap[varName] = newnode

        if definite:

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "par"
            q.arg1 = 'var' + str(newnode.num)
            self.quadruplesList.append(q)

    def Parser_declaration(self, node):

        if node == None:

            return

        begin = node.child

        if begin.sibling.name == ";":

            return node.sibling

        vartype = begin.child.content

        if vartype == "void":

            self.error(begin.child.line, "void type can't assign to variable")

        decl = begin.sibling

        self.Parser_init_declarator_list(vartype, decl)

        return node.sibling



# TODO =======================================DIVIDE=======================================
    def Parser_init_declarator_list(self, vartype, node):

        if node == None:

            return

        if node.child.name == 'init_declarator_list':

            self.Parser_init_declarator_list(vartype, node.child)

        elif node.child.name == 'init_declarator':

            self.Parser_init_declarator(vartype, node.child)

        if node.sibling.name == ',':

            self.Parser_init_declarator(vartype, node.sibling.sibling)

    def Parser_init_declarator(self, vartype, node):

        if node == None:

            return

        declarator = node.child

        if declarator.sibling == None:

            if declarator.child.name == 'IDENTIFIER':

                id = declarator.child

                var = id.content

                if self.lookupCurruntVar(var) == 0:

                    newvar = varNode()

                    newvar.name = var

                    newvar.type = vartype

                    newvar.num = self.varNum

                    self.varNum += 1

                    self.blockStack[len(self.blockStack) -
                                    1].varMap[var] = newvar  # not sure

                else:

                    self.error(declarator.child.line,
                               'Variable multiple declaration')

            else:

                if declarator.child.sibling.name == '(':

                    funcName = declarator.child.child.content

                    funcType = vartype

                    if len(self.blockStack) > 1:

                        self.error(
                            declarator.child.sibling.line, 'Function declaration must at global environment.')

                    parament_list = declarator.child.sibling.sibling

                    newFunc = funcNode()

                    # newFunc.isdefined = False

                    newFunc.name = funcName

                    newFunc.type = funcType

                    self.funcPool.append({funcName, newFunc})

                    self.Parser_parameter_list(parament_list, funcName, False)

                elif declarator.child.sibling.name == '[':

                    arrayName = declarator.child.child.content

                    arrayType = vartype

                    assign_exp = declarator.child.sibling.sibling

                    rnode = self.Parser_assignment_expression(assign_exp)

                    if rnode.type != 'int':

                        self.error(declarator.child.sibling.line,
                                   "Array size must be int.")

                    tnode = varNode()

                    if arrayType == 'int':

                        tempname = "temp" + str(self.tempNum)

                        self.tempNum += 1

                        tnode = self.createTempVar(tempname, 'int')

                        self.blockStack[len(self.blockStack) -
                                        1].varMap[tempname] = tnode

                        tempVar3 = varNode()

                        tempName3 = 'temp' + str(self.tempNum)

                        tempVar3.name = tempName3

                        tempVar3.type = 'int'

                        # not sure
                        self.blockStack[len(self.blockStack) -
                                        1].varMap[tempName3] = tempVar3

                        q = Quadruples()
                        q.num = self.linenum
                        self.linenum += 1
                        q.op = "asn"
                        q.arg2 = tempName3
                        q.arg1 = "#4"
                        self.quadruplesList.append(q)

                        q = Quadruples()
                        q.num = self.linenum
                        self.linenum += 1
                        q.op = "mul"
                        q.arg1 = tempName3
                        q.arg2 = rnode.name
                        q.result = tnode.name
                        self.quadruplesList.append(q)

                    elif arrayType == 'double':

                        tempname = "temp" + str(self.tempNum)

                        self.tempNum += 1

                        tnode = self.createTempVar(tempname, 'int')

                        self.blockStack[len(self.blockStack) -
                                        1].varMap[tempname] = tnode

                        tempVar3 = varNode()

                        tempName3 = 'temp' + str(self.tempNum)

                        tempVar3.name = tempName3

                        tempVar3.type = 'int'

                        # not sure
                        self.blockStack[len(self.blockStack) -
                                        1].varMap[tempName3] = tempVar3

                        q = Quadruples()
                        q.num = self.linenum
                        self.linenum += 1
                        q.op = "asn"
                        q.arg2 = tempName3
                        q.arg1 = "#8"
                        self.quadruplesList.append(q)

                        q = Quadruples()
                        q.num = self.linenum
                        self.linenum += 1
                        q.op = "mul"
                        q.arg1 = tempName3
                        q.arg2 = rnode.name
                        q.result = tnode.name
                        self.quadruplesList.append(q)

                    elif arrayType == 'bool':

                        tnode = rnode

                    anode = arrayNode()  # ?

                    anode.name = arrayName

                    anode.type = arrayType

                    anode.num = self.arrayNum

                    self.arrayNum += 1

                    self.blockStack[len(self.blockStack) -
                                    1].arrayMap[arrayName] = anode

        elif declarator.sibling.name == '=':

            newvar = varNode()

            if declarator.child.name == 'IDEMTIFIER':

                id = declarator.child

                var = id.content

                if self.lookupCurruntVar(var) == 0:

                    newvar.name = var

                    newvar.type = vartype

                    newvar.num = self.varNum

                    self.varNum += 1

                    self.blockStack[len(self.blockStack) -
                                    1].varMap[var] = newvar  # not sure

                else:

                    self.error(declarator.child.line,
                               'Variable multiple declaration')

                initializer = declarator.sibling.sibling

                if initializer == None:

                    self.error(declarator.line,
                               'Lack the initializer for variable')

                else:

                    if initializer.child.name == 'assignment_expression':

                        rnode = self.Parser_assignment_expression(
                            initializer.child)

                        q = Quadruples()
                        q.num = self.linenum
                        self.linenum += 1
                        q.op = "asn"
                        q.SetArgName(2, newvar)
                        q.SetArgName(1, rnode)

                        self.quadruplesList.append(q)

                        rtype = rnode.type

                        if rtype != vartype:

                            self.error(initializer.child.line, 'Wrong type to variable ' +
                                       declarator.child.content + ": " + rtype + ' to ' + vartype)

        else:

            self.error(declarator.sibling.line, "Wrong value to variable")

    def Parser_assignment_expression(self, assign_exp):

        if assign_exp.child.name == 'logical_or_expression':

            logical_or_exp = assign_exp.child

            return self.Parser_logical_or_expression(logical_or_exp)

        elif assign_exp.child.name == "monocular_expression":

            unary_exp = assign_exp.child

            op = assign_exp.child.sibling.child.name

            next_assign_exp = assign_exp.child.sibling.sibling

            node1 = self.Parser_monocular_expression(unary_exp)

            node2 = self.Parser_assignment_expression(next_assign_exp)

            if op == '=':

                node3 = node2

            else:

                tempname = 'temp' + str(self.tempNum)

                self.tempNum += 1

                node3 = self.createTempVar(tempname, node1.type)

                self.blockStack[len(self.blockStack) -
                                1].varMap[tempname] = node3

                if op == 'MUL_ASSIGN':

                    if node1.type != node2.type:

                        self.error(assign_exp.child.line,
                                   "Different type for two variables.")

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "mul"
                    q.SetArgName(1, node1)
                    q.SetArgName(2, node2)
                    q.result = tempname
                    self.quadruplesList.append(q)

                elif op == 'DIV_ASSIGN':

                    if node1.type != node2.type:

                        self.error(assign_exp.child.line,
                                   "Different type for two variables.")

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "div"
                    q.SetArgName(1, node1)
                    q.SetArgName(2, node2)
                    q.result = tempname
                    self.quadruplesList.append(q)

                elif op == 'MOD_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.child.line,
                                   "The two variables must be int.")

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "mod"
                    q.SetArgName(1, node1)
                    q.SetArgName(2, node2)
                    q.result = tempname
                    self.quadruplesList.append(q)

                elif op == 'ADD_ASSIGN':

                    if node1.type != node2.type:

                        self.error(assign_exp.child.line,
                                   "Different type for two variables.")

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "add"
                    q.SetArgName(1, node1)
                    q.SetArgName(2, node2)
                    q.result = tempname
                    self.quadruplesList.append(q)

                elif op == 'SUB_ASSIGN':

                    if node1.type != node2.type:

                        self.error(assign_exp.child.line,
                                   "Different type for two variables.")

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "sub"
                    q.SetArgName(1, node1)
                    q.SetArgName(2, node2)
                    q.result = tempname
                    self.quadruplesList.append(q)

                elif op == 'LEFT_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.child.line,
                                   "The two variables must be int.")

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "sll"
                    q.SetArgName(1, node1)
                    q.SetArgName(2, node2)
                    q.result = tempname
                    self.quadruplesList.append(q)

                elif op == 'RIGHT_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.child.line,
                                   "The two variables must be int.")

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "srl"
                    q.SetArgName(1, node1)
                    q.SetArgName(2, node2)
                    q.result = tempname
                    self.quadruplesList.append(q)

                elif op == 'AND_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.child.line,
                                   "The two variables must be int.")

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "and"
                    q.SetArgName(1, node1)
                    q.SetArgName(2, node2)
                    q.result = tempname
                    self.quadruplesList.append(q)

                elif op == 'XOR_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.child.line,
                                   "The two variables must be int.")

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "xor"
                    q.SetArgName(1, node1)
                    q.SetArgName(2, node2)
                    q.result = tempname
                    self.quadruplesList.append(q)

                elif op == 'OR_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.child.line,
                                   "The two variables must be int.")

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "or"
                    q.SetArgName(1, node1)
                    q.SetArgName(2, node2)
                    q.result = tempname
                    self.quadruplesList.append(q)

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "asn"
            q.SetArgName(2, node1)
            q.SetArgName(1, node2)
            self.quadruplesList.append(q)

            return node1

    def Parser_logical_or_expression(self, logical_or_exp):

        if logical_or_exp.child.name == 'logical_and_expression':

            logical_and_exp = logical_or_exp.child

            return self.Parser_logical_and_expression(logical_and_exp)

        elif logical_or_exp.child.name == 'logical_or_expression':

            node1 = self.Parser_logical_or_expression(logical_or_exp.child)

            node2 = self.Parser_logical_and_expression(
                logical_or_exp.child.sibling.sibling)

            if node1.type != 'bool' or node2 != 'bool':

                self.error(logical_or_exp.child.sibling.line,
                           'Logical Or operation should only used to bool.')

            tempname = 'temp' + str(self.tempNum)

            self.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) -
                            1].varMap[tempname] = newnode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "or"
            q.SetArgName(1, node1)
            q.SetArgName(2, node2)
            q.result = tempname
            self.quadruplesList.append(q)

            q = Quadruples()

            newnode.bool_exp = q.GetNodeName(
                node1) + ' || ' + q.GetNodeName(node2)

            return newnode

    def Parser_logical_and_expression(self, logical_and_exp):

        if logical_and_exp.child.name == 'bitwise_or_expression':

            inclusive_or_exp = logical_and_exp.child

            return self.Parser_bitwise_or_expression(inclusive_or_exp)

        elif logical_and_exp.child.name == 'logical_and_expression':

            node1 = self.Parser_logical_and_expression(logical_and_exp.child)

            node2 = self.Parser_bitwise_or_expression(
                logical_and_exp.child.sibling.sibling)

            if node1.type != 'bool' or node2 != 'bool':

                self.error(logical_and_exp.child.sibling.line,
                           'Logical And operation should only used to bool.')

            tempname = 'temp' + str(self.tempNum)

            self.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) -
                            1].varMap[tempname] = newnode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "and"
            q.SetArgName(1, node1)
            q.SetArgName(2, node2)
            q.result = tempname
            self.quadruplesList.append(q)

            q = Quadruples()
            newnode.bool_exp = q.GetNodeName(
                node1) + ' && ' + q.GetNodeName(node2)

            return newnode

    def Parser_bitwise_or_expression(self, inclusive_or_exp):

        if inclusive_or_exp.child.name == 'xor_expression':

            exclusive_or_exp = inclusive_or_exp.child

            return self.Parser_xor_expression(exclusive_or_exp)

        elif inclusive_or_exp.child.name == 'bitwise_or_expression':

            node1 = self.Parser_bitwise_or_expression(inclusive_or_exp.child)

            node2 = self.Parser_xor_expression(
                inclusive_or_exp.child.sibling.sibling)

            if node1.type != 'int' or node2 != 'int':

                self.error(inclusive_or_exp.child.sibling.line,
                           'Inclusive Or operation should only used to bool.')

            tempname = 'temp' + str(self.tempNum)

            self.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) -
                            1].varMap[tempname] = newnode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "ior"
            q.SetArgName(1, node1)
            q.SetArgName(2, node2)
            q.result = tempname
            self.quadruplesList.append(q)

            return newnode

    def Parser_xor_expression(self, exclusive_or_exp):

        if exclusive_or_exp.child.name == 'and_expression':

            and_exp = exclusive_or_exp.child

            return self.Parser_and_expression(and_exp)

        elif exclusive_or_exp.child.name == 'xor_expression':

            node1 = self.Parser_xor_expression(exclusive_or_exp.child)

            node2 = self.Parser_and_expression(
                exclusive_or_exp.child.sibling.sibling)

            if node1.type != 'int' or node2 != 'int':

                self.error(exclusive_or_exp.child.sibling.line,
                           'Exclusive Or operation should only used to bool.')

            tempname = 'temp' + str(self.tempNum)

            self.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) -
                            1].varMap[tempname] = newnode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "xor"
            q.SetArgName(1, node1)
            q.SetArgName(2, node2)
            q.result = tempname
            self.quadruplesList.append(q)

            return newnode

    def Parser_and_expression(self, and_exp):

        if and_exp.child.name == 'equaljudge_expression':

            equality_exp = and_exp.child

            return self.Parser_equaljudge_expression(equality_exp)

        elif and_exp.child.name == 'and_expression':

            node1 = self.Parser_and_expression(and_exp.child)

            node2 = self.Parser_equaljudge_expression(and_exp.child.sibling.sibling)

            if node1.type != 'int' or node2 != 'int':

                self.error(and_exp.child.sibling.line,
                           'And operation should only used to bool.')

            tempname = 'temp' + str(self.tempNum)

            self.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) -
                            1].varMap[tempname] = newnode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "and"
            q.SetArgName(1, node1)
            q.SetArgName(2, node2)
            q.result = tempname
            self.quadruplesList.append(q)

            return newnode

    def Parser_equaljudge_expression(self, equality_exp):

        print("########")

        print(equality_exp.name)

        print(equality_exp.child.name)

        print("########")

        if equality_exp.child.name == 'compare_expression':

            relational_exp = equality_exp.child

            return self.Parser_compare_expression(relational_exp)

        elif equality_exp.child.sibling.name == 'EQ_OP' or equality_exp.child.sibling.name == 'NE_OP':

            if equality_exp.child.sibling.name == 'EQ_OP':

                op = '=='

            else:

                op = '!='

            node1 = self.Parser_equaljudge_expression(equality_exp.child)

            node2 = self.Parser_compare_expression(
                equality_exp.child.sibling.sibling)

            if node1.type != node2.type:

                self.error(equality_exp.child.sibling.line,
                           'Different type for two variables.')

            tempname = 'temp' + str(self.tempNum)

            self.tempNum += 1

            newnode = self.createTempVar(tempname, 'bool')

            self.blockStack[len(self.blockStack) -
                            1].varMap[tempname] = newnode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            if op == '!=':
                q.op = "ne"
            else:
                q.op = "eq"
            q.SetArgName(1, node1)
            q.SetArgName(2, node2)
            q.result = tempname
            self.quadruplesList.append(q)

            q = Quadruples()
            newnode.bool_exp = q.GetNodeName(
                node1) + " " + op + " " + q.GetNodeName(node2)

            return newnode

    def Parser_compare_expression(self, relational_exp):

        if relational_exp.child.name == 'shift_expression':

            shift_exp = relational_exp.child

            return self.Parser_shift_expression(shift_exp)

        else:

            op = relational_exp.child.sibling.name

            if op == 'LE_OP':

                op = '<='

            elif op == 'GE_OP':

                op = '>='

            if op == '>' or op == '<' or op == '>=' or op == '<=':

                node1 = self.Parser_compare_expression(relational_exp.child)

                node2 = self.Parser_shift_expression(
                    relational_exp.child.sibling.sibling)

                if node1.type != node2.type:

                    self.error(relational_exp.child.sibling.line,
                               'Different type for two variables.')

                tempname = 'temp' + str(self.tempNum)

                self.tempNum += 1

                newnode = self.createTempVar(tempname, 'bool')

                self.blockStack[len(self.blockStack) -
                                1].varMap[tempname] = newnode

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                if op == '<' or op == '<=':
                    q.op = "lt"
                else:
                    q.op = "gt"
                q.SetArgName(1, node1)
                q.SetArgName(2, node2)
                q.result = tempname
                self.quadruplesList.append(q)

                q = Quadruples()
                newnode.bool_exp = q.GetNodeName(
                    node1) + " " + op + " " + q.GetNodeName(node2)

                return newnode

    def Parser_shift_expression(self, shift_exp):

        print("########")

        print(shift_exp.name)

        print(shift_exp.child.name)

        print("########")

        if shift_exp.child.name == 'addsub_expression':

            additive_exp = shift_exp.child

            return self.Parser_addsub_expression(additive_exp)

        elif shift_exp.child.sibling.name == 'LEFT_OP' or shift_exp.child.sibling.name == 'RIGHT_OP':

            if shift_exp.child.sibling.name == 'LEFT_OP':

                op = '<<'

            else:

                op = '>>'

            node1 = self.Parser_shift_expression(shift_exp.child)

            node2 = self.Parser_addsub_expression(shift_exp.child.sibling.sibling)

            if node1.type != 'int' or node2.type != 'int':

                self.error(shift_exp.child.sibling.line,
                           'Shift operation should only used to int.')

            tempname = 'temp' + str(self.tempNum)

            self.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) -
                            1].varMap[tempname] = newnode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            if op == '<<':
                q.op = "sll"
            else:
                q.op = "srl"
            q.SetArgName(1, node1)
            q.SetArgName(2, node2)
            q.result = tempname
            self.quadruplesList.append(q)

            return newnode


# TODO =======================================DIVIDE=======================================
    def Parser_addsub_expression(self, additive_exp):

        if additive_exp.child.name == "muldiv_expression":

            mult_exp = additive_exp.child

            return self.Parser_muldiv_expression(mult_exp)

        elif (additive_exp.child.sibling.name == "+" or additive_exp.child.sibling.name == "-"):

            node1 = self.Parser_addsub_expression(additive_exp.child)

            node2 = self.Parser_muldiv_expression(
                additive_exp.child.sibling.sibling)

            if node1.type != node2.type:

                self.error(additive_exp.child.sibling.line,
                           "Different type for two variables.")

            tempname = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[-1].varMap[tempname] = newnode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            if additive_exp.child.sibling.name == '+':
                q.op = "add"
            else:
                q.op = "sub"
            q.SetArgName(1, node1)
            q.SetArgName(2, node2)
            q.result = tempname
            self.quadruplesList.append(q)

            return newnode

    def Parser_muldiv_expression(self, mult_exp):

        if mult_exp.child.name == "monocular_expression":

            unary_exp = mult_exp.child

            return self.Parser_monocular_expression(unary_exp)

        elif (mult_exp.child.sibling.name == "*" or mult_exp.child.sibling.name == "/" or mult_exp.child.sibling.name == "%"):

            node1 = self.Parser_muldiv_expression(mult_exp.child)

            node2 = self.Parser_monocular_expression(mult_exp.child.sibling.sibling)

            if node1.type != node2.type:

                self.error(mult_exp.child.sibling.line,
                           "Different type for two variables.")

            tempname = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newNode = self.createTempVar(tempname, node1.type)

            self.blockStack[-1].varMap[tempname] = newNode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            if mult_exp.child.sibling.name == '*':
                q.op = "mul"
            elif mult_exp.child.sibling.name == '/':
                q.op = "div"
            else:
                q.op = "mod"
            q.SetArgName(1, node1)
            q.SetArgName(2, node2)
            q.result = tempname
            self.quadruplesList.append(q)

            return newNode

    def Parser_monocular_expression(self, unary_exp):

        if unary_exp.child.name == "postfix_expression":

            post_exp = unary_exp.child

            return self.Parser_postfix_expression(post_exp)

        elif unary_exp.child.name == "INC_OP":

            rnode = self.Parser_monocular_expression(unary_exp.child.sibling)

            if rnode.type != "int":

                self.error(unary_exp.child.sibling.line,
                           "++ operation can only use for int type.")

            tempname = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newNode = self.createTempVar(tempname, "int")

            self.blockStack[-1].varMap[tempname] = newNode

            q.Quadruples()
            q.num = linenum
            linenum += 1
            q.op = "asn"
            q.arg2 = tempname
            q.arg1 = "#1"
            self.quadruplesList.append(q)

            if rnode.use_addr:

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "add"
                q.arg1 = "*"+rnode.name
                q.arg2 = tempname
                q.result = "*"+rnode.name
                self.quadruplesList.append(q)

            else:

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "add"
                q.arg1 = q.GetNodeName(rnode)
                q.arg2 = tempname
                q.result = q.GetNodeName(rnode)
                self.quadruplesList.append(q)

            return rnode

        elif unary_exp.child.name == "DEC_OP":

            rnode = self.Parser_monocular_expression(unary_exp.child.sibling)

            if rnode.type != "int":

                self.error(unary_exp.child.sibling.line,
                           "-- operation can only use for int type.")

            tempname = "temp" + str(self.tempNum)

            self.tempNum

            newNode = self.createTempVar(tempname, "int")

            self.blockStack[-1].varMap[tempname] = newNode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "asn"
            q.arg1 = "#1"
            q.arg2 = tempname

            self.quadruplesList.append(q)

            if rnode.use_addr:

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "add"
                q.arg1 = "*"+rnode.name
                q.arg2 = tempname
                q.result = "*"+rnode.name
                self.quadruplesList.append(q)

            else:

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "sub"
                q.arg1 = q.GetNodeName(rnode)
                q.arg2 = tempname
                q.result = q.GetNodeName(rnode)
                self.quadruplesList.append(q)

            return rnode

        elif (unary_exp.child.name == "monocular_operator"):

            op = unary_exp.child.child.name

            rnode = self.Parser_monocular_expression(unary_exp.child.sibling)

            if op == "+":

                if (rnode.type != "int" and rnode.type != "double"):

                    self.error(unary_exp.child.child.line,
                               "operator '+' can only used to int or double")

                return rnode

            elif op == "-":

                if rnode.type != "int" and rnode.type != "double":

                    self.error(unary_exp.child.child.line,
                               "operator '-' can only used to int or double")

                tempzeroname = "temp" + str(self.tempNum)

                self.tempNum = self.tempNum + 1

                newzeronode = self.createTempVar(tempzeroname, rnode.type)

                self.blockStack[-1].varMap[tempzeroname] = newzeronode

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "asn"
                q.arg1 = "#0"
                q.arg2 = tempzeroname

                self.quadruplesList.append(q)

                tempname = "temp" + str(self.tempNum)

                self.tempNum = self.tempNum + 1

                newnode = self.createTempVar(tempname, rnode.type)

                self.blockStack[-1].varMap[tempname] = newnode

                if rnode.use_addr:

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "sub"
                    q.arg1 = tempzeroname
                    q.arg2 = "*" + rnode.name
                    q.result = tempname
                    self.quadruplesList.append(q)

                else:

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "sub"
                    q.arg1 = tempzeroname
                    q.arg2 = q.GetNodeName(rnode)
                    q.result = tempname
                    self.quadruplesList.append(q)

                return newnode

            elif op == "~":

                op = "~"

            elif op == "!":

                op = "!"

    def Parser_postfix_expression(self, post_exp):

        if post_exp.child.name == "basic_expression":

            primary_exp = post_exp.child

            return self.Parser_basic_expression(primary_exp)

        elif post_exp.child.sibling.name == "[":

            arrayName = post_exp.child.child.child.content

            expression = post_exp.child.sibling.sibling

            enode = self.Parser_expression(expression)

            anode = self.getArrayNode(arrayName)

            if anode.num < 0:

                self.error(post_exp.child.sibling.line,
                           "Undifined array " + arrayName)

            tempVar = varNode()

            tempName = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            tempVar.name = tempName

            tempVar.type = anode.type

            tempVar.use_addr = True

            self.blockStack[-1].varMap[tempName] = tempVar

            if anode.type == "int" or anode.type == "double":

                tempVar2 = varNode()

                tempName2 = "temp" + str(self.tempNum)

                self.tempNum = self.tempNum + 1

                tempVar2.name = tempName2

                tempVar2.type = "int"

                self.blockStack[-1].varMap[tempName2] = tempVar2

                if anode.type == "int":

                    tempVar3 = varNode()

                    tempName3 = "temp" + str(self.tempNum)

                    self.tempNum = self.tempNum + 1

                    tempVar3.name = tempName3

                    tempVar3.type = "int"

                    self.blockStack[-1].varMap[tempName3] = tempVar3

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "asn"
                    q.arg2 = tempName3
                    q.arg1 = "#4"
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "mul"
                    q.arg1 = q.GetNodeName(enode)
                    q.arg2 = tempName3
                    q.result = tempName2
                    self.quadruplesList.append(q)

                elif anode.type == "double":

                    tempVar3 = varNode()

                    tempName3 = "temp" + str(self.tempNum)

                    self.tempNum = self.tempNum + 1

                    tempVar3.name = tempName3

                    tempVar3.type = "int"

                    self.blockStack[-1].varMap[tempName3] = tempVar3

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "asn"
                    q.arg2 = tempName3
                    q.arg1 = "#8"
                    self.quadruplesList.append(q)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "mul"
                    q.arg1 = q.GetNodeName(enode)
                    q.arg2 = tempName3
                    q.result = tempName2
                    self.quadruplesList.append(q)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "add"
                q.arg1 = "&"+q.GetNodeName(anode)
                q.arg2 = q.GetNodeName(tempVar2)
                q.result = tempName
                self.quadruplesList.append(q)

                return tempVar

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "add"
            q.arg1 = "&"+q.GetNodeName(anode)
            q.arg2 = q.GetNodeName(enode)
            q.result = tempName
            self.quadruplesList.append(q)

            return tempVar

        elif (post_exp.child.sibling.name == "("):

            funcName = post_exp.child.child.child.content

            newNode = varNode()

            if (funcName not in self.funcPool):

                self.error(post_exp.child.child.child.line,
                           "Undefined function " + funcName)

            if (post_exp.child.sibling.sibling.name == "argument_expression_list"):

                argument_exp_list = post_exp.child.sibling.sibling

                self.Parser_argument_expression_list(
                    argument_exp_list, funcName)

            func = self.funcPool[funcName]

            if (func.re_type == "void"):

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "call"
                q.arg1 = funcName
                self.quadruplesList.append(q)

            else:

                tempname = "temp" + str(self.tempNum)

                self.tempNum = self.tempNum + 1

                newNode = self.createTempVar(
                    tempname, self.funcPool[funcName].re_type)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "call"
                q.arg1 = funcName
                q.arg2 = tempname
                self.quadruplesList.append(q)

            return newNode

        elif (post_exp.child.sibling.name == "INC_OP"):

            rnode = self.Parser_postfix_expression(post_exp.child)

            if (rnode.type != "int"):

                self.error(post_exp.child.sibling.line,
                           "++ operation can only use for int type.")

            tempname = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newnode = self.createTempVar(tempname, "int")

            self.blockStack[-1].varMap[tempname] = newnode

            tempnameone = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newNode = self.createTempVar(tempnameone, "int")

            self.blockStack[-1].varMap[tempnameone] = newNode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "asn"
            q.arg2 = tempnameone
            q.arg1 = "#1"
            self.quadruplesList.append(q)

            if (rnode.use_addr):

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "asn"
                q.arg2 = tempname
                q.arg1 = "*" + rnode.name
                self.quadruplesList.append(q)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "add"
                q.arg1 = "*" + rnode.name
                q.arg2 = tempnameone
                q.result = "*" + rnode.name
                self.quadruplesList.append(q)

            else:

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "asn"
                q.arg1 = q.GetNodeName(rnode)
                q.arg2 = tempname

                self.quadruplesList.append(q)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "add"
                q.arg1 = q.GetNodeName(rnode)
                q.arg2 = tempnameone
                q.result = q.GetNodeName(rnode)
                self.quadruplesList.append(q)

            return newnode

        elif (post_exp.child.sibling.name == "DEC_OP"):

            rnode = self.Parser_postfix_expression(post_exp.child)

            if (rnode.type != "int"):

                self.error(post_exp.child.sibling.line,
                           "-- operation can only use for int type.")

            tempname = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newnode = self.createTempVar(tempname, "int")

            self.blockStack[-1].varMap[tempname] = newnode

            tempnameone = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newNode = self.createTempVar(tempnameone, "int")

            self.blockStack[-1].varMap[tempnameone] = newNode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "asn"
            q.arg1 = "#1"
            q.arg2 = tempnameone
            self.quadruplesList.append(q)

            if (rnode.use_addr):

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "asn"
                q.arg2 = tempname
                q.arg1 = "*" + rnode.name
                self.quadruplesList.append(q)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "div"
                q.arg1 = "*" + rnode.name
                q.arg2 = tempnameone
                q.result = "*" + rnode.name
                self.quadruplesList.append(q)

            else:

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "asn"
                q.arg1 = q.GetNodeName(rnode)
                q.arg2 = tempname

                self.quadruplesList.append(q)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "div"
                q.arg1 = q.GetNodeName(rnode)
                q.arg2 = tempnameone
                q.result = q.GetNodeName(rnode)
                self.quadruplesList.append(q)

            return newnode

    def Parser_argument_expression_list(self, node, funcName):

        if node == None:

            return

        argu_exp_list = node.child

        func = self.funcPool[funcName]

        i = 0

        while (argu_exp_list.name == "argument_expression_list"):

            rnode = self.Parser_assignment_expression(
                argu_exp_list.sibling.sibling)

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "arg"
            q.SetArgName(1, rnode)
            self.quadruplesList.append(q)

            argu_exp_list = argu_exp_list.child

            i = i + 1

            if (func.para_list[len(func.para_list) - i].type != rnode.type):

                self.error(argu_exp_list.line,
                           "Wrong type arguments to function " + funcName)

        rnode = self.Parser_assignment_expression(argu_exp_list)

        q = Quadruples()
        q.num = self.linenum
        self.linenum += 1
        q.op = "arg"
        q.SetArgName(1, rnode)
        self.quadruplesList.append(q)

        i = i + 1

        if (func.para_list[len(func.para_list) - i].type != rnode.type):

            self.error(argu_exp_list.line,
                       "Wrong type arguments to function " + funcName)

        # if (i != len(func.para_list)) :

            #self.error(argu_exp_list.line, "The number of arguments doesn't equal to the function parameters number.")

    def Parser_basic_expression(self, primary_exp):

        if (primary_exp.child.name == "IDENTIFIER"):

            content = primary_exp.child.content

            rnode = self.lookupNode(content)

            if (rnode.num < 0):

                self.error(primary_exp.child.line,
                           "Undefined variable " + content)

            return rnode

        elif (primary_exp.child.name == "True" or primary_exp.child.name == "FALSE"):

            content = primary_exp.child.content

            tempname = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newNode = self.createTempVar(tempname, "bool")

            self.blockStack[-1].varMap.insert[tempname] = newNode

            if(primary_exp.child.name == "True"):

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "asn"
                q.arg2 = tempname
                q.arg1 = "#1"
                self.quadruplesList.append(q)

            else:

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "asn"
                q.arg2 = tempname
                q.arg1 = "#0"
                self.quadruplesList.append(q)

            return newNode

        elif (primary_exp.child.name == "CONSTANT_INT"):

            content = primary_exp.child.content

            tempname = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newNode = self.createTempVar(tempname, "int")

            self.blockStack[-1].varMap[tempname] = newNode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "asn"
            q.arg2 = tempname
            q.arg1 = "#"+content
            self.quadruplesList.append(q)

            return newNode

        elif (primary_exp.child.name == "CONSTANT_DOUBLE"):

            content = primary_exp.child.content

            tempname = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newNode = self.createTempVar(tempname, "double")

            self.blockStack[-1].varMap[tempname] = newNode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "asn"
            q.arg2 = tempname
            q.arg1 = "#F"+content
            self.quadruplesList.append(q)

            return newNode

        elif (primary_exp.child.name == "("):

            expression = primary_exp.child.sibling

            return self.Parser_expression(expression)

    def lookupVar(self, name):

        N = range(len(self.blockStack))

        for i in reversed(N):

            if (self.blockStack[i].varMap.has_key(name)):

                return self.blockStack[i].varMap[name].type

        return ""

    def lookupCurruntVar(self, name):

        if name in self.blockStack[-1].varMap:

            return True

        else:

            return False

    def lookupNode(self, name):

        N = range(len(self.blockStack))

        for i in reversed(N):

            if name in self.blockStack[i].varMap:

                return self.blockStack[i].varMap[name]

        temp = varNode()

        temp.num = -1

        return temp

    def getFuncRType(self):

        N = range(len(self.blockStack))

        for i in reversed(N):

            if (self.blockStack[i].is_func):

                return self.blockStack[i].func.re_type

        return ""

    def getArrayType(self, name):

        N = range(len(self.blockStack))

        for i in reversed(N):

            if (self.blockStack[i].arrayMap.has_key(name)):

                return self.blockStack[i].arrayMap[name].type

        return ""

    def getArrayNode(self, name):

        N = range(len(self.blockStack))

        for i in reversed(N):

            if (self.blockStack[i].arrayMap.has_key(name)):

                return self.blockStack[i].arrayMap[name]

        temp = arrayNode()

        temp.num = -1

        return temp

    def getBreakBlockNumber(self):

        N = range(len(self.blockStack))

        for i in reversed(N):

            if (self.blockStack[i].can_bk):

                return i

        return -1

    def error(self, line, errorstring):

        # self.print_code()

        print("self.error! line ", line)

        print(errorstring)

        exit(1)

    def createTempVar(self, name, type):

        var = varNode()

        var.name = name

        var.type = type

        var.num = -1

        return var

    def print_map(self):

        N = range(len(self.blockStack))

        for i in reversed(N):

            print("Block ", i)

            for key, value in self.blockStack[i].varMap.items():

                print("     ", key, " ", value.type)


