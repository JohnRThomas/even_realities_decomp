/*
 * Function: CC_PalTerminate
 * Entry:    0007d5d4
 * Prototype: void __stdcall CC_PalTerminate(void)
 */


/* exclude_from_export */

void CC_PalTerminate(void)

{
  CC_PalMutexDestroy((undefined4 *)&DAT_20002f70);
  CC_PalMutexDestroy((undefined4 *)&DAT_20002f6c);
  CC_PalMutexDestroy((undefined4 *)&DAT_20002f68);
  CC_PalMutexDestroy((undefined4 *)&DAT_20002f64);
  return;
}


