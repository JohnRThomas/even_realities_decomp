/*
 * Function: FUN_01021ed4
 * Entry:    01021ed4
 * Prototype: int __stdcall FUN_01021ed4(uint param_1, uint param_2, int param_3, undefined2 * param_4)
 */


int FUN_01021ed4(uint param_1,uint param_2,int param_3,undefined2 *param_4)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar6;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar7;
  undefined1 local_29 [5];
  
  cVar2 = FUN_01022134();
  uVar1 = DAT_21000042;
  if ((((DAT_2100003c == param_1) && (DAT_2100003d == param_2)) && (DAT_2100003e == param_3)) &&
     (DAT_2100003f == cVar2)) {
    iVar5 = (int)DAT_21000043;
    *param_4 = DAT_21000040;
    *(undefined1 *)(param_4 + 1) = uVar1;
  }
  else {
    switch(param_1) {
    case 1:
      uVar3 = 0;
      break;
    case 2:
      uVar3 = 1;
      break;
    default:
      FUN_01009500(6,0x405,extraout_r2,param_1 - 1);
      uVar6 = extraout_r2_01;
      uVar7 = extraout_r3_00;
      goto LAB_01021f80;
    case 4:
      uVar3 = 3;
      break;
    case 8:
      uVar3 = 2;
    }
    iVar5 = FUN_01022140(uVar3,param_2,param_3,local_29);
    uVar6 = extraout_r2_00;
    uVar7 = extraout_r3;
    if (iVar5 != 0) {
LAB_01021f80:
      iVar4 = FUN_01009500(0x75,0x3d,uVar6,uVar7);
      iVar4 = iVar4 * 2;
                    /* WARNING (jumptable): Read-only address (ram,0x00000000) is written */
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      MasterStackPointer = 0;
      iVar5 = iVar4;
      if (*(undefined4 **)(iVar4 + 0x58) != (undefined4 *)0x0) {
        iVar5 = FUN_01028294(DAT_21001664,*(undefined4 **)(iVar4 + 0x58));
        *(undefined4 *)(iVar4 + 0x58) = 0;
      }
      return iVar5;
    }
    FUN_01020a8c(param_2);
    iVar5 = FUN_01022120();
    DAT_21000040 = *param_4;
    DAT_21000042 = *(undefined1 *)(param_4 + 1);
    DAT_2100003c = (byte)param_1;
    DAT_2100003d = (byte)param_2;
    DAT_2100003e = (char)param_3;
    DAT_21000043 = (char)iVar5;
    DAT_2100003f = cVar2;
  }
  return iVar5;
}


