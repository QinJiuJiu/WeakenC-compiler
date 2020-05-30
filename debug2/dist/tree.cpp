#include "tree.h"

int count_node = 0;

string inttostr(int n)
{
    char buf[10];
    sprintf(buf, "%d", n);
    string b = buf;
    return b;
}

int strtoint(string s)
{
    int n;
    n = atoi(s.c_str());
    return n;
}

SyntaxTree *create_tree(string name, int num, ...)
{

    va_list valist;

    SyntaxTree *head = new SyntaxTree();

    if (!head)
    {

        printf("Out of space \n");

        exit(0);
    }

    head->number = count_node++;

    head->child = NULL;

    head->sibling = NULL;

    head->content = "";

    SyntaxTree *temp = NULL;

    head->name = name;

    va_start(valist, num);

    if (num > 0)
    {

        temp = va_arg(valist, SyntaxTree *);

        head->child = temp;

        head->line = temp->line;

        if (num == 1)
        {

            //head->content = temp->content;

            if (temp->content.size() > 0)
            {

                head->content = temp->content;
            }

            else
                head->content = "";
        }

        else
        {

            for (int i = 1; i < num; ++i)
            {

                temp->sibling = va_arg(valist, SyntaxTree *);

                temp = temp->sibling;
            }
        }
    }

    else
    {

        int line = va_arg(valist, int);

        head->line = line;

        if (head->name == "CONSTANT_INT")
        {

            int value;

            value = atoi(yytext); //10��������

            head->content = inttostr(value);

            //printf("%d",value);
        }

        else if (head->name == "CONSTANT_DOUBLE")
        {

            head->content = yytext;
        }

        else if (head->name == "TRUE")
        {

            head->content = inttostr(1);
        }

        else if (head->name == "FALSE")
        {

            head->content = inttostr(0);
        }

        else if (head->name == "STRING_LITERAL")
        {

            head->content = yytext;
        }

        else
        {

            head->content = yytext;
        }
    }

    return head;
}

void analysis_tree(SyntaxTree *head, int leavel)
{

    if (head != NULL)
    {

        string Name = head->name;

        if (head->line != -1)
        {

            for (int i = 0; i < leavel; ++i)
            {

                cout << ". ";
            }

            cout << head->name;

            if (head->name == "IDENTIFIER" || head->name == "BOOL" || head->name == "INT" ||

                head->name == "CHAR" || head->name == "DOUBLE")
            {

                cout << ":" << head->content;
            }

            else if (head->name == "CONSTANT_INT" || head->name == "TRUE" || head->name == "FALSE")
            {

                cout << ":" << head->content << " ";
            }

            else if (head->name == "CONSTANT_DOUBLE")
            {

                cout << ":" << head->content << " ";
            }

            else if (head->name == "STRING_LITERAL")
            {

                cout << ":" << head->content;
            }

            else
            {

                cout << " <" << head->line << ">";
            }

            cout << endl;
        }

        analysis_tree(head->child, leavel + 1);

        analysis_tree(head->sibling, leavel);
    }
}

void free_tree(SyntaxTree *node)
{

    if (node == NULL)

        return;

    free_tree(node->child);

    delete node;

    free_tree(node->sibling);
}

void write_to_file(SyntaxTree *root, string path)
{

    ofstream outfile;

    outfile.open(path);

    traverse_tree(root, outfile);

    outfile.close();
}

void traverse_tree(SyntaxTree *node, ofstream &outfile)
{

    outfile << "{";

    outfile << "\"name\":\"" << node->name << "\",";

    outfile << "\"content\":\"" << node->content << "\",";

    outfile << "\"line\":" << to_string(node->line) << ",";

    outfile << "\"children\":[";

    if (node->child)
    {

        traverse_tree(node->child, outfile);
    }

    outfile << "]";

    outfile << "}";

    if (node->sibling)
    {

        outfile << ",";

        traverse_tree(node->sibling, outfile);
    }
}

// graphivz
void print_tree(SyntaxTree *root, FILE *fp)
{
    if (root == NULL)
        return;
    if (root->child == NULL && root->sibling == NULL)
    {
        fprintf(fp, "\tnode%d[shape=plaintext, label=\"%s\", height=.3];\n",
                root->number, root->name.c_str());
    }
    if (root->child != NULL)
    {
        fprintf(fp, "\tedge[color = red];\n");
        fprintf(fp, "\tnode%d[shape=plaintext, label=\"%s\", height=.3];\n\tnode%d->node%d;\n",
                root->number, root->name.c_str(), root->number, root->child->number);
        fprintf(fp, "\tedge[color = black];\n");
    }

    if (root->sibling != NULL)
    {
        fprintf(fp, "\tnode%d[shape=plaintext, label=\"%s\", height=.3];\n\tnode%d->node%d;\n",
                root->number, root->name.c_str(), root->number, root->sibling->number);
    }

    if (root->child != NULL)
    {

        print_tree(root->child, fp);
    }
    if (root->sibling != NULL)
    {

        print_tree(root->sibling, fp);
    }

    return;
}
