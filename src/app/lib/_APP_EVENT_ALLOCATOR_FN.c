/*
 * Function: _APP_EVENT_ALLOCATOR_FN
 * Entry:    00066e74
 * Prototype: void * __stdcall _APP_EVENT_ALLOCATOR_FN(uint size)
 */


/* exclude_from_export */

void * _APP_EVENT_ALLOCATOR_FN(uint size)

{
  void *pvVar1;
  
  pvVar1 = app_event_manager_alloc(0xc);
  if (pvVar1 != (void *)0x0) {
    *(undefined **)((int)pvVar1 + 4) = &DAT_000f8ba4;
  }
  return pvVar1;
}


