/*
 * Function: ?_save_sys_settings
 * Entry:    00024abc
 * Prototype: undefined4 __stdcall ?_save_sys_settings(GlassesState * param_1)
 */


undefined4 __save_sys_settings(GlassesState *param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  undefined4 *puVar4;
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
  char *pcVar3;
  undefined4 *puVar5;
  
  memset(local_a0,0,0x90);
  local_a8 = 1;
  local_a4 = param_1->field2803_0x10b8;
  local_a0[0] = param_1->esb_channel;
  uStack_9c = *(undefined4 *)&(param_1->imu_fusion_context).field_0x80;
  uStack_98 = *(undefined4 *)&(param_1->opt3007_context).field_0x14;
  uStack_94 = (param_1->jdb_panel_context).field_0x368;
  puVar1 = auStack_93;
  pcVar2 = SERIAL_NUMBER;
  do {
    pcVar3 = pcVar2 + 4;
    *puVar1 = *(undefined4 *)pcVar2;
    puVar1 = puVar1 + 1;
    pcVar2 = pcVar3;
  } while (pcVar3 != (char *)0x20003036);
  puVar1 = auStack_73;
  puVar4 = &DAT_20003006;
  do {
    puVar5 = puVar4 + 1;
    *puVar1 = *puVar4;
    puVar1 = puVar1 + 1;
    puVar4 = puVar5;
  } while (puVar5 != (undefined4 *)0x20003016);
  uStack_53 = param_1->field_0x3;
  uStack_52 = param_1->field_0x4;
  uStack_51 = param_1->field_0x10a8;
  uStack_50 = param_1->field_0x10a9;
  uStack_4c = param_1->field2802_0x10b4;
  uStack_48 = param_1->field2765_0x108a;
  local_46 = param_1->field2766_0x108c;
  local_40 = *(undefined4 *)&param_1->field_0xfa4;
  local_44 = *(undefined4 *)&param_1->field_0xfa8;
  local_3c = *(undefined4 *)&param_1->field_0xfac;
  local_38 = *(undefined4 *)&param_1->field_0xfb0;
  local_2c = *(undefined4 *)&param_1->field_0xfb4;
  local_28 = *(undefined4 *)&param_1->field_0xfb8;
  local_34 = *(undefined2 *)&(param_1->jdb_panel_context).field_0x36e;
  local_32 = *(undefined2 *)&(param_1->jdb_panel_context).field_0x370;
  local_30 = *(undefined2 *)&(param_1->jdb_panel_context).field_0x372;
  local_24 = param_1->field2804_0x10bc;
  uStack_20 = param_1->field2805_0x10c0;
  local_1c = param_1->field2806_0x10c4;
  local_18 = param_1->field2801_0x10b0;
  local_14 = param_1->field_0x10c8;
  local_13 = param_1->field_0x10d0;
  flash_settings_write_and_verify(&DAT_00130000,&local_a8,0x98);
  return 0;
}


