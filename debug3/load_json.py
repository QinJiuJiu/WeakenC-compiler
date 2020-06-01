#!/usr/bin/python
# coding=utf-8
import json

from parser import Parser


class SyntaxTree:
    def __init__(self):
        self.content = ''
        self.name = ''
        self.line = -1
        self.child = self
        self.sibling = self


def creat_node(dt, total, num):
    node = SyntaxTree()

    dic = dt[num]
    node.content = dic['content']
    node.name = dic['name']
    node.line = dic['line']
    if len(dic['children']) > 0:
        node.child = creat_node(dic['children'], len(dic['children']) - 1, 0)
    else:
        node.child = None
    if num < total:
        node.sibling = creat_node(dt, total, num + 1)
    elif num == total:
        node.sibling = None
    return node


def traverse_tree(node):
    print(node.name)
    if node.child is not None:
        traverse_tree(node.child)

    if node.sibling is not None:
        traverse_tree(node.sibling)


with open("syntax-tree.json", 'r') as load_f:
    load_dict = json.load(load_f)
    root = SyntaxTree()
    root.name = load_dict['content']
    root.name = load_dict['name']
    root.line = load_dict['line']

    dt = load_dict['children']
    root.child = creat_node(dt, len(dt) - 1, 0)
    root.sibling = None

    traverse_tree(root)

    parser = Parser(root)

