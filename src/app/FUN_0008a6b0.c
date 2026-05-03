/*
 * Function: FUN_0008a6b0
 * Entry:    0008a6b0
 * Prototype: undefined __stdcall FUN_0008a6b0(char * param_1, undefined4 param_2, uint param_3, byte * param_4)
 */


void FUN_0008a6b0(char *param_1,undefined4 param_2,uint param_3,byte *param_4)

{
  uint uVar1;
  ssize_t sVar2;
  int iVar3;
  size_t __n;
  undefined8 uVar4;
  
  if ((int)param_3 < 0) {
    vsprintf(param_1,(char *)param_4,(va_list)&stack0x00000000);
  }
  else {
    uVar1 = FUN_0007aed8(param_1,param_3,param_4,(uint *)&stack0x00000000);
    if ((-1 < (int)uVar1) && (param_3 <= uVar1)) {
      uVar4 = FUN_00054410();
      iVar3 = (int)((ulonglong)uVar4 >> 0x20);
      sVar2 = _write((int)uVar4,(void *)(int)*(short *)(iVar3 + 0xe),__n);
      if (sVar2 < 0) {
        *(ushort *)(iVar3 + 0xc) = *(ushort *)(iVar3 + 0xc) & 0xefff;
      }
      else {
        *(int *)(iVar3 + 0x54) = *(int *)(iVar3 + 0x54) + sVar2;
      }
                    /* WARNING: Could not recover jumptable at 0x0008a704. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)0x8a6e5)();
      return;
    }
  }
  return;
}


