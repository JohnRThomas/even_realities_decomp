/*
 * Function: virtqueue_free
 * Entry:    0007418c
 * Prototype: undefined __stdcall virtqueue_free(void * param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void virtqueue_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (((*(short *)((int)param_1 + 0x24) != *(short *)((int)param_1 + 10)) && (3 < *FUN_000741ba))
       && (*(code **)(FUN_000741ba + 4) != (code *)0x0)) {
      (**(code **)(FUN_000741ba + 4))(4,uRam000741c0,*(undefined4 *)((int)param_1 + 4));
    }
    k_free(param_1);
    return;
  }
  return;
}


