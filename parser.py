#! /usr/bin/python
# coding=utf-8
import os

from block import varNode

from block import funcNode

from block import arrayNode

from block import Block

from innerCode import InnerCode



class Praser:

    funcPool = None

    blockStack = None

    innerCode = None

    root = None



    def __init__(self, root):

        self.funcPool = {}

        self.blockStack = []

        self.innerCode = InnerCode()

        self.root = root

        self.praserInit()

        self.innerCode.printCode()
    

    def praserInit(self):

        wholeBlock = Block()

        self.blockStack.append(wholeBlock)



        writeNode = funcNode()

        writeNode.name = "print"

        writeNode.rtype = "void"

        pnode = varNode()

        pnode.type = "int"

        writeNode.paralist.append(pnode)



        self.funcPool["print"] = writeNode



        readNode = funcNode()

        readNode.name = "read"

        readNode.rtype = "int"

        self.funcPool["read"] = readNode



        self.praserGramTree(self.root)



    def praserGramTree(self, node):

        if node == None or node.line == -1:

            return

        if node.name == "declaration":

            node = self.praser_declaration(node)

        elif node.name == "function_definition":

            node = self.praser_function_definition(node)

        elif node.name == "statement":

            node = self.praser_statement(node)



        if node is not None:

            self.praserGramTree(node.left)

            self.praserGramTree(node.right)



    def praser_statement(self, node):
        
        if node==None:
            return

        temp = node.left

        if node.left.name == "labeled_statement":
            node.left.name = "labeled_statement"
            
        if node.left.name == "compound_statement":

            self.praser_compound_statement(node.left)

        if node.left.name == "expression_statement":

            self.praser_expression_statement(node.left)

        if node.left.name == "selection_statement":

            self.praser_selection_statement(node.left)

        if node.left.name == "iteration_statement":

            self.praser_iteration_statement(node.left)

        if node.left.name == "jump_statement":

            self.praser_jump_statement(node.left)

        

        return node.right



    def praser_jump_statement(self, node):
    
        if node==None:
            return

        if node.left.name == "GOTO":
            node.left.name = "GOTO"

        elif node.left.name == "CONTINUE":
            node.left.name == "CONTINUE"
            
        elif node.left.name == "BREAK":

            num = self.getBreakBlockNumber()

            if num < 0:

                self.error(node.left.line, "This scope doesn't support break.")

            

            self.innerCode.addCode("GOTO " + self.blockStack[num].breakLabelname)

        elif node.left.name == "RETURN":

            funcType = self.getFuncRType()

            if node.left.right.name == "expression":

                rnode = self.praser_expression(node.left.right)

                self.innerCode.addCode(self.innerCode.createCodeforReturn(rnode)) 

                if rnode.type != funcType:

                    self.error(node.left.right.line, "return type doesn't equal to function return type.")

            elif node.left.right.name == ";":

                self.innerCode.addCode("RETURN")

                if funcType != "void":

                    self.error(node.left.right.line, "You should return " + self.blockStack[-1].func.rtype)



    def praser_expression_statement(self, node):
        if node==None:
            return
        if node.left.name == "expression":

            self.praser_expression(node.left)



    def praser_expression(self, node):
        if node==None:
            return
        if node.left.name == "expression":

            return self.praser_expression(node.left)

        elif node.left.name == "assignment_expression":

            return self.praser_assignment_expression(node.left)

        

        if node.right.name == ",":

            return self.praser_assignment_expression(node.right.right)



    def praser_compound_statement(self, node):
        if node==None:
            return
        self.praserGramTree(node)



    def praser_selection_statement(self, node):
        if node==None:
            return
        if node.left.name == "IF":

            if node.left.right.right.right.right.right==None:

                newblock = Block()

                self.blockStack.append(newblock)



                expression = node.left.right.right

                exp_rnode = self.praser_expression(expression)

                statement = node.left.right.right.right.right



                label1 = self.innerCode.getLabelName()

                label2 = self.innerCode.getLabelName()



                if exp_rnode.type == "bool":

                    self.innerCode.addCode("IF " + exp_rnode.boolString + " GOTO " + label1)

                else:

                    tempzeroname = "temp" + str(self.innerCode.tempNum)

                    self.innerCode.tempNum = self.innerCode.tempNum + 1

                    newznode = self.createTempVar(tempzeroname, "int")

                    self.innerCode.addCode(tempzeroname + " := #0")

                    self.innerCode.addCode("IF " + self.innerCode.getNodeName(exp_rnode) + " != " + tempzeroname + " GOTO " + label1)

                

                self.innerCode.addCode("GOTO " + label2)

                self.innerCode.addCode("LABEL " + label1 + " :")



                self.statement

                self.innerCode.addCode("LABEL " + label2 + " :")

                self.blockStack.pop()

            elif node.left.right.right.right.right.right.name == "ELSE":

                newblock1 = Block()

                self.blockStack.append(newblock1)

                expression = node.left.right.right

                exp_rnode = self.praser_expression(expression)

                statement1 = node.left.right.right.right.right

                statement2 = node.left.right.right.right.right.right.right



                label1 = self.innerCode.getLabelName()

                label2 = self.innerCode.getLabelName()

                label3 = self.innerCode.getLabelName()



                if exp_rnode.type == "bool":

                    self.innerCode.addCode("IF " + exp_rnode.boolString + " GOTO " + label1)

                else:

                    tempzeroname = "temp" + str(self.innerCode.tempNum)

                    self.innerCode.tempNum = self.innerCode.tempNum + 1

                    newznode = self.createTempVar(tempzeroname, "int")

                    self.innerCode.addCode(tempzeroname + " := #0")

                    self.innerCode.addCode("IF " + self.innerCode.getNodeName(exp_rnode) + " != " + tempzeroname + " GOTO " + label1)



                self.innerCode.addCode("GOTO " + label2)

                self.innerCode.addCode("LABEL " + label1 + " :")



                self.statement1

                self.innerCode.addCode("GOTO " + label3)

                self.blockStack.pop()

                self.innerCode.addCode("LABEL " + label2 + " :")

                newblock2 = Block()

                self.blockStack.append(newblock2)

                self.statement2

                self.innerCode.addCode("LABEL " + label3 + " :")

                self.blockStack.pop()



        #elif node.left.name == "SWITCH":

    

    def praser_iteration_statement(self, node):
        if node==None:
            return
        if node.left.name == "WHILE":

            newblock = Block()

            newblock.canBreak = True

            self.blockStack.append(newblock)



            expression = node.left.right.right

            statement = node.left.right.right.right.right



            label1 = self.innerCode.getLabelName()

            label2 = self.innerCode.getLabelName()

            label3 = self.innerCode.getLabelName()



            self.blockStack[-1].breakLabelname = label3

            self.innerCode.addCode("LABEL " + label1 + " :")

            var = self.praser_expression(expression)

            

            if var.type == "bool":

                self.innerCode.addCode("IF " + var.boolString + " GOTO " + label2)

            else:

                tempzeroname = "temp" + str(self.innerCode.tempNum)

                self.innerCode.tempNum = self.innerCode.tempNum + 1

                newznode = self.createTempVar(tempzeroname, "int")

                self.innerCode.addCode(tempzeroname + " := #0")

                

                self.innerCode.addCode("IF " + self.innerCode.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2)



            self.innerCode.addCode("GOTO " + label3)

            self.innerCode.addCode("LABEL " + label2 + " :")

            self.praser_statement(statement)

            self.innerCode.addCode("GOTO " + label1)

            self.innerCode.addCode("LABEL " + label3 + " :")

            self.blockStack.pop()

        elif node.left.name == "DO":

            newblock = Block()

            newblock.canBreak = True

            self.blockStack.append(newblock)



            expression = node.left.right

            statement = node.left.right.right.right.right



            label1 = self.innerCode.getLabelName()

            label2 = self.innerCode.getLabelName()



            self.blockStack[-1].breakLabelname = label2

            self.innerCode.addCode("LABEL " + label1 + " :")

            self.statement

            

            var = self.praser_expression(expression)

            

            if var.type == "bool":

                self.innerCode.addCode("IF " + var.boolString + " GOTO " + label1)

            else:

                tempzeroname = "temp" + str(self.innerCode.tempNum)

                self.innerCode.tempNum = self.innerCode.tempNum + 1

                newznode = self.createTempVar(tempzeroname, "int")

                self.innerCode.addCode(tempzeroname + " := #0")

                

                self.innerCode.addCode("IF " + self.innerCode.getNodeName(var) + " != " + tempzeroname + " GOTO " + label1)



            self.innerCode.addCode("LABEL " + label2 + " :")

            self.blockStack.pop()

        elif node.left.name == "FOR":

            if node.left.right.right.name == "expression_statement":

                if node.left.right.right.right.right.name == ")":

                    newblock = Block()

                    newblock.canBreak = True

                    self.blockStack.append(newblock)



                    exp_state1 = node.left.right.right

                    exp_state2 = exp_state1.right

                    statement = exp_state2.right.right



                    label1 = self.innerCode.getLabelName()

                    label2 = self.innerCode.getLabelName()

                    label3 = self.innerCode.getLabelName()



                    self.blockStack[-1].breakLabelname = label3



                    if exp_state1.left.name == "expression":

                        self.praser_expression(exp_state1.left)

                    self.innerCode.addCode("LABEL " + label1 + " :")



                    if exp_state2.left.name == "expression":

                        var = self.praser_expression(exp_state2.left)

                        if var.type == "bool":

                            self.innerCode.addCode("IF " + var.boolString + " GOTO " + label2)

                        else:

                            tempzeroname = "temp" + str(self.innerCode.tempNum)

                            self.innerCode.tempNum = self.innerCode.tempNum + 1

                            newznode = self.createTempVar(tempzeroname, "int")

                            self.innerCode.addCode(tempzeroname + " := #0")

                            self.innerCode.addCode("IF " + self.innerCode.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2)

                    else:

                        self.innerCode.addCode("GOTO " + label2)

                    

                    self.innerCode.addCode("GOTO " + label3)

                    self.innerCode.addCode("LABEL " + label2 + " :")

                    self.praser_statement(statement)

                    self.innerCode.addCode("GOTO " + label1)

                    self.innerCode.addCode("LABEL " + label3 + " :")

                    self.blockStack.pop()

                elif node.left.right.right.right.right.name == "expression":

                    newblock = Block()

                    newblock.canBreak = True

                    self.blockStack.append(newblock)



                    exp_state1 = node.left.right.right

                    exp_state2 = exp_state1.right

                    exp = exp_state2.right

                    statement = exp.right.right



                    label1 = self.innerCode.getLabelName()

                    label2 = self.innerCode.getLabelName()

                    label3 = self.innerCode.getLabelName()



                    self.blockStack[-1].breakLabelname = label3



                    if exp_state1.left.name == "expression":

                        self.praser_expression(exp_state1.left)

                    self.innerCode.addCode("LABEL " + label1 + " :")



                    if exp_state2.left.name == "expression":

                        var = self.praser_expression(exp_state2.left)

                        if var.type == "bool":

                            self.innerCode.addCode("IF " + var.boolString + " GOTO " + label2)

                        else:

                            tempzeroname = "temp" + str(self.innerCode.tempNum)

                            self.innerCode.tempNum = self.innerCode.tempNum + 1

                            newznode = self.createTempVar(tempzeroname, "int")

                            self.innerCode.addCode(tempzeroname + " := #0")

                            self.innerCode.addCode("IF " + self.innerCode.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2)

                    else:

                        self.innerCode.addCode("GOTO " + label2)

                    

                    self.innerCode.addCode("GOTO " + label3)

                    self.innerCode.addCode("LABEL " + label2 + " :")

                    self.praser_statement(statement)

                    self.innerCode.addCode("GOTO " + label1)

                    self.innerCode.addCode("LABEL " + label3 + " :")

                    self.blockStack.pop()



            if node.left.right.right.name == "declaration":

                if node.left.right.right.right.right.name == ")":

                    newblock = Block()

                    newblock.canBreak = True

                    self.blockStack.append(newblock)



                    declaration = node.left.right.right

                    expression_statement = declaration.right

                    statement = expression_statement.right.right



                    label1 = self.innerCode.getLabelName()

                    label2 = self.innerCode.getLabelName()

                    label3 = self.innerCode.getLabelName()



                    self.blockStack[-1].breakLabelname = label3



                    self.praser_declaration(declaration)

                    self.innerCode.addCode("LABEL " + label1 + " :")



                    if expression_statement.left.name == "expression":

                        var = self.praser_expression(expression_statement.left)

                        if var.type == "bool":

                            self.innerCode.addCode("IF " + var.boolString + " GOTO " + label2)

                        else:

                            tempzeroname = "temp" + str(self.innerCode.tempNum)

                            self.innerCode.tempNum = self.innerCode.tempNum + 1

                            newznode = self.createTempVar(tempzeroname, "int")

                            self.innerCode.addCode(tempzeroname + " := #0")

                            self.innerCode.addCode("IF " + self.innerCode.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2)

                    else:

                        self.innerCode.addCode("GOTO " + label2)

                    

                    self.innerCode.addCode("GOTO " + label3)

                    self.innerCode.addCode("LABEL " + label2 + " :")

                    self.praser_statement(statement)

                    self.innerCode.addCode("GOTO " + label1)

                    self.innerCode.addCode("LABEL " + label3 + " :")

                    self.blockStack.pop()

                elif node.left.right.right.right.right.name == "expression":

                    newblock = Block()

                    newblock.canBreak = True

                    self.blockStack.append(newblock)



                    declaration = node.left.right.right

                    expression_statement = declaration.right

                    expression = expression_statement.right

                    statement = expression.right.right



                    label1 = self.innerCode.getLabelName()

                    label2 = self.innerCode.getLabelName()

                    label3 = self.innerCode.getLabelName()



                    self.blockStack[-1].breakLabelname = label3



                    self.praser_declaration(declaration)

                    self.innerCode.addCode("LABEL " + label1 + " :")



                    if expression_statement.left.name == "expression":

                        var = self.praser_expression(expression_statement.left)

                        if var.type == "bool":

                            self.innerCode.addCode("IF " + var.boolString + " GOTO " + label2)

                        else:

                            tempzeroname = "temp" + str(self.innerCode.tempNum)

                            self.innerCode.tempNum = self.innerCode.tempNum + 1

                            newznode = self.createTempVar(tempzeroname, "int")

                            self.innerCode.addCode(tempzeroname + " := #0")

                            self.innerCode.addCode("IF " + self.innerCode.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2)

                    else:

                        self.innerCode.addCode("GOTO " + label2)

                    

                    self.innerCode.addCode("GOTO " + label3)

                    self.innerCode.addCode("LABEL " + label2 + " :")

                    self.praser_statement(statement)

                    self.praser_expression(expression)

                    self.innerCode.addCode("GOTO " + label1)

                    self.innerCode.addCode("LABEL " + label3 + " :")

                    self.blockStack.pop()



    def praser_function_definition(self, node):
        if node==None:
            return
            
        type_specifier = node.left

        declarator = node.left.right

        compound_statement = declarator.right



        funcType = type_specifier.left.content

        funcName = declarator.left.left.content



        isdeclared = False

        if funcName in self.funcPool.keys():

            if self.funcPool[funcName].isdefinied:

                self.error(declarator.left.left.line, "Function " + funcName + " is duplicated definition.")

            else:

                isdeclared = True

                declarFunc = self.funcPool[funcName]

                self.funcPool.pop(funcName)

        

        funBlock = Block()

        funBlock.isfunc = True

        funBlock.func.name = funcName

        funBlock.func.rtype = funcType

        funBlock.func.isdefinied = True



        self.blockStack.append(funBlock)

        self.funcPool[funcName] = funBlock.func

        self.innerCode.addCode("FUNCTION " + funcName + " :")



        if declarator.left.right.right.name == "parameter_list":

            self.praser_parameter_list(declarator.left.right.right, funcName, True)

        

        func = self.funcPool[funcName]

        if isdeclared:

            if func.rtype != declarFunc.rtype:

                self.error(type_specifier.left.line, "Function return type doesn't equal to the function declared before.")

            print(funBlock.func.paralist.size())

            if func.paralist.size() != declarFunc.paralist.size():

                self.error(declarator.left.right.right.line, "The number of function parameters doesn't equal to the function declared before.")

            for i in range (len((funBlock.func.paralist))):

                if func.paralist[i].type != declarFunc.paralist[i].type:

                    self.error(declarator.left.right.right.line, "The parameter " + funBlock.func.paralist[i].name + "'s type doesn't equal to the function declared before.")

                

        funBlock.func = func

        self.praser_compound_statement(compound_statement)

        self.blockStack.pop()

        return node.right



    def praser_parameter_list(self, node, funcName, definite):
        if node==None:
            return
        if node.left.name == "parameter_list":

            self.praser_parameter_list(node.left, funcName, definite)

        elif node.left.name == "parameter_declaration":

            self.praser_parameter_declaration(node.left, funcName, definite)

        

        if node.right.name == ",":

            self.praser_parameter_declaration(node.right.right, funcName, definite)

        

    def praser_parameter_declaration(self, node, funcName, definite):
        if node==None:
            return
        type_specifier = node.left

        declarator = node.left.right

        typeName = type_specifier.left.content

        if typeName == "void":

            self.error(type_specifier.line, "Void can't definite parameter.")

        

        varName = declarator.left.content

        newnode = varNode()

        newnode.name = varName

        newnode.type = typeName



        if definite:

            newnode.num = self.innerCode.varNum = newnode.num = self.innerCode.varNum + 1

            self.blockStack[-1].func.paralist.append(newnode)

        

        self.funcPool[funcName].paralist.append(newnode)

        self.blockStack[-1].varMap[varName] = newnode



        if definite:

            self.innerCode.addCode(self.innerCode.createCodeforParameter(newnode))

    

    def praser_declaration(self, node):
        if node==None:
            return
        begin = node.left

        if begin.right.name == ";":

            return node.right

        vartype = begin.left.content

        if vartype == "void":

            self.error(begin.left.line, "void type can't assign to variable")

        

        decl = begin.right

        self.praser_init_declarator_list(vartype, decl)

        return node.right



