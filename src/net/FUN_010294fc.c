/*
 * Function: FUN_010294fc
 * Entry:    010294fc
 * Prototype: int __stdcall FUN_010294fc(void)
 */


int FUN_010294fc(void)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 extraout_r2;
  int iVar4;
  undefined8 uVar5;
  undefined4 uStack_1c;
  int local_18 [3];
  
  local_18[0] = 0;
  local_18[1] = 0x50000;
  do {
    iVar4 = local_18[0];
    iVar3 = FUN_0100a5d8(local_18);
    if (iVar3 != 0) {
      bVar1 = false;
      goto LAB_01029516;
    }
  } while ((*(char *)(local_18[0] + 0xa5) == -0x80) || (*(char *)(local_18[0] + 0x109) != '\0'));
  bVar1 = true;
  iVar4 = local_18[0];
LAB_01029516:
  cVar2 = FUN_0101bf4c();
  if (cVar2 == '\x05') {
    if (!bVar1) {
      uVar5 = FUN_0101b94c(&uStack_1c);
      if ((int)uVar5 != 0) {
        return (int)uVar5;
      }
      FUN_0101947c(0,(int)((ulonglong)uVar5 >> 0x20),extraout_r2);
      return 0;
    }
  }
  else if (!bVar1) {
    return 0xc;
  }
  *(undefined1 *)(iVar4 + 0xa4) = 0xff;
  return 0;
}


