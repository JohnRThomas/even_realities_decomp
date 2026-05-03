/*
 * Function: FUN_0102f200
 * Entry:    0102f200
 * Prototype: undefined __stdcall FUN_0102f200(uint param_1, undefined4 * param_2)
 */


void FUN_0102f200(uint param_1,undefined4 *param_2)

{
  byte local_38 [4];
  char *local_34;
  undefined4 local_30;
  char *local_2c;
  undefined4 uStack_28;
  
  if (param_2 != (undefined4 *)0x0) {
    local_30 = *param_2;
    local_2c = (char *)param_2[1];
    uStack_28 = param_2[2];
    local_34 = "r0/a1:  0x%08x  r1/a2:  0x%08x  r2/a3:  0x%08x";
    local_38[0] = 5;
    local_38[1] = 0;
    local_38[2] = 0;
    local_38[3] = 0;
    FUN_0102ea44(0x103c084,0x2840,local_38,(undefined1 *)0x0);
    local_30 = param_2[3];
    local_2c = (char *)param_2[4];
    uStack_28 = param_2[5];
    local_34 = "r3/a4:  0x%08x r12/ip:  0x%08x r14/lr:  0x%08x";
    local_38[0] = 5;
    local_38[1] = 0;
    local_38[2] = 0;
    local_38[3] = 0;
    FUN_0102ea44(0x103c084,0x2840,local_38,(undefined1 *)0x0);
    uStack_28 = param_2[7];
    local_2c = " xpsr:  0x%08x";
    local_30 = 3;
    FUN_0102ea44(0x103c084,0x1840,(byte *)&local_30,(undefined1 *)0x0);
    uStack_28 = param_2[6];
    local_30 = 3;
    local_2c = "Faulting instruction address (r15/pc): 0x%08x";
    FUN_0102ea44(0x103c084,0x1840,(byte *)&local_30,(undefined1 *)0x0);
  }
  FUN_01036178(param_1,(int)param_2);
  return;
}


