/*
 * Function: %_lpuart_async_b
 * Entry:    00034c60
 * Prototype: undefined4 __stdcall %_lpuart_async_b(int param_1, undefined1 * param_2, int param_3)
 */


/* Sample Code: v2.5.1/nrf/samples/peripheral/lpuart/src/main.c */

undefined4 __lpuart_async_b(int param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == 0) || (param_2 == (undefined1 *)0x0)) || (param_3 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = (**(code **)(*(int *)(param_1 + 8) + 4))();
    if (iVar1 == 0) {
      z_impl_k_sleep((k_timeout_t)0x4000);
      (**(code **)(*(int *)(param_1 + 8) + 0x1c))(param_1,*param_2);
      z_impl_k_sleep((k_timeout_t)0xccd);
      uVar2 = 0;
    }
    else {
      printk("Failed to initiate transmission\n");
      uVar2 = 0xfffffffe;
    }
  }
  return uVar2;
}


