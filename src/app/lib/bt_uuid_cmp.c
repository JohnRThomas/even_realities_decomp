/*
 * Function: bt_uuid_cmp
 * Entry:    000844f6
 * Prototype: int __stdcall bt_uuid_cmp(bt_uuid * u1, bt_uuid * u2)
 */


/* exclude_from_export_ai */

int bt_uuid_cmp(bt_uuid *u1,bt_uuid *u2)

{
  uint8_t uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bt_uuid_128 abStack_30 [4];
  bt_uuid_128 abStack_1c [4];
  
  uVar1 = u2->type;
  if (uVar1 == u1->type) {
    if (uVar1 == '\x01') {
      uVar3 = *(uint *)(u1 + 4);
      uVar4 = *(uint *)(u2 + 4);
    }
    else {
      if (uVar1 == '\x02') {
        iVar2 = memcmp(u1 + 1,u2 + 1,0x10);
        return iVar2;
      }
      if (uVar1 != '\0') {
        return -0x16;
      }
      uVar3 = (uint)*(ushort *)(u1 + 2);
      uVar4 = (uint)*(ushort *)(u2 + 2);
    }
    iVar2 = uVar3 - uVar4;
  }
  else {
    uuid_to_uuid128(u1,abStack_30);
    uuid_to_uuid128(u2,abStack_1c);
    iVar2 = memcmp((void *)((int)&abStack_30[0].uuid + 1),(void *)((int)&abStack_1c[0].uuid + 1),
                   0x10);
  }
  return iVar2;
}


