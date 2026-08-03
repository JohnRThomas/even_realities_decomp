/*
 * Function: _cleanup_r
 * Entry:    00079e38
 * Prototype: undefined __stdcall _cleanup_r(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* exclude_from_export */

void _cleanup_r(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  _fwalk_reent(param_1,(undefined *)0x79d79,param_3,param_4);
  return;
}


