/*
 * Function: FUN_0102badc
 * Entry:    0102badc
 * Prototype: int __stdcall FUN_0102badc(int param_1)
 */


int FUN_0102badc(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 local_24;
  code *local_20;
  undefined4 uStack_1c;
  undefined1 *local_18;
  undefined *puStack_14;
  
  uStack_1c = 0x201;
  local_20 = (code *)0x102bccd;
  local_24 = (uint)CONCAT11(param_1 != 0,1);
  local_18 = &DAT_0005012c;
  puStack_14 = (undefined *)0x101fb02;
  iVar1 = FUN_01033b74(&local_24);
  if (iVar1 == 0) {
    FUN_010342b8(3);
    if (DAT_210005b4 == 2) {
      FUN_0103428c(DAT_21004b9e / 5 + 0x50);
    }
    iVar1 = FUN_010341a4((undefined4 *)&DAT_21000767);
    if ((((iVar1 == 0) && (iVar1 = FUN_010341e0((undefined4 *)&DAT_21000763), iVar1 == 0)) &&
        (iVar1 = FUN_01034220(&DAT_21000761,2), iVar1 == 0)) &&
       (((iVar1 = FUN_0103426c(3), iVar1 == 0 && (DAT_e000e408 = 0, param_1 == 1)) &&
        ((iVar2 = FUN_01034048(), iVar2 != 0 && (iVar1 = iVar2, 0 < DAT_21000580)))))) {
      FUN_01039ee2((byte *)"esb_start_rx fail\n",extraout_r1,extraout_r2,DAT_21000580);
    }
  }
  return iVar1;
}


