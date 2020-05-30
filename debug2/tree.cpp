#include"tree.h"






int count_node=0;


string inttostr(int n) {
	char buf[10];
	sprintf(buf, "%d", n);
	string b = buf;
	return b;
}

int strtoint(string s) {
	int n;
	n = atoi(s.c_str());
	return n;
}

gramTree* create_tree(string name, int num,...) {



    va_list valist;



    gramTree* head = new gramTree();



    if(!head) {



        printf("Out of space \n");



        exit(0);



    }   

	head->number=count_node++;

    head->left = NULL;



    head->right = NULL;



    head->content = "";

	
	

    gramTree* temp = NULL;



    head->name = name;



    va_start(valist,num);



    if(num > 0) {



        temp = va_arg(valist,gramTree*);



        head->left = temp;



        head->line = temp->line;



        if(num == 1) {



            //head->content = temp->content;



            if(temp->content.size() > 0) {



                head->content = temp->content;



            }



            else head->content = "";



        }



        else {



            for(int i = 1; i < num; ++i ) {



                temp->right = va_arg(valist,gramTree*);



                temp = temp->right;



            }



        }



    }



    else {



        int line = va_arg(valist,int);



        head->line = line;



        if(head->name == "CONSTANT_INT") {



           int value;



            value = atoi(yytext);      //10进制整数



           head->content = inttostr(value);



           //printf("%d",value);



        }



        else if(head->name == "CONSTANT_DOUBLE") {



           head->content = yytext;



        }



        else if(head->name == "TRUE") {



           head->content = inttostr(1);



        }



        else if(head->name == "FALSE") {



           head->content = inttostr(0);



        }



        else if(head->name == "STRING_LITERAL") {



           head->content = yytext;



        }



        else {



            head->content = yytext;



        }



    



    }



    return head;



}







void eval(gramTree *head,int leavel) {



    if(head!=NULL) {



        string Name = head->name;



        if(head->line!=-1) {



            for(int i=0;i<leavel;++i) {



                cout << ". ";



            }



           cout << head->name;



        



            if(head->name == "IDENTIFIER"||head->name == "BOOL"|| head->name == "INT" || 



            head->name == "CHAR" || head->name == "DOUBLE") {



                cout << ":" << head->content;



            }



            else if(head->name == "CONSTANT_INT" || head->name == "TRUE" || head->name == "FALSE") {



                cout << ":" << head->content << " ";



            }



            else if(head->name == "CONSTANT_DOUBLE") {



                cout << ":" << head->content << " ";



            }



            else if(head->name=="STRING_LITERAL") {



                cout << ":" << head->content;



            }



            else {



                cout << " <" << head->line << ">";



            }



            cout << endl;



        }



        eval(head->left,leavel+1);



        eval(head->right,leavel);



    }



}







void freeGramTree(gramTree* node) {



	if (node == NULL)



		return;



	freeGramTree(node->left);



	delete node;



	freeGramTree(node->right);



}









void write_json(gramTree* root,string path){

    ofstream outfile;

    outfile.open(path);

    traverse(root, outfile);

    outfile.close();

}





void traverse(gramTree* node, ofstream &outfile){

    outfile << "{";

    outfile << "\"name\":\"" << node->name << "\",";

    outfile << "\"content\":\"" << node->content << "\",";

    outfile << "\"line\":" << to_string(node->line) << ",";

   

    outfile << "\"children\":[";

    if(node->left){

        traverse(node->left, outfile);

    }

    outfile << "]";

    outfile << "}";

    if(node->right){

        outfile << ",";

        traverse(node->right, outfile);

    }

}


// graphivz
void print_tree(gramTree *root,FILE *fp) {
	if(root==NULL) return;
	if(root->left==NULL&&root->right==NULL){
		fprintf(fp, "\tnode%d[shape=plaintext, label=\"%s\", height=.3];\n",
			root->number, root->name.c_str());
	}
	if(root->left!=NULL){
		fprintf(fp, "\tedge[color = red];\n");
		fprintf(fp, "\tnode%d[shape=plaintext, label=\"%s\", height=.3];\n\tnode%d->node%d;\n",
                root->number, root->name.c_str(),root->number, root->left->number);
		fprintf(fp, "\tedge[color = black];\n");
	}		
	
	if(root->right!=NULL){
		fprintf(fp, "\tnode%d[shape=plaintext, label=\"%s\", height=.3];\n\tnode%d->node%d;\n",
                root->number, root->name.c_str(),root->number, root->right->number);
	}		

    if (root->left != NULL) {
        
        print_tree(root->left, fp);
    }
    if (root->right != NULL) {
        
        print_tree(root->right, fp);
    }

    return;
}


