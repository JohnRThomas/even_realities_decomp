/*
 * Function: img_mgmt_vercmp
 * Entry:    00084128
 * Prototype: int __stdcall img_mgmt_vercmp(image_version * a, image_version * b)
 */


/* exclude_from_export_ai */

int img_mgmt_vercmp(image_version *a,image_version *b)

{
  ushort uVar1;
  ushort uVar2;
  
  if (b->iv_major <= a->iv_major) {
    if (b->iv_major < a->iv_major) {
      return 1;
    }
    if (b->iv_minor <= a->iv_minor) {
      if (b->iv_minor < a->iv_minor) {
        return 1;
      }
      uVar1 = a->iv_revision;
      uVar2 = b->iv_revision;
      if (uVar2 <= uVar1) {
        if (uVar2 < uVar1) {
          a = (image_version *)&DAT_00000001;
        }
        if (uVar1 == uVar2) {
          a = (image_version *)0x0;
        }
        return (int)a;
      }
    }
  }
  return -1;
}


