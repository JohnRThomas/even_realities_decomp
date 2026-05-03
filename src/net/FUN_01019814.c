/*
 * Function: FUN_01019814
 * Entry:    01019814
 * Prototype: undefined4 __stdcall FUN_01019814(undefined1 param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_01019814(undefined1 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint extraout_r2;
  
  iVar1 = DAT_21000fe0;
  if (param_2 != (undefined4 *)0x0) {
    uVar2 = *param_2;
    DAT_21000ff0 = *(undefined2 *)(param_2 + 1);
    DAT_21000feb = param_1;
    DAT_21000fec = uVar2;
    *(undefined1 *)(DAT_21000fe0 + 9) = DAT_21000fd5;
    *(undefined4 *)(iVar1 + 10) = DAT_21000fd6;
    *(undefined2 *)(iVar1 + 0xe) = _DAT_21000fda;
    return uVar2;
  }
  FUN_01009500(0x32,0xb96,param_3,param_4);
  DAT_21000fe4 = (byte)(extraout_r2 >> 0x1e);
  if (extraout_r2 >> 0x1e == 3) {
    DAT_21000fe0 = 0;
  }
  return 0;
}


