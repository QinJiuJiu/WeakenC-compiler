%{

#include <cstdlib>

#include <cstdio>

#include <string>

#include<fstream>

#include "tree.h"

using namespace std;

extern char *yytext;

extern int column;

extern FILE * yyin;

extern FILE * yyout;

SyntaxTree *root;

extern int yylineno;

FILE * fp;

int yylex(void);

void yyerror(const char*); 

%}

%union{

    struct SyntaxTree* gt;

}



%token <gt> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF CONSTANT_INT CONSTANT_DOUBLE

%token <gt> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP

%token <gt> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN

%token <gt> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN

%token <gt> XOR_ASSIGN OR_ASSIGN TYPE_NAME


%token <gt> CHAR INT DOUBLE VOID BOOL 


%token <gt> IF ELSE  WHILE DO FOR  CONTINUE BREAK RETURN


%token <gt> TRUE FALSE


%token <gt> ';' ',' ':' '=' '[' ']' '.' '&' '!' '~' '-' '+' '*' '/' '%' '<' '>' '^' '|' '?' '{' '}' '(' ')'

%type <gt> basic_expression postfix_expression argument_expression_list monocular_expression monocular_operator

%type <gt> muldiv_expression addsub_expression shift_expression compare_expression equaljudge_expression

%type <gt> and_expression xor_expression bitwise_or_expression logical_and_expression logical_or_expression

%type <gt> assignment_expression assignment_operator expression

%type <gt> declaration init_declarator_list init_declarator type_definition

%type <gt> declarator 

%type <gt> parameter_list parameter_declaration identifier_list

%type <gt> abstract_declarator initializer initializer_list designation designator_list

%type <gt> designator statement compound_statement block_item_list block_item expression_statement

%type <gt> selection_statement iteration_statement jump_statement translation_unit external_declaration function_definition

%type <gt> declaration_list



%nonassoc LOWER_THAN_ELSE

%nonassoc ELSE

%%


Program: 


    translation_unit {



        root = create_tree("Program",1,$1);



    }



    ;





basic_expression: 



    IDENTIFIER {



        $$ = create_tree("basic_expression",1,$1);



    }



    |



    TRUE {



        $$ = create_tree("basic_expression",1,$1);



    }



    |



    FALSE {



        $$ = create_tree("basic_expression",1,$1);



    }



    | CONSTANT_INT {





        $$ = create_tree("basic_expression",1,$1);



        



    }



    | CONSTANT_DOUBLE {



        $$ = create_tree("basic_expression",1,$1);




    }



    | '(' expression ')'{



        $$ = create_tree("basic_expression",3,$1,$2,$3);



    }



    ;




postfix_expression:



    basic_expression{



        $$ = create_tree("postfix_expression",1,$1);



    }



    |   postfix_expression '[' expression ']'{



        $$ = create_tree("postfix_expression",4,$1,$2,$3,$4);




    }



    |   postfix_expression '(' ')'{



        $$ = create_tree("postfix_expression",3,$1,$2,$3);



    }



    |   postfix_expression '(' argument_expression_list ')'{



        $$ = create_tree("postfix_expression",4,$1,$2,$3,$4);




    }



    |   postfix_expression INC_OP{






        $$ = create_tree("postfix_expression",2,$1,$2);



    }



    |   postfix_expression DEC_OP{




        $$ = create_tree("postfix_expression",2,$1,$2);



    }



    ;







argument_expression_list:



    assignment_expression{



        $$ = create_tree("argument_expression_list",1,$1);



    }



    |   argument_expression_list ',' assignment_expression {



        $$ = create_tree("argument_expression_list",3,$1,$2,$3);



    }



    ;








monocular_expression:



    postfix_expression{




        $$ = create_tree("monocular_expression",1,$1);



    }



    |   INC_OP monocular_expression{







        $$ = create_tree("monocular_expression",2,$1,$2);



    }



    |   DEC_OP monocular_expression{





        $$ = create_tree("monocular_expression",2,$1,$2);



    }



    |   monocular_operator monocular_expression{



        $$ = create_tree("monocular_expression",2,$1,$2);



    }



    ;



