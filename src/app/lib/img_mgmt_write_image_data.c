/*
 * Function: img_mgmt_write_image_data
 * Entry:    00054b1c
 * Prototype: int __stdcall img_mgmt_write_image_data(uint offset, void * data, uint num_bytes, bool last)
 */


/* exclude_from_export_ai */

int img_mgmt_write_image_data(uint offset,void *data,uint num_bytes,bool last)

{
  int iVar1;
  int iVar2;
  
  if ((offset == 0) &&
     (iVar2 = flash_img_init_id((flash_img_context *)&DAT_2000b334,(uint8_t)DAT_2000b55c),
     iVar2 != 0)) {
    iVar2 = 10;
  }
  else {
    iVar1 = flash_img_buffered_write((flash_img_context *)&DAT_2000b334,data,num_bytes,last);
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = 0xc;
    }
  }
  return iVar2;
}


