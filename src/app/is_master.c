/*
 * Function: ?_is_master
 * Entry:    00016608
 * Prototype: bool __stdcall ?_is_master(void)
 */


bool __is_master(void)

{
  return GLOBAL_STATE->is_master;
}


