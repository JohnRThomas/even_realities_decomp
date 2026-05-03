/*
 * Function: FUN_00027fa8
 * Entry:    00027fa8
 * Prototype: int __stdcall FUN_00027fa8(char * param_1)
 */


int FUN_00027fa8(char *param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *(int *)(param_1 + 0x88);
  bVar1 = param_1[0x10];
  cVar2 = param_1[0x11];
  if ((((*(int *)(param_1 + 0x80) != DAT_2000847c) || ((uint)DAT_20019939 != (uint)bVar1)) ||
      (DAT_20003047 != cVar2)) ||
     ((DAT_200023f8 != iVar3 || (DAT_20008478 != *(int *)(param_1 + 0x84))))) {
    if (cVar2 == '\0') {
      iVar5 = -0x15e;
    }
    else if (cVar2 == '\x02') {
      iVar5 = 700;
    }
    else {
      iVar5 = 0;
    }
    if (*param_1 == '\x02') {
      iVar4 = 0x76c;
    }
    else {
      iVar4 = 4000;
    }
    DAT_200023f4 = (int)(iVar4 * (uint)bVar1) / iVar3;
    DAT_200023f8 = iVar3;
    DAT_20003047 = cVar2;
    DAT_20008478 = *(int *)(param_1 + 0x84);
    DAT_2000847c = *(int *)(param_1 + 0x80);
    DAT_20019939 = bVar1;
    __is_master();
    iVar3 = *(int *)(param_1 + 0x84);
    iVar5 = (short)(ushort)(byte)param_1[0x10] * 0x32 + iVar5;
    if ((iVar3 == 0) && (iVar3 = *(int *)(param_1 + 0x80), iVar3 == 0)) {
      *(int *)(param_1 + 8) = iVar5 + -0x189c;
      *(int *)(param_1 + 0xc) = iVar5 + -0x2454;
    }
    else {
      *(int *)(param_1 + 8) = iVar3 - iVar5;
      *(int *)(param_1 + 0xc) = (iVar3 + -0x1194) - iVar5;
    }
  }
  return DAT_200023f4;
}


