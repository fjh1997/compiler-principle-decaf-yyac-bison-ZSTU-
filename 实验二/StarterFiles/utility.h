/*utility.h
 *一些有用的函数(出错处理)
 *这里我们把stderr换成了stdout,是为了比较方便地输出结果。
*/
#include <stdarg.h>
#include <string.h>
#include "parser_tab.h"
extern const char *GetLineNumbered(int num);
extern YYLTYPE yylloc;

#define BufferSize   2048
int numErrors = 0;		// counts number of times ReportError was called

static void UnderlineErrorInLine(const char *line, struct yyltype *pos)
{
  int i;
  if (!line) return;
  fprintf(stdout, "%s\n", line);		//here should be stderr
  for (i = 1; i <= pos->last_column; i++)
    fprintf(stdout, "%c", i >= pos->first_column ? '^' : ' ');	//here should be stderr
  fprintf(stdout, "\n");		//here should be stderr
}

/*Function ReportError()
 *Useage:  ReportError(&yylloc,"Unexpected char: %c\n", ch);
 *----------------------------------------------------------
 *用于报错，第一个参数用于说明出错的位置，如果无法说明具体出错的位置，可以
 *置为NULL
*/
void ReportError(struct yyltype *pos, const char *format, ...)
{
  va_list args;
  char errbuf[BufferSize];
  
  numErrors++;
  va_start(args, format);
  vsprintf(errbuf,format, args);
  va_end(args);
  if (strlen(errbuf) > BufferSize) {
    fprintf(stdout,"Error message too long\n");		//here should be stderr
  } else {
    fflush(stdout); // make sure any buffered text has been output
    if (pos) {

      fprintf(stdout,"\n*** Error line %d column %d\n",
              pos->first_line, pos->first_column);	//here should be stderr
      UnderlineErrorInLine(GetLineNumbered(pos->first_line), pos);
    } else {
      fprintf(stdout,"\n*** Error at unidentified line\n");	//here should be stderr
    }
   fprintf(stdout,"*** %s\n\n", errbuf);	//here should be stderr
  }
}