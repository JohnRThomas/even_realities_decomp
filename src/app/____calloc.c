/*
 * Function: $_?_calloc
 * Entry:    0007a0c8
 * Prototype: void * __stdcall $_?_calloc(size_t nmemb, size_t size)
 */


void * ____calloc(size_t nmemb,size_t size)

{
  uint *puVar1;
  uint *puVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  uVar7 = (size + 3 & 0xfffffffc) + 8;
  if (uVar7 < 0xc) {
    uVar7 = 0xc;
  }
  if (((int)uVar7 < 0) || (uVar7 < size)) {
    *(undefined4 *)nmemb = 0xc;
  }
  else {
    __lock_acquire_recursive();
    puVar2 = DAT_2000d608;
    for (puVar6 = DAT_2000d608; puVar6 != (uint *)0x0; puVar6 = (uint *)puVar6[1]) {
      uVar5 = *puVar6 - uVar7;
      if (-1 < (int)uVar5) {
        if (0xb < uVar5) {
          *puVar6 = uVar5;
          puVar6 = (uint *)((int)puVar6 + uVar5);
          goto LAB_0007a12c;
        }
        puVar1 = (uint *)puVar6[1];
        if (puVar2 != puVar6) {
          puVar2[1] = puVar6[1];
          puVar1 = DAT_2000d608;
        }
        goto LAB_0007a13a;
      }
      puVar2 = puVar6;
    }
    if (DAT_2000d604 == 0) {
      DAT_2000d604 = sbrk_aligned((int *)nmemb,0);
    }
    puVar2 = (uint *)sbrk_aligned((int *)nmemb,uVar7);
    if ((puVar2 != (uint *)0xffffffff) &&
       ((puVar6 = (uint *)((int)puVar2 + 3U & 0xfffffffc), puVar2 == puVar6 ||
        (iVar4 = sbrk_aligned((int *)nmemb,(int)puVar6 - (int)puVar2), iVar4 != -1)))) {
LAB_0007a12c:
      *puVar6 = uVar7;
      puVar1 = DAT_2000d608;
LAB_0007a13a:
      DAT_2000d608 = puVar1;
      __lock_release_recursive();
      puVar2 = puVar6 + 1;
      pvVar3 = (void *)((int)puVar6 + 0xbU & 0xfffffff8);
      iVar4 = (int)pvVar3 - (int)puVar2;
      if (iVar4 != 0) {
        puVar2 = (uint *)((int)puVar2 - (int)pvVar3);
      }
      if (iVar4 == 0) {
        return pvVar3;
      }
      *(uint **)((int)puVar6 + iVar4) = puVar2;
      return pvVar3;
    }
    *(undefined4 *)nmemb = 0xc;
    __lock_release_recursive();
  }
  return (void *)0x0;
}


