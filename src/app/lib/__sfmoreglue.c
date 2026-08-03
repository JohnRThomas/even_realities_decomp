/*
 * Function: __sfmoreglue
 * Entry:    0008a2c4
 * Prototype: undefined4 * __stdcall __sfmoreglue(undefined4 * d, int n)
 */


/* exclude_from_export_ai */

undefined4 * __sfmoreglue(undefined4 *d,int n)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = (n + -1) * 0x68;
  puVar1 = _malloc_r((size_t)d,iVar2 + 0x74);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = n;
    puVar1[2] = puVar1 + 3;
    memset(puVar1 + 3,0,iVar2 + 0x68);
  }
  return puVar1;
}


