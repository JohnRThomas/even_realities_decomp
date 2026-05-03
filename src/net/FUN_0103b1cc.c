/*
 * Function: FUN_0103b1cc
 * Entry:    0103b1cc
 * Prototype: int __stdcall FUN_0103b1cc(byte * param_1, char * param_2, int param_3)
 */


int FUN_0103b1cc(byte *param_1,char *param_2,int param_3)

{
  int iVar1;
  char *local_14;
  int iStack_10;
  
  if ((((param_1 == (byte *)0x0) || (*param_1 == 0)) || (param_2 == (char *)0x0)) ||
     ((*param_2 == '\0' || (param_3 == 0)))) {
    iVar1 = -0x16;
  }
  else {
    local_14 = param_2;
    iStack_10 = param_3;
    iVar1 = FUN_01035948(param_1,&local_14);
    if (iVar1 == 0) {
      if (*(code **)(local_14 + 8) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0103b1f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (**(code **)(local_14 + 8))(local_14,param_2,param_3);
        return iVar1;
      }
      iVar1 = -0x13;
    }
  }
  return iVar1;
}


