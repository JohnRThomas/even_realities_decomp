/*
 * Function: get_sn_info
 * Entry:    00032e00
 * Prototype: undefined4 __stdcall get_sn_info(int param_1, undefined4 param_2, undefined4 * param_3, char * param_4)
 */


undefined4 get_sn_info(int param_1,undefined4 param_2,undefined4 *param_3,char *param_4)

{
  undefined4 *puVar1;
  size_t n;
  undefined4 uVar2;
  undefined1 *puVar3;
  char local_38 [36];
  
  uVar2 = 0;
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  memset(local_38 + 4,0,0x1c);
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (char *)0x0)) {
    printk("get_sn_info para is NULL\n");
    uVar2 = 0xffffffff;
  }
  else {
    puVar3 = (undefined1 *)*param_3;
    *puVar3 = 0x22;
    puVar3[1] = *(undefined1 *)(param_1 + 1);
    puVar3[2] = 3;
    puVar1 = FUN_00025338();
    __sprintf_chk(local_38,0,0x20,"%s",puVar1);
    n = strlen(local_38);
    puVar3[3] = (char)n;
    memcpy(puVar3 + 4,local_38,n);
    *param_4 = (char)n + '\x04';
  }
  return uVar2;
}


