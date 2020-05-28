class Message:
	def __init__(self):
		self.line = -1
		self.num = 0
		


class Optimize:
	def __init__(self,codelist):
		self.codelist = codelist
		self.tempMessage = {}
		self.num=-1
		self.establishMap(self.codelist)
		self.dropTrumpTemp(self.codelist)
	
	
	def getCodeList(self):
		return self.codelist

	def establishMap(self) :
		for i in range (len(self.codelist)):
			str = self.codelist[i]
			begin = 0
			w = str.find("temp", begin)
			while (w != 4294967295) :

				end = str.find(" ", w)
				name = str[w : end - w]

				if (self.tempMessage.has_key(name)) :
					if (str.find("CALL") != 4294967295)
						self.tempMessage[name].num += 1000
					self.tempMessage[name].num=self.tempMessage[name].num+1
			
				else :
					m=Message()
					m.line = i
					m.num = 1
					if (str.find("CALL") != 4294967295):
						m.num += 1000
					self.tempMessage[name]=m
			
				begin = end
				w = str.find("temp", begin)


	def dropTrumpTemp(self) :
		lines=set()
		
		for value in self.tempMessage.values():
			if(value.num==1):
				lines.add(value.line)
		
		for i in range (len(self.codelist)):

			if (i in lines) ==False :
				self.codelist.append(self.codelist[i])
 