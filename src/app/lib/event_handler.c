/*
 * Function: event_handler
 * Entry:    00064b00
 * Prototype: void __stdcall event_handler(int * event, void * context)
 */


/* exclude_from_export_ai */

void event_handler(int *event,void *context)

{
  char cVar1;
  undefined1 *puVar2;
  
  cVar1 = (char)*event;
  if (cVar1 == '\x01') {
    puVar2 = (undefined1 *)0xbae0001;
  }
  else if (cVar1 == '\x02') {
    puVar2 = (undefined1 *)0xbae0002;
  }
  else if (cVar1 == '\0') {
    puVar2 = &DAT_0bad0000;
  }
  else {
    puVar2 = (undefined1 *)0xbad0001;
  }
  *(undefined1 **)((int)context + 0x30) = puVar2;
  k_sem_give((k_sem *)((int)context + 0x18));
  return;
}


