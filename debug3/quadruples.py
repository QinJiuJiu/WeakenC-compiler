class Quadruples:
    def __init__(self):

        self.num = 0
        self.op = ""
        self.arg1 = ""
        self.arg2 = ""
        self.result = ""

    def SetArgName(self, num, node):

        if node.type == 1:

            argTemp = '*' + node.name

        else:

            if node.num < 0:

                argTemp = node.name

            else:

                argTemp = 'var' + str(node.num)

        if num == 1:
            self.arg1 = argTemp
        elif num == 2:
            self.arg2 = argTemp
        else:
            self.result = argTemp

    def GetNodeName(self, node):

        if node.type == 1:

            result = '*' + node.name

        else:

            if node.num < 0:
                result = node.name


            else:

                result = 'var' + str(node.num)

        return result

