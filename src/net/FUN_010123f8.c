/*
 * Function: FUN_010123f8
 * Entry:    010123f8
 * Prototype: int __stdcall FUN_010123f8(char * param_1)
 */


int FUN_010123f8(char *param_1)

{
  int iVar1;
  undefined4 extraout_r2;
  
  if ((DAT_21000f24 != '\0') || (*param_1 == -1)) {
    return 0xc;
  }
  iVar1 = FUN_01011b2c((int)param_1);
  if ((iVar1 == 0) && (DAT_21000f24 != '\x01')) {
    FUN_010121ac(param_1,0,extraout_r2);
    return 0;
  }
  return iVar1;
}


