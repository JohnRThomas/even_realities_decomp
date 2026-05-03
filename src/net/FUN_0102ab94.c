/*
 * Function: FUN_0102ab94
 * Entry:    0102ab94
 * Prototype: undefined __stdcall FUN_0102ab94(void)
 */


void FUN_0102ab94(void)

{
  int iVar1;
  char cVar2;
  undefined2 local_30;
  undefined4 local_2e;
  undefined4 local_2a;
  undefined4 local_26;
  undefined1 local_22;
  
  FUN_0103bdee((undefined1 *)((int)&local_2e + 2),0,0x1c);
  cVar2 = '\n';
  local_30 = 0x701;
  local_2e = DAT_210045f0;
  local_2a = DAT_210045ec;
  local_26 = DAT_210045e8;
  local_22 = DAT_21004c9f;
  while ((iVar1 = (**(code **)(DAT_210045f4 + 0xa8))(&local_30,0x20), iVar1 < 1 &&
         (cVar2 = cVar2 + -1, cVar2 != '\0'))) {
    FUN_01039ddc(10);
  }
  return;
}


