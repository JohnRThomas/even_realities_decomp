/*
 * Function: ble_printk
 * Entry:    00019e30
 * Prototype: void __stdcall ble_printk(char * param_1, char * param_2, undefined4 param_3, undefined4 param_4, ...)
 */


void ble_printk(char *param_1,char *param_2,undefined4 param_3,undefined4 param_4,...)

{
  int iVar1;
  char local_e8 [200];
  char *pcStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pcStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar1 = FUN_00018320();
  memset(local_e8,0,200);
  vsnprintf(local_e8,200,param_1,&pcStack_c);
  __enqueue_debug(local_e8);
  local_e8[0] = '\0';
  if ((*(char *)(iVar1 + 0x248) == '\0') && (*(int *)(iVar1 + 0x220) == 0)) {
    DAT_20007f2c = 1;
    k_sem_give((k_sem *)(iVar1 + 0x218));
  }
  return;
}


