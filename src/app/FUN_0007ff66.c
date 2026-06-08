/*
 * Function: FUN_0007ff66
 * Entry:    0007ff66
 * Prototype: undefined __stdcall FUN_0007ff66(int param_1, int param_2)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void FUN_0007ff66(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  GlassesState *pGVar3;
  uint uVar4;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  uint extraout_r1_02;
  
  bVar2 = FUN_0002da10(param_1);
  if (!bVar2) {
    return;
  }
  pGVar3 = __get_dashboard_state();
  if (pGVar3->field_0xdb != '\0') {
    pGVar3 = __get_dashboard_state();
    pGVar3->field_0xdb = 0;
  }
  if ((*(char *)(*(int *)(param_1 + 0x1008) + 6) != '\0') ||
     (bVar2 = false, *(char *)(*(int *)(param_1 + 0x100c) + 6) != '\0')) {
    FUN_00030458();
    memset((void *)(*(int *)(param_1 + 0x100c) + 6),0,0x1e0);
    memset((void *)(*(int *)(param_1 + 0x1008) + 6),0,0x1e0);
    bVar2 = true;
  }
  if (**(char **)(param_1 + 0x1004) != '\0') {
    **(char **)(param_1 + 0x1004) = '\0';
    bVar2 = true;
  }
  if (*(char *)(*(int *)(param_1 + 0x1000) + 1) != '\0') {
    FUN_00030458();
    *(undefined1 *)(*(int *)(param_1 + 0x1000) + 1) = 0;
    bVar2 = true;
  }
  if (*(char *)(*(int *)(param_1 + 0x1034) + 1) != '\0') {
    FUN_00030458();
    *(undefined1 *)(*(int *)(param_1 + 0x1034) + 1) = 0;
    bVar2 = true;
  }
  if (*(char *)(param_1 + 0xd5) == '\x06') {
    FUN_00030458();
    *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x73) = 0;
    bVar2 = true;
  }
  if (*(char *)(*(int *)(param_1 + 0xff0) + 0x74) == '\x01') {
    *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x74) = 2;
  }
  if (*(char *)(param_1 + 0xd5) == '\x04') {
    bVar2 = true;
  }
  if (**(char **)(param_1 + 0x101c) != '\0') {
    **(char **)(param_1 + 0x101c) = '\0';
    bVar2 = true;
  }
  uVar4 = (uint)**(byte **)(param_1 + 0x1020);
  if (uVar4 != 0) {
    **(byte **)(param_1 + 0x1020) = 0;
    bVar2 = true;
  }
  if (*(char *)(*(int *)(param_1 + 0x1010) + 7) != '\0') {
    FUN_00030458();
    FUN_00080338(1);
    bVar2 = true;
    uVar4 = extraout_r1;
  }
  cVar1 = **(char **)(param_1 + 0x1014);
  if (cVar1 == '\x01') {
    FUN_00030458();
    **(undefined1 **)(param_1 + 0x1014) = 0;
    bVar2 = true;
    uVar4 = extraout_r1_00;
  }
  else if (cVar1 == '\x02') {
    uVar4 = 3;
    **(char **)(param_1 + 0x1014) = '\x03';
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
      goto LAB_00080082;
    }
  }
  else {
    **(char **)(param_1 + 0x1028) = '\0';
    if (**(char **)(param_1 + 0x102c) == '\0') goto LAB_00080082;
  }
  FUN_00030458();
  **(undefined1 **)(param_1 + 0x102c) = 0;
  uVar4 = extraout_r1_01;
LAB_00080082:
  if (param_2 != 0) {
    FUN_00029774(0,uVar4,0);
    uVar4 = extraout_r1_02;
  }
  update_persist_task_status_to_idle(param_1,uVar4);
  pGVar3 = __get_dashboard_state();
  if (pGVar3->field_0xda == '\x06') {
    return;
  }
  memset((void *)(param_1 + 0xef),0,0x5dc);
  return;
}


