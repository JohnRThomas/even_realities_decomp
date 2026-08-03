/*
 * Function: hci_cmd_done
 * Entry:    00056ba4
 * Prototype: void __stdcall hci_cmd_done(uint16_t opcode, uint8_t status, net_buf * buf)
 */


/* exclude_from_export */

void hci_cmd_done(uint16_t opcode,uint8_t status,net_buf *buf)

{
  byte bVar1;
  net_buf_pool *pnVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  dword in_stack_ffffffb8;
  uint8_t *in_stack_ffffffbc;
  void *in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  uint local_30;
  char *local_2c;
  net_buf_pool *pnStack_28;
  undefined *local_24;
  
  uVar4 = (uint)opcode;
  pnVar2 = net_buf_pool_get((uint)buf->pool_id);
  if (pnVar2 == (net_buf_pool *)&DAT_20003cec) {
    iVar3 = net_buf_id(buf);
    if (*(ushort *)(&DAT_2000b5d6 + iVar3 * 0xc) == uVar4) {
      if (DAT_20002140 != (net_buf *)0x0) {
        net_buf_unref(DAT_20002140);
        DAT_20002140 = (net_buf *)0x0;
      }
      iVar3 = net_buf_id(buf);
      if ((*(int *)(&DAT_2000b5d8 + iVar3 * 0xc) != 0) && (status == '\0')) {
        iVar3 = net_buf_id(buf);
        piVar5 = *(int **)(&DAT_2000b5d8 + iVar3 * 0xc);
        uVar4 = 1 << (piVar5[1] & 0x1fU);
        uVar6 = (uint)piVar5[1] >> 5;
        if ((char)piVar5[2] == '\0') {
          atomic_and((atomic_t *)(*piVar5 + uVar6 * 4),~uVar4);
        }
        else {
          atomic_or((atomic_t *)(*piVar5 + uVar6 * 4),uVar4);
        }
      }
      iVar3 = net_buf_id(buf);
      if (*(int *)(&DAT_2000b5dc + iVar3 * 0xc) != 0) {
        iVar3 = net_buf_id(buf);
        (&DAT_2000b5d4)[iVar3 * 0xc] = status;
        iVar3 = net_buf_id(buf);
        k_sem_give(*(k_sem **)(&DAT_2000b5dc + iVar3 * 0xc));
      }
    }
    else {
      iVar3 = net_buf_id(buf);
      local_24 = (undefined *)(uint)*(ushort *)(&DAT_2000b5d6 + iVar3 * 0xc);
      local_2c = "OpCode 0x%04x completed instead of expected 0x%04x";
      local_30 = 4;
      pnStack_28 = (net_buf_pool *)uVar4;
      LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x2080,&local_30,4,(dword)in_stack_ffffffc0,
              in_stack_ffffffc4,in_stack_ffffffc8);
    }
  }
  else {
    bVar1 = buf->pool_id;
    pnStack_28 = net_buf_pool_get((uint)bVar1);
    local_24 = &DAT_20003cec;
    local_30 = uVar4;
    local_2c = (char *)(uint)bVar1;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x3080,&stack0xffffffc8,6,in_stack_ffffffb8,
            in_stack_ffffffbc,in_stack_ffffffc0);
  }
  return;
}


