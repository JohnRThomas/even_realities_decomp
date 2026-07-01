/*
 * Function: FUN_00018ba8
 * Entry:    00018ba8
 * Prototype: undefined __stdcall FUN_00018ba8(void)
 */


void FUN_00018ba8(void)

{
  atomic_and((atomic_t *)&ancs_discovery_flags,-2);
  atomic_and((atomic_t *)&ancs_discovery_flags,-3);
  atomic_and((atomic_t *)&ancs_discovery_flags,-5);
  return;
}


