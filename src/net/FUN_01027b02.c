/*
 * Function: FUN_01027b02
 * Entry:    01027b02
 * Prototype: int __stdcall FUN_01027b02(int * param_1, uint param_2, undefined4 param_3)
 */


int FUN_01027b02(int *param_1,uint param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int local_10;
  int *local_c;
  
  local_10 = 0;
  if ((param_2 < 8) || (param_3 = 0xfffe, 0xfffe < param_2)) {
    FUN_01009500(0x15,0x1d2,param_3,param_2);
  }
  local_c = param_1;
  if (*param_1 != 0) {
    for (; (param_2 != *(ushort *)(*local_c + 4) && (*(int *)*local_c != 0));
        local_c = (int *)*local_c) {
    }
    local_10 = *local_c;
    if (param_2 == *(ushort *)(local_10 + 4)) {
      FUN_010279da(local_c);
    }
    else {
      bVar1 = FUN_01027a2c(local_10,(short)param_2);
      if (bVar1) {
        iVar2 = *local_c;
        FUN_01027996((undefined4 *)(param_2 + iVar2),*(short *)(*local_c + 4) - (short)param_2);
        FUN_010279da(local_c);
        FUN_010279b8((undefined4 *)(param_2 + iVar2),local_c);
      }
      else {
        local_10 = 0;
      }
    }
  }
  return local_10;
}


