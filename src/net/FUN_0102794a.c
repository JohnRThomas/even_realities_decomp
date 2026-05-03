/*
 * Function: FUN_0102794a
 * Entry:    0102794a
 * Prototype: ushort __stdcall FUN_0102794a(ushort * param_1, int * param_2, ushort * param_3)
 */


ushort FUN_0102794a(ushort *param_1,int *param_2,ushort *param_3)

{
  ushort uVar1;
  
  uVar1 = *param_1;
  if (uVar1 < 0x45) {
    uVar1 = 0x45;
  }
  *param_3 = uVar1;
  *param_2 = (int)param_1 + (param_1[3] & 0x7fff) + 0x18;
  return param_1[6];
}


