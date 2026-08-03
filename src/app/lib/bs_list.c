/*
 * Function: bs_list
 * Entry:    00054d6c
 * Prototype: void __stdcall bs_list(char * buf, int len)
 */


/* exclude_from_export */

void bs_list(char *buf,int len)

{
  bool bVar1;
  int iVar2;
  int extraout_r0;
  char *string;
  uint in_r2;
  image_version *ver;
  size_t size;
  uint local_68;
  zcbor_string local_64;
  image_version iStack_5c;
  char acStack_54 [24];
  undefined1 local_3c;
  uint8_t auStack_38 [36];
  
  local_64.len = 0x20;
  local_64.value = auStack_38;
  iVar2 = img_mgmt_read_info(len,&iStack_5c,local_64.value,&local_68);
  if (((((iVar2 == 0) && (bVar1 = zcbor_map_start_encode((zcbor_state_t *)buf,0xf), bVar1)) &&
       (bVar1 = zcbor_tstr_encode_ptr(buf,"image",5), bVar1)) &&
      ((bVar1 = zcbor_uint32_encode((zcbor_state_t *)buf,(uint32_t *)((uint)len >> 1)), bVar1 &&
       (bVar1 = zcbor_tstr_encode_ptr(buf,"slot",4), bVar1)))) &&
     ((bVar1 = zcbor_uint32_encode((zcbor_state_t *)buf,(uint32_t *)(len & 1)), bVar1 &&
      (bVar1 = zcbor_tstr_encode_ptr(buf,"version",7), bVar1)))) {
    bs_list_img_ver((char *)&iStack_5c,(int)acStack_54,ver);
    if (extraout_r0 < 0) {
      size = 5;
      string = "<???>";
    }
    else {
      local_3c = 0;
      size = strlen(acStack_54);
      string = acStack_54;
    }
    bVar1 = zcbor_tstr_encode_ptr(buf,string,size);
    if (((((bVar1) && (bVar1 = zcbor_tstr_encode_ptr(buf,"hash",4), bVar1)) &&
         ((bVar1 = zcbor_bstr_encode((zcbor_state_t *)buf,&local_64), bVar1 &&
          (((bVar1 = zcbor_tstr_encode_ptr(buf,"bootable",8), bVar1 &&
            (bVar1 = zcbor_bool_put((zcbor_state_t *)buf,(bool *)(((local_68 ^ 0x10) & 0x1f) >> 4)),
            bVar1)) && (bVar1 = zcbor_tstr_encode_ptr(buf,"pending",7), bVar1)))))) &&
        ((bVar1 = zcbor_bool_put((zcbor_state_t *)buf,(bool *)((in_r2 & 3) >> 1)), bVar1 &&
         (bVar1 = zcbor_tstr_encode_ptr(buf,"confirmed",9), bVar1)))) &&
       ((bVar1 = zcbor_bool_put((zcbor_state_t *)buf,(bool *)((in_r2 & 7) >> 2)), bVar1 &&
        (((bVar1 = zcbor_tstr_encode_ptr(buf,"active",6), bVar1 &&
          (bVar1 = zcbor_bool_put((zcbor_state_t *)buf,(bool *)(in_r2 & 1)), bVar1)) &&
         ((bVar1 = zcbor_tstr_encode_ptr(buf,"permanent",9), bVar1 &&
          (bVar1 = zcbor_bool_put((zcbor_state_t *)buf,(bool *)((in_r2 & 0xf) >> 3)), bVar1))))))))
    {
      zcbor_map_end_encode((zcbor_state_t *)buf,0xf);
    }
  }
  return;
}


