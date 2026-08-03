/*
 * Function: sys_timepoint_timeout
 * Entry:    00089e94
 * Prototype: undefined8 __stdcall sys_timepoint_timeout(int * param_1, int param_2, uint param_3, uint param_4)
 */


/* exclude_from_export */

undefined8 sys_timepoint_timeout(int *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int64_t iVar5;
  
  if (param_4 == 0xffffffff && param_3 == 0xffffffff) {
    iVar3 = -1;
    iVar4 = iVar3;
  }
  else {
    if (param_4 != 0 || param_3 != 0) {
      iVar5 = sys_clock_tick_get();
      uVar2 = (uint)((ulonglong)iVar5 >> 0x20);
      uVar1 = (uint)iVar5;
      param_2 = (uVar2 - param_4) - (uint)(param_3 > uVar1);
      if (uVar2 <= param_4 && (uint)(param_3 <= uVar1) <= uVar2 - param_4) {
        iVar3 = param_3 - uVar1;
        iVar4 = (param_4 - uVar2) - (uint)(param_3 < uVar1);
        goto LAB_00089ec2;
      }
    }
    iVar3 = 0;
    iVar4 = iVar3;
  }
LAB_00089ec2:
  *param_1 = iVar3;
  param_1[1] = iVar4;
  return CONCAT44(param_2,param_1);
}


