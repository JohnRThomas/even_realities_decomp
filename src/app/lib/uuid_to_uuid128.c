/*
 * Function: uuid_to_uuid128
 * Entry:    00056490
 * Prototype: void __stdcall uuid_to_uuid128(bt_uuid * src, bt_uuid_128 * dst)
 */


/* exclude_from_export_ai */

void uuid_to_uuid128(bt_uuid *src,bt_uuid_128 *dst)

{
  uint8_t uVar1;
  undefined2 uVar2;
  bt_uuid *pbVar3;
  bt_uuid_128 *pbVar5;
  byte *pbVar6;
  dword *pdVar7;
  undefined4 uVar9;
  bt_uuid *pbVar4;
  dword *pdVar8;
  
  uVar1 = src->type;
  if (uVar1 == '\x01') {
    pbVar5 = dst;
    pdVar7 = &DAT_000f0cde;
    do {
      pdVar8 = pdVar7 + 1;
      pbVar6 = &pbVar5->val_BT_UUID_SIZE_128_;
      pbVar5->uuid = *pdVar7;
      pbVar5 = (bt_uuid_128 *)pbVar6;
      pdVar7 = pdVar8;
    } while (pdVar8 != (dword *)&UNK_000f0cee);
    *pbVar6 = 0;
    uVar9 = *(undefined4 *)(src + 4);
    *(char *)((int)&dst[2].uuid + 3) = (char)uVar9;
    *(char *)&dst[3].uuid = (char)((uint)uVar9 >> 0x10);
    dst[2].val_BT_UUID_SIZE_128_ = (byte)((uint)uVar9 >> 8);
    *(char *)((int)&dst[3].uuid + 1) = (char)((uint)uVar9 >> 0x18);
  }
  else if (uVar1 == '\x02') {
    pbVar4 = src;
    do {
      pbVar3 = pbVar4 + 4;
      pbVar6 = &dst->val_BT_UUID_SIZE_128_;
      dst->uuid = *(dword *)pbVar4;
      pbVar4 = pbVar3;
      dst = (bt_uuid_128 *)pbVar6;
    } while (pbVar3 != src + 0x10);
    *pbVar6 = pbVar3->type;
  }
  else if (uVar1 == '\0') {
    pbVar5 = dst;
    pdVar7 = &DAT_000f0cde;
    do {
      pdVar8 = pdVar7 + 1;
      pbVar6 = &pbVar5->val_BT_UUID_SIZE_128_;
      pbVar5->uuid = *pdVar7;
      pbVar5 = (bt_uuid_128 *)pbVar6;
      pdVar7 = pdVar8;
    } while (pdVar8 != (dword *)&UNK_000f0cee);
    *pbVar6 = 0;
    uVar2 = *(undefined2 *)(src + 2);
    *(char *)((int)&dst[2].uuid + 3) = (char)uVar2;
    dst[2].val_BT_UUID_SIZE_128_ = (byte)((ushort)uVar2 >> 8);
  }
  return;
}


