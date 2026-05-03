/*
 * Function: FUN_01022140
 * Entry:    01022140
 * Prototype: undefined4 __stdcall FUN_01022140(uint param_1, uint param_2, int param_3, undefined1 * param_4)
 */


undefined4 FUN_01022140(uint param_1,uint param_2,int param_3,undefined1 *param_4)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 < 5) && (param_4 != (undefined1 *)0x0)) {
    if (param_1 == 4) {
      uVar2 = 0x10;
    }
    else {
      uVar2 = 0x28;
    }
    if (param_2 < uVar2) {
      if ((*(int *)(&DAT_210016c8 + param_1 * 4) != 0) &&
         (iVar1 = (int)*(char *)(*(int *)(&DAT_210016c8 + param_1 * 4) + param_2), iVar1 <= param_3)
         ) {
        param_3 = iVar1;
      }
      *param_4 = (char)param_3;
      return 0;
    }
  }
  return 0xffffffea;
}


