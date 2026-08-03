/*
 * Function: s2b
 * Entry:    0007b9d0
 * Prototype: undefined __stdcall s2b(size_t param_1, int param_2, int param_3, int param_4, undefined4 param_5)
 */


/* exclude_from_export_ai */

void s2b(size_t param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  uint extraout_r1;
  int iVar3;
  int extraout_r2;
  int iVar4;
  int extraout_r3;
  byte *pbVar5;
  byte *pbVar6;
  
  uVar2 = 0;
  iVar4 = (param_4 + 8) / 9;
  iVar3 = 1;
  do {
    if (iVar4 <= iVar3) {
      puVar1 = Balloc(param_1,uVar2);
      if (puVar1 != (undefined4 *)0x0) {
        puVar1[5] = param_5;
        puVar1[4] = 1;
        if (param_3 < 10) {
          pbVar5 = (byte *)(param_2 + 10);
          param_3 = 9;
        }
        else {
          pbVar5 = (byte *)(param_2 + 9);
          do {
            pbVar6 = pbVar5 + 1;
            puVar1 = multadd(param_1,puVar1,10,*pbVar5 - 0x30);
            pbVar5 = pbVar6;
          } while (pbVar6 != (byte *)(param_2 + param_3));
          pbVar5 = (byte *)(param_2 + 9) + param_3 + -8;
        }
        iVar3 = param_3 - (int)pbVar5;
        for (; (int)(pbVar5 + iVar3) < param_4; pbVar5 = pbVar5 + 1) {
          puVar1 = multadd(param_1,puVar1,10,*pbVar5 - 0x30);
        }
        return;
      }
      __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/mprec.c"
                    ,0xce,(char *)0x0,"Balloc succeeded");
      uVar2 = extraout_r1;
      iVar3 = extraout_r2;
      iVar4 = extraout_r3;
    }
    iVar3 = iVar3 << 1;
    uVar2 = uVar2 + 1;
  } while( true );
}


