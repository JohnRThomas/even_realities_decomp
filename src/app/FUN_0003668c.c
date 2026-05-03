/*
 * Function: FUN_0003668c
 * Entry:    0003668c
 * Prototype: undefined4 __stdcall FUN_0003668c(char * param_1, char * param_2, undefined4 param_3)
 */


undefined4 FUN_0003668c(char *param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  
  if ((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) {
    if (BLE_DEBUG == 0) {
      printk("invalid param ! \n");
    }
    else {
      ble_printk("invalid param ! \n",param_2,param_3,BLE_DEBUG);
    }
  }
  else {
    uVar2 = (uint)DAT_2001aefc;
    for (puVar3 = &DAT_2001aefb; puVar3 != &DAT_2001aefb + uVar2 * 0x38; puVar3 = puVar3 + 0x38) {
      iVar1 = strncmp(puVar3 + 2,param_1,0x28);
      if ((iVar1 == 0) && (iVar1 = strncmp(puVar3 + 0x2a,param_2,0x10), iVar1 == 0)) {
        return 1;
      }
    }
  }
  return 0;
}


