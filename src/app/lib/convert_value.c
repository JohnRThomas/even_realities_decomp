/*
 * Function: convert_value
 * Entry:    00081a28
 * Prototype: int __stdcall convert_value(uint32_t num, uint base, uint alpha, char * buftop)
 */


/* exclude_from_export */

int convert_value(uint32_t num,uint base,uint alpha,char *buftop)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)base < 1) {
    iVar1 = L'0';
  }
  else {
    *(int *)base = *(int *)base + -1;
    uVar2 = *(int *)(num + 4) * 10 + (int)((ulonglong)*(uint *)num * 10 >> 0x20);
    *(int *)num = (int)((ulonglong)*(uint *)num * 10);
    *(uint *)(num + 4) = uVar2 & 0xfffffff;
    iVar1 = (uVar2 >> 0x1c) + 0x30;
  }
  return iVar1;
}


