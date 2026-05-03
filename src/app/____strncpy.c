/*
 * Function: $_?_strncpy
 * Entry:    0008a76e
 * Prototype: char * __stdcall $_?_strncpy(char * dst, char * src, size_t n)
 */


char * ____strncpy(char *dst,char *src,size_t n)

{
  byte bVar1;
  byte *pbVar2;
  size_t extraout_r2;
  byte *pbVar3;
  undefined8 uVar4;
  
  uVar4 = CONCAT44(src,dst);
  do {
    pbVar3 = (byte *)(dst + 1);
    if (*dst == 0) {
      pbVar2 = (byte *)((int)((ulonglong)uVar4 >> 0x20) + -1);
      while( true ) {
        pbVar2 = pbVar2 + 1;
        bVar1 = *pbVar2;
        pbVar3 = (byte *)(uint)bVar1;
        if (pbVar3 == (byte *)0x0) break;
        if (n == 0) goto LAB_0008a78a;
        n = n - 1;
        *dst = bVar1;
        dst = dst + 1;
      }
      if (n != 0) {
        *dst = bVar1;
        return (char *)uVar4;
      }
LAB_0008a78a:
      uVar4 = FUN_00054410();
      n = extraout_r2;
    }
    else if (n == 0) goto LAB_0008a78a;
    n = n - 1;
    dst = (char *)pbVar3;
  } while( true );
}


