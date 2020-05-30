

#! /usr/bin/python

# coding=utf-8


from block import varNode


from block import funcNode


from block import arrayNode


from block import Block


from quadruples import Quadruples


import os


class Praser:
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

        self.praserInit()

        self.print_quadruplesList()

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

        if node == None:

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

        if node == None:

            return

        if node.left.name == "GOTO":

            node.left.name = "GOTO"

        elif node.left.name == "CONTINUE":

            node.left.name == "CONTINUE"

        elif node.left.name == "BREAK":

            num = self.getBreakBlockNumber()

            if num < 0:

                self.error(node.left.line, "This scope doesn't support break.")

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "goto"
            q.arg1 = self.blockStack[num].breakLabelname
            self.quadruplesList.append(q)

        elif node.left.name == "RETURN":

            funcType = self.getFuncRType()

            if node.left.right.name == "expression":

                rnode = self.praser_expression(node.left.right)

                q = Quadruples()

                q.num = self.linenum
                self.linenum += 1

                q.op = "ret"
                q.SetArgName(1, rnode)

                self.quadruplesList.append(q)

                if rnode.type != funcType:

                    self.error(
                        node.left.right.line, "return type doesn't equal to function return type.")

            elif node.left.right.name == ";":

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "ret"
                self.quadruplesList.append(q)

                if funcType != "void":

                    self.error(
                        node.left.right.line, "You should return " + self.blockStack[-1].func.rtype)

    def praser_expression_statement(self, node):

        if node == None:

            return

        if node.left.name == "expression":

            self.praser_expression(node.left)

    def praser_expression(self, node):

        if node == None:

            return

        if node.left.name == "expression":

            return self.praser_expression(node.left)

        elif node.left.name == "assignment_expression":

            return self.praser_assignment_expression(node.left)

        if node.right.name == ",":

            return self.praser_assignment_expression(node.right.right)

    def praser_compound_statement(self, node):

        if node == None:

            return

        self.praserGramTree(node)

    def praser_selection_statement(self, node):

        if node == None:

            return

        if node.left.name == "IF":

            if node.left.right.right.right.right.right == None:

                newblock = Block()

                self.blockStack.append(newblock)

                expression = node.left.right.right

                exp_rnode = self.praser_expression(expression)

                statement = node.left.right.right.right.right

                label1 = 'label' + str(self.labelNum)

                self.labelNum += 1

                label2 = 'label' + str(self.labelNum)

                self.labelNum += 1

                if exp_rnode.type == "bool":

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "if_t"
                    q.arg1 = exp_rnode.boolString
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

                self.praser_statement(statement)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "lab"
                q.arg1 = label2
                self.quadruplesList.append(q)

                self.blockStack.pop()

            elif node.left.right.right.right.right.right.name == "ELSE":

                newblock1 = Block()

                self.blockStack.append(newblock1)

                expression = node.left.right.right

                exp_rnode = self.praser_expression(expression)

                statement1 = node.left.right.right.right.right

                statement2 = node.left.right.right.right.right.right.right

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
                    q.arg1 = exp_rnode.boolString
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

                self.praser_statement(statement1)

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

                self.praser_statement(statement2)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "lab"
                q.arg1 = label3
                self.quadruplesList.append(q)

                self.blockStack.pop()

        # elif node.left.name == "SWITCH":

    def praser_iteration_statement(self, node):

        if node == None:

            return

        if node.left.name == "WHILE":

            newblock = Block()

            newblock.canBreak = True

            self.blockStack.append(newblock)

            expression = node.left.right.right

            statement = node.left.right.right.right.right

            label1 = 'label' + str(self.labelNum)
            self.labelNum += 1

            label2 = 'label' + str(self.labelNum)
            self.labelNum += 1

            label3 = 'label' + str(self.labelNum)
            self.labelNum += 1

            self.blockStack[-1].breakLabelname = label3

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "lab"
            q.arg1 = label1
            self.quadruplesList.append(q)

            var = self.praser_expression(expression)

            if var.type == "bool":

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "if_t"
                q.arg1 = var.boolString
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

            self.praser_statement(statement)

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

        elif node.left.name == "DO":

            newblock = Block()

            newblock.canBreak = True

            self.blockStack.append(newblock)

            expression = node.left.right

            statement = node.left.right.right.right.right

            label1 = 'label' + str(self.labelNum)
            self.labelNum += 1

            label2 = 'label' + str(self.labelNum)
            self.labelNum += 1

            self.blockStack[-1].breakLabelname = label2

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "lab"
            q.arg1 = label1
            self.quadruplesList.append(q)

            self.praser_statement(statement)

            var = self.praser_expression(expression)

            if var.type == "bool":

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "if_t"
                q.arg1 = exp_rnode.boolString
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

        elif node.left.name == "FOR":

            if node.left.right.right.name == "expression_statement":

                if node.left.right.right.right.right.name == ")":

                    newblock = Block()

                    newblock.canBreak = True

                    self.blockStack.append(newblock)

                    exp_state1 = node.left.right.right

                    exp_state2 = exp_state1.right

                    statement = exp_state2.right.right

                    label1 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label2 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label3 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    self.blockStack[-1].breakLabelname = label3

                    if exp_state1.left.name == "expression":

                        self.praser_expression(exp_state1.left)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    if exp_state2.left.name == "expression":

                        var = self.praser_expression(exp_state2.left)

                        if var.type == "bool":

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_t"
                            q.arg1 = exp_rnode.boolString
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

                    self.praser_statement(statement)

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

                elif node.left.right.right.right.right.name == "expression":

                    newblock = Block()

                    newblock.canBreak = True

                    self.blockStack.append(newblock)

                    exp_state1 = node.left.right.right

                    exp_state2 = exp_state1.right

                    exp = exp_state2.right

                    statement = exp.right.right

                    label1 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label2 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label3 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    self.blockStack[-1].breakLabelname = label3

                    if exp_state1.left.name == "expression":

                        self.praser_expression(exp_state1.left)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    if exp_state2.left.name == "expression":

                        var = self.praser_expression(exp_state2.left)

                        if var.type == "bool":

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_t"
                            q.arg1 = var.boolString
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

                    self.praser_statement(statement)

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

            if node.left.right.right.name == "declaration":

                if node.left.right.right.right.right.name == ")":

                    newblock = Block()

                    newblock.canBreak = True

                    self.blockStack.append(newblock)

                    declaration = node.left.right.right

                    expression_statement = declaration.right

                    statement = expression_statement.right.right

                    label1 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label2 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label3 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    self.blockStack[-1].breakLabelname = label3

                    self.praser_declaration(declaration)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    if expression_statement.left.name == "expression":

                        var = self.praser_expression(expression_statement.left)

                        if var.type == "bool":

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_t"
                            q.arg1 = exp_rnode.boolString
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

                    self.praser_statement(statement)

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

                elif node.left.right.right.right.right.name == "expression":

                    newblock = Block()

                    newblock.canBreak = True

                    self.blockStack.append(newblock)

                    declaration = node.left.right.right

                    expression_statement = declaration.right

                    expression = expression_statement.right

                    statement = expression.right.right

                    label1 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label2 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    label3 = 'label' + str(self.labelNum)
                    self.labelNum += 1

                    self.blockStack[-1].breakLabelname = label3

                    self.praser_declaration(declaration)

                    q = Quadruples()
                    q.num = self.linenum
                    self.linenum += 1
                    q.op = "lab"
                    q.arg1 = label1
                    self.quadruplesList.append(q)

                    if expression_statement.left.name == "expression":

                        var = self.praser_expression(expression_statement.left)

                        if var.type == "bool":

                            q = Quadruples()
                            q.num = self.linenum
                            self.linenum += 1
                            q.op = "if_t"
                            q.arg1 = exp_rnode.boolString
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

                    self.praser_statement(statement)

                    self.praser_expression(expression)

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

    def praser_function_definition(self, node):

        if node == None:

            return

        type_specifier = node.left

        declarator = node.left.right

        compound_statement = declarator.right

        funcType = type_specifier.left.content

        funcName = declarator.left.left.content

        isdeclared = False

        if funcName in self.funcPool.keys():

            if self.funcPool[funcName].isdefinied:

                self.error(declarator.left.left.line, "Function " +
                           funcName + " is duplicated definition.")

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

        q = Quadruples()
        q.num = self.linenum
        self.linenum += 1
        q.op = "func"
        q.arg1 = funcName
        self.quadruplesList.append(q)

        if declarator.left.right.right.name == "parameter_list":

            self.praser_parameter_list(
                declarator.left.right.right, funcName, True)

        func = self.funcPool[funcName]

        if isdeclared:

            if func.rtype != declarFunc.rtype:

                self.error(type_specifier.left.line,
                           "Function return type doesn't equal to the function declared before.")

            print(len(funBlock.func.paralist))

            if len(func.paralist) != len(declarFunc.paralist):

                self.error(declarator.left.right.right.line,
                           "The number of function parameters doesn't equal to the function declared before.")

            for i in range(len((funBlock.func.paralist))):

                if func.paralist[i].type != declarFunc.paralist[i].type:

                    self.error(declarator.left.right.right.line, "The parameter " +
                               funBlock.func.paralist[i].name + "'s type doesn't equal to the function declared before.")

        funBlock.func = func

        self.praser_compound_statement(compound_statement)

        self.blockStack.pop()

        return node.right

    def praser_parameter_list(self, node, funcName, definite):

        if node == None:

            return

        if node.left.name == "parameter_list":

            self.praser_parameter_list(node.left, funcName, definite)

        elif node.left.name == "parameter_declaration":

            self.praser_parameter_declaration(node.left, funcName, definite)

        if node.right.name == ",":

            self.praser_parameter_declaration(
                node.right.right, funcName, definite)

    def praser_parameter_declaration(self, node, funcName, definite):

        if node == None:

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

            self.blockStack[-1].func.paralist.append(newnode)

            newnode.num = self.varNum

            self.varNum = self.varNum + 1

            self.blockStack[-1].func.paralist.append(newnode)

        if newnode not in self.funcPool[funcName].paralist:

            self.funcPool[funcName].paralist.append(newnode)

        self.blockStack[-1].varMap[varName] = newnode

        if definite:

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "par"
            q.arg1 = 'var' + str(newnode.num)
            self.quadruplesList.append(q)

    def praser_declaration(self, node):

        if node == None:

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

        if node == None:

            return

        if node.left.name == 'init_declarator_list':

            self.praser_init_declarator_list(vartype, node.left)

        elif node.left.name == 'init_declarator':

            self.praser_init_declarator(vartype, node.left)

        if node.right.name == ',':

            self.praser_init_declarator(vartype, node.right.right)

    def praser_init_declarator(self, vartype, node):

        if node == None:

            return

        declarator = node.left

        if declarator.right == None:

            if declarator.left.name == 'IDENTIFIER':

                id = declarator.left

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

                    self.error(declarator.left.line,
                               'Variable multiple declaration')

            else:

                if declarator.left.right.name == '(':

                    funcName = declarator.left.left.content

                    funcType = vartype

                    if len(self.blockStack) > 1:

                        self.error(
                            declarator.left.right.line, 'Function declaration must at global environment.')

                    parament_list = declarator.left.right.right

                    newFunc = funcNode()

                    # newFunc.isdefined = False

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

                        self.error(declarator.left.right.line,
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

                    anode = arrayNode()	 # ?

                    anode.name = arrayName

                    anode.type = arrayType

                    anode.num = self.arrayNum

                    self.arrayNum += 1

                    self.blockStack[len(self.blockStack) -
                                    1].arrayMap[arrayName] = anode

        elif declarator.right.name == '=':

            newvar = varNode()

            if declarator.left.name == 'IDEMTIFIER':

                id = declarator.left

                var = id.content

                if self.lookupCurruntVar(var) == 0:

                    newvar.name = var

                    newvar.type = vartype

                    newvar.num = self.varNum

                    self.varNum += 1

                    self.blockStack[len(self.blockStack) -
                                    1].varMap[var] = newvar  # not sure

                else:

                    self.error(declarator.left.line,
                               'Variable multiple declaration')

                initializer = declarator.right.right

                if initializer == None:

                    self.error(declarator.line,
                               'Lack the initializer for variable')

                else:

                    if initializer.left.name == 'assignment_expression':

                        rnode = self.praser_assignment_expression(
                            initializer.left)

                        q = Quadruples()
                        q.num = self.linenum
                        self.linenum += 1
                        q.op = "asn"
                        q.SetArgName(2, newvar)
                        q.SetArgName(1, rnode)

                        self.quadruplesList.append(q)

                        rtype = rnode.type

                        if rtype != vartype:

                            self.error(initializer.left.line, 'Wrong type to variable ' +
                                       declarator.left.content + ": " + rtype + ' to ' + vartype)

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

                tempname = 'temp' + str(self.tempNum)

                self.tempNum += 1

                node3 = self.createTempVar(tempname, node1.type)

                self.blockStack[len(self.blockStack) -
                                1].varMap[tempname] = node3

                if op == 'MUL_ASSIGN':

                    if node1.type != node2.type:

                        self.error(assign_exp.left.line,
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

                        self.error(assign_exp.left.line,
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

                        self.error(assign_exp.left.line,
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

                        self.error(assign_exp.left.line,
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

                        self.error(assign_exp.left.line,
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

                        self.error(assign_exp.left.line,
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

                        self.error(assign_exp.left.line,
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

                        self.error(assign_exp.left.line,
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

                        self.error(assign_exp.left.line,
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

                        self.error(assign_exp.left.line,
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

    def praser_logical_or_expression(self, logical_or_exp):

        if logical_or_exp.left.name == 'logical_and_expression':

            logical_and_exp = logical_or_exp.left

            return self.praser_logical_and_expression(logical_and_exp)

        elif logical_or_exp.left.name == 'logical_or_expression':

            node1 = self.praser_logical_or_expression(logical_or_exp.left)

            node2 = self.praser_logical_and_expression(
                logical_or_exp.left.right.right)

            if node1.type != 'bool' or node2 != 'bool':

                self.error(logical_or_exp.left.right.line,
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

            newnode.boolString = q.GetNodeName(
                node1) + ' || ' + q.GetNodeName(node2)

            return newnode

    def praser_logical_and_expression(self, logical_and_exp):

        if logical_and_exp.left.name == 'inclusive_or_expression':

            inclusive_or_exp = logical_and_exp.left

            return self.praser_inclusive_or_expression(inclusive_or_exp)

        elif logical_and_exp.left.name == 'logical_and_expression':

            node1 = self.praser_logical_and_expression(logical_and_exp.left)

            node2 = self.praser_inclusive_or_expression(
                logical_and_exp.left.right.right)

            if node1.type != 'bool' or node2 != 'bool':

                self.error(logical_and_exp.left.right.line,
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
            newnode.boolString = q.GetNodeName(
                node1) + ' && ' + q.GetNodeName(node2)

            return newnode

    def praser_inclusive_or_expression(self, inclusive_or_exp):

        if inclusive_or_exp.left.name == 'exclusive_or_expression':

            exclusive_or_exp = inclusive_or_exp.left

            return self.praser_exclusive_or_expression(exclusive_or_exp)

        elif inclusive_or_exp.left.name == 'inclusive_or_expression':

            node1 = self.praser_inclusive_or_expression(inclusive_or_exp.left)

            node2 = self.praser_exclusive_or_expression(
                inclusive_or_exp.left.right.right)

            if node1.type != 'int' or node2 != 'int':

                self.error(inclusive_or_exp.left.right.line,
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

    def praser_exclusive_or_expression(self, exclusive_or_exp):

        if exclusive_or_exp.left.name == 'and_expression':

            and_exp = exclusive_or_exp.left

            return self.praser_and_expression(and_exp)

        elif exclusive_or_exp.left.name == 'exclusive_or_expression':

            node1 = self.praser_exclusive_or_expression(exclusive_or_exp.left)

            node2 = self.praser_and_expression(
                exclusive_or_exp.left.right.right)

            if node1.type != 'int' or node2 != 'int':

                self.error(exclusive_or_exp.left.right.line,
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

    def praser_and_expression(self, and_exp):

        if and_exp.left.name == 'equality_expression':

            equality_exp = and_exp.left

            return self.praser_equality_expression(equality_exp)

        elif and_exp.left.name == 'and_expression':

            node1 = self.praser_and_expression(and_exp.left)

            node2 = self.praser_equality_expression(and_exp.left.right.right)

            if node1.type != 'int' or node2 != 'int':

                self.error(and_exp.left.right.line,
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

    def praser_equality_expression(self, equality_exp):

        print("########")

        print(equality_exp.name)

        print(equality_exp.left.name)

        print("########")

        if equality_exp.left.name == 'relational_expression':

            relational_exp = equality_exp.left

            return self.praser_relational_expression(relational_exp)

        elif equality_exp.left.right.name == 'EQ_OP' or equality_exp.left.right.name == 'NE_OP':

            if equality_exp.left.right.name == 'EQ_OP':

                op = '=='

            else:

                op = '!='

            node1 = self.praser_equality_expression(equality_exp.left)

            node2 = self.praser_relational_expression(
                equality_exp.left.right.right)

            if node1.type != node2.type:

                self.error(equality_exp.left.right.line,
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
            newnode.boolString = q.GetNodeName(
                node1) + " " + op + " " + q.GetNodeName(node2)

            return newnode

    def praser_relational_expression(self, relational_exp):

        if relational_exp.left.name == 'shift_expression':

            shift_exp = relational_exp.left

            return self.praser_shift_expression(shift_exp)

        else:

            op = relational_exp.left.right.name

            if op == 'LE_OP':

                op = '<='

            elif op == 'GE_OP':

                op = '>='

            if op == '>' or op == '<' or op == '>=' or op == '<=':

                node1 = self.praser_relational_expression(relational_exp.left)

                node2 = self.praser_shift_expression(
                    relational_exp.left.right.right)

                if node1.type != node2.type:

                    self.error(relational_exp.left.right.line,
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
                newnode.boolString = q.GetNodeName(
                    node1) + " " + op + " " + q.GetNodeName(node2)

                return newnode

    def praser_shift_expression(self, shift_exp):

        print("########")

        print(shift_exp.name)

        print(shift_exp.left.name)

        print("########")

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

                self.error(shift_exp.left.right.line,
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
    def praser_additive_expression(self, additive_exp):

        if additive_exp.left.name == "multiplicative_expression":

            mult_exp = additive_exp.left

            return self.praser_multiplicative_expression(mult_exp)

        elif (additive_exp.left.right.name == "+" or additive_exp.left.right.name == "-"):

            node1 = self.praser_additive_expression(additive_exp.left)

            node2 = self.praser_multiplicative_expression(
                additive_exp.left.right.right)

            if node1.type != node2.type:

                self.error(additive_exp.left.right.line,
                           "Different type for two variables.")

            tempname = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newnode = self.createTempVar(tempname, node1.type)

            self.blockStack[-1].varMap[tempname] = newnode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            if additive_exp.left.right.name == '+':
                q.op = "add"
            else:
                q.op = "sub"
            q.SetArgName(1, node1)
            q.SetArgName(2, node2)
            q.result = tempname
            self.quadruplesList.append(q)

            return newnode

    def praser_multiplicative_expression(self, mult_exp):

        if mult_exp.left.name == "unary_expression":

            unary_exp = mult_exp.left

            return self.praser_unary_expression(unary_exp)

        elif (mult_exp.left.right.name == "*" or mult_exp.left.right.name == "/" or mult_exp.left.right.name == "%"):

            node1 = self.praser_multiplicative_expression(mult_exp.left)

            node2 = self.praser_unary_expression(mult_exp.left.right.right)

            if node1.type != node2.type:

                self.error(mult_exp.left.right.line,
                           "Different type for two variables.")

            tempname = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newNode = self.createTempVar(tempname, node1.type)

            self.blockStack[-1].varMap[tempname] = newNode

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            if mult_exp.left.right.name == '*':
                q.op = "mul"
            elif mult_exp.left.right.name == '/':
                q.op = "div"
            else:
                q.op = "mod"
            q.SetArgName(1, node1)
            q.SetArgName(2, node2)
            q.result = tempname
            self.quadruplesList.append(q)

            return newNode

    def praser_unary_expression(self, unary_exp):

        if unary_exp.left.name == "postfix_expression":

            post_exp = unary_exp.left

            return self.praser_postfix_expression(post_exp)

        elif unary_exp.left.name == "INC_OP":

            rnode = self.praser_unary_expression(unary_exp.left.right)

            if rnode.type != "int":

                self.error(unary_exp.left.right.line,
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

            if rnode.useAddress:

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

        elif unary_exp.left.name == "DEC_OP":

            rnode = self.praser_unary_expression(unary_exp.left.right)

            if rnode.type != "int":

                self.error(unary_exp.left.right.line,
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

            if rnode.useAddress:

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

        elif (unary_exp.left.name == "unary_operator"):

            op = unary_exp.left.left.name

            rnode = self.praser_unary_expression(unary_exp.left.right)

            if op == "+":

                if (rnode.type != "int" and rnode.type != "double"):

                    self.error(unary_exp.left.left.line,
                               "operator '+' can only used to int or double")

                return rnode

            elif op == "-":

                if rnode.type != "int" and rnode.type != "double":

                    self.error(unary_exp.left.left.line,
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

                if rnode.useAddress:

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

    def praser_postfix_expression(self, post_exp):

        if post_exp.left.name == "primary_expression":

            primary_exp = post_exp.left

            return self.praser_primary_expression(primary_exp)

        elif post_exp.left.right.name == "[":

            arrayName = post_exp.left.left.left.content

            expression = post_exp.left.right.right

            enode = self.praser_expression(expression)

            anode = self.getArrayNode(arrayName)

            if anode.num < 0:

                self.error(post_exp.left.right.line,
                           "Undifined array " + arrayName)

            tempVar = varNode()

            tempName = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            tempVar.name = tempName

            tempVar.type = anode.type

            tempVar.useAddress = True

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

        elif (post_exp.left.right.name == "("):

            funcName = post_exp.left.left.left.content

            newNode = varNode()

            if (funcName not in self.funcPool):

                self.error(post_exp.left.left.left.line,
                           "Undefined function " + funcName)

            if (post_exp.left.right.right.name == "argument_expression_list"):

                argument_exp_list = post_exp.left.right.right

                self.praser_argument_expression_list(
                    argument_exp_list, funcName)

            func = self.funcPool[funcName]

            if (func.rtype == "void"):

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
                    tempname, self.funcPool[funcName].rtype)

                q = Quadruples()
                q.num = self.linenum
                self.linenum += 1
                q.op = "call"
                q.arg1 = funcName
                q.arg2 = tempname
                self.quadruplesList.append(q)

            return newNode

        elif (post_exp.left.right.name == "INC_OP"):

            rnode = self.praser_postfix_expression(post_exp.left)

            if (rnode.type != "int"):

                self.error(post_exp.left.right.line,
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

            if (rnode.useAddress):

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

        elif (post_exp.left.right.name == "DEC_OP"):

            rnode = self.praser_postfix_expression(post_exp.left)

            if (rnode.type != "int"):

                self.error(post_exp.left.right.line,
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

            if (rnode.useAddress):

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

    def praser_argument_expression_list(self, node, funcName):

        if node == None:

            return

        argu_exp_list = node.left

        func = self.funcPool[funcName]

        i = 0

        while (argu_exp_list.name == "argument_expression_list"):

            rnode = self.praser_assignment_expression(
                argu_exp_list.right.right)

            q = Quadruples()
            q.num = self.linenum
            self.linenum += 1
            q.op = "arg"
            q.SetArgName(1, rnode)
            self.quadruplesList.append(q)

            argu_exp_list = argu_exp_list.left

            i = i + 1

            if (func.paralist[len(func.paralist) - i].type != rnode.type):

                self.error(argu_exp_list.line,
                           "Wrong type arguments to function " + funcName)

        rnode = self.praser_assignment_expression(argu_exp_list)

        q = Quadruples()
        q.num = self.linenum
        self.linenum += 1
        q.op = "arg"
        q.SetArgName(1, rnode)
        self.quadruplesList.append(q)

        i = i + 1

        if (func.paralist[len(func.paralist) - i].type != rnode.type):

            self.error(argu_exp_list.line,
                       "Wrong type arguments to function " + funcName)

        # if (i != len(func.paralist)) :

            #self.error(argu_exp_list.line, "The number of arguments doesn't equal to the function parameters number.")

    def praser_primary_expression(self, primary_exp):

        if (primary_exp.left.name == "IDENTIFIER"):

            content = primary_exp.left.content

            rnode = self.lookupNode(content)

            if (rnode.num < 0):

                self.error(primary_exp.left.line,
                           "Undefined variable " + content)

            return rnode

        elif (primary_exp.left.name == "True" or primary_exp.left.name == "FALSE"):

            content = primary_exp.left.content

            tempname = "temp" + str(self.tempNum)

            self.tempNum = self.tempNum + 1

            newNode = self.createTempVar(tempname, "bool")

            self.blockStack[-1].varMap.insert[tempname] = newNode

            if(primary_exp.left.name == "True"):

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

        elif (primary_exp.left.name == "CONSTANT_INT"):

            content = primary_exp.left.content

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

        elif (primary_exp.left.name == "CONSTANT_DOUBLE"):

            content = primary_exp.left.content

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

        elif (primary_exp.left.name == "("):

            expression = primary_exp.left.right

            return self.praser_expression(expression)

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

            if (self.blockStack[i].isfunc):

                return self.blockStack[i].func.rtype

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

            if (self.blockStack[i].canBreak):

                return i

        return -1

    def error(self, line, errorstring):

        self.print_code()

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

                print("		", key, " ", value.type)

