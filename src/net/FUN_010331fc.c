/*
 * Function: FUN_010331fc
 * Entry:    010331fc
 * Prototype: undefined4 __stdcall FUN_010331fc(byte param_1, byte param_2)
 */


undefined4 FUN_010331fc(byte param_1,byte param_2)

{
  uint uVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  
  if (DAT_21004a94 == '\x01') {
    if (0xfb < DAT_2100625e) {
      return 0;
    }
    pbVar2 = (byte *)(&DAT_21004a34)[DAT_21004a54];
    bVar3 = DAT_2100625e;
  }
  else {
    pbVar2 = (byte *)(&DAT_21004a34)[DAT_21004a54];
    bVar3 = DAT_21004aa5;
    if (DAT_21004a95 == '\0') {
      *pbVar2 = 0;
      goto LAB_01033232;
    }
  }
  *pbVar2 = bVar3;
LAB_01033232:
  pbVar2 = (byte *)(&DAT_21004a34)[DAT_21004a54];
  uVar4 = DAT_21004a54 + 1;
  FUN_0103bdd4((int)(pbVar2 + 5),&DAT_21006260,(uint)*pbVar2);
  pbVar2[1] = param_1;
  uVar1 = Peripherals::RADIO_NS.RSSISAMPLE;
  pbVar2[4] = param_2;
  pbVar2[2] = (byte)uVar1 & 0x7f;
  if (7 < uVar4) {
    uVar4 = 0;
  }
  pbVar2[3] = ~DAT_2100625f & 1;
  DAT_21004a5c = DAT_21004a5c + 1;
  DAT_21004a54 = uVar4;
  return 1;
}


