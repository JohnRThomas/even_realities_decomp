/*
 * Function: FUN_010303f0
 * Entry:    010303f0
 * Prototype: uint * __stdcall FUN_010303f0(int param_1, undefined4 param_2, uint param_3, uint * param_4, undefined1 * param_5, uint param_6)
 */


uint * FUN_010303f0(int param_1,undefined4 param_2,uint param_3,uint *param_4,undefined1 *param_5,
                   uint param_6)

{
  uint uVar1;
  uint *puVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint *puVar3;
  byte local_30 [4];
  char *local_2c;
  int iStack_28;
  uint *puStack_20;
  
  puStack_20 = param_4;
  if (param_1 == 0) {
    puVar2 = (uint *)&DAT_210009c8;
  }
  else {
    if (param_1 != 2) {
      local_2c = "Invalid tx type: %u";
      local_30[0] = 3;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      iStack_28 = param_1;
      FUN_0102ea44(0x103bfe4,0x1840,local_30,(undefined1 *)0x0);
      return (uint *)0x0;
    }
    puVar2 = (uint *)&DAT_21000994;
  }
  puVar2 = FUN_0103ac0c(puVar2,param_2,param_3,param_4);
  if (puVar2 != (uint *)0x0) {
    puVar3 = puVar2 + 3;
    FUN_010307d4((int *)puVar3,1,extraout_r2,extraout_r3);
    *(char *)(puVar2 + 6) = (char)param_1;
    if (param_5 == (undefined1 *)0x0) {
      return puVar2;
    }
    if (param_6 == 0) {
      return puVar2;
    }
    uVar1 = FUN_0103ac28((int *)puVar3);
    if (param_6 <= uVar1) {
      FUN_0103ac38((int *)puVar3,param_5,param_6);
      return puVar2;
    }
    FUN_01030754(puVar2,extraout_r1,extraout_r2_00,extraout_r3_00);
  }
  return (uint *)0x0;
}


