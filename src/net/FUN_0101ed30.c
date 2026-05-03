/*
 * Function: FUN_0101ed30
 * Entry:    0101ed30
 * Prototype: bool __stdcall FUN_0101ed30(int param_1, uint param_2, uint param_3, uint param_4, ushort param_5, ushort param_6, ushort param_7)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0101ed30(int param_1,uint param_2,uint param_3,uint param_4,ushort param_5,ushort param_6,
                 ushort param_7)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_2 - 6 & 0xffff) < 0xc7b) {
    if ((param_3 - 6 & 0xffff) < 0xc7b) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
  }
  else {
    bVar2 = false;
  }
  if (param_1 == 0) {
    cVar1 = *(char *)(_FUN_0101edcc + 4);
  }
  else {
    cVar1 = *(char *)(param_1 + 0x73);
  }
  if (((cVar1 != '\0') && (!bVar2)) && (param_2 - 0xd01 < 7)) {
    if (param_3 - 0xd01 < 7) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
  }
  if (((bVar2) && (param_2 <= param_3)) &&
     ((param_4 < 500 &&
      (((param_5 - 10 & 0xffff) < 0xc77 &&
       (iVar3 = FUN_0100de00(param_3), uVar4 = (uint)param_5 * 10000,
       iVar3 = iVar3 * (param_4 + 1 & 0xffff), (uint)(iVar3 * 2) <= uVar4 && uVar4 + iVar3 * -2 != 0
       )))))) {
    bVar2 = param_6 <= param_7;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


