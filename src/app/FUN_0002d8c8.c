/*
 * Function: FUN_0002d8c8
 * Entry:    0002d8c8
 * Prototype: undefined4 __stdcall FUN_0002d8c8(char * param_1, int param_2, int param_3)
 */


undefined4 FUN_0002d8c8(char *param_1,int param_2,int param_3)

{
  char *pcVar1;
  undefined4 extraout_r3;
  undefined4 uVar2;
  undefined4 extraout_r3_00;
  
  if (param_3 != 0) {
    FUN_0008027a(param_1,param_2,1);
    pcVar1 = "imu-on";
    uVar2 = extraout_r3_00;
  }
  else {
    FUN_0008027a(param_1,param_2,0);
    pcVar1 = "imu-off";
    uVar2 = extraout_r3;
  }
  trigger_screen_state_change(pcVar1,param_2,(uint)(param_3 != 0),uVar2);
  return 0;
}


