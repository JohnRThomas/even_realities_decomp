/*
 * Function: user_callback
 * Entry:    00087ff0
 * Prototype: void __stdcall user_callback(device * dev, uart_event * event)
 */


/* exclude_from_export */

void user_callback(device *dev,uart_event *event)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)**(undefined4 **)(dev->data + 0xc);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00087ffa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(dev,event,(*(undefined4 **)(dev->data + 0xc))[1]);
    return;
  }
  return;
}