monocular_operator:



    '+' {



        $$ = create_tree("monocular_operator",1,$1);



    }



    | '-' {



        $$ = create_tree("monocular_operator",1,$1);



    }



    | '~' {



        $$ = create_tree("monocular_operator",1,$1);



    }



    | '!' {



        $$ = create_tree("monocular_operator",1,$1);



    }



    ;




muldiv_expression:



    monocular_expression {



        $$ = create_tree("muldiv_expression",1,$1);



    }



    | muldiv_expression '*' monocular_expression {



        $$ = create_tree("muldiv_expression",3,$1,$2,$3);



    }



    | muldiv_expression '/' monocular_expression {



        $$ = create_tree("muldiv_expression",3,$1,$2,$3);



    }



    | muldiv_expression '%' monocular_expression {



        $$ = create_tree("muldiv_expression",3,$1,$2,$3);



    }



    ;





addsub_expression:



    muldiv_expression  {



        $$ = create_tree("addsub_expression",1,$1);



    }



    | addsub_expression '+' muldiv_expression {



        $$ = create_tree("addsub_expression",3,$1,$2,$3);



    }



    | addsub_expression '-' muldiv_expression {



        $$ = create_tree("addsub_expression",3,$1,$2,$3);



    }



    ;



shift_expression:



    addsub_expression {



        $$ = create_tree("shift_expression",1,$1);



    }



    | shift_expression LEFT_OP addsub_expression {




        $$ = create_tree("shift_expression",3,$1,$2,$3);



    }



    | shift_expression RIGHT_OP addsub_expression {





        $$ = create_tree("shift_expression",3,$1,$2,$3);



    }



    ;





compare_expression:



    shift_expression {



        $$ = create_tree("compare_expression",1,$1);



    }



    | compare_expression '<' shift_expression {



        $$ = create_tree("compare_expression",3,$1,$2,$3);



    }



    | compare_expression '>' shift_expression {



        $$ = create_tree("compare_expression",3,$1,$2,$3);



    }



    | compare_expression LE_OP shift_expression {





        $$ = create_tree("compare_expression",3,$1,$2,$3);



    }



    | compare_expression GE_OP shift_expression {






        $$ = create_tree("compare_expression",3,$1,$2,$3);



    }



    ;





equaljudge_expression:



    compare_expression {



        $$ = create_tree("equaljudge_expression",1,$1);



    }



    | equaljudge_expression EQ_OP compare_expression {






        $$ = create_tree("equaljudge_expression",3,$1,$2,$3);



    }



    | equaljudge_expression NE_OP compare_expression {





        $$ = create_tree("equaljudge_expression",3,$1,$2,$3);



    }



    ;







and_expression:



    equaljudge_expression {



        $$ = create_tree("and_expression",1,$1);



    }



    | and_expression '&' equaljudge_expression {



        $$ = create_tree("and_expression",3,$1,$2,$3);



    }



    ;





xor_expression:



    and_expression {



        $$ = create_tree("xor_expression",1,$1);



    }



    | xor_expression '^' and_expression {



        $$ = create_tree("xor_expression",3,$1,$2,$3);



    }



    ;






bitwise_or_expression:



    xor_expression {



        $$ = create_tree("bitwise_or_expression",1,$1);



    }



    | bitwise_or_expression '|' xor_expression {



        $$ = create_tree("bitwise_or_expression",3,$1,$2,$3);



    }



    ;







logical_and_expression:



    bitwise_or_expression {



        $$ = create_tree("logical_and_expression",1,$1);



    }



    | logical_and_expression AND_OP bitwise_or_expression {






        $$ = create_tree("logical_and_expression",3,$1,$2,$3);



    }



    ;




