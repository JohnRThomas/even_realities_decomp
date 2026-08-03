/*
 * Function: __strcpy_chk
 * Entry:    0008a7ae
 * Prototype: char * __stdcall __strcpy_chk(char * param_1, char * param_2, size_t param_3)
 */


/* exclude_from_export_ai */

char * __strcpy_chk(char *param_1,char *param_2,size_t param_3)

{
  size_t sVar1;
  char *pcVar2;
  
  sVar1 = strlen(param_2);
  sVar1 = sVar1 + 1;
  if (sVar1 <= param_3) {
    if (param_2 <= param_1) {
      if (param_1 < param_2 + sVar1) goto LAB_0008a7c2;
      if (param_2 != param_1) goto LAB_0008a7da;
    }
    if (param_1 + sVar1 <= param_2) {
LAB_0008a7da:
      pcVar2 = memcpy(param_1,param_2,sVar1);
      return pcVar2;
    }
  }
LAB_0008a7c2:
                    /* WARNING: Subroutine does not return */
  __chk_fail();
}