# TODO =======================================DIVIDE=======================================

    def praser_init_declarator_list(self, vartype, node):
        if node==None:
            return
        if node.left.name == 'init_declarator_list':

            self.praser_init_declarator_list(vartype, node.left)

        elif node.left.name == 'init_declarator':

            self.praser_init_declarator(vartype, node.left)



        if node.right.name == ',':

            self.praser_init_declarator(vartype, node.right.right)



    def praser_init_declarator(self, vartype, node):
        if node==None:
            return
        declarator = node.left

        if declarator.right == 0:

            if declarator.left.name == 'IDENTIFIER':

                id = declarator.left

                var = id.content

                if self.lookupCurruntVar(var) == 0:

                    newvar = varNode()

                    newvar.name = var

                    newvar.type = vartype

                    newvar.num = self.innerCode.varNum

                    self.innerCode.varNum += 1

                    self.blockStack[len(self.blockStack) - 1].varmap[var] = newvar  # not sure

                else:

                    self.error(declarator.left.line, 'Variable multiple declaration')

            else:

                if declarator.left.right.name == '(':

                    funcName = declarator.left.left.content

                    funcType = vartype

                    if self.blockStack.size() > 1:

                        self.error(declarator.left.right.line, 'Function declaration must at global environment.')

                    parament_list = declarator.left.right.right

                    newFunc = funcNode()

                    newFunc.isdefined = False

                    newFunc.name = funcName

                    newFunc.type = funcType

                    self.funcPool.append({funcName, newFunc})



                    

                    self.praser_parameter_list(parament_list, funcName, False)



                elif declarator.left.right.name == '[':

                    arrayName = declarator.left.left.content

                    arrayType = vartype

                    assign_exp = declarator.left.right.right

                    rnode = self.praser_assignment_expression(assign_exp)

                    if rnode.type != 'int':

                        self.error(declarator.left.right.line, "Array size must be int.")



                    tnode = varNode()

                    if arrayType == 'int':

                      

                        tempname = "temp" + str(self.innerCode.tempNum)

                        self.innerCode.tempNum += 1

                        tnode = self.createTempVar(tempname, 'int')

                        self.blockStack[len(self.blockStack) - 1].varmap[tempname] = tnode



                        tempVar3 = varNode()

                        tempName3 = 'temp' + str(self.innerCode.tempNum)

                        tempVar3.name = tempName3

                        tempVar3.type = 'int'

                        self.blockStack[len(self.blockStack) - 1].varmap[tempName3] = tempVar3  # not sure

                        self.innerCode.addCode(tempName3 + ' := #4')

                        self.innerCode.addCode(tnode.name + ' := ' + tempName3 + ' * ' + rnode.name)



                    elif arrayType == 'double':

                        

                        tempname = "temp" + str(self.innerCode.tempNum)

                        self.innerCode.tempNum += 1

                        tnode = self.createTempVar(tempname, 'int')

                        self.blockStack[len(self.blockStack) - 1].varmap[tempname] = tnode



                        tempVar3 = varNode()

                        tempName3 = 'temp' + str(self.innerCode.tempNum)

                        tempVar3.name = tempName3

                        tempVar3.type = 'int'

                        self.blockStack[len(self.blockStack) - 1].varmap[tempName3] = tempVar3  # not sure

                        self.innerCode.addCode(tempName3 + ' := #8')

                        self.innerCode.addCode(tnode.name + ' := ' + tempName3 + ' * ' + rnode.name)



                    elif arrayType == 'bool':

                        tnode = rnode



                    anode = arrayNode()  # ?

                    anode.name = arrayName

                    anode.type = arrayType

                    anode.num = self.innerCode.arrayNum

                    self.innerCode.arrayNum += 1

                    self.innerCode.addCode('DEC' + self.innerCode.getarrayNodeName(anode) + ' ' + tnode.name)



                    self.blockStack[len(self.blockStack) - 1].varmap[arrayName] = anode



        elif declarator.right.name == '=':

            newvar = varNode()

            if declarator.left.name == 'IDEMTIFIER':

                id = declarator.left

                var = id.content

                if self.lookupCurruntVar(var) == 0:

                    newvar.name = var

                    newvar.type = vartype

                    newvar.num = self.innerCode.varNum

                    self.innerCode.varNum += 1

                    self.blockStack[len(self.blockStack) - 1].varmap[var] = newvar # not sure

                else:

                    self.error(declarator.left.line, 'Variable multiple declaration')



                initializer = declarator.right.right

                if initializer==None:

                    self.error(declarator.line, 'Lack the initializer for variable')

                else:

                    if initializer.left.name == 'assignment_expression':

                        rnode = self.praser_assignment_expression(initializer.left)

                        self.innerCode.addCode(self.innerCode.createCodeforAssign(newvar, rnode))

                        rtype = rnode.type

                        if rtype != vartype:

                            self.error(initializer.left.line, 'Wrong type to variable ' + declarator.left.content + ": " + rtype + ' to ' + vartype)

        else:

            self.error(declarator.right.line, "Wrong value to variable")



    def praser_assignment_expression(self, assign_exp):
        
        if assign_exp.left.name == 'logical_or_expression':

            logical_or_exp = assign_exp.left

            return self.praser_logical_or_expression(logical_or_exp)

        elif assign_exp.left.name == "unary_expression":

            unary_exp = assign_exp.left

            op = assign_exp.left.right.left.name

            next_assign_exp = assign_exp.left.right.right

            node1 = self.praser_unary_expression(unary_exp)

            node2 = self.praser_assignment_expression(next_assign_exp)

            if op == '=':

                node3 = node2

            else:

                tempname = 'temp' + str(self.innerCode.tempNum)

                self.innerCode.tempNum += 1

                node3 = self.createTempVar(tempname, node1.type)



                self.blockStack[len(self.blockStack) - 1].varmap[tempname] = node3



                if op == 'MUL_ASSIGN':

                    if node1.type != node2.type:

                        self.error(assign_exp.left.line, "Different type for two variables.")

                    self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '*', node1, node2))

                elif op == 'DIV_ASSIGN':

                    if node1.type != node2.type:

                        self.error(assign_exp.left.line, "Different type for two variables.")

                    self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '/', node1, node2))

                elif op == 'MOD_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.left.line, "The two variables must be int.")

                    self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '%', node1, node2))

                elif op == 'ADD_ASSIGN':

                    if node1.type != node2.type:

                        self.error(assign_exp.left.line, "Different type for two variables.")

                    self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '+', node1, node2))

                elif op == 'SUB_ASSIGN':

                    if node1.type != node2.type:

                        self.error(assign_exp.left.line, "Different type for two variables.")

                    self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '-', node1, node2))

                elif op == 'LEFT_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.left.line, "The two variables must be int.")

                    self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '<<', node1, node2))

                elif op == 'RIGHT_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.left.line, "The two variables must be int.")

                    self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '>>', node1, node2))

                elif op == 'AND_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.left.line, "The two variables must be int.")

                    self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '&', node1, node2))

                elif op == 'XOR_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.left.line, "The two variables must be int.")

                    self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '^', node1, node2))

                elif op == 'OR_ASSIGN':

                    if node1.type != 'int' or node2.type != 'int':

                        self.error(assign_exp.left.line, "The two variables must be int.")

                    self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '|', node1, node2))

            self.innerCode.addCode(self.innerCode.createCodeforVar(node1, node3))

            return node1



    def praser_logical_or_expression(self, logical_or_exp):
 
        if logical_or_exp.left.name == 'logical_and_expression':

            logical_and_exp = logical_or_exp.left

            return self.praser_logical_and_expression(logical_and_exp)

        elif logical_or_exp.left.name == 'logical_or_expression':

            node1 = self.praser_logical_or_expression(logical_or_exp.left)

            node2 = self.praser_logical_and_expression(logical_or_exp.left.right.right)



            if node1.type != 'bool' or node2 != 'bool':

                self.error(logical_or_exp.left.right.line, 'Logical Or operation should only used to bool.')



            tempname = 'temp' + str(self.innerCode.tempNum)

            self.innerCode.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) - 1].varmap[tempname] = newnode

            self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '||', node1, node2))

            newnode.boolString = self.innerCode.getNodeName(node1) + ' || ' + self.innerCode.getNodeName(node2)

            return newnode



    def praser_logical_and_expression(self, logical_and_exp):
       
        if logical_and_exp.left.name == 'inclusive_or_expression':

            inclusive_or_exp = logical_and_exp.left

            return self.praser_inclusive_or_expression(inclusive_or_exp)

        elif logical_and_exp.left.name == 'logical_amd_expression':

            node1 = self.praser_logical_and_expression(logical_and_exp.left)

            node2 = self.praser_inclusive_or_expression(logical_and_exp.left.right.right)



            if node1.type != 'bool' or node2 != 'bool':

                self.error(logical_and_exp.left.right.line, 'Logical And operation should only used to bool.')



            tempname = 'temp' + str(self.innerCode.tempNum)

            self.innerCode.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) - 1].varmap[tempname] = newnode

            self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '&&', node1, node2))

            newnode.boolString = self.innerCode.getNodeName(node1) + ' && ' + self.innerCode.getNodeName(node2)

            return newnode



    def praser_inclusive_or_expression(self, inclusive_or_exp):
       
        if inclusive_or_exp.left.name == 'exclusive_or_expression':

            exclusive_or_exp = inclusive_or_exp.left

            return self.praser_exclusive_or_expression(exclusive_or_exp)

        elif inclusive_or_exp.left.name == 'inclusive_or_expression':

            node1 = self.praser_inclusive_or_expression(inclusive_or_exp.left)

            node2 = self.praser_exclusive_or_expression(inclusive_or_exp.left.right.right)



            if node1.type != 'int' or node2 != 'int':

                self.error(inclusive_or_exp.left.right.line, 'Inclusive Or operation should only used to bool.')



            tempname = 'temp' + str(self.innerCode.tempNum)

            self.innerCode.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) - 1].varmap[tempname] = newnode

            self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '|', node1, node2))

            return newnode



    def praser_exclusive_or_expression(self, exclusive_or_exp):
       
        if exclusive_or_exp.left.name == 'and_expression':

            and_exp = exclusive_or_exp.left

            return self.praser_and_expression(and_exp)

        elif exclusive_or_exp.left.name == 'exclusive_or_expression':

            node1 = self.praser_exclusive_or_expression(exclusive_or_exp.left)

            node2 = self.praser_and_expression(exclusive_or_exp.left.right.right)



            if node1.type != 'int' or node2 != 'int':

                self.error(exclusive_or_exp.left.right.line, 'Exclusive Or operation should only used to bool.')



            tempname = 'temp' + str(self.innerCode.tempNum)

            self.innerCode.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) - 1].varmap[tempname] = newnode

            self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '^', node1, node2))

            return newnode



    def praser_and_expression(self, and_exp):
        
        if and_exp.left.name == 'equality_expression':

            equality_exp = and_exp.left

            return self.praser_equality_expression(equality_exp)

        elif and_exp.left.name == 'and_expression':

            node1 = self.praser_and_expression(and_exp.left)

            node2 = self.praser_equality_expression(and_exp.left.right.right)



            if node1.type != 'int' or node2 != 'int':

                self.error(and_exp.left.right.line, 'And operation should only used to bool.')



            tempname = 'temp' + str(self.innerCode.tempNum)

            self.innerCode.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) - 1].varmap[tempname] = newnode

            self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, '&', node1, node2))

            return newnode



    def praser_equality_expression(self, equality_exp):
    
        print("########")
        print(equality_exp.name)
        print(equality_exp.left.name)
        print("########")
        
        if equality_exp.left.name == 'equality_expression':

            relational_exp = equality_exp.left

            return self.praser_relational_expression(relational_exp)

        elif equality_exp.left.right.name == 'EQ_OP' or equality_exp.left.right.name == 'NE_OP':

            if equality_exp.left.right.name == 'EQ_OP':

                op = '=='

            else:

                op = '!='



            node1 = self.praser_equality_expression(equality_exp.left)

            node2 = self.praser_relational_expression(equality_exp.left.right.right)



            if node1.type != node2.type:

                self.error(equality_exp.left.right.line, 'Different type for two variables.')



            tempname = 'temp' + str(self.innerCode.tempNum)

            self.innerCode.tempNum += 1

            newnode = self.createTempVar(tempname, 'bool')

            self.blockStack[len(self.blockStack) - 1].varmap[tempname] = newnode

            self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, op, node1, node2))



            newnode.boolString = self.innerCode.getNodeName(node1) + " " + op + " " + self.innerCode.getNodeName(node2)

            return newnode



    def praser_relational_expression(self, relational_exp):
        
        if relational_exp.left.name == 'equality_expression':

            shift_exp = relational_exp.left

            return self.praser_shift_expression(relational_exp)

        else:

            op = relational_exp.left.right.name

            if op == 'LE_OP':

                op = '<='

            elif op == 'GE_OP':

                op = '>='



            if op == '>' or op == '<' or op == '>=' or op == '<=':

                node1 = self.praser_relational_expression(relational_exp.left)

                node2 = self.praser_shift_expression(relational_exp.left.right.right)



                if node1.type != node2.type:

                    self.error(relational_exp.left.right.line, 'Different type for two variables.')



                tempname = 'temp' + str(self.innerCode.tempNum)

                self.innerCode.tempNum += 1

                newnode = self.createTempVar(tempname, 'bool')

                self.blockStack[len(self.blockStack) - 1].varmap[tempname] = newnode

                self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, op, node1, node2))



                newnode.boolString = self.innerCode.getNodeName(node1) + " " + op + " " + self.innerCode.getNodeName(node2)

                return newnode



    def praser_shift_expression(self, shift_exp):
        
        if shift_exp.left.name == 'additive_expression':

            additive_exp = shift_exp.left

            return self.praser_additive_expression(additive_exp)

        elif shift_exp.left.right.name == 'LEFT_OP' or shift_exp.left.right.name == 'RIGHT_OP':

            if shift_exp.left.right.name == 'LEFT_OP':

                op = '<<'

            else:

                op = '>>'



            node1 = self.praser_shift_expression(shift_exp.left)

            node2 = self.praser_additive_expression(shift_exp.left.right.right)



            if node1.type != 'int' or node2.type != 'int':

                self.error(shift_exp.left.right.line, 'Shift operation should only used to int.')



            tempname = 'temp' + str(self.innerCode.tempNum)

            self.innerCode.tempNum += 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[len(self.blockStack) - 1].varmap[tempname] = newnode

            self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, op, node1, node2))

            return newnode

