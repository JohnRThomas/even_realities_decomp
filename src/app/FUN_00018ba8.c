/*
 * Function: FUN_00018ba8
 * Entry:    00018ba8
 * Prototype: undefined __stdcall FUN_00018ba8(void)
 */


void FUN_00018ba8(void)

{
  atomic_and((atomic_t *)&GLOBAL_STATE.sem_8.count,-2);
  atomic_and((atomic_t *)&GLOBAL_STATE.sem_8.count,-3);
  atomic_and((atomic_t *)&GLOBAL_STATE.sem_8.count,-5);
  return;
}


