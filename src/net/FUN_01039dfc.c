/*
 * Function: FUN_01039dfc
 * Entry:    01039dfc
 * Prototype: undefined4 __stdcall FUN_01039dfc(undefined1 * param_1, undefined1 * param_2)
 */


undefined4 FUN_01039dfc(undefined1 *param_1,undefined1 *param_2)

{
  undefined4 local_10c;
  undefined1 auStack_108 [248];
  
  local_10c = 0;
  FUN_0103bdee(auStack_108,0,0xf8);
  FUN_0103bcfa((undefined1 *)&local_10c,param_1,param_2,&UNK_000000fc);
  FUN_0102ae78((undefined1 *)&local_10c);
  FUN_0102acb0();
  return 0;
}


