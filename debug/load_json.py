#!/usr/bin/python
# coding=utf-8
import json

from parser import Praser

class gramTree:
    def __init__(self):
        self.content = ''
        self.name = ''
        self.line = -1
        self.left = self
        self.right = self


def creat_node(dt, total, num):
    node = gramTree()

    dic = dt[num]
    node.name = dic['content']
    node.name = dic['name']
    node.line = dic['line']
    if len(dic['children']) > 0:
        node.left = creat_node(dic['children'], len(dic['children']) - 1, 0)
    else:
        node.left = None
    if num < total:
        node.right = creat_node(dt, total, num + 1)
    elif num == total:
        node.right = None
    return node


def traverse(node):
    print(node.name)
    if node.left is not None:
        traverse(node.left)

    if node.right is not None:
        traverse(node.right)




with open("syntax-tree.json", 'r') as load_f:
    load_dict = json.load(load_f)
    root = gramTree()
    root.name = load_dict['content']
    root.name = load_dict['name']
    root.line = load_dict['line']

    dt = load_dict['children']
    root.left = creat_node(dt, len(dt) - 1, 0)
    root.right = None

    traverse(root)

    parser=Praser(root)




