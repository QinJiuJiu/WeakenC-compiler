#! /usr/bin/python
# coding=utf-8


class InnerCode:

    def __init__(self):

        self.tempNum = 0

        self.varNum = 0

        self.labelNum = 0

        self.arrayNum = 0

        self.codeList = []

    def addCode(self, str):

        self.codeList.append(str)
        print("**********")
        print(len(self.codeList))
        print("**********")


    def printCode(self):
        print("**********")
        print(len(self.codeList))
        print("**********")
        #opt = Optimize(self.codeList)  # add codeOptimize

        #self.codeList = opt.getCodeList()

        out = open('innerCode.txt', 'a')

        for i in range(len(self.codeList)):

            print(self.codeList[i])

            out.write(self.codeList[i])

            out.write('\n')



    def createCodeforVar(self, tempname, op, node1, node2):

        result = tempname + ' := '

        if node1.useAddress == 1:

           result += '*' + node1.name

        else:

            if node1.num < 0:

                result += node1.name

            else:

                result += 'var' + str(node1.num)



        result += ' ' + op + ' '



        if node2.useAddress == 1:

            result += '*' + node2.name

        else:

            if node2.num < 0:

                result += node2.name

            else:

                result += 'var' + str(node2.num)



        return result



    def createCodeforAssign(self, node1, node2):

        if node1.useAddress == 1:

            result = '*' + node1.name + " := "

        else:

            result = 'var' + str(node1.num)

            result += ' := '



        if node2.useAddress == 1:

            result = result + '*' + node2.name

        else:

            if node2.num < 0:

                result += node2.name

            else:

                result += 'var' + str(node2.num)



        return result



    def createCodeforParameter(self, node):

        result = 'PARAM'

        result += 'var' + str(node.num)

        return result



    def createCodeforReturn(self, node):

        result = 'RETURN'

        if node.useAddress == 1:

            result += '*' + node.name

        else:

            if node.num < 0:

                result += node.name

            else:

                result += 'var' + str(node.num)

        return result



    def createCodeforArgument(self, node):

        result = 'ARG'

        if node.useAddress == 1:

            result += '*' + node.name

        else:

            if node.num < 0:

                result += node.name

            else:

                result += 'var' + str(node.num)

        return result



    def getNodeName(self, node):

        if node.useAddress == 1:

            result = '*' + node.name

        else:

            if node.num < 0:

                result = node.name

            else:

                result = 'var' + str(node.num)

        return result



    def getarrayNodeName(self, node):

        result = 'array' + str(node.num)

        return result



    def getLabelName(self):

        result = 'label' + str(self.labelNum)

        self.labelNum += 1

        return result


