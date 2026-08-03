/*
 * Function: str_out
 * Entry:    00081516
 * Prototype: int __stdcall str_out(int c, str_context * ctx)
 */


/* exclude_from_export */

int str_out(int c,str_context *ctx)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar1 = ctx[2];
  iVar3 = *ctx;
  iVar4 = iVar1 + 1;
  if ((iVar3 == 0) || (ctx[1] <= iVar1)) {
    ctx[2] = iVar4;
  }
  else {
    iVar2 = ctx[1] + -1;
    bVar5 = iVar2 == iVar1;
    if (bVar5) {
      iVar1 = 0;
    }
    ctx[2] = iVar4;
    if (bVar5) {
      *(char *)(iVar3 + iVar2) = (char)iVar1;
    }
    if (!bVar5) {
      *(char *)(iVar3 + iVar1) = (char)c;
    }
  }
  return c;
}


