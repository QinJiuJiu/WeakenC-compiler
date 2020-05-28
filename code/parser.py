# import os

class Praser:
    funcPool = None
    blockStack = None
    innerCode = None
    root = None

    def __init__(self, innerCode, root):
        self.funcPool = {}
        self.blockStack = []
        self.innerCode = innerCode
        self.root = root
        self.praserInit()
    
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
        if node.isnull == True or node.line = -1:
            return
        if node.name == "declaration":
            node = self.praser_declaration(node)
        elif node.name == "function_definition":
            node = self.praser_function_definition(node)
        elif node.name == "statement":
            node = self..(node)

        if node.isnull == False:
            self.praserGramTree(node.left)
		    self.praserGramTree(node.right)

    def praser_statement(self, node):
        temp = node.left
        if node.left.name == "labeled_statement":
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
        if node.left.name == "GOTO":
        elif node.left.name == "CONTINUE":
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
        if node.left.name == "expression":
            self.praser_expression(node.left)

    def praser_expression(self, node):
        if node.left.name == "expression":
            return self.praser_expression(node.left)
        elif node.left.name == "assignment_expression":
            return self.praser_assignment_expression(node.left)
        
        if node.right.name == ",":
            return self.praser_assignment_expression(node.right.right)

    def praser_compound_statement(self, node):
        self.praserGramTree(node)

    def praser_selection_statement(self, node):
        if node.left.name == "IF":
            if node.left.right.right.right.right.right.isnull == True:
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

                self..(statement)
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

                self..(statement1)
                self.innerCode.addCode("GOTO " + label3)
                self.blockStack.pop()
                self.innerCode.addCode("LABEL " + label2 + " :")
                newblock2 = Block()
                self.blockStack.append(newblock2)
                self..(statement2)
                self.innerCode.addCode("LABEL " + label3 + " :")
                self.blockStack.pop()

        elif node.left.name == "SWITCH":
    
    def praser_iteration_statement(self, node):
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
            self..(statement)
            
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
            self.praser_parameter_list(declarator.left.right.right, funcName,True)
        
        func = self.funcPool[funcName]
        if isdeclared:
            if func.rtype != declarFunc.rtype:
                self.error(type_specifier.left.line, "Function return type doesn't equal to the function declared before.")
            print(funBlock.func.paralist.size())
            if func.paralist.size() != declarFunc.paralist.size():
                self.error(declarator.left.right.right.line, "The number of function parameters doesn't equal to the function declared before.")
            for i in range funBlock.func.paralist.size():
                if func.paralist[i].type != declarFunc.paralist[i].type:
                    self.error(declarator.left.right.right.line, "The parameter " + funBlock.func.paralist[i].name + "'s type doesn't equal to the function declared before." )
                
        funBlock.func = func
        self.praser_compound_statement(compound_statement)
        self.blockStack.pop()
        return node.right

    def praser_parameter_list(self, node, funcName, definite):
        if node.left.name == "parameter_list":
            self.praser_parameter_list(node.left, funcName,definite)
        elif node.left.name == "parameter_declaration":
            self.praser_parameter_declaration(node.left,funcName,definite)
        
        if node.right.name == ",":
            self.praser_parameter_declaration(node.right.right, funcName,definite)
        
    def praser_parameter_declaration(self, node, funcName, definite):
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
        begin = node.left
        if begin.right.name == ";":
            return node.right
        vartype = begin.left.content
        if vartype == "void":
            self.error(begin.left.line,"void type can't assign to variable")
        
        decl = begin.right
        self.praser_init_declarator_list(vartype, decl)
        return node.right
        





























