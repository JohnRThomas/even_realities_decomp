/*
 * Function: bg_thread_main
 * Entry:    00074aa0
 * Prototype: void __stdcall bg_thread_main(void * unused1, void * unused2, void * unused3)
 */


/* exclude_from_export */

void bg_thread_main(void *unused1,void *unused2,void *unused3)

{
  slice_expired = 1;
  z_sys_init_run_level(INIT_LEVEL_POST_KERNEL);
  boot_banner();
  z_sys_init_run_level(INIT_LEVEL_APPLICATION);
  z_init_static_threads();
  main();
  DAT_200069e4 = DAT_200069e4 & 0xfe;
  return;
}


