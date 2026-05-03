/*
 * Function: FUN_010095dc
 * Entry:    010095dc
 * Prototype: undefined4 __stdcall FUN_010095dc(int param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_010095dc(int param_1)

{
  bool bVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_1 == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    cVar2 = FUN_01025f5c();
    if ((cVar2 == '\0') || (uVar3 = FUN_01024ecc(), 500 < uVar3)) {
      uVar4 = 0xffffffff;
    }
    else {
      DAT_21000a58 = param_1;
      FUN_01009bac(0x100957d);
      DAT_21000a5c = 0;
      DAT_21000a5d = 0;
      DAT_21000a4f = 0;
      DAT_21000a50 = 0;
      DAT_21000a54 = 0;
      DAT_21000a4e = 0;
      FUN_01026284((undefined4 *)&DAT_21000a30,0,0x1e);
      DAT_21000a35._0_1_ = 0x1b;
      _DAT_21000a30 = 0x101;
      DAT_21000a35._1_2_ = 0x31b;
      DAT_21000a32 = 1;
      ram0x21000a38 = 0x302;
      DAT_21000a44 = 1;
      DAT_21000a3a = 0x1f;
      _DAT_21000a3c = 0x208;
      DAT_21000a40 = 0x4901;
      iVar5 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        iVar5 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      FUN_0100af90();
      if (iVar5 == 0) {
        enableIRQinterrupts();
        uVar4 = 0;
      }
      else {
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}


