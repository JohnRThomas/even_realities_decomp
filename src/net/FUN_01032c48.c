/*
 * Function: FUN_01032c48
 * Entry:    01032c48
 * Prototype: uint * __stdcall FUN_01032c48(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


uint * FUN_01032c48(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar5;
  char cVar6;
  uint *puVar7;
  byte local_28 [4];
  char *local_24;
  uint uStack_20;
  undefined4 uStack_18;
  
  pcVar4 = s__I__8t__PJ______X_<_bt_sdc_ecdh_0103e315;
  if (param_1 == 0) {
    pcVar4 = &DAT_210051f6;
  }
  uStack_18 = param_4;
  uVar1 = FUN_01039250((uint *)&DAT_21005216,(uint *)pcVar4,(uint *)&DAT_21005216);
  cVar6 = '\0';
  uVar5 = extraout_r1;
  if (uVar1 != 0) {
    local_24 = "public key is not valid (err %d)";
    local_28[0] = 3;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    uStack_20 = uVar1;
    FUN_0102ea44(0x103bffc,0x1840,local_28,(undefined1 *)0x0);
    cVar6 = '\x12';
    uVar5 = extraout_r1_00;
  }
  puVar2 = FUN_01030390(1,uVar5,0xffffffff,(uint *)0xffffffff);
  puVar7 = puVar2 + 3;
  puVar3 = (undefined1 *)FUN_01030844((int *)puVar7,2);
  *puVar3 = 0x3e;
  puVar3[1] = 0x22;
  puVar3 = (undefined1 *)FUN_01030844((int *)puVar7,1);
  *puVar3 = 9;
  pcVar4 = (char *)FUN_01030844((int *)puVar7,0x21);
  *pcVar4 = cVar6;
  if (cVar6 == '\0') {
    FUN_01032c00(pcVar4 + 1,&DAT_21005216);
  }
  else {
    FUN_0103bdee(pcVar4 + 1,0xff,0x20);
  }
  return puVar2;
}


