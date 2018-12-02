/*scanner.l
 *---------
 *生成scanner.
 */
 
%{
#include <string.h>
#include "scanner.h"
#include "parser.h"
#include "utility.h"

/*全局变量
 *-------
 */
static int curLineNum, curColNum;
static char curLine[512];


static void DoBeforeEachAction(); 
#define YY_USER_ACTION DoBeforeEachAction();

%}
%option stack
%s N C
%x COPY

/* Definitions
 * -----------
 * To make our rules more readable, we establish some definitions here.
 */
DIGIT             ([0-9])
HEX_DIGIT         ([0-9a-fA-F])
HEX_INTEGER       (0[Xx]{HEX_DIGIT}+)
INTEGER           ({DIGIT}+)
EXPONENT          ([Ee][-+]{INTEGER})
DOUBLE            ({INTEGER}"."{DIGIT}*{EXPONENT}?)
BEG_STRING        (\"[^"\n]*)
STRING            ({BEG_STRING}\")
IDENTIFIER        ([a-zA-Z][a-zA-Z_0-9]*)
OPERATOR          ([+\-*/%=<>\\,.;!(){}\[\]])
BEG_COMMENT       ("/*")
END_COMMENT       ("*/")
SINGLE_COMMENT    ("//"[^\n]*)
WHITE             ([ \t]*)

%%             /* BEGIN RULES SECTION */

<COPY>.*               { strncpy(curLine, yytext, sizeof(curLine));
                         curColNum = 1;
                         yy_pop_state(); yyless(0); }
<COPY><<EOF>>          { yy_pop_state();}
<*>\n                  { curLineNum++; curColNum = 1;
                         if (YYSTATE != COPY) yy_push_state(COPY); }

{WHITE}                { /* ignore space & tabs in normal or comment */  }


 /* -------------------- Comments ----------------------------- */
{BEG_COMMENT}          { yy_push_state(C); }
<C>{END_COMMENT}       { yy_pop_state(); }
<C><<EOF>>             { ReportError(&yylloc,
                         "Input ends with unterminated comment.");
                         return 0; }
<C>[^*\n/]*            { /* grab all non-star, non-slash, non-newline */}
<C>.                   { /* ignore everything else that doesn't match */ }
<N>{SINGLE_COMMENT}    { /* skip to end of line for // comment */ } 


 /* --------------------- Keywords ------------------------------- */
<N>"void"              { return T_Void;        }
<N>"int"               { return T_Int;         }
<N>"double"            { return T_Double;      }
<N>"bool"              { return T_Bool;        }
<N>"string"            { return T_String;      }
<N>"class"             { return T_Class;       }
<N>"extends"           { return T_Extends;     }
<N>"this"              { return T_This;        }
<N>"null"              { return T_Null;        }
<N>"while"             { return T_While;       }
<N>"for"               { return T_For;         }
<N>"if"                { return T_If;          }
<N>"else"              { return T_Else;        }
<N>"return"            { return T_Return;      }
<N>"New"               { return T_New;         }
<N>"NewArray"          { return T_NewArray;    }
<N>"Print"             { return T_Print;       }
<N>"ReadInteger"       { return T_ReadInteger; }
<N>"ReadLine"          { return T_ReadLine;    }


 /* -------------------- Operators ----------------------------- */
<N>"<="                { return T_LessEqual;   }
<N>">="                { return T_GreaterEqual;}
<N>"=="                { return T_Equal;       }
<N>"!="                { return T_NotEqual;    }
<N>"&&"                { return T_And;         }
<N>"||"                { return T_Or;          }
<N>{OPERATOR}          { return yytext[0];     }


 /* -------------------- Constants ------------------------------ */
<N>"true"|"false"      { yylval.boolConstant = (yytext[0] == 't');
                         return T_BoolConstant; }
<N>{INTEGER}           { yylval.integerConstant = strtol(yytext, NULL, 10);
                         return T_IntConstant; }
<N>{HEX_INTEGER}       { yylval.integerConstant = strtol(yytext, NULL, 16);
                         return T_IntConstant; }
<N>{DOUBLE}            { yylval.doubleConstant = atof(yytext);
                         return T_DoubleConstant; }
<N>{STRING}            { yylval.stringConstant = strdup(yytext); 
                         return T_StringConstant; }
<N>{BEG_STRING}/\n     { ReportError(&yylloc,
                         "Illegal newline in string constant %s", yytext); }
<N>{BEG_STRING}        { ReportError(&yylloc,
                         "Input ends with unterminated string %s", yytext);}


 /* -------------------- Identifiers --------------------------- */
<N>{IDENTIFIER}        {
                        /* The lexer records the identifier name in yylval.
                         * The parser is reponsible for looking up the name
                         * in the appropriate scope(s) to find the decl.
                         */
                         strncpy(yylval.identifier, yytext,
                                 sizeof(yylval.identifier)-1);
                         return T_Identifier; }


 /* -------------------- Default rule (error) -------------------- */
<N>.                   {ReportError(&yylloc,"Unrecognized char: '%c'", yytext[0]);  }

%%
void yyerror(char *msg)
{
	ReportError(&yylloc, "%s", msg);
}

int yywrap()
{
	return (1);
}

/*
 * Function: Inityylex()
 * --------------------
 * This function will be called before any calls to yylex().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the scanner (set global variables, configure starting state, etc.). 
 */
void Inityylex()
{
    BEGIN(N);  // Start in Normal state
    yy_push_state(COPY);  // but copy first line at start
    curLineNum = 1;
    curColNum = 1;
}


/*
 * Function: DoBeforeEachAction()
 * ------------------------------
 * This function is installed as the YY_USER_ACTION. This is a place
 * to group code common to all actions.
 * On each match, we fill in the fields to record its location and
 * update our column counter.
 */
static void DoBeforeEachAction()
{
   yylloc.first_line = curLineNum;
   yylloc.first_column = curColNum;
   yylloc.last_column = curColNum + yyleng - 1;
   curColNum += yyleng;
}

/* Function: GetLineNumbered()
 * ---------------------------
 * Returns string with contents of line numbered n or NULL if the
 * contents of that line are no longer available. Basically only the
 * line currently being scanned is available, although we could keep
 * a few lines back if we put more effort into it :-). The pointer
 * returned is to an internally maintained static buffer which will
 * be overwritten. If you want to preserve, be sure to copy elsewhere.
 */
const char *GetLineNumbered(int num) {
    return (num == curLineNum) ? curLine : NULL;
}


