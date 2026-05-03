/*
 * Function: FUN_01016ec0
 * Entry:    01016ec0
 * Prototype: undefined __stdcall FUN_01016ec0(int param_1, byte * param_2)
 */


void FUN_01016ec0(int param_1,byte *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 auStack_18 [2];
  
  puVar2 = auStack_18;
  DAT_21000f99 = 0;
  DAT_21000f9a = *DAT_21000fe0;
  uVar1 = FUN_0100ddd0(*(uint *)(DAT_21000fe0 + 10));
  DAT_21000fb0 = (undefined2)uVar1;
  DAT_21000fb2 = DAT_21000fe0[0xe];
  DAT_21000fb4 = DAT_21000fe0[0xf];
  DAT_21000fb6 = 0xff00;
  DAT_21000fb8 = 0xffff;
  if (param_1 == 0) {
    FUN_0100e818((int)DAT_21001050,auStack_18);
    uVar1 = ((uint)*DAT_21001050 << 0x19) >> 0x1f;
  }
  else {
    puVar2 = (undefined4 *)FUN_0100ea94((int)param_2,1);
    uVar1 = (uint)(*param_2 >> 7);
  }
  if (((DAT_2100100d == '\0') || (uVar1 == 0)) || ((*(byte *)((int)puVar2 + 5) & 0xc0) != 0x40)) {
    DAT_21000fa4 = 0;
    DAT_21000fa8 = 0;
  }
  else {
    DAT_21000fa4 = *puVar2;
    DAT_21000fa8 = *(undefined2 *)(puVar2 + 1);
  }
  if (DAT_21001009 == 0xff) {
    DAT_21000f9d = DAT_21001020;
    DAT_21000faa = 0;
    DAT_21000f9e = DAT_21001019;
    DAT_21000fae = 0;
    DAT_21000fa2 = DAT_2100101d;
  }
  else {
    iVar3 = FUN_0100d298((uint)DAT_21001009,&DAT_21000f9d,&DAT_21000f9e);
    if (iVar3 == 0) {
      FUN_01009500(0x32,&DAT_00001596,extraout_r2,extraout_r3);
                    /* WARNING (jumptable): Read-only address (ram,0x00000017) is written */
                    /* WARNING: Read-only address (ram,0x00000017) is written */
      uRam00000017 = 0;
      iVar3 = FUN_0100df60();
      DAT_2100001c = (undefined1)iVar3;
      FUN_01019ee0();
                    /* WARNING: Could not recover jumptable at 0x01017010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)0x1016fdf)(1);
      return;
    }
    DAT_21000f9d = DAT_21000f9d | 2;
    if (param_1 == 0) {
      puVar2 = &DAT_21001019;
    }
    else {
      puVar2 = (undefined4 *)FUN_0100ea94((int)param_2,0);
    }
    DAT_21000faa = *puVar2;
    DAT_21000fae = *(undefined2 *)(puVar2 + 1);
  }
  FUN_0100ddc8((int)DAT_21000fe0,(int)DAT_21000fe9);
  FUN_0100f788((undefined4 *)&DAT_21000f90,0x10175c9,2);
  DAT_21000fc3 = *DAT_21000fe0;
  DAT_21000fc5 = *(undefined1 *)((int)DAT_21000fe0 + 0xcd);
  FUN_0100f7c8((undefined4 *)&DAT_21000fba,0x1016a71,2);
  return;
}