logical_or_expression:



    logical_and_expression {



        $$ = create_tree("logical_or_expression",1,$1);



    }



    | logical_or_expression OR_OP logical_and_expression {





        $$ = create_tree("logical_or_expression",3,$1,$2,$3);



    }



    ;







assignment_expression:



    logical_or_expression {






        $$ = create_tree("assignment_expression",1,$1);



    }



    | monocular_expression assignment_operator assignment_expression {



        $$ = create_tree("assignment_expression",3,$1,$2,$3);



    }



    ;






assignment_operator:



    '=' {



        $$ = create_tree("assignment_operator",1,$1);



    }



    | MUL_ASSIGN {




        $$ = create_tree("assignment_operator",1,$1);



    }



    | DIV_ASSIGN {




        $$ = create_tree("assignment_operator",1,$1);



    }



    | MOD_ASSIGN {





        $$ = create_tree("assignment_operator",1,$1);



    }



    | ADD_ASSIGN {






        $$ = create_tree("assignment_operator",1,$1);



    }



    | SUB_ASSIGN {





        $$ = create_tree("assignment_operator",1,$1);



    }



    | LEFT_ASSIGN {






        $$ = create_tree("assignment_operator",1,$1);



    }



    | RIGHT_ASSIGN {






        $$ = create_tree("assignment_operator",1,$1);



    }



    | AND_ASSIGN {




        $$ = create_tree("assignment_operator",1,$1);



    }



    | XOR_ASSIGN {





        $$ = create_tree("assignment_operator",1,$1);



    }



    | OR_ASSIGN {





        $$ = create_tree("assignment_operator",1,$1);



    }



    ;







expression:



    assignment_expression {





        $$ = create_tree("expression",1,$1);



    }



    | expression ',' assignment_expression {




        $$ = create_tree("expression",3,$1,$2,$3);



    }



    ;











declaration:



    type_definition ';' {



        $$ = create_tree("declaration",2,$1,$2); //?



    }



    | type_definition init_declarator_list ';' {



        $$ = create_tree("declaration",3,$1,$2,$3);



    }



    ;











init_declarator_list:



    init_declarator {



        $$ = create_tree("init_declarator_list",1,$1);



    }



    | init_declarator_list ',' init_declarator {



        $$ = create_tree("init_declarator_list",3,$1,$2,$3);



    }



    ;







init_declarator:



    declarator {



        $$ = create_tree("init_declarator",1,$1);



    }



    | declarator '=' initializer {



        $$ = create_tree("init_declarator",3,$1,$2,$3);



    }



    ;













type_definition:



    VOID {



        $$ = create_tree("type_definition",1,$1);



    }



    | CHAR {



        $$ = create_tree("type_definition",1,$1);



    }



    | INT {



        $$ = create_tree("type_definition",1,$1);



    }



    | DOUBLE {



        $$ = create_tree("type_definition",1,$1);    



    }



    | BOOL {



        $$ = create_tree("type_definition",1,$1);



    }



    ;















declarator:



    IDENTIFIER {



      


        $$ = create_tree("declarator",1,$1);



    }



    | '(' declarator ')' {



        


        $$ = create_tree("declarator",3,$1,$2,$3);



    }



    | declarator '[' assignment_expression ']' {





        $$ = create_tree("declarator",4,$1,$2,$3,$4);



    }



    | declarator '[' '*' ']' {





        $$ = create_tree("declarator",4,$1,$2,$3,$4);



    }



    | declarator '[' ']' {





        $$ = create_tree("declarator",3,$1,$2,$3);



    }



    | declarator '(' parameter_list ')' {






        $$ = create_tree("declarator",4,$1,$2,$3,$4);



    }



    | declarator '(' identifier_list ')' {






        $$ = create_tree("declarator",4,$1,$2,$3,$4);



    }



    | declarator '(' ')' {



  


        $$ = create_tree("declarator",3,$1,$2,$3);



    }



    ;






