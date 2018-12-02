
/*parser.y
 *
 *bison�����ļ������ڲ���parser
 *
 *pp2:�������ֻ�����parser�Ĺ�Լ��������ֻ��Ҫ��֤�����ļ��Ƿ����
 *decaf���Ե��ķ������ѹ�Լ���������
 *
*/
%{

/*
 *ͬflexһ������һ��%{ %}�ڲ��ĳ��򽫱�ֱ��copy��parser_tab.h/c��
 *���Կ��Խ�Ҫinclude��ͷ�ļ���ȫ�ֱ����ŵ������
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <process.h>	
#include "scanner.h"

%}

/*
 *�����������Զ���tokens,types,precedence �� associativity�ȡ�
*/

/*
 *��program��ʼ��Լ
*/
%start Program

/*
 *yylval
 *------
 *�������ȫ�ֱ���yylval�����������Լ��ķ��ս����
*/

/*Tokens
 *------
 *������Ǹ���bison��Ҫ�õ���token���͡�
 *bison���Ը���Щ���Ͷ���Ψһ�����ֲ����#define ��parser_tab.h�ļ��С�
*/
%token T_Void T_Bool T_Int T_Double T_String T_Class 
%token T_LessEqual T_GreaterEqual T_Equal T_NotEqual
%token T_And T_Or T_Null T_Extends T_This
%token T_While T_For T_If T_Else T_Return
%token T_Identifier
%token T_StringConstant T_IntConstant T_DoubleConstant T_BoolConstant
%token T_New T_NewArray T_Print T_ReadInteger T_ReadLine

%token T_PostPlus T_PostMinus
%token T_Switch T_Case T_Default T_Break

%nonassoc Lower_Than_Else
%nonassoc T_Else

%nonassoc '='
%left T_Or
%left T_And
%left T_Equal T_NotEqual
%nonassoc '<' T_LessEqual '>' T_GreaterEqual
%left '+' '-'
%left '*' '/' '%'
%left T_PostPlus T_PostMinus '!' UMINUS // unary -
%left '[' '.'

%union {			/*bison���Դ���������в���yylval�Ķ���*/
  int integerConstant;
  int boolConstant;
  const char *stringConstant;
  double doubleConstant;
  char identifier[128];
}


/*Precedence and Associativity
 *----------------------------
 *����������ȼ��ͽ����
 *Note: NO SPACE between % and nonassoc, left, right!!!!!
*/

%%
/*
 *�����д����Ĺ���Ͷ���
*/

	Program      :  DeclList { printf("Program -> DeclList\n"); @1}
                          // pp2: don't remove @1 symbol above!!
                          // It is necessary to trick yacc into
                          // maintaining the yylloc stack
             ;  

DeclList     :  DeclList Decl 	{ printf("DeclList -> DeclList Decl\n"); }
             |  				{ printf("DeclList ->\n"); }
             ;

 
Decl         :	VariableDecl 	{ printf("Decl -> VariableDecl\n"); }
			 |	ClassDefn 		{ printf("Decl -> ClassDefn\n"); }
			 |  FunctionDefn 	{ printf("Decl -> FunctionDefn\n"); }
			 |  FunctionDecl 	{ printf("Decl -> FunctionDecl\n"); }
             ;

VariableDecl :	Variable ';' { printf("VariableDecl -> Variable ;\n"); }
			 //|	error ';'	 { printf("VariableDecl -> error ;\n"); }
			 ;
			 
Variable	 :	Type T_Identifier { printf("Variable -> Type identifier\n"); }
			 ;
			 
Type		 :	T_Int 					{ printf("Type -> int\n"); }
			 |	T_Double 				{ printf("Type -> double\n"); }
			 |	T_Bool 					{ printf("Type -> bool\n"); }
			 |	T_String 				{ printf("Type -> string\n"); }
			 |	T_Void 					{ printf("Type -> void\n"); }			 
			 |	T_Class T_Identifier 	{ printf("Type -> class identifier\n"); }
			 |	Type '[' ']' 			{ printf("Type -> Type [ ]\n"); }
			 ;

FunctionDecl :	Type T_Identifier '(' Formals ')' ';' { printf("FunctionDecl -> Type identifier ( Formals ) ;\n") }
			 ;

Formals		 :	VariableList 	{ printf("Formals -> VariableList\n"); }
			 |					{ printf("Formals ->\n"); }
			 ;
			 
VariableList :	VariableList ',' Variable 	{ printf("VariableList -> VariableList , Variable\n"); }
			 |	Variable 					{ printf("VariableList -> Variable\n"); }
			 ;
			 
FunctionDefn :	Type T_Identifier '(' Formals ')' StmtBlock { printf("FunctionDefn -> Type identifier ( Formals ) StmtBlock\n"); }
			 //|	error '}'									{ printf("FunctionDefn -> error }\n"); }
			 ;
ClassDefn	 :	T_Class T_Identifier OptExtends '{' FieldList '}' { printf("ClassDefn -> class identifier OptExtends { FieldList }\n"); }
			 ;
			 
OptExtends	 :	T_Extends T_Identifier 	{ printf("OptExtends -> extends identifier\n"); }
			 |							{ printf("OptExtends ->\n"); }
			 ;
			 
FieldList	 :	FieldList Field { printf("FieldList -> FieldList Field\n"); }
			 |					{ printf("FieldList ->\n"); }
			 ;
			 
Field		 :	VariableDecl { printf("Field -> VariableDecl\n"); }
			 |	FunctionDecl { printf("Field -> FunctionDecl\n"); }
			 |	FunctionDefn { printf("Field -> FunctionDefn\n"); }
			 ;
			 
StmtBlock	 :	'{' StmtList '}' { printf("StmtBlock -> { StmtList }\n"); }
			 ;
			 
StmtList	 :	StmtList Stmt 	{ printf("StmtList -> StmtList Stmt\n"); }
			 |					{ printf("StmtList ->\n"); }
			 ;
			 
Stmt		 :	VariableDecl 	{ printf("Stmt -> VariableDecl\n"); }
			 |	SimpleStmt ';' 	{ printf("Stmt -> SimpleStmt ;\n"); }
			 |	IfStmt 			{ printf("Stmt -> IfStmt\n"); }
			 |	WhileStmt 		{ printf("Stmt -> WhileStmt\n"); }
			 |	ForStmt 		{ printf("Stmt -> ForStmt\n"); }
			 |	SwitchStmt		{ printf("Stmt -> SwitchStmt\n"); }
			 |	ReturnStmt ';' 	{ printf("Stmt -> ReturnStmt ;\n"); }
			 |	PrintStmt ';' 	{ printf("Stmt -> PrintStmt ;\n"); }
			 |	StmtBlock 		{ printf("Stmt -> StmtBlock\n"); }
			 |	BreakStmt ';'	{ printf("Stmt -> BreakStmt ;\n"); }
			 //|	error ';'		{ printf("Stmt -> error ;\n"); }
			 ;
SimpleStmt	 :	LValue '=' Expr { printf("SimpleStmt -> LValue = Expr\n"); }
			 |	Expr 			{ printf("SimpleStmt -> Expr\n"); }
			 |					{ printf("SimpleStmt ->\n"); }
			 ;
			 
LValue		 :	OptReceiver T_Identifier 				{ printf("LValue -> OptReceiver identifier\n"); }
			 |	Expr '[' Expr ']' 						{ printf("LValue -> Expr [ Expr ]\n"); }
			 ;
			 
OptReceiver	 :	Expr '.' 	{ printf("OptReceiver -> Expr .\n"); }
			 |				{ printf("OptReceiver ->\n"); }
			 ;
			 
Call		 :	OptReceiver T_Identifier '(' Actuals ')' { printf("Call -> OptReceiver identifier ( Actuals )\n"); }
			 ;

Actuals		 :	ExprList 	{ printf("Actuals -> ExprList\n"); }
			 |				{ printf("Actuals ->\n"); }
			 ;

ExprList	 :	ExprList ',' Expr 	{ printf("ExprList -> ExprList , Expr\n"); }
			 |	Expr 				{ printf("ExprList -> Expr\n"); }
			 ;

ForStmt		 :	T_For '(' SimpleStmt';' BoolExpr';' SimpleStmt')' Stmt { printf("ForStmt -> for ( SimpleStmt; BoolExpr; SimpleStmt) Stmt\n"); }
			 ;
			 
WhileStmt	 :	T_While	'(' BoolExpr ')' Stmt { printf("WhileStmt -> while ( BoolExpr ) Stmt\n"); }
			 ;

IfStmt		 :	T_If '(' BoolExpr ')' Stmt OptElse { printf("IfStmt -> if ( BoolExpr ) Stmt OptElse\n"); }
			 ;
			 
OptElse		 :	T_Else Stmt 			{ printf("OptElse -> else Stmt\n"); }
			 |	%prec Lower_Than_Else	{ printf("OptElse ->\n"); }
			 ;

SwitchStmt	 :	T_Switch '(' Expr ')' '{' CaseStmt CaseList DefaultStmt '}' { printf("SwitchStmt -> switch ( Expr ) { CaseStmt CaseList Default }\n"); }
			 ;

CaseList	 :	CaseList CaseStmt { printf("CaseList -> CaseList CaseStmt\n"); }
			 |					  { printf("CaseList ->\n");}
			 ;
			 
CaseStmt	 :	T_Case T_IntConstant ':' StmtList { printf("CaseStmt -> case intConstant : StmtList\n"); }
			 ;
			 
DefaultStmt	 :	T_Default ':' StmtList { printf("DefaultStmt -> default : StmtList\n"); }
			 |				  		   { printf("DefaultStmt ->\n"); }
			 ;

BreakStmt	 :	T_Break { printf("BreakStmt -> break\n"); }
			 ;
			 
ReturnStmt	 :	T_Return 		{ printf("ReturnStmt -> return\n"); }
			 |	T_Return Expr 	{ printf("ReturnStmt -> return Expr\n"); }
			 ;

PrintStmt	 :	T_Print '(' ExprList ')' { printf("PrintStmt -> Print ( ExprList )\n"); }
			 ;
			 
BoolExpr	 :	Expr { printf("BoolExpr -> Expr\n"); }
			 ;
			 
Expr		 :	Constant 							{ printf("Expr -> Constant\n"); }
			 |	LValue 								{ printf("Expr -> LValue\n"); }	
			 |	LValue T_PostPlus					{ printf("Expr -> LValue ++\n"); }	
			 |	LValue T_PostMinus					{ printf("Expr -> LValue --\n"); }		 			 			 			 			 			 
			 |	T_This 								{ printf("Expr -> this\n"); }			 			 			 			 
			 |	Call 								{ printf("Expr -> Call\n"); }			 			 			 			 
			 |	'(' Expr ')' 						{ printf("Expr -> ( Expr )\n");}			 			 			 			 
			 |	Expr '+' Expr 						{ printf("Expr -> Expr + Expr\n"); }			 			 			 			 
			 |	Expr '-' Expr 						{ printf("Expr -> Expr - Expr\n"); }			 			 			 			 
			 |	Expr '*' Expr 						{ printf("Expr -> Expr * Expr\n"); }			 			 			 			 
			 |	Expr '/' Expr 						{ printf("Expr -> Expr / Expr\n"); }			 			 			 			 
			 |	Expr '%' Expr 						{ printf("Expr -> Expr %% Expr\n"); }			 			 			 			 
			 |	'-' Expr 			%prec  UMINUS	{ printf("Expr -> - Expr\n"); }			 			 			 
			 |	Expr '<' Expr 						{ printf("Expr -> Expr < Expr\n"); }			 			 			 			 
			 |	Expr T_LessEqual Expr 				{ printf("Expr -> Expr <= Expr\n"); }			 			 			 			 
			 |	Expr '>' Expr 						{ printf("Expr -> Expr > Expr\n"); }			 			 			 			 
			 |	Expr T_GreaterEqual Expr 			{ printf("Expr -> Expr >= Expr\n"); }			 			 			 			 
			 |	Expr T_Equal Expr 					{ printf("Expr -> Expr == Expr\n"); }			 			 			 			 
			 |	Expr T_NotEqual Expr 				{ printf("Expr -> Expr != Expr\n"); }			 			 			 			 
			 |	Expr T_And Expr 					{ printf("Expr -> Expr && Expr\n"); }			 			 			 			 
			 |	Expr T_Or Expr 						{ printf("Expr -> Expr || Expr\n"); }			 			 			 			 
			 |	'!' Expr 							{ printf("Expr -> ! Expr\n"); }			 			 			 			 
			 |	T_ReadInteger '(' ')' 				{ printf("Expr -> ReadInteger ( )\n"); }			 			 			 			 
			 |	T_ReadLine '(' ')' 					{ printf("Expr -> ReadLine ( )\n"); }			 			 			 			 
			 |	T_New '(' T_Identifier ')' 			{ printf("Expr -> New ( identifier )\n"); }			 			 			 			 
			 |	T_NewArray '(' Expr ',' Type ')' 	{ printf("Expr -> NewArray ( Expr , Type )\n"); }			 			 			 			 
			 ;		 			 			 			 
			 
Constant	 :	T_IntConstant 		{ printf("Constant -> intConstant\n"); }
			 |	T_DoubleConstant 	{ printf("Constant -> doubleConstant\n"); }			 			 			 			 
			 |	T_BoolConstant 		{ printf("Constant -> boolConstant\n"); }			 			 			 			 
			 |	T_StringConstant 	{ printf("Constant -> stringConstant\n"); }			 			 			 			 
			 |	T_Null 				{ printf("Constant -> null\n"); }			 			 			 			 
			 ;




%% 
/*
 *�﷨���򵽴�Ϊֹ��
 *���������Լ�����ĺ�������Щ��������ֱ�ӱ�copy��parser_tab.c�ļ��У�
 *�������ҪһЩ�����ĺ���������д�������
*/
void Inityyparse(void)
{
}
