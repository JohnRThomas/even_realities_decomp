/*
 * Function: FUN_01030390
 * Entry:    01030390
 * Prototype: uint * __stdcall FUN_01030390(uint param_1, undefined4 param_2, uint param_3, uint * param_4)
 */


uint * FUN_01030390(uint param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  uint *puVar2;
  byte local_20 [4];
  char *local_1c;
  uint uStack_18;
  
  if ((param_1 < 6) && (iVar1 = (0x2aU >> (param_1 & 0xff)) << 0x1f, iVar1 < 0)) {
    puVar2 = FUN_0103ac0c((uint *)&DAT_210009fc,iVar1,param_3,param_4);
    if (puVar2 != (uint *)0x0) {
      FUN_010307d4((int *)(puVar2 + 3),1,extraout_r2,extraout_r3);
      *(char *)(puVar2 + 6) = (char)param_1;
    }
  }
  else {
    local_1c = "Invalid rx type: %u";
    local_20[0] = 3;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[3] = 0;
    uStack_18 = param_1;
    FUN_0102ea44(0x103bfe4,0x1840,local_20,(undefined1 *)0x0);
    puVar2 = (uint *)0x0;
  }
  return puVar2;
}


