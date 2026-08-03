/*
 * Function: onoff_manager_init
 * Entry:    000819aa
 * Prototype: int __stdcall onoff_manager_init(onoff_manager * mgr, onoff_transitions * transitions)
 */


/* exclude_from_export */

int onoff_manager_init(onoff_manager *mgr,onoff_transitions *transitions)

{
  int iVar1;
  
  if ((((mgr == (onoff_manager *)0x0) || (transitions == (onoff_transitions *)0x0)) ||
      (*transitions == 0)) || (transitions[1] == 0)) {
    iVar1 = -0x16;
  }
  else {
    memset(mgr,0,0x20);
    iVar1 = 0;
    mgr->last_res = (int)transitions;
  }
  return iVar1;
}


