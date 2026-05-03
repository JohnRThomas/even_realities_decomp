/*
 * Function: FUN_010296ea
 * Entry:    010296ea
 * Prototype: int __stdcall FUN_010296ea(ushort * param_1, int param_2)
 */


int FUN_010296ea(ushort *param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int extraout_r1;
  int extraout_r1_00;
  ushort *local_10;
  int local_c;
  
  local_10 = param_1;
  local_c = param_2;
  iVar3 = FUN_0100d7c0(*param_1,(undefined1 *)&local_10);
  iVar1 = local_c;
  if (iVar3 == 0) {
    if ((((char)local_10 == '\0') && (bVar2 = FUN_01028ac4(local_c), iVar3 = extraout_r1_00, !bVar2)
        ) || (((char)local_10 == '\x01' &&
              (bVar2 = FUN_01028ae0(local_c), iVar3 = extraout_r1, !bVar2)))) {
      iVar3 = 2;
    }
    else if (*(char *)(iVar1 + 0x173) == '\0') {
      *(undefined1 *)(iVar1 + 0x173) = 1;
    }
    else {
      iVar3 = 0x3a;
    }
  }
  return iVar3;
}


