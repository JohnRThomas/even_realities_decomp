/*
 * Function: onoff_started_callback
 * Entry:    0008700e
 * Prototype: void __stdcall onoff_started_callback(device * dev, clock_control_subsys_t sys, void * user_data)
 */


/* exclude_from_export */

void onoff_started_callback(device *dev,clock_control_subsys_t sys,void *user_data)

{
                    /* WARNING: Could not recover jumptable at 0x00087018. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*user_data)(dev->data + (sys & 0xffU) * 0x20,0);
  return;
}