parameter_list:



    parameter_declaration {



        $$ = create_tree("parameter_list",1,$1);



    }



    | parameter_list ',' parameter_declaration {



        $$ = create_tree("parameter_list",3,$1,$2,$3);



    }



    ;







parameter_declaration:



    type_definition declarator {



        $$ = create_tree("parameter_declaration",2,$1,$2);



    }



    | type_definition abstract_declarator {



        $$ = create_tree("parameter_declaration",2,$1,$2);



    }



    | type_definition {



        $$ = create_tree("parameter_declaration",1,$1);



    }



    ;







identifier_list:



    IDENTIFIER {



        $$ = create_tree("identifier_list",1,$1);



    }



    | identifier_list ',' IDENTIFIER {



        $$ = create_tree("identifier_list",3,$1,$2,$3);



    }



    ;







abstract_declarator:



    '(' abstract_declarator ')' {



        $$ = create_tree("abstract_declarator",3,$1,$2,$3);



    }



    | '[' ']' {



        $$ = create_tree("abstract_declarator",2,$1,$2);



    }



    | '[' assignment_expression ']' {



        $$ = create_tree("abstract_declarator",3,$1,$2,$3);



    }



    | abstract_declarator '[' ']' {



        $$ = create_tree("abstract_declarator",3,$1,$2,$3);



    }



    | abstract_declarator '[' assignment_expression ']' {



        $$ = create_tree("abstract_declarator",4,$1,$2,$3,$4);



    }



    | '[' '*' ']' {



        $$ = create_tree("abstract_declarator",3,$1,$2,$3);



    }



    | abstract_declarator '[' '*' ']' {



        $$ = create_tree("abstract_declarator",4,$1,$2,$3,$4);



    }



    | '(' ')' {



        $$ = create_tree("abstract_declarator",2,$1,$2);



    }



    | '(' parameter_list ')' {



        $$ = create_tree("abstract_declarator",3,$1,$2,$3);



    }



    | abstract_declarator '(' ')' {



        $$ = create_tree("abstract_declarator",3,$1,$2,$3);



    }



    | abstract_declarator '(' parameter_list ')' {



        $$ = create_tree("abstract_declarator",4,$1,$2,$3,$4);



    }



    ;







initializer:



    assignment_expression {



        $$ = create_tree("initializer",1,$1);



    }



    | '{' initializer_list '}' {






        $$ = create_tree("initializer",3,$1,$2,$3);



    }



    | '{' initializer_list ',' '}' {






        $$ = create_tree("initializer",4,$1,$2,$3,$4);



    }



    ;







initializer_list:



    initializer {



        $$ = create_tree("initializer_list",1,$1);



    }



    | designation initializer {



        $$ = create_tree("initializer_list",2,$1,$2);



    }



    | initializer_list ',' initializer {



        $$ = create_tree("initializer_list",3,$1,$2,$3);



    }



    | initializer_list ',' designation initializer {



        $$ = create_tree("initializer_list",3,$1,$2,$3);



    }



    ;







designation:



    designator_list '=' {



        $$ = create_tree("designation",2,$1,$2);



    }



    ;







designator_list:



    designator {



        $$ = create_tree("designator_list",1,$1);



    }



    | designator_list designator {



        $$ = create_tree("designator_list",2,$1,$2);



    }



    ;







designator: 



    '[' logical_or_expression ']' {



        $$ = create_tree("designator",3,$1,$2,$3);



    }



    | '.' IDENTIFIER {



        $$ = create_tree("designator",2,$1,$2);



    }



    ;







//声明



statement:



    compound_statement {



        $$ = create_tree("statement",1,$1);



    }



    | expression_statement{



        $$ = create_tree("statement",1,$1);



    }



    | selection_statement {



        $$ = create_tree("statement",1,$1);



    }



    | iteration_statement {



        $$ = create_tree("statement",1,$1);



    }



    | jump_statement {



        $$ = create_tree("statement",1,$1);



    }



    ;






