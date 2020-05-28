def praser_additive_expression(self,additive_exp):
	if (additive_exp.left.name == "multiplicative_expression"):
		mult_exp =additive_exp.left
		return self.praser_multiplicative_expression(mult_exp)
	
	elif (additive_exp.left.right.name == "+" || additive_exp.left.right.name == "-") :
		node1 = self.praser_additive_expression(additive_exp.left)
		node2 = self.praser_multiplicative_expression(additive_exp.left.right.right)

		if (node1.type != node2.type) :
			self.error(additive_exp.left.right.line, "Different type for two variables.")
		

		tempname = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum=self.innerCode.tempNum+1
		newnode = self.createTempVar(tempname, node1.type)
		self.blockStack[-1].varMap[tempname]=newnode

		self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, additive_exp.left.right.name, node1, node2))
		return newnode
	

 
def praser_multiplicative_expression(self,mult_exp):
	if (mult_exp.left.name == "unary_expression") :
		unary_exp = mult_exp.left
		return self.praser_unary_expression(unary_exp)
	
	elif (mult_exp.left.right.name == "*" || mult_exp.left.right.name == "/" || mult_exp.left.right.name == "%"):
		node1 = self.praser_multiplicative_expression(mult_exp.left)
		node2 = self.praser_unary_expression(mult_exp.left.right.right)

		if (node1.type != node2.type):
			self.error(mult_exp.left.right.line, "Different type for two variables.")
		

		tempname = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum=self.innerCode.tempNum+1
		newNode = self.createTempVar(tempname, node1.type)
		self.blockStack[-1].varMap[tempname]=newNode

		self.innerCode.addCode(self.innerCode.createCodeforVar(tempname, mult_exp.left.right.name,node1,node2))
		return newNode

	
 

def praser_unary_expression(self,unary_exp) :
	if (unary_exp.left.name == "postfix_expression") :
		post_exp = unary_exp.left
		return self.praser_postfix_expression(post_exp)
	
	elif (unary_exp.left.name == "INC_OP") :
		rnode = self.praser_unary_expression(unary_exp.left.right)
		if (rnode.type != "int"):
			self.error(unary_exp.left.right.line, "++ operation can only use for int type.")

		tempname = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum=self.innerCode.tempNum+1
		newNode = self.createTempVar(tempname, "int")
		self.blockStack[-1].varMap[tempname]=newNode

		self.innerCode.addCode(tempname + " := #1")

		
		if (rnode.useAddress) :
			self.innerCode.addCode("*" + rnode.name + " := *" + rnode.name + " + " + tempname)
		
		else:
			self.innerCode.addCode(self.innerCode.getNodeName(rnode) + " := " + self.innerCode.getNodeName(rnode) + " + "  + tempname)
		

		return rnode

	
	elif (unary_exp.left.name == "DEC_OP") :

		rnode = self.praser_unary_expression(unary_exp.left.right)
		if (rnode.type != "int"):
			self.error(unary_exp.left.right.line, "-- operation can only use for int type.")

		tempname = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum
		newNode = self.createTempVar(tempname, "int")
		self.blockStack[-1].varMap.[tempname]=newNode

		self.innerCode.addCode(tempname + " := #1")

		
		if (rnode.useAddress) :
			self.innerCode.addCode("*" + rnode.name + " := *" + rnode.name + " - " + tempname)
		
		else :
			self.innerCode.addCode(self.innerCode.getNodeName(rnode) + " := " + self.innerCode.getNodeName(rnode) + " - " + tempname)
		

		return rnode
	
	elif (unary_exp.left.name == "unary_operator") :
		op = unary_exp.left.left.name
		rnode = self.praser_unary_expression(unary_exp.left.right)
		if (op == "+") :

			if (rnode.type != "int" && rnode.type != "double"):
				self.error(unary_exp.left.left.line, "operator '+' can only used to int or double")
			return rnode
		
		elif (op == "-") :

			if (rnode.type != "int" && rnode.type != "double"):
				self.error(unary_exp.left.left.line, "operator '-' can only used to int or double")

			tempzeroname = "temp" + str(self.innerCode.tempNum)
			self.innerCode.tempNum=self.innerCode.tempNum+1
			newzeronode = self.createTempVar(tempzeroname, rnode.type)
			self.blockStack[-1].varMap[tempzeroname]=newzeronode
			self.innerCode.addCode(tempzeroname + " := #0")

			tempname = "temp" + str(self.innerCode.tempNum)
			self.innerCode.tempNum=self.innerCode.tempNum+1
			newnode = self.createTempVar(tempname, rnode.type)
			self.blockStack[-1].varMap[tempname]=newnode


			if (rnode.useAddress) :
				self.innerCode.addCode(tempname + " := " + tempzeroname + " - *" + rnode.name)
			
			else :
				self.innerCode.addCode(tempname + " := " + tempzeroname + " - " + self.innerCode.getNodeName(rnode))
			
			return newnode
		
		elif (op == "~") :
			op="~"
		
		elif (op == "!") :

			op="!"
	

 

