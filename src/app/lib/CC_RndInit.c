/*
 * Function: CC_RndInit
 * Entry:    0007cecc
 * Prototype: undefined __stdcall CC_RndInit(void * param_1)
 */


/* exclude_from_export_ai */

void CC_RndInit(void *param_1)

{
  memset(param_1,0,0xa4);
  *(undefined4 *)((int)param_1 + 0x10) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x1c) = 0xfff0;
                    /* WARNING: Could not recover jumptable at 0x0007cef0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_20002f7c)((int)param_1 + 0x9c);
  return;
}


