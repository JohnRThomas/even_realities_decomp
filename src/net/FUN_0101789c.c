/*
 * Function: FUN_0101789c
 * Entry:    0101789c
 * Prototype: undefined * __stdcall FUN_0101789c(ushort * param_1, int param_2)
 */


undefined * FUN_0101789c(ushort *param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint extraout_r2;
  char cVar8;
  undefined2 local_50;
  byte *local_4c;
  undefined4 local_48;
  byte local_3f;
  code *UNRECOVERED_JUMPTABLE;
  
  cVar2 = DAT_2100001c;
  if (DAT_21001012 == '\0') {
    return (undefined *)0x0;
  }
  if (DAT_21001038 == '\0') {
    if ((char)*param_1 == '\0') {
      DAT_21001038 = '\x01';
    }
    else {
      DAT_21001038 = '\x02';
    }
  }
  if (DAT_21001000 == '\b') {
    cVar8 = '\x03';
  }
  else if (DAT_21001000 == '\t') {
    cVar8 = '\x02';
  }
  else {
    cVar8 = '\x01';
  }
  if (DAT_2100001c != '\x7f') {
    DAT_2100001c = 0x7f;
    uVar4 = FUN_0101a2a0(param_1,param_2,&DAT_21000fd6,(uint)DAT_21001049,DAT_2100101f,DAT_21001009,
                         cVar2,cVar8);
    if (uVar4 == 0) {
      if (cVar8 == '\x02') {
        return (undefined *)0x0;
      }
    }
    else {
      bVar1 = *(byte *)((int)param_1 + 1);
      if ((bVar1 & 0x10) == 0) {
        FUN_01019e60();
        return (undefined *)(bVar1 & 0x10);
      }
      puVar5 = FUN_01017818(2,*(byte **)(param_1 + 0xc));
      if (puVar5 != (undefined *)0x0) {
        DAT_21001018 = 0;
        FUN_01020d00();
        return puVar5;
      }
    }
    FUN_01019ee0();
    return (undefined *)0x0;
  }
  FUN_01017028(param_1,param_2,0x7f,&DAT_2100001c);
  UNRECOVERED_JUMPTABLE = (code *)0x1017949;
  iVar6 = FUN_0100df60();
  DAT_2100001c = (char)iVar6;
  if ((*(byte *)(extraout_r2 >> 0x1e) & 0xf) == 7) {
    FUN_0101a870((byte *)(extraout_r2 >> 0x1e),(byte *)&local_50);
    local_48 = 0;
    if ((((byte)local_50 == 0) && ((int)((uint)local_50._1_1_ << 0x1f) < 0)) &&
       (bVar3 = FUN_0100b23c((uint)local_3f,local_4c,(uint)DAT_21001020,(byte *)&DAT_21001019),
       bVar3)) {
      FUN_01029dd6((ushort *)&DAT_21001014,1);
      puVar5 = FUN_0101789c(&local_50,0xff);
      if (puVar5 != (undefined *)0x0) {
        uVar7 = 3;
        goto LAB_0101796e;
      }
    }
  }
  uVar7 = 1;
LAB_0101796e:
                    /* WARNING: Could not recover jumptable at 0x01017970. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  puVar5 = (undefined *)(*UNRECOVERED_JUMPTABLE)(uVar7);
  return puVar5;
}


