/*
 * Function: bt_dev_show_info
 * Entry:    00057b64
 * Prototype: void __stdcall bt_dev_show_info(void)
 */


/* exclude_from_export */

void bt_dev_show_info(void)

{
  char *str;
  char *extraout_r1;
  char *str_00;
  char *extraout_r1_00;
  size_t extraout_r2;
  size_t len;
  size_t extraout_r2_00;
  char *pcVar1;
  uint uVar2;
  bt_addr_le_t *addr;
  dword in_stack_ffffffa8;
  uint8_t *in_stack_ffffffac;
  void *in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  undefined1 *puVar3;
  char *local_40;
  char *local_3c;
  char *pcStack_38;
  uint local_34;
  undefined1 *local_30;
  undefined2 local_2c;
  
  atomic_or(&DAT_200020d4,4);
  pcStack_38 = "";
  if (1 < DAT_20002007) {
    pcStack_38 = "[0]";
  }
  local_34 = bt_addr_le_to_str((bt_addr_le_t *)&bt_dev,str,(uint)DAT_20002007);
  addr = (bt_addr_le_t *)&bt_dev;
  local_3c = "Identity%s: %s";
  local_30 = &DAT_03010200;
  local_40 = &DAT_02000004;
  LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x28c0,&local_40,&DAT_02000004,(dword)in_stack_ffffffb0,
          in_stack_ffffffb4,in_stack_ffffffb8);
  str_00 = extraout_r1;
  len = extraout_r2;
  for (pcVar1 = &DAT_00000001; addr = addr + 1, (int)pcVar1 < (int)(uint)DAT_20002007;
      pcVar1 = pcVar1 + 1) {
    local_34 = bt_addr_le_to_str(addr,str_00,len);
    local_3c = "Identity[%d]: %s";
    local_30 = (undefined1 *)CONCAT22(local_30._2_2_,0x301);
    local_40 = &DAT_01000004;
    pcStack_38 = pcVar1;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x24c0,&local_40,0x301,(dword)in_stack_ffffffb0,
            in_stack_ffffffb4,in_stack_ffffffb8);
    str_00 = extraout_r1_00;
    len = extraout_r2_00;
  }
  uVar2 = (uint)DAT_20002070;
  local_40 = ver_str(DAT_20002070);
  pcStack_38 = (char *)(uint)DAT_20002072;
  local_34 = (uint)DAT_20002076;
  local_30 = (undefined1 *)CONCAT22(local_30._2_2_,0x200);
  puVar3 = &DAT_01000006;
  local_3c = (char *)uVar2;
  LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x34c0,&stack0xffffffb8,&DAT_01000006,in_stack_ffffffa8,
          in_stack_ffffffac,in_stack_ffffffb0);
  uVar2 = (uint)DAT_20002071;
  pcStack_38 = ver_str(DAT_20002071);
  local_30 = (undefined1 *)(uint)DAT_20002074;
  local_3c = "LMP: version %s (0x%02x) subver 0x%04x";
  local_2c = 0x200;
  local_40 = &DAT_01000005;
  local_34 = uVar2;
  LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x2cc0,&local_40,&DAT_01000005,(dword)in_stack_ffffffb0,
          in_stack_ffffffb4,puVar3);
  return;
}


