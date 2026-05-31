/*
 * Function: FUN_0004d328
 * Entry:    0004d328
 * Prototype: cJSON_bool __stdcall FUN_0004d328(cJSON * item, parse_buffer * input_buffer)
 */


cJSON_bool FUN_0004d328(cJSON *item,parse_buffer *input_buffer)

{
  undefined **ppuVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  float in_s0;
  uint uVar7;
  char acStack_25 [17];
  
  uVar7 = (uint)(in_s0 * 100.0);
  uVar4 = (uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f);
  acStack_25[1] = '\0';
  acStack_25[2] = '\0';
  acStack_25[3] = '\0';
  acStack_25[4] = '\0';
  acStack_25[5] = '\0';
  acStack_25[6] = '\0';
  acStack_25[7] = '\0';
  acStack_25[8] = '\0';
  acStack_25[9] = '\0';
  acStack_25[10] = '\0';
  acStack_25[0xb] = '\0';
  acStack_25[0xc] = '\0';
  if ((int)uVar4 < 10) {
    iVar6 = 2;
  }
  else if ((int)uVar4 < 100) {
    iVar6 = 1;
  }
  else {
    iVar6 = 0;
  }
  iVar2 = 0;
  while (uVar4 != 0) {
    if ((iVar2 == 2) && (iVar6 == 0)) {
      iVar2 = 3;
      acStack_25[3] = 0x2e;
    }
    acStack_25[iVar2 + 1] = (char)uVar4 + (char)(uVar4 / 10) * -10 + '0';
    iVar2 = iVar2 + 1;
    uVar4 = uVar4 / 10;
  }
  if (iVar6 == 2) {
    if ((int)uVar7 < 1) {
      uVar3 = 0x2d;
    }
    else {
      uVar3 = 0x2b;
    }
    acStack_25[iVar2 + 1] = '0';
    *(undefined1 *)&item->next = uVar3;
    iVar2 = iVar2 + 1;
  }
  else {
    if ((int)uVar7 < 1) {
      uVar3 = 0x2d;
    }
    else {
      uVar3 = 0x2b;
    }
    *(undefined1 *)&item->next = uVar3;
    if (iVar6 == 0) {
      pcVar5 = acStack_25 + iVar2 + 1;
      ppuVar1 = &item->next;
      while (item != (cJSON *)((int)ppuVar1 + iVar2)) {
        pcVar5 = pcVar5 + -1;
        item = (cJSON *)((int)&item->next + 1);
        *(char *)&item->next = *pcVar5;
      }
      *(undefined1 *)((int)&item->next + 1) = 0;
      return iVar2 + 1;
    }
  }
  *(undefined1 *)((int)&item->next + 1) = 0x30;
  pcVar5 = (char *)((int)&item->next + 2);
  *pcVar5 = '.';
  iVar6 = iVar2;
  while (iVar6 + -1 != -1) {
    pcVar5 = pcVar5 + 1;
    *pcVar5 = acStack_25[iVar6];
    iVar6 = iVar6 + -1;
  }
  return iVar2 + 3;
}