def praser_postfix_expression(self,post_exp) :
	
	if (post_exp.left.name == "primary_expression") :
		primary_exp = post_exp.left
		return self.praser_primary_expression(primary_exp)
	
	elif (post_exp.left.right.name == "[") :
		
		arrayName = post_exp.left.left.left.content
		expression = post_exp.left.right.right
		enode = self.praser_expression(expression)
		anode = self.getArrayNode(arrayName)

		if (anode.num < 0):
			self.error(post_exp.left.right.line, "Undifined array " + arrayName)

		tempVar=varNode()
		tempName = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum=self.innerCode.tempNum+1
		tempVar.name = tempName
		tempVar.type = anode.type
		tempVar.useAddress = true
		self.blockStack[-1].varMap.[tempName]=tempVar


		if (anode.type == "int" || anode.type == "double") :
			tempVar2=varNode()
			tempName2 = "temp" + str(self.innerCode.tempNum)
			self.innerCode.tempNum=self.innerCode.tempNum+1
			tempVar2.name = tempName2
			tempVar2.type = "int"
			self.blockStack[-1].varMap.[tempName2]=tempVar2

			if (anode.type == "int") :

				tempVar3=varNode()
				tempName3 = "temp" + str(self.innerCode.tempNum)
				self.innerCode.tempNum=self.innerCode.tempNum+1
				tempVar3.name = tempName3
				tempVar3.type = "int"
				self.blockStack[-1].varMap.[tempName3]=tempVar3 

				self.innerCode.addCode(tempName3 + " := #4")

				self.innerCode.addCode(tempName2 + " := " + self.innerCode.getNodeName(enode) + " * " + tempName3)
			
			elif (anode.type == "double"):
				tempVar3=varNode()
				tempName3 = "temp" + str(self.innerCode.tempNum)
				self.innerCode.tempNum=self.innerCode.tempNum+1
				tempVar3.name = tempName3
				tempVar3.type = "int"
				self.blockStack[-1].varMap.[tempName3]=tempVar3

				self.innerCode.addCode(tempName3 + " := #8")

				self.innerCode.addCode(tempName2 + " := " + self.innerCode.getNodeName(enode) + " * " + tempName3)
			

			self.innerCode.addCode(tempName + " := &" + self.innerCode.self.getArrayNodeName(anode) + " + " + self.innerCode.getNodeName(tempVar2))
			return tempVar
		

		self.innerCode.addCode(tempName + " := &" + self.innerCode.self.getArrayNodeName(anode) + " + " + self.innerCode.getNodeName(enode))
		return tempVar
	
	elif (post_exp.left.right.name == "(") :
		#函数调用
		funcName = post_exp.left.left.left.content
		newNode=varNode()
		
		if (self.funcPool.find(funcName) == self.funcPool.end()) :
			self.error(post_exp.left.left.left.line, "Undefined function " + funcName)
		

		if (post_exp.left.right.right.name == "argument_expression_list") :
			argument_exp_list = post_exp.left.right.right
			self.praser_argument_expression_list(argument_exp_list, funcName)
			

		

		funcNode func = self.funcPool[funcName]
		
		if (func.rtype == "void") :
			self.innerCode.addCode("CALL " + funcName)
		
		else :
			tempname = "temp" + str(self.innerCode.tempNum)
			self.innerCode.tempNum=self.innerCode.tempNum+1

			newNode = self.createTempVar(tempname, self.funcPool[funcName].rtype)
			self.innerCode.addCode(tempname + " := CALL " + funcName)

		

		return newNode
		
	
	elif (post_exp.left.right.name == "INC_OP") :
		rnode = self.praser_postfix_expression(post_exp.left)

		if (rnode.type != "int"):
			self.error(post_exp.left.right.line, "++ operation can only use for int type.")

		tempname = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum=self.innerCode.tempNum+1
		newnode = self.createTempVar(tempname, "int")
		self.blockStack[-1].varMap.[tempname]=newnode

		tempnameone = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum=self.innerCode.tempNum+1
		newNode = self.createTempVar(tempnameone, "int")
		self.blockStack[-1].varMap[tempnameone]=newNode

		self.innerCode.addCode(tempnameone + " := #1")

		
		if (rnode.useAddress) :
			self.innerCode.addCode(tempname + " := *" + rnode.name)
			self.innerCode.addCode("*" + rnode.name + " := *" + rnode.name + " + " + tempnameone)
		
		else :
			self.innerCode.addCode(tempname += " := " + self.innerCode.getNodeName(rnode))
			self.innerCode.addCode(self.innerCode.getNodeName(rnode) +  " := " + self.innerCode.getNodeName(rnode) + " + " + tempnameone)
		

		return newnode
	
	elif (post_exp.left.right.name == "DEC_OP"):

		rnode = self.praser_postfix_expression(post_exp.left)

		if (rnode.type != "int"):
			self.error(post_exp.left.right.line, "-- operation can only use for int type.")

		tempname = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum=self.innerCode.tempNum+1
		newnode = self.createTempVar(tempname, "int")
		self.blockStack[-1].varMap[tempname]=newnode

		tempnameone = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum=self.innerCode.tempNum+1
		newNode = self.createTempVar(tempnameone, "int")
		self.blockStack[-1].varMap.[tempnameone]=newNode 

		self.innerCode.addCode(tempnameone + " := #1")

		
		if (rnode.useAddress) :
			self.innerCode.addCode(tempname + " := *" + rnode.name)
			self.innerCode.addCode("*" + rnode.name + " := *" + rnode.name + " - " + tempnameone)
		
		else :
			self.innerCode.addCode(tempname += " := " + self.innerCode.getNodeName(rnode))
			self.innerCode.addCode(self.innerCode.getNodeName(rnode) + " := " + self.innerCode.getNodeName(rnode) + " - " + tempnameone)
		

		return newnode


 

