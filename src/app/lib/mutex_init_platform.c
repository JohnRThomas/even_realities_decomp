/*
 * Function: mutex_init_platform
 * Entry:    000530e0
 * Prototype: void __stdcall mutex_init_platform(nrf_cc3xx_platform_mutex_t * mutex)
 */


/* exclude_from_export_ai */

void mutex_init_platform(nrf_cc3xx_platform_mutex_t *mutex)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  if (mutex == (nrf_cc3xx_platform_mutex_t *)0x0) {
    (*nrf_cc3xx_platform_abort_apis_t_20002f10.abort_fn)("mutex_init called with NULL parameter");
  }
  puVar3 = (undefined1 *)mutex[1];
  if (puVar3 == (undefined1 *)0x3a000) {
    return;
  }
  if (puVar3 == (undefined1 *)0xe80000) {
    return;
  }
  if (puVar3 == (undefined1 *)0xa95c5f2c) {
    if (*mutex != 0) goto LAB_00053148;
  }
  else {
    if (puVar3 < (undefined1 *)0x3a001) {
      if (puVar3 == &DAT_0000003a) goto LAB_00053148;
      puVar2 = (undefined1 *)0xeba;
    }
    else {
      puVar2 = &DAT_3a00003a;
    }
    if (puVar3 == puVar2) goto LAB_00053148;
  }
  iVar1 = k_mem_slab_alloc((k_mem_slab *)&DAT_2000b1b4,(void **)mutex,
                           (k_timeout_t)0xffffffffffffffff);
  if ((iVar1 != 0) || (*mutex == 0)) {
    (*nrf_cc3xx_platform_abort_apis_t_20002f10.abort_fn)
              ("Could not allocate mutex before initializing");
  }
  memset((void *)*mutex,0,0x14);
  mutex[1] = 0xe80;
LAB_00053148:
  z_impl_k_mutex_init((k_mutex *)*mutex);
  mutex[1] = mutex[1] | 0x3a;
  return;
}


