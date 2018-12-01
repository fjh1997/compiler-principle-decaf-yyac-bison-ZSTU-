/*
 *declaration.h
 *定义了一个类，用于存储identifier的定义，包括变量名、函数命等。
*/
#ifndef _H_declaration
#define _H_declaration

class Declaration {

 private:

    const char *name;
    int lineFound,numoccur;
  public:

    /* Pass in the identifier's name and the line where it
     * first occurs to construct a new declaration object */
    Declaration(const char *name, int lineNum = -1, int numoccur = 1);
    
    const char *GetName();
    int GetLineFound();
    int GetOccurrences();
    
    /* call this whenever the same identifier is seen */
    void IncrementOccurrences();
    
    /* called from pp1's main. The method should print the
     * identifier name, occurrence count, and first line seen like this:
     * (myVariable seen 5 time(s), first on line 114) */
    void Print();
};

 
#endif
