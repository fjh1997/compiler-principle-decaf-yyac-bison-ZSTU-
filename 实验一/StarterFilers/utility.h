/*
utility.h
定义了ReportError函数，用于报错。
不要修改。
*/
#ifndef _H_utility
#define _H_utility

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "scanner.h"

#define BufferSize 256
void ReportError(struct yyltype *pos, char *format, ...);

void ReportError(struct yyltype *pos, char *format, ...)
{
  va_list args;
  char errbuf[BufferSize];
  
  va_start(args, format);
  vsprintf(errbuf,format, args);
  va_end(args);
  if (strlen(errbuf) > BufferSize) {
    fprintf(stdout,"Error message too long\n");
  } else {
    fflush(stdout); // make sure any buffered text has been output
    if (pos)
	fprintf(stdout,"\n*** Error line %d column %d\n", pos->first_line, pos->first_column);
    else
	fprintf(stdout,"\n*** Error at unidentified position\n");
	
   fprintf(stdout,"*** %s\n\n", errbuf);
  }
}
#endif