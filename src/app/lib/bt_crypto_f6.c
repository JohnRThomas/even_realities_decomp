/*
 * Function: bt_crypto_f6
 * Entry:    00086dec
 * Prototype: int __stdcall bt_crypto_f6(uint8_t * w, uint8_t * n1, uint8_t * n2, uint8_t * r, uint8_t * iocap, bt_addr_le_t * a1, bt_addr_le_t * a2, uint8_t * check)
 */


/* exclude_from_export_ai */

int bt_crypto_f6(uint8_t *w,uint8_t *n1,uint8_t *n2,uint8_t *r,uint8_t *iocap,bt_addr_le_t *a1,
                bt_addr_le_t *a2,uint8_t *check)

{
  int iVar1;
  size_t length;
  uint8_t auStack_74 [16];
  uint8_t auStack_64 [16];
  undefined1 auStack_54 [16];
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [3];
  uint8_t local_31;
  undefined4 local_30;
  undefined2 local_2c;
  uint8_t local_2a;
  undefined4 local_29;
  undefined2 local_25;
  
  sys_memcpy_swap(auStack_64,n1,0x10);
  sys_memcpy_swap(auStack_54,n2,0x10);
  sys_memcpy_swap(auStack_44,r,0x10);
  sys_memcpy_swap(auStack_34,iocap,3);
  local_31 = a1->type;
  local_30 = *(undefined4 *)(a1->a).val;
  local_2c = *(undefined2 *)((a1->a).val + 4);
  sys_memcpy_swap(&local_30,&a1->a,6);
  local_2a = a2->type;
  local_29 = *(undefined4 *)(a2->a).val;
  local_25 = *(undefined2 *)((a2->a).val + 4);
  sys_memcpy_swap(&local_29,&a2->a,6);
  sys_memcpy_swap(auStack_74,w,0x10);
  iVar1 = bt_crypto_aes_cmac(auStack_74,auStack_64,0x41,check);
  if (iVar1 == 0) {
    sys_mem_swap(check,length);
  }
  return iVar1;
}


