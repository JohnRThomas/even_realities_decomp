/*
 * Function: bt_init
 * Entry:    00057cd8
 * Prototype: int __stdcall bt_init(void)
 */


/* exclude_from_export_ai */

int bt_init(void)

{
  int extraout_r0;
  int iVar1;
  
  bt_init();
  if (DAT_2000b64c != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00057ce8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*DAT_2000b64c)();
    return iVar1;
  }
  return extraout_r0;
}


