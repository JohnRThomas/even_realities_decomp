/*
 * Function: FUN_0102ea44
 * Entry:    0102ea44
 * Prototype: undefined __stdcall FUN_0102ea44(uint param_1, uint param_2, byte * param_3, undefined1 * param_4)
 */


void FUN_0102ea44(uint param_1,uint param_2,byte *param_3,undefined1 *param_4)

{
  byte *pbVar1;
  undefined4 extraout_r3;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  undefined1 *local_68;
  char *local_64;
  undefined1 auStack_3c [8];
  uint *local_34;
  byte *local_30;
  undefined4 local_2c;
  
  pbVar3 = (byte *)((param_2 << 0xc) >> 0x15);
  puVar2 = (uint *)(param_2 >> 0x14);
  uVar4 = 0;
  if (pbVar3 != (byte *)0x0) {
    local_34 = (uint *)0x0;
    local_30 = (byte *)0x0;
    local_2c = 0;
    pbVar1 = FUN_0102c7a4(param_3,pbVar3,(undefined *)0x0,&local_34,10,(int)auStack_3c,4);
    if (&DAT_000007ff < pbVar1) {
      local_64 = "Message (\"%s\") dropped because it exceeds size limitation (%u)";
      local_68 = &DAT_01000004;
      FUN_0102ea44(0x103c03c,0x2480,(byte *)&local_68,(undefined1 *)0x0);
      return;
    }
    uVar4 = (uint)pbVar1 & 0x7ff;
    puVar2 = (uint *)FUN_0102e6b4(((uint)(pbVar1 + (int)puVar2 + 0x17) & 0xfffffff8) >> 2);
    param_2 = param_2 & 0xfff001ff;
    if (puVar2 == (uint *)0x0) goto LAB_0102eb3c;
    local_34 = puVar2 + 4;
    local_2c = 0;
    local_30 = pbVar1;
    pbVar3 = FUN_0102c7a4(param_3,pbVar3,(undefined *)0x103aa8d,&local_34,10,(int)auStack_3c,4);
    if (-1 < (int)pbVar3) goto LAB_0102eb3c;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/logging/log_msg.c",
                 0x59,extraout_r3);
    FUN_0103a370();
  }
  puVar2 = (uint *)FUN_0102e6b4(((int)puVar2 + 0x17U & 0xfffffff8) >> 2);
LAB_0102eb3c:
  FUN_0103aab8(puVar2,param_1,param_2 & 0xfff001ff | uVar4 << 9,param_4);
  return;
}


