/*
 * Function: FUN_0100a848
 * Entry:    0100a848
 * Prototype: undefined4 __stdcall FUN_0100a848(ushort param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_0100a848(ushort param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (DAT_21000bb4 == (undefined4 *)0x0) {
    FUN_01009500(0x18,0xc6,param_3,0);
  }
  if ((param_1 < *(byte *)(DAT_21000bb4 + 2)) &&
     (*(int *)((uint)param_1 * 4 + DAT_21000bb4[1]) != 0)) {
    puVar3 = *(undefined4 **)((uint)param_1 * 4 + DAT_21000bb4[1]);
    *(undefined4 *)((uint)param_1 * 4 + DAT_21000bb4[1]) = 0;
    FUN_01027bc6((undefined4 *)*DAT_21000bb4,puVar3,*(undefined2 *)((int)puVar3 + 2));
    iVar1 = FUN_0100a65c();
    if (iVar1 != 0) {
      FUN_01027ac2((undefined4 *)*DAT_21000bb4);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}