# TODO =======================================DIVIDE=======================================

    def praser_additive_expression(self, additive_exp):
       
        if additive_exp.left.name == "multiplicative_expression":

            mult_exp = additive_exp.left

            return self.praser_multiplicative_expression(mult_exp)

        

        elif (additive_exp.left.right.name == "+" or additive_exp.left.right.name == "-") :

            node1 = self.praser_additive_expression(additive_exp.left)

            node2 = self.praser_multiplicative_expression(additive_exp.left.right.right)



            if node1.type != node2.type:

                self.error(additive_exp.left.right.line, "Different type for two variables.")



            tempname = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum = self.innerCode.tempNum + 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[-1].varMap[tempname] = newnode



            self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, additive_exp.left.right.name, node1, node2))

            return newnode



    def praser_multiplicative_expression(self, mult_exp):
       
        if mult_exp.left.name == "unary_expression":

            unary_exp = mult_exp.left

            return self.praser_unary_expression(unary_exp)

        

        elif (mult_exp.left.right.name == "*" or mult_exp.left.right.name == "/" or mult_exp.left.right.name == "%"):

            node1 = self.praser_multiplicative_expression(mult_exp.left)

            node2 = self.praser_unary_expression(mult_exp.left.right.right)



            if node1.type != node2.type:

                self.error(mult_exp.left.right.line, "Different type for two variables.")



            tempname = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum = self.innerCode.tempNum + 1

            newNode = self.createTempVar(tempname, node1.type)

            self.blockStack[-1].varMap[tempname] = newNode



            self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, mult_exp.left.right.name, node1, node2))

            return newNode



    def praser_unary_expression(self, unary_exp) :
        
        if unary_exp.left.name == "postfix_expression":

            post_exp = unary_exp.left

            return self.praser_postfix_expression(post_exp)

        

        elif unary_exp.left.name == "INC_OP":

            rnode = self.praser_unary_expression(unary_exp.left.right)

            if rnode.type != "int":

                self.error(unary_exp.left.right.line, "++ operation can only use for int type.")



            tempname = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum = self.innerCode.tempNum + 1

            newNode = self.createTempVar(tempname, "int")

            self.blockStack[-1].varMap[tempname] = newNode



            self.innerCode.addCode(tempname + " := #1")

            

            if rnode.useAddress:

                self.innerCode.addCode("*" + rnode.name + " := *" + rnode.name + " + " + tempname)

            

            else:

                self.innerCode.addCode(self.innerCode.getNodeName(rnode) + " := " + self.innerCode.getNodeName(rnode) + " + " + tempname)



            return rnode

        

        elif unary_exp.left.name == "DEC_OP":



            rnode = self.praser_unary_expression(unary_exp.left.right)

            if rnode.type != "int":

                self.error(unary_exp.left.right.line, "-- operation can only use for int type.")



            tempname = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum

            newNode = self.createTempVar(tempname, "int")

            self.blockStack[-1].varMap[tempname] = newNode



            self.innerCode.addCode(tempname + " := #1")

            

            if rnode.useAddress:

                self.innerCode.addCode("*" + rnode.name + " := *" + rnode.name + " - " + tempname)

            

            else :

                self.innerCode.addCode(self.innerCode.getNodeName(rnode) + " := " + self.innerCode.getNodeName(rnode) + " - " + tempname)



            return rnode

        

        elif (unary_exp.left.name == "unary_operator") :

            op = unary_exp.left.left.name

            rnode = self.praser_unary_expression(unary_exp.left.right)

            if op == "+":



                if (rnode.type != "int" and rnode.type != "double"):

                    self.error(unary_exp.left.left.line, "operator '+' can only used to int or double")

                return rnode

            

            elif op == "-":



                if rnode.type != "int" and rnode.type != "double":

                    self.error(unary_exp.left.left.line, "operator '-' can only used to int or double")



                tempzeroname = "temp" + str(self.innerCode.tempNum)

                self.innerCode.tempNum = self.innerCode.tempNum + 1

                newzeronode = self.createTempVar(tempzeroname, rnode.type)

                self.blockStack[-1].varMap[tempzeroname] = newzeronode

                self.innerCode.addCode(tempzeroname + " := #0")



                tempname = "temp" + str(self.innerCode.tempNum)

                self.innerCode.tempNum = self.innerCode.tempNum + 1

                newnode = self.createTempVar(tempname, rnode.type)

                self.blockStack[-1].varMap[tempname] = newnode



                if rnode.useAddress:

                    self.innerCode.addCode(tempname + " := " + tempzeroname + " - *" + rnode.name)

                

                else :

                    self.innerCode.addCode(tempname + " := " + tempzeroname + " - " + self.innerCode.getNodeName(rnode))

                

                return newnode

            

            elif op == "~":

                op = "~"

            

            elif op == "!":



                op = "!"

    

    def praser_postfix_expression(self, post_exp) :

        

        if post_exp.left.name == "primary_expression":

            primary_exp = post_exp.left

            return self.praser_primary_expression(primary_exp)

        

        elif post_exp.left.right.name == "[":           

            arrayName = post_exp.left.left.left.content

            expression = post_exp.left.right.right

            enode = self.praser_expression(expression)

            anode = self.getArrayNode(arrayName)



            if anode.num < 0:

                self.error(post_exp.left.right.line, "Undifined array " + arrayName)



            tempVar = varNode()

            tempName = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum = self.innerCode.tempNum + 1

            tempVar.name = tempName

            tempVar.type = anode.type

            tempVar.useAddress = True

            self.blockStack[-1].varMap[tempName] = tempVar



            if anode.type == "int" or anode.type == "double":

                tempVar2 = varNode()

                tempName2 = "temp" + str(self.innerCode.tempNum)

                self.innerCode.tempNum = self.innerCode.tempNum + 1

                tempVar2.name = tempName2

                tempVar2.type = "int"

                self.blockStack[-1].varMap[tempName2] = tempVar2



                if anode.type == "int":

                    tempVar3 = varNode()

                    tempName3 = "temp" + str(self.innerCode.tempNum)

                    self.innerCode.tempNum = self.innerCode.tempNum + 1

                    tempVar3.name = tempName3

                    tempVar3.type = "int"

                    self.blockStack[-1].varMap[tempName3] = tempVar3 

                    self.innerCode.addCode(tempName3 + " := #4")

                    self.innerCode.addCode(tempName2 + " := " + self.innerCode.getNodeName(enode) + " * " + tempName3)

                elif anode.type == "double":

                    tempVar3 = varNode()

                    tempName3 = "temp" + str(self.innerCode.tempNum)

                    self.innerCode.tempNum = self.innerCode.tempNum + 1

                    tempVar3.name = tempName3

                    tempVar3.type = "int"

                    self.blockStack[-1].varMap[tempName3] = tempVar3

                    self.innerCode.addCode(tempName3 + " := #8")

                    self.innerCode.addCode(tempName2 + " := " + self.innerCode.getNodeName(enode) + " * " + tempName3)



                self.innerCode.addCode(tempName + " := &" + self.innerCode.self.getArrayNodeName(anode) + " + " + self.innerCode.getNodeName(tempVar2))

                return tempVar



            self.innerCode.addCode(tempName + " := &" + self.innerCode.self.getArrayNodeName(anode) + " + " + self.innerCode.getNodeName(enode))

            return tempVar

        

        elif (post_exp.left.right.name == "(") :

           

            funcName = post_exp.left.left.left.content

            newNode = varNode()

            

            if (self.funcPool.find(funcName) == self.funcPool.end()) :

                self.error(post_exp.left.left.left.line, "Undefined function " + funcName)



            if (post_exp.left.right.right.name == "argument_expression_list") :

                argument_exp_list = post_exp.left.right.right

                self.praser_argument_expression_list(argument_exp_list, funcName)



            func = self.funcPool[funcName]

            

            if (func.rtype == "void") :

                self.innerCode.addCode("CALL " + funcName)

            

            else :

                tempname = "temp" + str(self.innerCode.tempNum)

                self.innerCode.tempNum = self.innerCode.tempNum + 1



                newNode = self.createTempVar(tempname, self.funcPool[funcName].rtype)

                self.innerCode.addCode(tempname + " := CALL " + funcName)



            return newNode

        

        elif (post_exp.left.right.name == "INC_OP") :

            rnode = self.praser_postfix_expression(post_exp.left)



            if (rnode.type != "int"):

                self.error(post_exp.left.right.line, "++ operation can only use for int type.")



            tempname = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum = self.innerCode.tempNum + 1

            newnode = self.createTempVar(tempname, "int")

            self.blockStack[-1].varMap[tempname] = newnode



            tempnameone = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum = self.innerCode.tempNum + 1

            newNode = self.createTempVar(tempnameone, "int")

            self.blockStack[-1].varMap[tempnameone] = newNode



            self.innerCode.addCode(tempnameone + " := #1")

            

            if (rnode.useAddress) :

                self.innerCode.addCode(tempname + " := *" + rnode.name)

                self.innerCode.addCode("*" + rnode.name + " := *" + rnode.name + " + " + tempnameone)

            

            else :

                self.innerCode.addCode(tempname + " := " + self.innerCode.getNodeName(rnode))

                self.innerCode.addCode(self.innerCode.getNodeName(rnode) + " := " + self.innerCode.getNodeName(rnode) + " + " + tempnameone)



            return newnode

        

        elif (post_exp.left.right.name == "DEC_OP"):



            rnode = self.praser_postfix_expression(post_exp.left)



            if (rnode.type != "int"):

                self.error(post_exp.left.right.line, "-- operation can only use for int type.")



            tempname = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum = self.innerCode.tempNum + 1

            newnode = self.createTempVar(tempname, "int")

            self.blockStack[-1].varMap[tempname] = newnode



            tempnameone = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum = self.innerCode.tempNum + 1

            newNode = self.createTempVar(tempnameone, "int")

            self.blockStack[-1].varMap[tempnameone] = newNode 



            self.innerCode.addCode(tempnameone + " := #1")

            

            if (rnode.useAddress) :

                self.innerCode.addCode(tempname + " := *" + rnode.name)

                self.innerCode.addCode("*" + rnode.name + " := *" + rnode.name + " - " + tempnameone)

            

            else :

                self.innerCode.addCode(tempname + " := " + self.innerCode.getNodeName(rnode))

                self.innerCode.addCode(self.innerCode.getNodeName(rnode) + " := " + self.innerCode.getNodeName(rnode) + " - " + tempnameone)



            return newnode

    



    def praser_argument_expression_list(self, node, funcName) :
        if node==None:
            return
        argu_exp_list = node.left

        func = self.funcPool[funcName]

        i = 0

        while (argu_exp_list.name == "argument_expression_list") :

            rnode = self.praser_assignment_expression(argu_exp_list.right.right)



            self.innerCode.addCode(self.innerCode.createCodeforArgument(rnode))



            argu_exp_list = argu_exp_list.left

            i = i + 1

            if (func.paralist[len(func.paralist) - i].type != rnode.type) :

                self.error(argu_exp_list.line, "Wrong type arguments to function " + funcName)

        

        rnode = self.praser_assignment_expression(argu_exp_list)

        self.innerCode.addCode(self.innerCode.createCodeforArgument(rnode))

        i = i + 1

        if (func.paralist[len(func.paralist) - i].type != rnode.type) :

            self.error(argu_exp_list.line, "Wrong type arguments to function " + funcName)

        

        if (i != len(func.paralist)) :

            self.error(argu_exp_list.line, "The number of arguments doesn't equal to the function parameters number.")





    def praser_primary_expression(self, primary_exp) :
        
        if (primary_exp.left.name == "IDENTIFIER") :

            content = primary_exp.left.content

            rnode = self.lookupNode(content)

            if (rnode.num < 0) :

                self.error(primary_exp.left.line, "Undefined variable " + content)

            

            return rnode

        

        elif (primary_exp.left.name == "True" or primary_exp.left.name == "FALSE") :

            content = primary_exp.left.content

            tempname = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum = self.innerCode.tempNum + 1

            newNode = self.createTempVar(tempname, "bool")

            self.blockStack[-1].varMap.insert[tempname] = newNode

            if(primary_exp.left.name == "True") :

                self.innerCode.addCode(tempname + " := #1")

            else :

                self.innerCode.addCode(tempname + " := #0")

            

            return newNode

        

        elif (primary_exp.left.name == "CONSTANT_INT") :

            content = primary_exp.left.content

            tempname = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum = self.innerCode.tempNum + 1

            

            newNode = self.createTempVar(tempname, "int")

            self.blockStack[-1].varMap[tempname] = newNode

            self.innerCode.addCode(tempname + " := #" + content)

            return newNode

        

        elif (primary_exp.left.name == "CONSTANT_DOUBLE") :

            content = primary_exp.left.content

            tempname = "temp" + str(self.innerCode.tempNum)

            self.innerCode.tempNum = self.innerCode.tempNum + 1



            newNode = self.createTempVar(tempname, "double")



            self.blockStack[-1].varMap[tempname] = newNode

            self.innerCode.addCode(tempname + " := F" + content)

            return newNode

        

        elif (primary_exp.left.name == "(") :

            expression = primary_exp.left.right

            return self.praser_expression(expression)



    

    def lookupVar(self, name) :

        N = range(len(self.blockStack))

        for i in reversed(N) :

            if (self.blockStack[i].varMap.has_key(name)):

                return self.blockStack[i].varMap[name].type

        

        return ""

    



    def lookupCurruntVar(self, name) :

        return self.blockStack[-1].varMap.has_key(name)



    

    def lookupNode(self, name) :

        N = range(len(self.blockStack))

        for i in reversed(N) :

            if (self.blockStack[i].varMap.has_key(name)):

                return self.blockStack[i].varMap[name]

        

        temp = varNode()

        temp.num = -1

        return temp





    def getFuncRType(self) :

        N = range(len(self.blockStack))

        for i in reversed(N):

            if (self.blockStack[i].isfunc):

                return self.blockStack[i].func.rtype

        

        return ""





    def getArrayType(self, name) :

        N = range(len(self.blockStack))

        for i in reversed(N):

            if (self.blockStack[i].arrayMap.has_key(name)):

                return self.blockStack[i].arrayMap[name].type

        

        return ""





    def getArrayNode(self, name) :

        N = range(len(self.blockStack))

        for i in reversed(N):

            if (self.blockStack[i].arrayMap.has_key(name)):

                return self.blockStack[i].arrayMap[name]

        

        temp = arrayNode()

        temp.num = -1

        return temp





    def getBreakBlockNumber(self) :

        N = range(len(self.blockStack))

        for i in reversed(N):

            if (self.blockStack[i].canBreak):

                return i

        

        return -1





    def error(self, line, errorstring) :



        self.print_code()



        print("self.error! line " , line)

        print(errorstring)

        exit(1)





    def createTempVar(self, name, type) :

        var = varNode()

        var.name = name

        var.type = type

        var.num = -1

        return var





    def print_map(self) :

        N = range(len(self.blockStack))

        for i in reversed(N):

            print("Block " , i)

            for key, value in self.blockStack[i].varMap.items():

            

                print("     " , key , " " , value.type)





    def print_code(self) :

        self.innerCode.printCode()
