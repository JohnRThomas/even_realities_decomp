/*
 * Function: FUN_010221c4
 * Entry:    010221c4
 * Prototype: bool __stdcall FUN_010221c4(char * param_1)
 */


bool FUN_010221c4(char *param_1)

{
  uint uVar1;
  
  if (param_1 != (char *)0x0) {
    if (*param_1 == '\0') {
      if ((((byte)param_1[4] < 2) && ((byte)param_1[5] < 2)) &&
         ((undefined *)(*(int *)(param_1 + 8) + -100) < &UNK_0001863d)) {
        uVar1 = *(uint *)(param_1 + 0xc);
        goto LAB_010221e4;
      }
    }
    else if (((*param_1 == '\x01') && ((byte)param_1[4] < 2)) &&
            (((byte)param_1[5] < 2 &&
             ((undefined *)(*(int *)(param_1 + 0xc) + -100) < &UNK_0001863d)))) {
      uVar1 = *(uint *)(param_1 + 8);
LAB_010221e4:
      return uVar1 < 256000000;
    }
  }
  return false;
}


