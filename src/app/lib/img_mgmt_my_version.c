/*
 * Function: img_mgmt_my_version
 * Entry:    0008423a
 * Prototype: int __stdcall img_mgmt_my_version(image_version * ver)
 */


/* exclude_from_export_ai */

int img_mgmt_my_version(image_version *ver)

{
  int iVar1;
  
  iVar1 = img_mgmt_read_info(0,ver,(uint8_t *)0x0,(uint32_t *)0x0);
  return iVar1;
}