def praser_argument_expression_list(self,node, funcName) :
	argu_exp_list = node.left
	func = self.funcPool[funcName]
	i = 0
	while (argu_exp_list.name == "argument_expression_list") :
		rnode = self.praser_assignment_expression(argu_exp_list.right.right)

		self.innerCode.addCode(self.innerCode.createCodeforArgument(rnode))

		argu_exp_list = argu_exp_list.left
		i=i+1
		if (func.paralist[len(func.paralist) - i].type != rnode.type) :
			self.error(argu_exp_list.line, "Wrong type arguments to function " + funcName)
		
	
	rnode = self.praser_assignment_expression(argu_exp_list)
	self.innerCode.addCode(self.innerCode.createCodeforArgument(rnode))
	i=i+1
	if (func.paralist[len(func.paralist) - i].type != rnode.type) :
		self.error(argu_exp_list.line, "Wrong type arguments to function " + funcName)
	
	if (i != len(func.paralist)) :
		self.error(argu_exp_list.line, "The number of arguments doesn't equal to the function parameters number.")
	


def praser_primary_expression(self,primary_exp) :
	if (primary_exp.left.name == "IDENTIFIER") :
		content = primary_exp.left.content
		rnode = self.lookupNode(content)
		if (rnode.num < 0) :
			self.error(primary_exp.left.line, "Undefined variable " + content)
		
		return rnode
	
	elif (primary_exp.left.name == "TRUE" || primary_exp.left.name == "FALSE") :
		content = primary_exp.left.content
		tempname = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum=self.innerCode.tempNum+1
		newNode = self.createTempVar(tempname, "bool")
		self.blockStack[-1].varMap.insert[tempname]=newNode
		if(primary_exp.left.name == "TRUE") :
			self.innerCode.addCode(tempname + " := #1")
		else :
			self.innerCode.addCode(tempname + " := #0")
		
		return newNode
	
	elif (primary_exp.left.name == "CONSTANT_INT") :
		content = primary_exp.left.content
		tempname = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum=self.innerCode.tempNum+1
		
		newNode = self.createTempVar(tempname, "int")
		self.blockStack[-1].varMap.[tempname]=newNode
		self.innerCode.addCode(tempname + " := #"  + content)
		return newNode
	
	elif (primary_exp.left.name == "CONSTANT_DOUBLE") :
		content = primary_exp.left.content
		tempname = "temp" + str(self.innerCode.tempNum)
		self.innerCode.tempNum=self.innerCode.tempNum+1

		newNode = self.createTempVar(tempname, "double")

		self.blockStack[-1].varMap[tempname]=newNode
		self.innerCode.addCode(tempname + " := F" + content)
		return newNode
	
	elif (primary_exp.left.name == "(") :
		expression = primary_exp.left.right
		return self.praser_expression(expression)
	


 
