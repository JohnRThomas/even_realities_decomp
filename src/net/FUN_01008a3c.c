/*
 * Function: FUN_01008a3c
 * Entry:    01008a3c
 * Prototype: undefined8 __stdcall FUN_01008a3c(uint param_1, uint param_2, uint param_3, uint param_4)
 */


undefined8 FUN_01008a3c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined8 uVar1;
  uint local_8 [2];
  
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_2 = 0xffffffff;
      param_1 = 0xffffffff;
    }
    return CONCAT44(param_2,param_1);
  }
  uVar1 = FUN_01026538(param_1,param_2,param_3,param_4,local_8);
  return uVar1;
}


