/*
 * Function: lshift
 * Entry:    0007bc98
 * Prototype: undefined4 * __stdcall lshift(size_t param_1, undefined4 * param_2, uint param_3)
 */


/* exclude_from_export_ai */

undefined4 * lshift(size_t param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint extraout_r1;
  uint *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int extraout_r3;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  uint *puVar13;
  
  uVar1 = (int)param_3 >> 5;
  iVar7 = param_2[4];
  uVar3 = param_2[1];
  iVar8 = param_2[2];
  iVar11 = iVar7 + uVar1 + 1;
  do {
    if (iVar11 <= iVar8) {
      puVar2 = Balloc(param_1,uVar3);
      if (puVar2 != (undefined4 *)0x0) {
        puVar5 = puVar2 + 4;
        for (iVar8 = 0; iVar8 < (int)uVar1; iVar8 = iVar8 + 1) {
          puVar5 = puVar5 + 1;
          *puVar5 = 0;
        }
        puVar10 = param_2 + 5;
        uVar3 = param_3 & 0x1f;
        puVar4 = puVar2 + (uVar1 & ~((int)param_3 >> 0x1f)) + 5;
        puVar13 = puVar10 + param_2[4];
        if (uVar3 == 0) {
          puVar4 = puVar4 + -1;
          do {
            puVar12 = puVar10 + 1;
            puVar4 = puVar4 + 1;
            *puVar4 = *puVar10;
            puVar10 = puVar12;
          } while (puVar12 < puVar13);
        }
        else {
          uVar6 = 0;
          puVar12 = puVar4;
          do {
            *puVar12 = *puVar10 << uVar3 | uVar6;
            puVar9 = puVar10 + 1;
            uVar6 = *puVar10 >> (0x20 - uVar3 & 0xff);
            puVar10 = puVar9;
            puVar12 = puVar12 + 1;
          } while (puVar9 < puVar13);
          iVar8 = ((int)puVar13 + (-0x15 - (int)param_2) & 0xfffffffcU) + 4;
          if (puVar13 < (uint *)((int)param_2 + 0x15)) {
            iVar8 = 4;
          }
          *(uint *)((int)puVar4 + iVar8) = uVar6;
          if (uVar6 != 0) {
            iVar11 = iVar7 + uVar1 + 2;
          }
        }
        puVar2[4] = iVar11 + -1;
        Bfree(param_1,param_2);
        return puVar2;
      }
      __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/mprec.c"
                    ,0x1d9,(char *)0x0,"Balloc succeeded");
      uVar3 = extraout_r1;
      iVar8 = extraout_r3;
    }
    uVar3 = uVar3 + 1;
    iVar8 = iVar8 << 1;
  } while( true );
}


