/*
 * Function: FUN_01017954
 * Entry:    01017954
 * Prototype: undefined __stdcall FUN_01017954(byte * param_1)
 */


void FUN_01017954(byte *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  code *UNRECOVERED_JUMPTABLE;
  undefined2 local_30;
  byte *local_2c;
  undefined4 local_28;
  byte local_1f;
  
  iVar2 = FUN_0100df60();
  DAT_2100001c = (undefined1)iVar2;
  if ((*param_1 & 0xf) == 7) {
    FUN_0101a870(param_1,(byte *)&local_30);
    local_28 = 0;
    if ((((byte)local_30 == 0) && ((int)((uint)local_30._1_1_ << 0x1f) < 0)) &&
       (bVar1 = FUN_0100b23c((uint)local_1f,local_2c,(uint)DAT_21001020,(byte *)&DAT_21001019),
       bVar1)) {
      FUN_01029dd6((ushort *)&DAT_21001014,1);
      puVar4 = FUN_0101789c(&local_30,0xff);
      if (puVar4 != (undefined *)0x0) {
        uVar3 = 3;
        goto LAB_0101796e;
      }
    }
  }
  uVar3 = 1;
LAB_0101796e:
                    /* WARNING: Could not recover jumptable at 0x01017970. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar3);
  return;
}


