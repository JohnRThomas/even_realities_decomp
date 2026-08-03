/*
 * Function: strncmp
 * Entry:    0008a7e6
 * Prototype: int __stdcall strncmp(char * s1, char * s2, size_t n)
 */


/* exclude_from_export */

int strncmp(char *s1,char *s2,size_t n)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  
  if (n == 0) {
    iVar2 = 0;
  }
  else {
    pbVar3 = (byte *)(s2 + -1);
    pbVar1 = (byte *)s1;
    do {
      uVar4 = (uint)*pbVar1;
      pbVar3 = pbVar3 + 1;
      if ((uVar4 != *pbVar3) || (pbVar1 + 1 == (byte *)(s1 + n))) break;
      pbVar1 = pbVar1 + 1;
    } while (uVar4 != 0);
    iVar2 = uVar4 - *pbVar3;
  }
  return iVar2;
}


