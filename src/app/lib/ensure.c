/*
 * Function: ensure
 * Entry:    00088708
 * Prototype: uchar * __stdcall ensure(printbuffer * p, size_t needed)
 */


/* exclude_from_export */

uchar * ensure(printbuffer *p,size_t needed)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  void *d;
  int iVar4;
  
  if (p == (printbuffer *)0x0) {
    return (uchar *)0x0;
  }
  iVar1 = *(int *)p->opaque;
  if (iVar1 == 0) {
    return (uchar *)0x0;
  }
  uVar2 = *(uint *)p[1].opaque;
  if ((uVar2 != 0) && (uVar2 <= *(uint *)p[2].opaque)) {
    return (uchar *)0x0;
  }
  if ((int)needed < 0) {
    return (uchar *)0x0;
  }
  d = *(void **)p[2].opaque;
  uVar3 = (int)d + needed + 1;
  if (uVar2 < uVar3) {
    if (*(int *)p[4].opaque != 0) {
      return (uchar *)0x0;
    }
    if (uVar3 < 0x40000000) {
      iVar4 = (int)d + needed + 2;
    }
    else {
      if ((int)uVar3 < 0) {
        return (uchar *)0x0;
      }
      iVar4 = 0x7fffffff;
    }
    if (*(code **)p[8].opaque == (code *)0x0) {
      d = (void *)(**(code **)p[6].opaque)(iVar4);
      if (d == (void *)0x0) goto LAB_0008874e;
      memcpy(d,*(void **)p->opaque,*(int *)p[2].opaque + 1);
      (**(code **)p[7].opaque)(*(undefined4 *)p->opaque);
    }
    else {
      d = (void *)(**(code **)p[8].opaque)(iVar1,iVar4);
      if (d == (void *)0x0) {
LAB_0008874e:
        (**(code **)p[7].opaque)(*(undefined4 *)p->opaque);
        *(undefined4 *)p->opaque = 0;
        *(undefined4 *)p[1].opaque = 0;
        return (uchar *)0x0;
      }
    }
    *(void **)p->opaque = d;
    *(int *)p[1].opaque = iVar4;
    iVar1 = *(int *)p[2].opaque;
  }
  return (uchar *)(iVar1 + (int)d);
}


