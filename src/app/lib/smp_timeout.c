/*
 * Function: smp_timeout
 * Entry:    0006168c
 * Prototype: void __stdcall smp_timeout(k_work * work)
 */


/* exclude_from_export_ai */

void smp_timeout(k_work *work)

{
  char local_10 [4];
  char *local_c;
  
  local_c = "SMP Timeout";
  local_10[0] = '\x02';
  local_10[1] = '\0';
  local_10[2] = '\0';
  local_10[3] = '\0';
  LOG_ERR(&PTR_s_bt_smp_0008b930,0x1040,local_10);
  smp_pairing_complete((bt_smp *)&work[-0x21].queue,'\b');
  atomic_set_bit((atomic_t *)&work[-0x21].flags,4);
  return;
}


