/*
 * Function: FUN_00080224
 * Entry:    00080224
 * Prototype: undefined __stdcall FUN_00080224(int param_1, int param_2)
 */


void FUN_00080224(int param_1,int param_2)

{
  bool bVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar2;
  undefined4 extraout_r1_01;
  undefined4 extraout_r2;
  undefined4 uVar3;
  
  bVar1 = FUN_0002da10(param_1);
  if (!bVar1) {
    return;
  }
  if (*(char *)(param_1 + 0xd5) == '\x06') {
    FUN_00030458();
    uVar3 = 0;
    *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x73) = 0;
    uVar2 = extraout_r1_01;
  }
  else {
    uVar2 = extraout_r1;
    uVar3 = extraout_r2;
    if (*(char *)(param_1 + 0xd5) != '\x04') {
      return;
    }
  }
  if (param_2 != 0) {
    FUN_00029774(0,uVar2,uVar3);
    uVar2 = extraout_r1_00;
  }
  update_persist_task_status_to_idle(param_1,uVar2);
  memset((void *)(param_1 + 0xef),0,0x5dc);
  return;
}


