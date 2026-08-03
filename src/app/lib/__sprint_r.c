/*
 * Function: __sprint_r
 * Entry:    0008a466
 * Prototype: int __stdcall __sprint_r(int * param_1, int * param_2, byte * param_3, int param_4)
 */


/* exclude_from_export_ai */

int __sprint_r(int *param_1,int *param_2,byte *param_3,int param_4)

{
  uint uVar1;
  byte *pbVar2;
  
  pbVar2 = param_3;
  do {
    if (pbVar2 == param_3 + param_4) {
      return 0;
    }
    uVar1 = _fputwc_r(param_1,(uint)*pbVar2,param_2);
    pbVar2 = pbVar2 + 1;
  } while (uVar1 != 0xffffffff);
  return -1;
}


