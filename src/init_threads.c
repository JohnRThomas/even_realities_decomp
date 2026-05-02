/*
 * Function: init_threads
 * Entry:    0002c8b8
 * Prototype: undefined __stdcall init_threads(char * param_1)
 */


void init_threads(char *param_1)

{
  k_timeout_t delay;
  k_timeout_t delay_00;
  k_timeout_t delay_01;
  k_timeout_t delay_02;
  k_timeout_t delay_03;
  k_timeout_t delay_04;
  k_timeout_t delay_05;
  k_timeout_t delay_06;
  k_timeout_t delay_07;
  k_timeout_t delay_08;
  k_timeout_t delay_09;
  char cVar1;
  code *entry;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  uint32_t in_stack_ffffffe8;
  
  z_impl_k_mutex_init(&k_mutex_2000851c);
  FUN_00025b58(param_1);
  init_watchdog();
  cVar1 = FUN_00033d5c();
  if (cVar1 == '\0') {
    delay.ticks._4_4_ = unaff_r5;
    delay.ticks._0_4_ = unaff_r4;
    k_thread_create(&k_thread_20004858,(k_thread_stack_t *)&DAT_200277e0,0xc00,
                    (k_thread_entry_t)0x2cb05,param_1,(void *)0xfffffff6,(void *)0x0,0,
                    in_stack_ffffffe8,delay);
    delay_00.ticks._4_4_ = unaff_r5;
    delay_00.ticks._0_4_ = unaff_r4;
    k_thread_create(&k_thread_msg_sync_thread,(k_thread_stack_t *)&DAT_200255e0,0x400,
                    (k_thread_entry_t)0x2a8d1,param_1,(void *)0xfffffff6,(void *)0x0,0,
                    in_stack_ffffffe8,delay_00);
  }
  else {
    delay_06.ticks._4_4_ = unaff_r5;
    delay_06.ticks._0_4_ = unaff_r4;
    k_thread_create(&k_thread_20004858,(k_thread_stack_t *)&DAT_200277e0,0xc00,
                    (k_thread_entry_t)0x28939,param_1,(void *)0xfffffff6,(void *)0x0,0,
                    in_stack_ffffffe8,delay_06);
    start_aging_mode_thread();
    FUN_00034658();
  }
  delay_01.ticks._4_4_ = unaff_r5;
  delay_01.ticks._0_4_ = unaff_r4;
  k_thread_create((k_thread *)&DAT_20004270,(k_thread_stack_t *)&DAT_200249e0,0xc00,
                  (k_thread_entry_t)0x2c711,(void *)0x0,(void *)0xfffffff7,(void *)0x0,0,
                  in_stack_ffffffe8,delay_01);
  if (*param_1 == '\x01') {
    delay_02.ticks._4_4_ = unaff_r5;
    delay_02.ticks._0_4_ = unaff_r4;
    k_thread_create((k_thread *)&DAT_20004780,(k_thread_stack_t *)&DAT_20026fe0,0x800,
                    (k_thread_entry_t)0x2afb9,param_1,(void *)0xfffffff3,(void *)0x0,0,
                    in_stack_ffffffe8,delay_02);
    delay_03.ticks._4_4_ = unaff_r5;
    delay_03.ticks._0_4_ = unaff_r4;
    k_thread_create((k_thread *)&DAT_200046a8,(k_thread_stack_t *)&DAT_200267e0,0x800,
                    (k_thread_entry_t)0x28a0d,param_1,(void *)0xfffffff4,(void *)0x0,0,
                    in_stack_ffffffe8,delay_03);
    FUN_0004b358(param_1);
  }
  else {
    if (*param_1 != '\x02') goto LAB_0002c970;
    delay_07.ticks._4_4_ = unaff_r5;
    delay_07.ticks._0_4_ = unaff_r4;
    k_thread_create((k_thread *)&DAT_20004780,(k_thread_stack_t *)&DAT_20026fe0,0x800,
                    (k_thread_entry_t)0x2afb9,param_1,(void *)0xfffffff3,(void *)0x0,0,
                    in_stack_ffffffe8,delay_07);
    delay_08.ticks._4_4_ = unaff_r5;
    delay_08.ticks._0_4_ = unaff_r4;
    k_thread_create((k_thread *)&DAT_200046a8,(k_thread_stack_t *)&DAT_200267e0,0x800,
                    (k_thread_entry_t)0x28a0d,param_1,(void *)0xfffffff4,(void *)0x0,0,
                    in_stack_ffffffe8,delay_08);
    delay_09.ticks._4_4_ = unaff_r5;
    delay_09.ticks._0_4_ = unaff_r4;
    k_thread_create((k_thread *)&DAT_200045d0,(k_thread_stack_t *)&DAT_200261e0,0x600,
                    (k_thread_entry_t)0x29fbd,param_1,(void *)0xfffffff5,(void *)0x0,0,
                    in_stack_ffffffe8,delay_09);
  }
  FUN_0004c7ac(param_1);
LAB_0002c970:
  cVar1 = FUN_00033d5c();
  if (cVar1 == '\x01') {
    entry = (code *)0x2ad95;
  }
  else {
    entry = (code *)0x2c291;
  }
  delay_04.ticks._4_4_ = unaff_r5;
  delay_04.ticks._0_4_ = unaff_r4;
  k_thread_create((k_thread *)&DAT_200044f8,(k_thread_stack_t *)&DAT_20025de0,0x400,entry,param_1,
                  (void *)0xfffffff2,(void *)0x0,0,in_stack_ffffffe8,delay_04);
  delay_05.ticks._4_4_ = unaff_r5;
  delay_05.ticks._0_4_ = unaff_r4;
  k_thread_create((k_thread *)&DAT_20004420,(k_thread_stack_t *)&DAT_200259e0,0x400,
                  (k_thread_entry_t)0x2b999,param_1,(void *)0xfffffff3,(void *)0x0,0,
                  in_stack_ffffffe8,delay_05);
  return;
}


