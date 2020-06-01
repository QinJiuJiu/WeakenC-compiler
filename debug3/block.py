#! /usr/bin/python
# coding=utf-8
class varNode:
    def __init__(self):
        self.name = ""
        self.type = ""
        self.num = -1
        self.use_addr = False
        self.bool_exp = ""


class funcNode:
    def __init__(self):
        # self.isdefined=False
        self.name = ""
        self.re_type = ""
        self.para_list = []


class arrayNode:
    def __init__(self):
        self.name = ""
        self.type = ""
        self.num = -1


class Block:
    def __init__(self, name="", type="", num=-1):
        self.func = funcNode()
        self.is_func = False
        self.varMap = {}
        self.arrayMap = {}
        self.label_bk = ""
        self.can_bk = False

