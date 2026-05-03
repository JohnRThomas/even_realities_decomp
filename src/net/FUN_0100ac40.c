/*
 * Function: FUN_0100ac40
 * Entry:    0100ac40
 * Prototype: undefined1 * __stdcall FUN_0100ac40(void)
 */


undefined1 * FUN_0100ac40(void)

{
  byte local_d;
  undefined1 *local_c;
  
  local_c = (undefined1 *)0x0;
  local_d = 0;
  do {
    if (DAT_21000bb8 <= local_d) {
LAB_0100ac8a:
      if (local_c == (undefined1 *)0x0) {
        FUN_01009500(9,0xa9,(uint)local_d,0);
      }
      else {
        local_c[2] = 0;
        FUN_0100ab1c((int)local_c,'\x01');
        *local_c = 0;
      }
      return local_c;
    }
    if (*(char *)((uint)local_d * 0x28 + DAT_21000bbc) != '\0') {
      local_c = (undefined1 *)((uint)local_d * 0x28 + DAT_21000bbc);
      goto LAB_0100ac8a;
    }
    local_d = local_d + 1;
  } while( true );
}


