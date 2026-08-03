/*
 * Function: __memcpy_chk
 * Entry:    0008a830
 * Prototype: void * __stdcall __memcpy_chk(void * param_1, void * param_2, size_t param_3, size_t param_4)
 */


/* exclude_from_export_ai */

void * __memcpy_chk(void *param_1,void *param_2,size_t param_3,size_t param_4)

{
  char *pcVar1;
  
  if (param_3 <= param_4) {
    if (param_2 <= param_1) {
      if (param_1 < (void *)((int)param_2 + param_3)) goto LAB_0008a836;
      if (param_2 != param_1) goto LAB_0008a84e;
    }
    if ((void *)((int)param_1 + param_3) <= param_2) {
LAB_0008a84e:
      pcVar1 = strcpy(param_1,param_2);
      return pcVar1;
    }
  }
LAB_0008a836:
                    /* WARNING: Subroutine does not return */
  __chk_fail();
}


