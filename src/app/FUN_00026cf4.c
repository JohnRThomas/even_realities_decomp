/*
 * Function: FUN_00026cf4
 * Entry:    00026cf4
 * Prototype: undefined4 __stdcall FUN_00026cf4(char * param_1, undefined4 * param_2, int param_3)
 */


undefined4 FUN_00026cf4(char *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if (*param_1 != '\b') {
    return 0;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  if (param_3 != 0) {
    DAT_200083e8 = 0;
  }
  uVar1 = DAT_200083e8;
  param_2[1] = 1;
  switch(uVar1) {
  case 0:
    *param_2 = param_1 + 0x10;
    DAT_200083e8 = 1;
    goto LAB_00026d28;
  case 1:
    break;
  case 2:
    goto switchD_00026d14_caseD_2;
  case 3:
    goto switchD_00026d14_caseD_3;
  case 4:
    goto switchD_00026d14_caseD_4;
  case 5:
    goto switchD_00026d14_caseD_5;
  case 6:
    goto switchD_00026d14_caseD_6;
  case 7:
    goto switchD_00026d14_caseD_7;
  case 8:
    goto switchD_00026d14_caseD_8;
  default:
    goto switchD_00026d14_default;
  }
  if ((int)((uint)(byte)param_1[0x10] << 0x1f) < 0) {
    *param_2 = param_1 + 0x11;
    DAT_200083e8 = 2;
    goto LAB_00026d28;
  }
switchD_00026d14_caseD_2:
  if ((int)((uint)(byte)param_1[0x10] << 0x1e) < 0) {
    *param_2 = param_1 + 0x12;
    DAT_200083e8 = 3;
  }
  else {
switchD_00026d14_caseD_3:
    if ((int)((uint)(byte)param_1[0x10] << 0x1d) < 0) {
      *param_2 = param_1 + 0x13;
      DAT_200083e8 = 4;
    }
    else {
switchD_00026d14_caseD_4:
      if ((int)((uint)(byte)param_1[0x10] << 0x1c) < 0) {
        *param_2 = param_1 + 0x14;
        DAT_200083e8 = 5;
      }
      else {
switchD_00026d14_caseD_5:
        if ((int)((uint)(byte)param_1[0x10] << 0x1b) < 0) {
          *param_2 = param_1 + 0x15;
          DAT_200083e8 = 6;
        }
        else {
switchD_00026d14_caseD_6:
          if ((int)((uint)(byte)param_1[0x10] << 0x1a) < 0) {
            *param_2 = param_1 + 0x16;
            DAT_200083e8 = 7;
          }
          else {
switchD_00026d14_caseD_7:
            if ((int)((uint)(byte)param_1[0x10] << 0x19) < 0) {
              *param_2 = param_1 + 0x17;
              DAT_200083e8 = 8;
            }
            else {
switchD_00026d14_caseD_8:
              if (param_1[0x10] < '\0') {
                *param_2 = param_1 + 0x18;
                DAT_200083e8 = 9;
              }
              else {
switchD_00026d14_default:
                *param_2 = 0;
                param_2[1] = 0;
              }
            }
          }
        }
      }
    }
  }
LAB_00026d28:
  return *param_2;
}