compound_statement:



    '{' '}' {



        $$ = create_tree("compound_statement",2,$1,$2);



    }



    | '{' block_item_list '}' {



        $$ = create_tree("compound_statement",3,$1,$2,$3);



    }



    ;







block_item_list:



    block_item {



        $$ = create_tree("block_item_list",1,$1);



    }



    | block_item_list block_item {



        $$ = create_tree("block_item_list",2,$1,$2);



    }



    ;







block_item:



    declaration {



        $$ = create_tree("block_item",1,$1);



    }



    | statement {



        $$ = create_tree("block_item",1,$1);



    }



    ;







expression_statement:



    ';' {



        $$ = create_tree("expression_statement",1,$1);



    }



    | expression ';' {



        $$ = create_tree("expression_statement",2,$1,$2);



    }



    ;





selection_statement:



    IF '(' expression ')' statement %prec LOWER_THAN_ELSE {



        $$ = create_tree("selection_statement",5,$1,$2,$3,$4,$5);



    }



    | IF '(' expression ')' statement ELSE statement {



        $$ = create_tree("selection_statement",7,$1,$2,$3,$4,$5,$6,$7);



    }



   



    ;







iteration_statement:



    WHILE '(' expression ')' statement {



        $$ = create_tree("iteration_statement",5,$1,$2,$3,$4,$5);



    }



    | DO statement WHILE '(' expression ')' ';' {



        $$ = create_tree("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);



    }



    | FOR '(' expression_statement expression_statement ')' statement {



        $$ = create_tree("iteration_statement",6,$1,$2,$3,$4,$5,$6);



    }



    | FOR '(' expression_statement expression_statement expression ')' statement {



        $$ = create_tree("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);



    }



    | FOR '(' declaration expression_statement ')' statement {



        $$ = create_tree("iteration_statement",6,$1,$2,$3,$4,$5,$6);



    }



    | FOR '(' declaration expression_statement expression ')' statement {



        $$ = create_tree("iteration_statement",7,$1,$2,$3,$4,$5,$6,$7);



    }



    ;





jump_statement:


    CONTINUE ';' {



        $$ = create_tree("jump_statement",2,$1,$2);



    }



    | BREAK ';' {



        $$ = create_tree("jump_statement",2,$1,$2);



    }



    | RETURN ';' {



        $$ = create_tree("jump_statement",2,$1,$2);



    }



    | RETURN expression ';' {



        $$ = create_tree("jump_statement",3,$1,$2,$3);



    }



    ;







translation_unit:



    external_declaration {



        $$ = create_tree("translation_unit",1,$1);



    }



    | translation_unit external_declaration {



        $$ = create_tree("translation_unit",2,$1,$2);



    }



    ;







external_declaration:



    function_definition {



        $$ = create_tree("external_declaration",1,$1);




    }



    | declaration {



        $$ = create_tree("external_declaration",1,$1);



    }



    ;







function_definition:



    type_definition declarator declaration_list compound_statement {



        $$ = create_tree("function_definition",4,$1,$2,$3,$4);



    }



    | type_definition declarator compound_statement {



        $$ = create_tree("function_definition",3,$1,$2,$3);



    }



    ;







declaration_list:



    declaration {



        $$ = create_tree("declaration_list",1,$1);



    }



    | declaration_list declaration {



        $$ = create_tree("declaration_list",2,$1,$2);



    }



    ;







%%











void yyerror(char const *s)



{



    fflush(stdout);



    printf("\n%*s\n%*s\n", column, "^", column, s);



}











int main(int argc,char* argv[]) {







    yyin = fopen(argv[1],"r");



    yyparse();



    printf("\n");



    analysis_tree(root,0);   //输出语法分析树



    write_to_file(root,"syntax-tree.json");

    

    //graphivz

    fp = fopen("ir_tree.dot", "w");

    fprintf(fp, "digraph G{\n");

    print_tree(root,fp);

    fprintf(fp, "}\n");

    fclose(fp);


    free_tree(root);







    fclose(yyin);



    return 0;



}
