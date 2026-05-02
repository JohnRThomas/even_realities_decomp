/*
 * Function: FUN_00085444
 * Entry:    00085444
 * Prototype: undefined4 __stdcall FUN_00085444(bt_gatt_attr * param_1, undefined4 param_2, undefined4 * param_3)
 */


undefined4 FUN_00085444(bt_gatt_attr *param_1,undefined4 param_2,undefined4 *param_3)

{
  uint8_t uVar1;
  char cVar2;
  uint uVar3;
  
  uVar1 = bt_gatt_check_perm((bt_conn *)*param_3,param_1,0x12a);
  *(uint8_t *)(param_3 + 5) = uVar1;
  if (uVar1 != '\0') {
    return 0;
  }
  if (*(char *)(param_3 + 2) == '\0') {
    cVar2 = '\x02';
  }
  else {
    cVar2 = (*(char *)(param_3 + 2) == '\x18') * '\x04';
  }
  uVar3 = (*(code *)param_1->write)
                    (*param_3,param_1,param_3[3],*(undefined2 *)(param_3 + 4),
                     *(undefined2 *)((int)param_3 + 0x12),cVar2);
  if ((int)uVar3 < 0) {
    if (0xffffff00 < uVar3) {
      cVar2 = -(char)uVar3;
      goto LAB_0008549a;
    }
  }
  else if (uVar3 == *(ushort *)(param_3 + 4)) {
    *(undefined1 *)(param_3 + 5) = 0;
    return 1;
  }
  cVar2 = '\x0e';
LAB_0008549a:
  *(char *)(param_3 + 5) = cVar2;
  return 0;
}


