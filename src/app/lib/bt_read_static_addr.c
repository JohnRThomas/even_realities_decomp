/*
 * Function: bt_read_static_addr
 * Entry:    000585fc
 * Prototype: uint8_t __stdcall bt_read_static_addr(bt_hci_vs_static_addr * addrs, uint8_t size)
 */


/* exclude_from_export_ai */

uint8_t bt_read_static_addr(bt_hci_vs_static_addr *addrs,uint8_t size)

{
  int iVar1;
  uint8_t *puVar2;
  uint8_t *puVar4;
  uint uVar5;
  bt_hci_vs_static_addr *pbVar6;
  bt_hci_vs_static_addr *pbVar7;
  dword in_stack_ffffffc8;
  net_buf *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_20;
  char *local_1c;
  uint8_t *puVar3;
  
  if ((int)((uint)DAT_200020c2 << 0x1f) < 0) {
    iVar1 = bt_hci_cmd_send_sync(0xfc09,(net_buf *)0x0,(net_buf **)&stack0xffffffcc);
    if (iVar1 == 0) {
      puVar4 = (in_stack_ffffffcc->field6_0xc).field0.data;
      uVar5 = (uint)puVar4[1];
      puVar4 = puVar4 + 2;
      iVar1 = 0;
      if (size <= uVar5) {
        uVar5 = (uint)size;
      }
      for (; iVar1 < (int)uVar5; iVar1 = iVar1 + 1) {
        puVar2 = puVar4;
        pbVar6 = addrs + iVar1;
        do {
          puVar3 = puVar2 + 4;
          pbVar7 = (bt_hci_vs_static_addr *)((pbVar6->bdaddr).val + 4);
          *(undefined4 *)(pbVar6->bdaddr).val = *(undefined4 *)puVar2;
          puVar2 = puVar3;
          pbVar6 = pbVar7;
        } while (puVar3 != puVar4 + 0x14);
        *(undefined2 *)(pbVar7->bdaddr).val = *(undefined2 *)puVar3;
        puVar4 = puVar4 + 0x16;
      }
      net_buf_unref(in_stack_ffffffcc);
      if (uVar5 == 0) {
        local_1c = "No static addresses stored in controller";
        local_20 = 2;
        LOG_WRN(&PTR_s_bt_id_0008b900,0x1080,&local_20,2,in_stack_ffffffc8,
                (uint8_t *)in_stack_ffffffcc,in_stack_ffffffd0);
      }
      goto LAB_00058624;
    }
    local_1c = "Failed to read static addresses";
  }
  else {
    local_1c = "Read Static Addresses command not available";
  }
  uVar5 = 0;
  local_20 = 2;
  LOG_WRN(&PTR_s_bt_id_0008b900,0x1080,&local_20,2,in_stack_ffffffc8,(uint8_t *)in_stack_ffffffcc,
          in_stack_ffffffd0);
LAB_00058624:
  return (uint8_t)uVar5;
}


