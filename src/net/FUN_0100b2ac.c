/*
 * Function: FUN_0100b2ac
 * Entry:    0100b2ac
 * Prototype: bool __stdcall FUN_0100b2ac(undefined4 * param_1, char * param_2)
 */


bool FUN_0100b2ac(undefined4 *param_1,char *param_2)

{
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined1 local_24;
  char local_23;
  char local_22;
  char local_21;
  char local_13;
  char local_12;
  char local_11;
  
  local_21 = param_2[3];
  local_40 = *param_1;
  uStack_3c = param_1[1];
  uStack_38 = param_1[2];
  uStack_34 = param_1[3];
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  uStack_2c = 0;
  local_22 = param_2[4];
  local_23 = param_2[5];
  FUN_0100afe8((uint)&local_40);
  if ((*param_2 == local_11) && (param_2[1] == local_12)) {
    return param_2[2] == local_13;
  }
  return false;
}


