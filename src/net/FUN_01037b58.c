/*
 * Function: FUN_01037b58
 * Entry:    01037b58
 * Prototype: undefined __stdcall FUN_01037b58(int * param_1)
 */


void FUN_01037b58(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  
  cVar1 = *(char *)((int)param_1 + 0xd);
  if (cVar1 < 0) {
    uVar3 = *(byte *)((int)param_1 + 0xd) & 0x7f;
    *(char *)((int)param_1 + 0xd) = (char)uVar3;
    FUN_01037b1c(&DAT_21004b40,param_1,(int)cVar1,uVar3);
  }
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x80;
  if (param_1 == (int *)&DAT_210043a8) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0xc1,
                 &DAT_210043a8);
    FUN_0103a370();
  }
  puVar2 = &DAT_21004b40;
  piVar4 = DAT_21004b40;
  if ((int **)DAT_21004b40 == &DAT_21004b40) {
    piVar4 = (int *)0x0;
  }
  for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)piVar4 + 0xe)) &&
       (*(char *)((int)param_1 + 0xe) < *(char *)((int)piVar4 + 0xe))) {
      puVar2 = (undefined4 *)piVar4[1];
      *param_1 = (int)piVar4;
      param_1[1] = (int)puVar2;
      *puVar2 = param_1;
      piVar4[1] = (int)param_1;
      goto LAB_01037bca;
    }
    if (DAT_21004b44 == piVar4) break;
  }
  *param_1 = (int)&DAT_21004b40;
  param_1[1] = (int)DAT_21004b44;
  *DAT_21004b44 = (int)param_1;
  DAT_21004b44 = param_1;
LAB_01037bca:
  FUN_01037734((uint)(DAT_21004b30 - (int)param_1 == 0),puVar2,&DAT_21004b28,
               DAT_21004b30 - (int)param_1);
  return;
}


