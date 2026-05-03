/*
 * Function: FUN_00026c5c
 * Entry:    00026c5c
 * Prototype: undefined4 __stdcall FUN_00026c5c(char * param_1, undefined4 * param_2, int param_3)
 */


undefined4 FUN_00026c5c(char *param_1,undefined4 *param_2,int param_3)

{
  char *pcVar1;
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if (*param_1 != '\a') {
    return 0;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  if (param_3 != 0) {
    DAT_200083ec = 0;
  }
  param_2[1] = 1;
  switch(DAT_200083ec) {
  case 0:
    pcVar1 = param_1 + 0x10;
    break;
  case 1:
    DAT_20019935 = param_1[0x14] & 1U | param_1[0x11] << 6 | (param_1[0x12] & 0xfU) << 2 |
                   (param_1[0x13] & 1U) << 1;
    *param_2 = &DAT_20019935;
    goto LAB_00026cb2;
  case 2:
    DAT_20019935 = param_1[0x16] & 0x1fU | param_1[0x15] << 5;
    *param_2 = &DAT_20019935;
    goto LAB_00026cb2;
  case 3:
    pcVar1 = param_1 + 0x17;
    break;
  case 4:
    pcVar1 = param_1 + 0x18;
    break;
  case 5:
    pcVar1 = param_1 + 0x19;
    break;
  default:
    *param_2 = 0;
    param_2[1] = 0;
    goto LAB_00026cb2;
  }
  *param_2 = pcVar1;
LAB_00026cb2:
  DAT_200083ec = DAT_200083ec + 1;
  return *param_2;
}


