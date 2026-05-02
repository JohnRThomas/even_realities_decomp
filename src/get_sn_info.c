/*
 * Function: get_sn_info
 * Entry:    00032e00
 * Prototype: undefined4 __stdcall get_sn_info(int param_1, undefined4 param_2, undefined4 * param_3, char * param_4)
 */


undefined4 get_sn_info(int param_1,undefined4 param_2,undefined4 *param_3,char *param_4)

{
  size_t n;
  undefined4 uVar1;
  undefined1 *puVar2;
  char local_38 [36];
  
  uVar1 = 0;
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  memset(local_38 + 4,0,0x1c);
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (char *)0x0)) {
    printk("get_sn_info para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar2 = (undefined1 *)*param_3;
    *puVar2 = 0x22;
    puVar2[1] = *(undefined1 *)(param_1 + 1);
    puVar2[2] = 3;
    FUN_00025338();
    FUN_0008a6b0(local_38,0,0x20,(byte *)0xaab27);
    n = ____strlen(local_38);
    puVar2[3] = (char)n;
    memcpy(puVar2 + 4,local_38,n);
    *param_4 = (char)n + '\x04';
  }
  return uVar1;
}


