/*
 * Function: cc3xx_free
 * Entry:    0008706c
 * Prototype: int __stdcall cc3xx_free(void)
 */


/* exclude_from_export */

int cc3xx_free(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = CC_LibFini((int *)0x0,(void *)0x0,0);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = -0x16;
  }
  return iVar2;
}


