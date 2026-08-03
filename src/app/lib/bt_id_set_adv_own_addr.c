/*
 * Function: bt_id_set_adv_own_addr
 * Entry:    00058700
 * Prototype: int __stdcall bt_id_set_adv_own_addr(bt_le_ext_adv * adv, uint32_t options, bool dir_adv, uint8_t * own_addr_type)
 */


/* exclude_from_export_ai */

int bt_id_set_adv_own_addr(bt_le_ext_adv *adv,uint32_t options,bool dir_adv,uint8_t *own_addr_type)

{
  int iVar1;
  int extraout_r0;
  int extraout_r0_00;
  int iVar2;
  byte bVar3;
  uint8_t uVar4;
  uint uVar5;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  
  if ((adv == (bt_le_ext_adv *)0x0) || (own_addr_type == (uint8_t *)0x0)) {
    return -0x16;
  }
  uVar5 = (uint)adv->id;
  if ((int)(options << 0xc) < 0) {
    if ((int)(options << 0x1d) < 0) {
      local_1c = "Can\'t set both IDENTITY & NRPA";
      local_20 = 2;
      LOG_WRN(&PTR_s_bt_id_0008b900,0x1040,&local_20,2,in_stack_ffffffd0,in_stack_ffffffd4,
              in_stack_ffffffd8);
      return -0x16;
    }
    iVar1 = set_random_address((bt_addr_t *)adv);
    iVar2 = 0;
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  else {
    if ((int)(options << 0x1f) < 0) {
      if (dir_adv) {
        if (((int)(options << 0x1a) < 0) && (-1 < (int)((uint)(byte)DAT_200020d8 << 0x19))) {
          return -0x86;
        }
        bVar3 = *(byte *)((int)&bt_dev + uVar5 * 7);
        if (bVar3 == 1) goto LAB_00058788;
        *own_addr_type = bVar3;
      }
      else {
        bVar3 = *(byte *)((int)&bt_dev + uVar5 * 7);
        if (bVar3 != 1) goto LAB_00058784;
LAB_00058788:
        le_set_random_address((net_buf *)adv,(net_buf **)((int)&bt_dev + uVar5 * 7 + 1));
        if (extraout_r0 != 0) {
          return extraout_r0;
        }
        bVar3 = *(byte *)((int)&bt_dev + uVar5 * 7);
        *own_addr_type = bVar3;
        if (!dir_adv) {
          return 0;
        }
      }
      if (-1 < (int)(options << 0x1a)) {
        return 0;
      }
      bVar3 = bVar3 | 2;
LAB_00058784:
      *own_addr_type = bVar3;
      return 0;
    }
    if ((int)(options << 0x1d) < 0) {
      bVar3 = *(byte *)((int)&bt_dev + uVar5 * 7);
      if (bVar3 != 1) goto LAB_00058784;
      le_set_random_address
                ((net_buf *)adv,(net_buf **)((int)&bt_dev + (short)(ushort)adv->id * 7 + 1));
      uVar4 = *(uint8_t *)((int)&bt_dev + uVar5 * 7);
      iVar2 = extraout_r0_00;
      goto LAB_000587ca;
    }
    iVar2 = set_random_address((bt_addr_t *)adv);
  }
  uVar4 = '\x01';
LAB_000587ca:
  *own_addr_type = uVar4;
  return iVar2;
}


