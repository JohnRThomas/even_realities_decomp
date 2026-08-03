/*
 * Function: blocking_start_callback
 * Entry:    0008703e
 * Prototype: void __stdcall blocking_start_callback(device * dev, clock_control_subsys_t subsys, void * user_data)
 */


/* exclude_from_export */

void blocking_start_callback(device *dev,clock_control_subsys_t subsys,void *user_data)

{
  k_sem_give(user_data);
  return;
}


