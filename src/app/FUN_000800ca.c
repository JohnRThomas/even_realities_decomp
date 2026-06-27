/*
 * Function: FUN_000800ca
 * Entry:    000800ca
 * Prototype: undefined __stdcall FUN_000800ca(int param_1, int param_2)
 */


void FUN_000800ca(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  GlassesState *pGVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 extraout_r1_06;
  undefined4 extraout_r1_07;
  undefined4 uVar4;
  
  bVar2 = FUN_0002da10(param_1);
  if (!bVar2) {
    return;
  }
  pGVar3 = __get_dashboard_state();
  uVar4 = extraout_r1;
  if (pGVar3->field_0xdb != '\0') {
    pGVar3 = __get_dashboard_state();
    pGVar3->field_0xdb = 0;
    uVar4 = extraout_r1_00;
  }
  if ((*(char *)(*(int *)(param_1 + 0x1008) + 6) != '\0') ||
     (bVar2 = false, *(char *)(*(int *)(param_1 + 0x100c) + 6) != '\0')) {
    FUN_00030458();
    memset((void *)(*(int *)(param_1 + 0x100c) + 6),0,0x1e0);
    memset((void *)(*(int *)(param_1 + 0x1008) + 6),0,0x1e0);
    bVar2 = true;
    uVar4 = extraout_r1_01;
  }
  if (**(char **)(param_1 + 0x1004) != '\0') {
    bVar2 = true;
    **(char **)(param_1 + 0x1004) = '\0';
  }
  if (*(char *)(*(int *)(param_1 + 0x1000) + 1) != '\0') {
    FUN_00030458();
    bVar2 = true;
    *(undefined1 *)(*(int *)(param_1 + 0x1000) + 1) = 0;
    uVar4 = extraout_r1_02;
  }
  if (*(char *)(*(int *)(param_1 + 0x1034) + 1) != '\0') {
    FUN_00030458();
    bVar2 = true;
    *(undefined1 *)(*(int *)(param_1 + 0x1034) + 1) = 0;
    uVar4 = extraout_r1_03;
  }
  if (*(char *)(param_1 + 0xd5) == '\x06') {
    FUN_00030458();
    *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x73) = 0;
    uVar4 = extraout_r1_04;
  }
  if (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) == '\x01') {
    *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 2;
  }
  if (**(char **)(param_1 + 0x1018) != '\0') {
    bVar2 = true;
    **(char **)(param_1 + 0x1018) = '\0';
  }
  if (**(char **)(param_1 + 0x101c) != '\0') {
    bVar2 = true;
    **(char **)(param_1 + 0x101c) = '\0';
  }
  if (*(char *)(*(int *)(param_1 + 0x1010) + 7) != '\0') {
    FUN_00030458();
    FUN_00080338(1);
    bVar2 = true;
    uVar4 = extraout_r1_05;
  }
  cVar1 = **(char **)(param_1 + 0x1014);
  if (cVar1 == '\x01') {
    FUN_00030458();
    **(undefined1 **)(param_1 + 0x1014) = 0;
    bVar2 = true;
    uVar4 = extraout_r1_06;
  }
  else if (cVar1 == '\x02') {
    **(char **)(param_1 + 0x1014) = '\x03';
  }
  if (**(char **)(param_1 + 0x1020) != '\0') {
    bVar2 = true;
    **(char **)(param_1 + 0x1020) = '\0';
  }
  if (**(char **)(param_1 + 0x1024) != '\0') {
    bVar2 = true;
    **(char **)(param_1 + 0x1024) = '\0';
  }
  if (**(char **)(param_1 + 0x1028) == '\0') {
    if (**(char **)(param_1 + 0x102c) == '\0') {
      if (!bVar2) {
        return;
      }
      goto LAB_000801e8;
    }
  }
  else {
    **(char **)(param_1 + 0x1028) = '\0';
    if (**(char **)(param_1 + 0x102c) == '\0') goto LAB_000801e8;
  }
  FUN_00030458();
  **(undefined1 **)(param_1 + 0x102c) = 0;
  uVar4 = extraout_r1_07;
LAB_000801e8:
  if (param_2 != 0) {
    FUN_00029774(0,uVar4,0);
  }
  memset((void *)(param_1 + 0xef),0,0x5dc);
  return;
}


