/*
 * Function: FUN_0100a0d8
 * Entry:    0100a0d8
 * Prototype: int __stdcall FUN_0100a0d8(uint param_1, byte * param_2)
 */


int FUN_0100a0d8(uint param_1,byte *param_2)

{
  byte *extraout_r1;
  byte *extraout_r1_00;
  byte *extraout_r1_01;
  byte *pbVar1;
  uint extraout_r2;
  uint extraout_r2_00;
  undefined4 uVar2;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  uint uVar3;
  uint *puVar4;
  undefined8 uVar5;
  undefined1 *local_1c;
  undefined3 local_18;
  byte bStack_15;
  uint local_14;
  uint local_10;
  char local_9;
  
  uVar3 = (uint)param_2[1] + (uint)param_2[2];
  pbVar1 = param_2;
  if (0xff < uVar3) {
    FUN_01009500(0x17,0x15b,(uint)param_2[2],uVar3);
    pbVar1 = extraout_r1;
  }
  uVar3 = (uint)*param_2;
  if (param_2[1] < uVar3) {
    FUN_01009500(0x17,0x15f,uVar3,(uint)param_2[1]);
    pbVar1 = extraout_r1_00;
    uVar3 = extraout_r2;
  }
  local_9 = param_1 == 0;
  local_10 = param_1;
  if ((!(bool)local_9) && (DAT_21000ba8 != '\x02')) {
    FUN_0100a0d8(0,param_2);
    pbVar1 = extraout_r1_01;
    uVar3 = extraout_r2_00;
  }
  if (local_9 == '\0') {
    puVar4 = &local_10;
  }
  else {
    puVar4 = (uint *)0x0;
  }
  FUN_01009e68(puVar4,pbVar1,uVar3);
  local_1c = (undefined1 *)0x101e0e9;
  _local_18 = CONCAT13(param_2[1],0x80360);
  local_14 = local_14 & 0xffffff00;
  FUN_01009f08(0,&local_1c,(uint)param_2[1]);
  local_1c = (undefined1 *)0x1016591;
  _local_18 = CONCAT13(param_2[2],0x803f0);
  local_14 = local_14 & 0xffffff00;
  FUN_01009f08(1,&local_1c,(uint)param_2[2]);
  local_1c = (undefined1 *)0x1012a5d;
  _local_18 = CONCAT13(param_2[3],0x80150);
  local_14._0_1_ = 0xff;
  FUN_01009f08(2,&local_1c,(uint)param_2[3]);
  local_1c = (undefined1 *)0x102a2c1;
  _local_18 = CONCAT13(param_2[4],0x80090);
  local_14._0_1_ = 0xff;
  FUN_01009f08(3,&local_1c,(uint)param_2[4]);
  local_1c = (undefined1 *)0x10203c9;
  _local_18 = CONCAT13(param_2[5],0x800a8);
  local_14 = CONCAT31(local_14._1_3_,1);
  FUN_01009f08(4,&local_1c,(uint)param_2[5]);
  uVar2 = 0;
  local_1c = &LAB_0102a3b4_1;
  _local_18 = CONCAT13(param_2[6],0x80000);
  local_14._0_1_ = 0xff;
  local_14._1_3_ = 0;
  if (param_2[6] != 0) {
    uVar2 = FUN_010203a4();
    _local_18 = CONCAT22(stack0xffffffea,(short)uVar2);
    uVar2 = extraout_r2_01;
  }
  FUN_01009f08(5,&local_1c,uVar2);
  local_1c = &LAB_0102a3b8_1;
  _local_18 = CONCAT13(param_2[7],0x80080);
  local_14._0_1_ = 0xff;
  FUN_01009f08(6,&local_1c,(uint)param_2[7]);
  local_1c = (undefined1 *)0x101e90d;
  _local_18 = CONCAT13(param_2[8],0x80078);
  local_14._0_1_ = 2;
  FUN_01009f08(7,&local_1c,(uint)param_2[8]);
  local_1c = (undefined1 *)0x101e879;
  _local_18 = CONCAT13(param_2[9],0x801f0);
  local_14._0_1_ = 0;
  FUN_01009f08(8,&local_1c,(uint)param_2[9]);
  local_1c = (undefined1 *)0x101e961;
  _local_18 = CONCAT13(param_2[10],0x80120);
  local_14._0_1_ = 0xff;
  FUN_01009f08(9,&local_1c,(uint)param_2[10]);
  local_1c = (undefined1 *)0x101e9e1;
  _local_18 = CONCAT13(param_2[0xb],0x80100);
  local_14 = (uint)local_14._1_3_ << 8;
  uVar5 = FUN_01009f08(10,&local_1c,(uint)param_2[0xb]);
  FUN_0100a074((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),extraout_r2_02);
  return DAT_21000bac - param_1;
}


