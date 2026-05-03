/*
 * Function: FUN_00024abc
 * Entry:    00024abc
 * Prototype: undefined4 __stdcall FUN_00024abc(GlassesState * param_1)
 */


undefined4 FUN_00024abc(GlassesState *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 local_a0 [4];
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined1 uStack_94;
  undefined4 auStack_93 [8];
  undefined4 auStack_73 [8];
  undefined1 uStack_53;
  undefined1 uStack_52;
  undefined1 uStack_51;
  undefined1 uStack_50;
  undefined4 uStack_4c;
  undefined2 uStack_48;
  undefined2 local_46;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  
  memset(local_a0,0,0x90);
  local_a8 = 1;
  local_a4 = param_1->field3705_0x10b8;
  local_a0[0] = param_1->field_0x2;
  uStack_9c = *(undefined4 *)&(param_1->imu_fusion_context).field_0x80;
  uStack_98 = *(undefined4 *)&(param_1->opt3007_context).field_0x14;
  uStack_94 = param_1->field_0xed4;
  puVar1 = auStack_93;
  puVar3 = &DAT_20003026;
  do {
    puVar2 = puVar3 + 1;
    *puVar1 = *puVar3;
    puVar1 = puVar1 + 1;
    puVar3 = puVar2;
  } while (puVar2 != (undefined4 *)0x20003036);
  puVar1 = auStack_73;
  puVar3 = &DAT_20003006;
  do {
    puVar2 = puVar3 + 1;
    *puVar1 = *puVar3;
    puVar1 = puVar1 + 1;
    puVar3 = puVar2;
  } while (puVar2 != (undefined4 *)0x20003016);
  uStack_53 = param_1->field_0x3;
  uStack_52 = param_1->field_0x4;
  uStack_51 = param_1->field_0x10a8;
  uStack_50 = param_1->field_0x10a9;
  uStack_4c = param_1->field3704_0x10b4;
  uStack_48 = param_1->field3667_0x108a;
  local_46 = param_1->field3668_0x108c;
  local_40 = *(undefined4 *)&param_1->field_0xfa4;
  local_44 = *(undefined4 *)&param_1->field_0xfa8;
  local_3c = *(undefined4 *)&param_1->field_0xfac;
  local_38 = *(undefined4 *)&param_1->field_0xfb0;
  local_2c = *(undefined4 *)&param_1->field_0xfb4;
  local_28 = *(undefined4 *)&param_1->field_0xfb8;
  local_34 = param_1->field3446_0xeda;
  local_32 = param_1->field3447_0xedc;
  local_30 = param_1->field3448_0xede;
  local_24 = param_1->field3706_0x10bc;
  uStack_20 = param_1->field3707_0x10c0;
  local_1c = param_1->field3708_0x10c4;
  local_18 = param_1->field3703_0x10b0;
  local_14 = param_1->field_0x10c8;
  local_13 = param_1->field_0x10d0;
  flash_settings_write_and_verify(0x130000,&local_a8,0x98);
  return 0;
}


