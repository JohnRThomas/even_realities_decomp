/*
 * Function: FUN_00080534
 * Entry:    00080534
 * Prototype: int __stdcall FUN_00080534(undefined4 param_1, undefined4 param_2, int param_3)
 */


int FUN_00080534(undefined4 param_1,undefined4 param_2,int param_3)

{
  aw9320x_err_code aVar1;
  int iVar2;
  
  iVar2 = print_object(param_3);
  if ((iVar2 == 0) && (iVar2 = FUN_000804e6(), iVar2 == 0)) {
    aVar1 = aw9320x_i2c_write(0x4820,4);
    iVar2 = -(uint)(aVar1 != AW_OK);
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


