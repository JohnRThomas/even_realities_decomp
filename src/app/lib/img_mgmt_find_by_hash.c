/*
 * Function: img_mgmt_find_by_hash
 * Entry:    00084206
 * Prototype: int __stdcall img_mgmt_find_by_hash(uint8_t * find, image_version * ver)
 */


/* exclude_from_export_ai */

int img_mgmt_find_by_hash(uint8_t *find,image_version *ver)

{
  int iVar1;
  int image_slot;
  uint8_t auStack_30 [32];
  
  image_slot = 0;
  while ((iVar1 = img_mgmt_read_info(image_slot,ver,auStack_30,(uint32_t *)0x0), iVar1 != 0 ||
         (iVar1 = memcmp(auStack_30,find,0x20), iVar1 != 0))) {
    image_slot = image_slot + 1;
    if (image_slot == 4) {
      return -1;
    }
  }
  return image_slot;
}


