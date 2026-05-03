/*
 * Function: FUN_01031bac
 * Entry:    01031bac
 * Prototype: undefined4 __stdcall FUN_01031bac(uint param_1, undefined4 param_2, uint param_3, uint param_4, undefined4 param_5, undefined4 param_6, char param_7)
 */


undefined4
FUN_01031bac(uint param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,
            undefined4 param_6,char param_7)

{
  bool bVar1;
  uint uVar2;
  int extraout_r1;
  int extraout_r1_00;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  
  bVar1 = FUN_01031a08(param_1);
  uVar8 = FUN_01031b68();
  uVar6 = (uint)((ulonglong)uVar8 >> 0x20);
  uVar2 = (uint)uVar8;
  if (param_4 < uVar6 || uVar6 - param_4 < (uint)(param_3 <= uVar2)) {
    if (param_7 == '\0') {
      DAT_21004964 = DAT_21004964 | 1 << (param_1 & 0xff);
      goto LAB_01031ca2;
    }
  }
  else if (param_4 - uVar6 == (uint)(param_3 < uVar2) &&
           (uint)(0x800000 < param_3 - uVar2) <= (param_4 - uVar6) - (uint)(param_3 < uVar2)) {
    if (param_4 != (&DAT_21002b6c)[param_1 * 4] || param_3 != (&DAT_21002b68)[param_1 * 4]) {
      uVar6 = 0x10000 << (param_1 & 0xff);
      Peripherals::RTC1_NS.EVTENCLR = uVar6;
      FUN_0103ae6e((short)param_1);
      iVar7 = 3;
      uVar2 = param_3 & 0xffffff;
      iVar3 = extraout_r1;
      while( true ) {
        *(uint *)(iVar3 + (param_1 + 0x150) * 4) = uVar2 & 0xffffff;
        *(uint *)(iVar3 + 0x344) = uVar6;
        iVar4 = *(int *)(iVar3 + 0x504);
        if (((uVar2 - iVar4) - 3 & 0xffffff) < 0x7ffffe) break;
        if (*(int *)((int)&Peripherals::RTC1_NS.TASKS_START + ((param_1 + 0x50) * 4 & 0xffff)) != 0)
        {
          iVar4 = *(int *)(iVar3 + 0x504);
          if ((iVar4 - (param_3 & 0xffffff) & 0xffffff) < 0x800001) break;
          FUN_0103ae6e((short)param_1);
          iVar3 = extraout_r1_00;
        }
        if (param_7 != '\0') goto LAB_01031c7a;
        uVar2 = iVar7 + iVar4;
        iVar7 = iVar7 + 1;
      }
    }
LAB_01031ca2:
    (&DAT_21002b60)[param_1 * 4] = param_5;
    uVar5 = 0;
    (&DAT_21002b68)[param_1 * 4] = param_3;
    (&DAT_21002b6c)[param_1 * 4] = param_4;
    (&DAT_21002b64)[param_1 * 4] = param_6;
    goto LAB_01031c7e;
  }
LAB_01031c7a:
  uVar5 = 0xffffffea;
LAB_01031c7e:
  FUN_01031a90(param_1,(uint)bVar1);
  return uVar5;
}


