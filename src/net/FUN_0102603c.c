/*
 * Function: FUN_0102603c
 * Entry:    0102603c
 * Prototype: undefined __stdcall FUN_0102603c(uint param_1, undefined4 param_2, undefined4 param_3, uint param_4)
 */


void FUN_0102603c(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  uint uVar3;
  
  if (param_1 < 5) goto LAB_0102604a;
  uVar2 = 0x58;
  while( true ) {
    param_1 = FUN_01025edc(0x69,uVar2,param_3,param_4);
    param_3 = extraout_r2;
LAB_0102604a:
    iVar1 = param_1 * 8;
    param_4 = (uint)(byte)(&DAT_21001c28)[iVar1];
    if (param_4 == 1) break;
    uVar2 = 0x59;
  }
  if ((&DAT_21001c2a)[iVar1] != (char)((&DAT_21001c29)[iVar1] + '\x01')) {
    (&DAT_21001c29)[iVar1] = (&DAT_21001c29)[iVar1] + '\x01';
  }
  uVar3 = (uint)DAT_21001c20;
  if (-1 < (int)uVar3) {
    *(int *)(&DAT_e000e100 + ((uVar3 >> 5) + 0x40) * 4) = 1 << (uVar3 & 0x1f);
  }
  return;
}


