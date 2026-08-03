/*
 * Function: img_mgmt_read_info
 * Entry:    000552e4
 * Prototype: int __stdcall img_mgmt_read_info(int image_slot, image_version * ver, uint8_t * hash, uint32_t * flags)
 */


/* exclude_from_export_ai */

int img_mgmt_read_info(int image_slot,image_version *ver,uint8_t *hash,uint32_t *flags)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint offset;
  uint uVar5;
  byte local_45;
  short local_44;
  ushort local_42;
  int local_40 [2];
  ushort local_38;
  int local_34;
  uint32_t local_30;
  undefined4 local_2c;
  dword dStack_28;
  
  iVar1 = img_mgmt_erased_val(image_slot,&local_45);
  if (iVar1 != 0) {
    return 2;
  }
  iVar1 = img_mgmt_read(image_slot,0,local_40,0x20);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (ver == (image_version *)0x0) {
    if (local_40[0] != -0x690c47c3) {
LAB_000553a2:
      if (local_40[0] == (uint)local_45 * 0x1010101) {
        return 3;
      }
      return 0x17;
    }
  }
  else {
    memset(ver,(uint)local_45,8);
    if (local_40[0] != -0x690c47c3) goto LAB_000553a2;
    ver->iv_major = (undefined1)local_2c;
    ver->iv_minor = local_2c._1_1_;
    ver->iv_revision = local_2c._2_2_;
    ver->iv_build_num = dStack_28;
  }
  if (flags != (uint32_t *)0x0) {
    *flags = local_30;
  }
  uVar3 = (uint)local_38 + local_34;
  iVar1 = img_mgmt_read(image_slot,uVar3,&local_44,4);
  if ((iVar1 == 0) && (local_44 == 0x6908)) {
    uVar3 = uVar3 + local_42;
  }
  iVar1 = img_mgmt_read(image_slot,uVar3,&local_44,4);
  if ((iVar1 == 0) && (local_44 == 0x6907)) {
    uVar4 = (uint)local_42 + uVar3 + 4;
    uVar5 = 0;
    uVar3 = uVar3 + 4;
    while (offset = uVar3 + 4, offset <= uVar4) {
      iVar1 = img_mgmt_read(image_slot,uVar3,&local_44,4);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = (uint)local_42;
      if (local_44 == 0xff) {
        if (uVar2 == 0xffff) {
          return 5;
        }
LAB_000553ee:
        uVar3 = uVar2 + 4 + uVar3;
      }
      else {
        if ((local_44 != 0x10) || (uVar2 != 0x20)) goto LAB_000553ee;
        if (uVar5 != 0) {
          return 6;
        }
        if (hash != (uint8_t *)0x0) {
          if (uVar4 < uVar3 + 0x24) {
            return 7;
          }
          iVar1 = img_mgmt_read(image_slot,offset,hash,0x20);
          if (iVar1 != 0) {
            return iVar1;
          }
        }
        uVar5 = 1;
        uVar3 = offset;
      }
    }
    iVar1 = (uVar5 ^ 1) << 3;
  }
  else {
    iVar1 = 4;
  }
  return iVar1;
}


