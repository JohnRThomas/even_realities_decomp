/*
 * Function: setup_tx_cache
 * Entry:    000881d4
 * Prototype: undefined4 __stdcall setup_tx_cache(int param_1)
 */


/* exclude_from_export_ai */

undefined4 setup_tx_cache(int param_1)

{
  undefined4 uVar1;
  size_t n;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  n = *(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 0x1c);
  if (n == 0) {
    uVar1 = 0;
  }
  else {
    if (7 < n) {
      n = 8;
    }
    *(size_t *)(iVar2 + 0x14) = n;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10) =
         *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x18);
    iVar2 = *(int *)(param_1 + 0xc);
    memcpy(*(void **)(iVar2 + 0x18),(void *)(*(int *)(iVar2 + 0x1c) + *(int *)(iVar2 + 8)),n);
    uVar1 = 1;
  }
  return uVar1;
}


