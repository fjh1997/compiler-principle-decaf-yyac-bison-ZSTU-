/*
 *scanner.l
 *	
 *	Flex输入文件，生成scanner
*/

%{
/*
 *
 *这个*{}*中的程序将被直接copy到lex.yy.c中去，所以可以将要用到的头文件和
 *全局变量在这个地方定义。
 *
*/
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <malloc.h>
#include <string.h>
#include "scanner.h"
#include "hashtable.h"
#include "utility.h"

/*
 *Global variable: yylval
 *-----------------------
 *全局变量，我们可以从yylval中获得每个token的属性。
 *以后这个变量由bison/yacc自动生成，在这个实验里面，我们手动定义。
*/
YYSTYPE yylval;
static int line_num=1;
static int col_num=1;
Hashtable hashtable;
/*
 *Global variable: yylloc
 *-----------------------
 *全局变量，我们可以从yylloc中获得每个token的位置属性。
 *以后也由bison/yacc自动生成。
*/
struct yyltype yylloc;

/* 
 *Macro: YY_USER_ACTION 
 *---------------------
 *flex自己定义的宏，这个函数将在每个rule的action之前运行，所以，如果你的每个rule都
 *要执行类似的action的话，不妨把这个action放在这个函数中。
*/
static void DoBeforeEachAction(); 
#define YY_USER_ACTION DoBeforeEachAction();

%}
%option stack
%x C
/*
 *在这里定义你的辅助定义和开始条件
*/
IDENTIFIER 	([a-zA-Z][a-zA-Z0-9_]*)
BEG_COMMENT       ("/*")
END_COMMENT       ("*/")
INTEGER           [0-9]+
OPERATOR [+\-*/%=<>\\,.;!(){}\[\]]
FORESTRING        (\"[^"\n]*)
STRING            ({FORESTRING}\")
ERRSTRING     	  {FORESTRING}$
WHITE             [ \t]*
COMMENT    ("//"[^\n]*)
DOUBLE            ({INTEGER}(".")[0-9]*([Ee][-+]{INTEGER})?)
HEX_INTEGER       0[Xx]([0-9]|[a-fA-F])+
%%
<*>\n {line_num++;col_num=1;}
{WHITE}                { col_num+=yyleng;}
void	{col_num+=4;return T_Void;}
int	{col_num+=yyleng;return T_Int;}
double	{col_num+=yyleng;return T_Double;}
bool	{col_num+=yyleng;return T_Bool;}
string	{col_num+=yyleng;return T_String;}
class   {col_num+=yyleng;return T_Class;}
null	{col_num+=yyleng;return T_Null;}
"<="	{col_num+=yyleng;return T_LessEqual;}
">="	{col_num+=yyleng;return T_GreaterEqual;}
"=="	{col_num+=yyleng;return T_Equal;}
"!="	{col_num+=yyleng;return T_NotEqual;}
"&&"	{col_num+=yyleng;return T_And;}
"||"	{col_num+=yyleng;return T_Or;}
while	{col_num+=yyleng;return T_While;}
if	{col_num+=yyleng;return T_If;}
else	{col_num+=yyleng;return T_Else;}
return	{col_num+=yyleng;return T_Return;}

{STRING}            { strcpy(yylval.stringConstant,yytext);
			col_num+=yyleng;
                         return T_StringConstant; }
{HEX_INTEGER}       { yylval.integerConstant = strtol(yytext, NULL, 16);
			col_num+=yyleng;
                         return T_IntConstant; }
{INTEGER}           { yylval.integerConstant = strtol(yytext, NULL, 10);
			col_num+=strlen(yytext);
                         return T_IntConstant;
			 }
{DOUBLE}            { yylval.doubleConstant = atof(yytext);
                         col_num+=yyleng; 
			return T_DoubleConstant;
			}
true|false {
		col_num+=yyleng;
		yylval.boolConstant=!strcmp(yytext,"true")?true:false;
		return T_BoolConstant;
		}
public	{col_num+=yyleng;return T_Public;}
private	{col_num+=yyleng;return T_Private;}
extends    {col_num+=yyleng;return T_Extends;}
this    {col_num+=yyleng;return T_This;}
New	{col_num+=yyleng;return T_New;}
NewArray {col_num+=yyleng;return T_NewArray;}
Print	{col_num+=yyleng;return T_Print;}
ReadInteger {col_num+=yyleng;return T_ReadInteger;}
ReadLine {col_num+=yyleng;return T_ReadLine;}
{IDENTIFIER}     	{
			Declaration *temp;
			temp=hashtable.st_lookup(strdup(yytext));
			//printf(temp->GetName());
			if(temp==NULL)
		 	{
				//printf("yytext=:%s",yytext);
				temp=new Declaration(yytext,line_num,1);
				//printf("temp=:%s",temp->GetName());
				hashtable.st_insert(*temp);
				
		 	}
		 	else
		 	{
				
				temp->IncrementOccurrences();
		 	}
		 	yylval.decl=temp;
			col_num+=strlen(yytext);
		 	return T_Identifier;}



{COMMENT}    { col_num+=yyleng; } 


<*>{BEG_COMMENT}          { yy_push_state(C); col_num+=2;}
<C>{END_COMMENT}       { yy_pop_state(); col_num+=2;}

{ERRSTRING}     {
		ReportError(&yylloc,"Illegal newline in string constant %s", yytext);
		}
{FORESTRING}     ReportError(&yylloc,"Input ends with unterminated string %s", yytext);



{OPERATOR} 	{col_num++;return yytext[0];}
<C>. {col_num++; }
. {col_num++;ReportError(&yylloc,"Unrecognized char: '%c'", yytext[0]);}
%%

/*
 *Function yyerror()
 *------------------
 *输出错误信息，这个实验中使用ReportError来代替它。不用修改。
*/void yyerror(char *msg)
{
  ReportError(&yylloc, "%s", msg);
}

/*
 *Function yywrap()
 *----------------
 *当文件到了结束后执行这个函数，不用修改。
*/
int yywrap()
{
	return (1);
}

/*
 * Function: DoBeforeEachAction()
 * ------------------------------
 * 定义为YY_USER_ACTION的函数。
 */
static void DoBeforeEachAction()
{
  yylloc.first_line = line_num;
   yylloc.first_column = col_num;
   yylloc.last_column = col_num + yyleng - 1;


}