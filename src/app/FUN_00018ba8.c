/*
 * Function: FUN_00018ba8
 * Entry:    00018ba8
 * Prototype: undefined __stdcall FUN_00018ba8(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void FUN_00018ba8(void)

{
  atomic_and((atomic_t *)&GLOBAL_STATE.sem_8.count,-2);
  atomic_and((atomic_t *)&GLOBAL_STATE.sem_8.count,-3);
  atomic_and((atomic_t *)&GLOBAL_STATE.sem_8.count,-5);
  return;
}


