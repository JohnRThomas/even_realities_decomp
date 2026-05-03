/*
 * Function: FUN_010110b8
 * Entry:    010110b8
 * Prototype: undefined __stdcall FUN_010110b8(int param_1, int param_2, int param_3, undefined4 * param_4)
 */


void FUN_010110b8(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [16];
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  FUN_0100dba0((int)auStack_40,param_1,0x10);
  FUN_0100dba0((int)auStack_30,param_2,0x10);
  FUN_0100afe8((uint)auStack_40);
  if (param_3 != 0) {
    FUN_0100dba0((int)param_4,(int)&local_20,0x10);
    return;
  }
  *param_4 = local_20;
  param_4[1] = uStack_1c;
  param_4[2] = uStack_18;
  param_4[3] = uStack_14;
  return;
}


