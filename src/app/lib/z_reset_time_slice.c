/*
 * Function: z_reset_time_slice
 * Entry:    00076a30
 * Prototype: void __stdcall z_reset_time_slice(k_thread * curr)
 */


/* exclude_from_export */

void z_reset_time_slice(k_thread *curr)

{
  bool bVar1;
  _timeout *to;
  uint uVar2;
  
  uVar2 = (uint)(byte)_current.init_data;
  to = (_timeout *)(uVar2 * 0x18 + 0x20006ba8);
  z_abort_timeout(to);
  (&DAT_2001e2d9)[uVar2] = 0;
  bVar1 = sliceable(curr);
  if (bVar1) {
    z_add_timeout(to,(_timeout_func_t)0x769d1,(k_timeout_t)(longlong)(_current._60_4_ + -1));
    return;
  }
  return;
}


