/*
 * Function: bs_list_img_ver
 * Entry:    00055234
 * Prototype: void __stdcall bs_list_img_ver(char * dst, int maxlen, image_version * ver)
 */


/* exclude_from_export */

void bs_list_img_ver(char *dst,int maxlen,image_version *ver)

{
  int iVar1;
  
  iVar1 = snprintf((char *)maxlen,0x19,"%hu.%hu.%hu",(ushort)(byte)*dst,(ushort)(byte)dst[1],
                   *(ushort *)(dst + 2));
  if (*(uint *)(dst + 4) != 0) {
    snprintf((char *)(maxlen + iVar1),0x19 - iVar1,".%u",*(uint *)(dst + 4));
  }
  return;
}


