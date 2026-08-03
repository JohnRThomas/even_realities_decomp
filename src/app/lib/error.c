/*
 * Function: error
 * Entry:    000884e6
 * Prototype: undefined __stdcall error(uint param_1)
 */


/* exclude_from_export */

void error(uint param_1)

{
  app_event_header *aeh;
  
  aeh = _APP_EVENT_ALLOCATOR_FN(param_1);
  *(undefined1 *)&aeh[1].node.next = 0;
  _event_submit(aeh);
  set_power_state(POWER_STATE_ERROR_SUSPENDED);
  return;
}


