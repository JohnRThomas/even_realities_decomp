/*
 * Function: diff
 * Entry:    0007bd70
 * Prototype: undefined4 * __stdcall diff(size_t param_1, void * param_2, void * param_3)
 */


/* exclude_from_export_ai */

undefined4 * diff(size_t param_1,void *param_2,void *param_3)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *extraout_r0;
  int iVar5;
  uint uVar6;
  undefined4 *extraout_r2;
  undefined4 *puVar7;
  void *extraout_r3;
  uint uVar8;
  uint *puVar9;
  int *piVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  uint *puVar15;
  bool bVar16;
  uint *local_2c;
  
  iVar3 = cmp(param_2,param_3);
  bVar16 = iVar3 < 0;
  if (iVar3 == 0) {
    puVar4 = Balloc(param_1,0);
    puVar7 = puVar4;
    if (puVar4 != (undefined4 *)0x0) goto LAB_0007bd9e;
    iVar5 = 0x232;
  }
  else {
    pvVar1 = param_2;
    pvVar2 = extraout_r3;
    if (bVar16) {
      iVar3 = 1;
      pvVar1 = param_3;
      pvVar2 = param_2;
    }
    if (!bVar16) {
      iVar3 = 0;
      pvVar2 = param_3;
    }
    puVar4 = Balloc(param_1,*(uint *)((int)pvVar1 + 4));
    if (puVar4 != (undefined4 *)0x0) {
      iVar14 = *(int *)((int)pvVar1 + 0x10);
      iVar5 = *(int *)((int)pvVar2 + 0x10);
      puVar4[3] = iVar3;
      local_2c = (uint *)((int)pvVar1 + 0x10);
      puVar9 = (uint *)((int)pvVar2 + 0x14) + iVar5;
      puVar15 = (uint *)((int)pvVar1 + iVar14 * 4 + 0x14);
      iVar3 = 0;
      puVar11 = puVar4 + 5;
      puVar13 = (uint *)((int)pvVar2 + 0x14);
      do {
        puVar12 = puVar13 + 1;
        local_2c = local_2c + 1;
        uVar8 = ((*local_2c & 0xffff) - (*puVar13 & 0xffff)) + iVar3;
        iVar5 = ((*local_2c >> 0x10) - (*puVar13 >> 0x10)) + ((int)uVar8 >> 0x10);
        iVar3 = iVar5 >> 0x10;
        *puVar11 = uVar8 & 0xffff | iVar5 * 0x10000;
        puVar11 = puVar11 + 1;
        puVar13 = puVar12;
      } while (puVar12 < puVar9);
      iVar5 = ((int)puVar9 + (-0x15 - (int)pvVar2) & 0xfffffffcU) + 4;
      if (puVar9 < (uint *)((int)pvVar2 + 0x15)) {
        iVar5 = 4;
      }
      puVar9 = (uint *)(iVar5 + (int)(puVar4 + 5));
      puVar12 = (uint *)((int)pvVar1 + iVar5 + 0x14);
      puVar13 = puVar9;
      for (puVar11 = puVar12; puVar11 < puVar15; puVar11 = puVar11 + 1) {
        uVar8 = *puVar11;
        uVar6 = uVar8 + iVar3;
        iVar5 = (uVar8 >> 0x10) + ((int)((uVar8 & 0xffff) + iVar3) >> 0x10);
        iVar3 = iVar5 >> 0x10;
        *puVar13 = uVar6 & 0xffff | iVar5 * 0x10000;
        puVar13 = puVar13 + 1;
      }
      uVar8 = (int)puVar15 + (3 - (int)puVar12) & 0xfffffffc;
      if (puVar15 < (uint *)((int)puVar12 + -3)) {
        uVar8 = 0;
      }
      piVar10 = (int *)((int)puVar9 + uVar8);
      while (piVar10 = piVar10 + -1, *piVar10 == 0) {
        iVar14 = iVar14 + -1;
      }
      puVar4[4] = iVar14;
      return puVar4;
    }
    iVar5 = 0x240;
  }
  __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/mprec.c"
                ,iVar5,(char *)0x0,"Balloc succeeded");
  puVar4 = extraout_r0;
  puVar7 = extraout_r2;
LAB_0007bd9e:
  puVar4[4] = 1;
  puVar4[5] = iVar3;
  return puVar7;
}


