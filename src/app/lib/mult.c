/*
 * Function: mult
 * Entry:    0007ba90
 * Prototype: undefined __stdcall mult(size_t param_1, int param_2, int param_3)
 */


/* exclude_from_export_ai */

void mult(size_t param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  uint uVar2;
  ushort *puVar3;
  uint *puVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  uint *puVar16;
  uint *puVar17;
  
  iVar6 = param_2;
  if (*(int *)(param_3 + 0x10) <= *(int *)(param_2 + 0x10)) {
    iVar6 = param_3;
    param_3 = param_2;
  }
  iVar14 = *(int *)(param_3 + 0x10);
  iVar12 = *(int *)(iVar6 + 0x10);
  uVar2 = *(uint *)(param_3 + 4);
  iVar9 = iVar14 + iVar12;
  if (*(int *)(param_3 + 8) < iVar9) {
    uVar2 = uVar2 + 1;
  }
  puVar1 = Balloc(param_1,uVar2);
  if (puVar1 == (undefined4 *)0x0) {
    __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/mprec.c"
                  ,0x15d,(char *)0x0,"Balloc succeeded");
    puVar1 = extraout_r0;
  }
  puVar8 = puVar1 + 5;
  puVar11 = puVar8 + iVar9;
  for (puVar4 = puVar8; puVar4 < puVar11; puVar4 = puVar4 + 1) {
    *puVar4 = 0;
  }
  puVar3 = (ushort *)(iVar6 + 0x14);
  puVar4 = (uint *)(param_3 + 0x14 + iVar14 * 4);
  puVar5 = puVar3 + iVar12 * 2;
  iVar6 = ((int)puVar4 + (-0x15 - param_3) & 0xfffffffcU) + 4;
  if (puVar4 < (uint *)(param_3 + 0x15)) {
    iVar6 = 4;
  }
  while (puVar3 < puVar5) {
    uVar2 = (uint)*puVar3;
    if (uVar2 != 0) {
      uVar15 = 0;
      puVar13 = puVar8;
      puVar17 = (uint *)(param_3 + 0x14);
      do {
        puVar16 = puVar17 + 1;
        uVar7 = uVar2 * (*puVar17 & 0xffff) + (*puVar13 & 0xffff) + uVar15;
        uVar10 = uVar2 * (*puVar17 >> 0x10) + (*puVar13 >> 0x10) + (uVar7 >> 0x10);
        uVar15 = uVar10 >> 0x10;
        *puVar13 = uVar7 & 0xffff | uVar10 * 0x10000;
        puVar13 = puVar13 + 1;
        puVar17 = puVar16;
      } while (puVar16 < puVar4);
      *(uint *)((int)puVar8 + iVar6) = uVar15;
    }
    uVar2 = (uint)puVar3[1];
    if (uVar2 != 0) {
      uVar15 = *puVar8;
      uVar7 = 0;
      puVar13 = (uint *)(param_3 + 0x14);
      puVar17 = puVar8;
      do {
        uVar7 = uVar2 * (ushort)*puVar13 + (uint)*(ushort *)((int)puVar17 + 2) + uVar7;
        *puVar17 = uVar15 & 0xffff | uVar7 * 0x10000;
        puVar16 = puVar13 + 1;
        uVar15 = uVar2 * (*puVar13 >> 0x10) + (uint)(ushort)puVar17[1] + (uVar7 >> 0x10);
        uVar7 = uVar15 >> 0x10;
        puVar13 = puVar16;
        puVar17 = puVar17 + 1;
      } while (puVar16 < puVar4);
      *(uint *)((int)puVar8 + iVar6) = uVar15;
    }
    puVar8 = puVar8 + 1;
    puVar3 = puVar3 + 2;
  }
  while ((0 < iVar9 && (puVar11 = puVar11 + -1, *puVar11 == 0))) {
    iVar9 = iVar9 + -1;
  }
  puVar1[4] = iVar9;
  return;
}


