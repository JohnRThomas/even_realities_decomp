/*
 * Function: slice_timeout
 * Entry:    000769d0
 * Prototype: void __stdcall slice_timeout(_timeout * t)
 */


/* exclude_from_export */

void slice_timeout(_timeout *t)

{
  undefined **ppuVar1;
  
  if ((((t != (_timeout *)0x0) && ((_timeout *)0x20006ba7 < t)) && (t < (_timeout *)&DAT_20006bc0))
     && (ppuVar1 = &t[-0x15559d2].fn, ppuVar1 == (undefined **)(((uint)ppuVar1 / 0x18) * 0x18))) {
    (&DAT_2001e2d9)[((int)ppuVar1 >> 3) * -0x55555555] = 1;
    return;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
          "((t) && ((uintptr_t) (slice_timeouts)) <= ((uintptr_t) (t)) && ((uintptr_t) (t)) < ((uintptr_t) (&(slice_timeouts)[((size_t) (((int) sizeof(char[1 - 2 * !(!__builtin_types_compatible_p(__typeof__(slice_timeouts), __typeof__(&(slice_timeouts)[0])))]) - 1) + (sizeof(slice_timeouts) / sizeof((slice_timeouts)[0]))))])) && (((uintptr_t) (t)) - ((uintptr_t) (slice_timeouts))) % sizeof((slice_timeouts)[0]) == 0)"
          ,"WEST_TOPDIR/zephyr/kernel/sched.c",467);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


