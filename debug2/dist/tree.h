
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

struct gramTree
{

    string content;

    //string type;

    string name;

    int line; //���ڴ�������

    int number; //��� ����ͼƬ�õ�

    struct gramTree *left;

    struct gramTree *right;

    /* double double_value;



    int int_value;



    string string_value;*/
};

extern struct gramTree *root;

struct gramTree *create_tree(string name, int num, ...);

void eval(struct gramTree *head, int leavel);

//char* my_substring(char* s, int begin, int end);

void freeGramTree(gramTree *node);

void write_json(gramTree *root, string path);

void traverse(gramTree *node, ofstream &outfile);

void print_tree(gramTree *root, FILE *fp);

#endif
