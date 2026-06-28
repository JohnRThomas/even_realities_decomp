/*
 * Function: FUN_00027314
 * Entry:    00027314
 * Prototype: int __stdcall FUN_00027314(undefined1 * param_1, char * param_2, char * param_3)
 */


int FUN_00027314(undefined1 *param_1,char *param_2,char *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint8_t num_msgs;
  int iVar4;
  int iVar5;
  i2c_msg local_168;
  undefined4 local_164;
  char local_160;
  char local_15f;
  char local_15e;
  char local_15d;
  char local_15c;
  char local_15b;
  char local_15a;
  char local_158;
  undefined1 local_154;
  undefined1 local_153;
  undefined1 local_152;
  undefined1 local_151;
  undefined1 local_150;
  undefined1 local_14f;
  undefined1 local_14e;
  undefined1 local_14d;
  undefined1 local_14c;
  undefined1 local_14b;
  device local_148;
  undefined4 uStack_130;
  undefined4 local_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined *local_120;
  undefined *puStack_11c;
  undefined *puStack_118;
  undefined *puStack_114;
  undefined *local_110;
  undefined *puStack_10c;
  undefined *puStack_108;
  undefined4 local_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 local_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined1 local_e0;
  char local_df;
  char local_de;
  astruct_1 aStack_c8;
  astruct_2 aStack_a8;
  undefined *local_88 [4];
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined *local_6c [21];
  
  local_14e = param_1[4];
  local_14d = param_1[6];
  local_14c = param_1[7];
  local_14b = param_1[8];
  local_153 = *param_1;
  local_151 = param_1[2];
  local_150 = param_1[3];
  local_152 = param_1[1];
  local_154 = 0x20;
  local_14f = param_1[9];
  uVar1 = FUN_000272ac_init_something_0(&aStack_c8,(undefined4 *)&local_154);
  uVar2 = FUN_0007f742((int)&aStack_c8);
  local_88[0] = local_148.state;
  local_88[1] = local_148.data;
  local_88[2] = local_148.pm;
  local_88[3] = (undefined *)uStack_130;
  local_78 = local_12c;
  uStack_74 = uStack_128;
  uStack_70 = uStack_124;
  uVar1 = (uVar1 | uVar2) & 0xffff;
  if (*param_2 == '\0') {
    iVar5 = 1;
  }
  else {
    local_160 = param_2[1];
    local_15f = param_2[2];
    local_15e = param_2[3];
    iVar5 = 2;
    local_15d = param_2[4];
    local_15c = param_2[5];
    local_15b = param_2[6];
    local_15a = param_2[7];
    local_158 = param_2[8];
    uVar2 = FUN_000272e0_init_something_1(&aStack_a8,(undefined4 *)&local_160);
    uVar3 = FUN_0007f742((int)&aStack_a8);
    uVar1 = (uVar2 | uVar3) & 0xffff | uVar1;
    local_6c[0] = (undefined *)local_104;
    local_6c[1] = (undefined *)uStack_100;
    local_6c[2] = (undefined *)uStack_fc;
    local_6c[3] = (undefined *)uStack_f8;
    local_6c[4] = (undefined *)local_f4;
    local_6c[5] = (undefined *)uStack_f0;
    local_6c[6] = (undefined *)uStack_ec;
  }
  if (*param_3 != '\0') {
    local_e8 = 0x57020651;
    local_e4 = 0x4f46434c;
    local_e0 = 0x44;
    local_df = param_3[1];
    local_de = param_3[2];
    local_148.name = (undefined *)&local_e8;
    local_148.config = &DAT_0000000b;
    uVar1 = FUN_0007f85c((int *)&local_148,(byte *)&local_120);
    local_88[iVar5 * 7] = local_120;
    local_88[iVar5 * 7 + 1] = puStack_11c;
    local_88[iVar5 * 7 + 2] = puStack_118;
    local_88[iVar5 * 7 + 3] = puStack_114;
    local_88[iVar5 * 7 + 4] = local_110;
    local_88[iVar5 * 7 + 5] = puStack_10c;
    local_88[iVar5 * 7 + 6] = puStack_108;
    iVar5 = iVar5 + 1;
  }
  iVar4 = 0;
  local_148.name = (undefined *)0x0;
  local_148.config = (undefined *)0x0;
  local_148.api = (undefined *)0x0;
  DAT_20019938 = 0;
  do {
    uVar2 = FUN_0007fb46(&local_148.name,(byte *)(local_88 + iVar4 * 7));
    iVar4 = iVar4 + 1;
    uVar1 = (uVar2 | uVar1) & 0xffff;
  } while (iVar4 != iVar5);
  local_168 = (i2c_msg)&local_e8;
  local_164 = 0x20;
  uVar2 = __i2c_transfer(&local_148,&local_168,num_msgs,0x20);
  uVar3 = FUN_00027204((void *)local_168,(ushort)local_164);
  return -(uint)((uVar3 & 0xffff) != 0 || (uVar1 != 0 || (uVar2 & 0xffff) != 0));
}


