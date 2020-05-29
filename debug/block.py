#! /usr/bin/python
# coding=utf-8
class varNode:
	  def __init__(self):
		self.name = ""
		self.type = ""
		self.num=-1
		self.useAddress=False
		self.boolString=""
        

class funcNode:
	def __init__(self):
		self.isdefined=False
		self.name=""
		self.rtype=""
		self.paralist=[]
		

class arrayNode:
	def __init__(self ):
		self.name = ""
		self.type = ""
		self.num=-1
	

class Block:
	def __init__(self, name="", type="", num=-1 ):
		self.func = funcNode()
		self.isfunc=False 
		self.varMap={}
		self.arrayMap={}
		self.breakLabelname=""
		self.canBreak=False


