/*
 * Function: FUN_0102e4b4
 * Entry:    0102e4b4
 * Prototype: uint __stdcall FUN_0102e4b4(int param_1, int param_2)
 */


/* WARNING: Removing unreachable block (ram,0x0102e4ca) */

uint FUN_0102e4b4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint extraout_r3;
  uint extraout_r3_00;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  
  piVar4 = &DAT_0103c0ac;
  do {
    iVar1 = FUN_0103aa54((int *)&DAT_2100466c);
    if (iVar1 != 0) {
      return 0;
    }
    uVar2 = 0;
    uVar5 = 0;
    uVar3 = extraout_r3;
    for (; piVar4 <= &DAT_0103c0bc; piVar4 = piVar4 + 4) {
      if (&UNK_0103c0bb < piVar4) {
        if (param_1 != 0) {
          while (uVar2 != 0) {
            uVar2 = FUN_0102e450(uVar2);
            if (param_2 != 0) {
              FUN_01038424(0x148,0);
            }
          }
          return 0;
        }
        return uVar2;
      }
      uVar3 = 0;
      if ((char)piVar4[3] != '\0') {
        if (*(code **)(*piVar4 + 0xc) != (code *)0x0) {
          (**(code **)(*piVar4 + 0xc))(piVar4);
        }
        if ((*(code **)(*piVar4 + 0x10) == (code *)0x0) ||
           (iVar1 = (**(code **)(*piVar4 + 0x10))(piVar4), iVar1 == 0)) {
          FUN_0102e9fc((int)piVar4,*(undefined4 *)piVar4[1],4);
          uVar3 = extraout_r3_00;
        }
        else {
          uVar3 = 1 << (uVar5 & 0xff);
          uVar2 = uVar2 | uVar3;
        }
        uVar5 = uVar5 + 1;
      }
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/logging/log_core.c",
                 0x126,uVar3);
    FUN_0103a370();
  } while( true );
}


