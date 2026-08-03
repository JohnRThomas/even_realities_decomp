/*
 * Function: __assert_func
 * Entry:    00079d3c
 * Prototype: void __stdcall __assert_func(char * file, int line, char * func, char * failedexpr)
 */


/* exclude_from_export */

void __assert_func(char *file,int line,char *func,char *failedexpr)

{
  FILE *fp;
  FILE *extraout_r0;
  
  fp = *(FILE **)(_REENT + 0xc);
  do {
    fprintf(fp,"assertion \"%s\" failed: file \"%s\", line %d%s%s\n");
    abort();
    fp = extraout_r0;
  } while( true );
}


