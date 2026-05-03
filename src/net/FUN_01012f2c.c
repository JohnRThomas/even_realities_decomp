/*
 * Function: FUN_01012f2c
 * Entry:    01012f2c
 * Prototype: undefined4 __stdcall FUN_01012f2c(undefined1 * param_1)
 */


undefined4 FUN_01012f2c(undefined1 *param_1)

{
  undefined2 uVar1;
  char cVar2;
  uint uVar3;
  uint extraout_r2;
  undefined1 uVar4;
  uint uVar5;
  
  cVar2 = DAT_21000f32;
  if (DAT_21000f24 == '\x01') {
    *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + 1;
    uVar3 = 0;
    if (cVar2 != '\0') {
      FUN_010210b0();
      FUN_010204a8();
      DAT_21000f32 = '\0';
      uVar3 = extraout_r2;
    }
    DAT_21000f24 = '\0';
    if ((byte)param_1[0x79] == 0) {
      uVar5 = (uint)(byte)param_1[0xd];
      if ((uVar5 == 0) || (uVar3 = (uint)*(ushort *)(param_1 + 0x40), uVar3 < uVar5)) {
        FUN_010148ec(param_1,0,uVar3,uVar5);
      }
      else {
        FUN_010148ec(param_1,1,uVar3,uVar5);
        if ((int)((uint)*(ushort *)(param_1 + 2) << 0x1f) < 0) {
          uVar1 = **(undefined2 **)(param_1 + 0x1c);
          cVar2 = FUN_01020088();
          if (cVar2 != '\0') {
            return 0;
          }
          cVar2 = param_1[0xd];
          *(undefined2 *)(param_1 + 0xb1) = uVar1;
          param_1[0xb0] = *param_1;
          param_1[0xaf] = 0x43;
        }
        else {
          cVar2 = FUN_01020088();
          if (cVar2 != '\0') {
            return 0;
          }
          cVar2 = param_1[0xd];
          param_1[0xb0] = *param_1;
          param_1[0xb1] = 0xff;
          param_1[0xb2] = 0xff;
          param_1[0xaf] = 0x43;
        }
        uVar4 = 0;
        if (cVar2 != '\0') {
          uVar4 = param_1[0x40];
        }
        param_1[0xb3] = uVar4;
        FUN_0100f788((undefined4 *)(param_1 + 0xa6),0x1011add,2);
      }
    }
    else {
      FUN_010148ec(param_1,1,uVar3,(uint)(byte)param_1[0x79]);
    }
  }
  return 0;
}


