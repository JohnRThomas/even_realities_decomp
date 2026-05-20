/*
 * Function: bt_keys_get_addr_impl
 * Entry:    000618c0
 * Prototype: bt_keys * __stdcall bt_keys_get_addr_impl(uint param_1, undefined4 * param_2)
 */


bt_keys * bt_keys_get_addr_impl(uint param_1,undefined4 *param_2)

{
  bt_keys *pbVar1;
  int iVar2;
  int iVar3;
  bt_keys *pbVar4;
  undefined4 uVar5;
  
  if (key_pool.id == param_1) {
    iVar2 = memcmp(&key_pool.addr,param_2,7);
    iVar3 = 0;
    if (iVar2 != 0) goto LAB_000618d8;
LAB_0006191a:
    pbVar4 = (bt_keys *)(key_pool.addr.a.val + iVar3 + -2);
  }
  else {
LAB_000618d8:
    iVar3 = memcmp(&key_pool.addr,&DAT_000f0b50,7);
    if (iVar3 == 0) {
      iVar3 = 0;
      if ((DAT_2000b988 == param_1) && (iVar2 = memcmp(&DAT_2000b989,param_2,7), iVar2 == 0)) {
LAB_00061918:
        iVar3 = 0x5c;
        goto LAB_0006191a;
      }
    }
    else {
      if ((DAT_2000b988 == param_1) && (iVar3 = memcmp(&DAT_2000b989,param_2,7), iVar3 == 0))
      goto LAB_00061918;
      iVar3 = memcmp(&DAT_2000b989,&DAT_000f0b50,7);
      if (iVar3 != 0) {
        return (bt_keys *)0x0;
      }
      iVar3 = 1;
    }
    (&key_pool)[iVar3].id = (uchar)param_1;
    uVar5 = *param_2;
    pbVar4 = &key_pool + iVar3;
    pbVar1 = &key_pool + iVar3;
    (pbVar1->addr).type = (char)uVar5;
    (pbVar1->addr).a.val[0] = (char)((uint)uVar5 >> 8);
    (pbVar1->addr).a.val[1] = (char)((uint)uVar5 >> 0x10);
    (pbVar1->addr).a.val[2] = (char)((uint)uVar5 >> 0x18);
    *(undefined2 *)((&key_pool)[iVar3].addr.a.val + 3) = *(undefined2 *)(param_2 + 1);
    (&key_pool)[iVar3].addr.a.val[5] = *(uint8_t *)((int)param_2 + 6);
  }
  return pbVar4;
}


