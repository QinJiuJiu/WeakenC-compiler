
#ifndef _TREE_H_

#define _TREE_H_

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cstdarg>

#include <iostream>

#include <fstream>

#include <string>

extern char *yytext;

extern int yylineno; //�ṩ��ǰ������Ϣ

using namespace std;

struct SyntaxTree
{

    string content;

    string name;

    int line; //���ڴ�������

    int number; //��� ����ͼƬ�õ�

    struct SyntaxTree *child;

    struct SyntaxTree *sibling;

};

extern struct SyntaxTree *root;

struct SyntaxTree *create_tree(string name, int num, ...);

void free_tree(SyntaxTree *node);

void print_tree(SyntaxTree *root, FILE *fp);

void analysis_tree(struct SyntaxTree *head, int leavel);

void traverse_tree(SyntaxTree *node, ofstream &outfile);

void write_to_file(SyntaxTree *root, string path);


#endif
