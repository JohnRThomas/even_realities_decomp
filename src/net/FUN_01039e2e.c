/*
 * Function: FUN_01039e2e
 * Entry:    01039e2e
 * Prototype: undefined4 __stdcall FUN_01039e2e(undefined4 param_1, undefined * UNRECOVERED_JUMPTABLE, undefined4 param_3, byte * param_4)
 */


undefined4
FUN_01039e2e(undefined4 param_1,undefined *UNRECOVERED_JUMPTABLE,undefined4 param_3,byte *param_4)

{
  byte bVar1;
  undefined4 uVar2;
  char *pcVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  
  if (param_4 != (byte *)0x0) {
    bVar1 = param_4[1];
    pbVar4 = param_4 + (uint)*param_4 * 4 + (uint)param_4[3] * 2 + (uint)param_4[2];
    for (uVar6 = 0; uVar6 < bVar1; uVar6 = uVar6 + 1) {
      pbVar5 = pbVar4 + 1;
      *(byte **)(param_4 + (uint)*pbVar4 * 4) = pbVar5;
      pcVar3 = FUN_0102aa68((char *)pbVar5);
      pbVar4 = pbVar5 + (int)(pcVar3 + 1);
    }
                    /* WARNING: Could not recover jumptable at 0x01039e6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)UNRECOVERED_JUMPTABLE)
                      (param_1,param_3,*(undefined4 *)(param_4 + 4),param_4 + 8);
    return uVar2;
  }
  return 0xffffffea;
}


