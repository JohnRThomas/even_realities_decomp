/*
 * Function: FUN_01011f54
 * Entry:    01011f54
 * Prototype: undefined4 __stdcall FUN_01011f54(undefined1 * param_1)
 */


undefined4 FUN_01011f54(undefined1 *param_1)

{
  undefined2 uVar1;
  byte bVar2;
  code *pcVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined2 *puVar6;
  int iVar7;
  byte local_19;
  
  local_19 = 0xff;
  uVar5 = FUN_01011d40((uint)param_1,5,(char *)&local_19);
  if (uVar5 != 0) {
    FUN_01011734((int)param_1,*(int *)(param_1 + 0x1c),(ushort)(byte)param_1[5]);
    param_1[0x85] = 0;
    uVar1 = **(undefined2 **)(param_1 + 0x1c);
    param_1[0xa3] = 0xff;
    *(undefined2 *)(param_1 + 0x86) = uVar1;
    *(undefined2 *)(param_1 + 0xa4) = 0xffff;
    FUN_01011988((uint)param_1,(int)*(undefined2 **)(param_1 + 0x1c),(uint)local_19);
    pcVar3 = DAT_21000074;
    puVar6 = *(undefined2 **)(param_1 + 0x1c);
    *(undefined2 *)(param_1 + 0xbd) = *puVar6;
    param_1[0xbf] = *(undefined1 *)((int)puVar6 + 0xcd);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(puVar6,param_1,1);
      puVar6 = *(undefined2 **)(param_1 + 0x1c);
    }
    pbVar4 = DAT_21000f20;
    *(undefined4 *)((int)puVar6 + 3) = *(undefined4 *)(DAT_21000f20 + 3);
    *(undefined2 *)((int)puVar6 + 7) = *(undefined2 *)(pbVar4 + 7);
    iVar7 = *(int *)(param_1 + 0x1c);
    bVar2 = (byte)(((uint)*pbVar4 << 0x19) >> 0x1f);
    *(byte *)(iVar7 + 2) = bVar2;
    pbVar4[0] = 0;
    pbVar4[1] = 0;
    FUN_0100e7bc(pbVar4,8);
    FUN_0100eb6c((int)DAT_21000f20,'\0');
    FUN_0100eb7c((int)DAT_21000f20,3,0);
    FUN_0100e964((int)DAT_21000f20,(int)(param_1 + 0x61),0,6);
    FUN_0100e838(DAT_21000f20,param_1[0x60]);
    FUN_0100e854(DAT_21000f20,bVar2);
    FUN_0100e964((int)DAT_21000f20,iVar7 + 3,1,6);
    FUN_01020afc(0xff,(uint)(byte)param_1[5],extraout_r2_00);
    FUN_01020f64((uint)DAT_21000f20);
    DAT_21000f24 = 9;
    return 1;
  }
  FUN_01011e64(param_1,extraout_r1,extraout_r2,extraout_r3);
  return 1;
}


