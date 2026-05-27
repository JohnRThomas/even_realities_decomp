/*
 * Function: ?_get_dmic_num_messages
 * Entry:    0003018c
 * Prototype: dword __stdcall ?_get_dmic_num_messages(void)
 */


dword __get_dmic_num_messages(void)

{
  return dmic_msgq.used_msgs;
}


