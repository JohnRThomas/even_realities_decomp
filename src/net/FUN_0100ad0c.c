/*
 * Function: FUN_0100ad0c
 * Entry:    0100ad0c
 * Prototype: ushort __stdcall FUN_0100ad0c(ushort * param_1, byte param_2, byte param_3)
 */


ushort FUN_0100ad0c(ushort *param_1,byte param_2,byte param_3)

{
  int iVar1;
  
  iVar1 = FUN_01027e62((ushort)param_3,0x2e,(ushort)param_2);
  if (param_1 != (ushort *)0x0) {
    FUN_01027dd2(param_1,(ushort)iVar1,(ushort)param_3,0x2e,(ushort)param_2);
    DAT_21000bc4 = param_1;
    DAT_21000bc8 = param_2;
    DAT_21000bc9 = param_3;
  }
  return (ushort)iVar1;
}


