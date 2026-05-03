/*
 * Function: lpuart_async_a
 * Entry:    00034cb4
 * Prototype: undefined4 __stdcall lpuart_async_a(int param_1, void * param_2, undefined4 param_3)
 */


undefined4 lpuart_async_a(int param_1,void *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  void *local_14;
  undefined4 uStack_10;
  
  if (param_1 != 0) {
    iVar2 = param_1;
    local_14 = param_2;
    uStack_10 = param_3;
    iVar1 = k_mem_slab_alloc((k_mem_slab *)&DAT_20003958,&local_14,(k_timeout_t)0x0);
    if (iVar1 == 0) {
      pcVar3 = (code *)**(undefined4 **)(param_1 + 8);
      if ((pcVar3 != (code *)0x0) &&
         (iVar2 = (*pcVar3)(param_1,0x34999,param_1,pcVar3,iVar2), iVar2 == 0)) {
        iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0xc))(param_1,local_14,0x100,10000);
        if (iVar2 == 0) {
          return 0;
        }
        printk("Failed to enable RX\n");
        return 0xfffffffd;
      }
      printk("Failed to set callback\n");
      return 0xfffffffe;
    }
    printk("Failed to alloc slab\n");
  }
  return 0xffffffff;
}