def lookupVar(self,name) :
	N = range(len(self.blockStack))
	for i in reversed(N) :
		if (self.blockStack[i].varMap.has_key(name)):
			return self.blockStack[i].varMap[name].type
	
	return ""


 

def lookupCurruntVar(self,name) :
	return self.blockStack[-1].varMap.has_key(name)


 
def lookupNode(self,name) :
	N = range(len(self.blockStack))
	for i in reversed(N) :
		if (self.blockStack[i].varMap.has_key(name)):
			return self.blockStack[i].varMap[name]
	
	temp=varNode()
	temp.num = -1
	return temp
 



def getFuncRType(self) :
	N = range(len(self.blockStack))
	for i in reversed(N):
		if (self.blockStack[i].isfunc):
			return self.blockStack[i].func.rtype
	
	return ""




def getArrayType(self,name) :
	N = range(len(self.blockStack))
	for i in reversed(N):
		if (self.blockStack[i].arrayMap.has_key(name)):
			return self.blockStack[i].arrayMap[name].type
	
	return ""

def getArrayNode(self,name) :
	N = range(len(self.blockStack))
	for i in reversed(N):
		if (self.blockStack[i].arrayMap.has_key(name)):
			return self.blockStack[i].arrayMap[name]
	
	temp=arrayNode()
	temp.num = -1
	return temp


def getBreakBlockNumber(self) :
	N = range(len(self.blockStack))
	for i in reversed(N):
		if (self.blockStack[i].canBreak):
			return i
	
	return -1


def error(self,line, self.error) :

	self.print_code()

	print( "self.error! line " ,line)
	print(self.error)
	exit(1)


def createTempVar(self,name,type) :
	var=varNode()
	var.name = name
	var.type = type
	var.num = -1
	return var


def print_map(self) :
	N = range(len(self.blockStack))
	for i in reversed(N):
		print( "Block " ,i )
		for key,value in self.blockStack[i].varMap.items():
		
			print( "     " ,key ," " ,value.type)

def print_code(self) :
	self.innerCode.printCode()
 

