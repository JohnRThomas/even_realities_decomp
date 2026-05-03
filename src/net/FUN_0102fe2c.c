/*
 * Function: FUN_0102fe2c
 * Entry:    0102fe2c
 * Prototype: uint __stdcall FUN_0102fe2c(uint * param_1, int param_2, uint param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0102fe2c(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte local_50 [4];
  char *local_4c;
  uint uStack_48;
  int local_3c;
  uint local_38 [2];
  byte local_30;
  uint local_2c;
  
  uVar4 = 0;
  local_3c = param_2;
  while( true ) {
    if (local_3c <= (int)uVar4) {
      return param_3;
    }
    uVar3 = param_1[1];
    if (uVar3 != 0) break;
LAB_0102fefa:
    uVar4 = uVar4 + 1;
    param_1 = param_1 + 3;
  }
  if (((uVar3 < 0x20) || ((uVar3 & 0x1f) != 0)) || (uVar5 = *param_1, (uVar5 & 0x1f) != 0)) {
    local_4c = "Partition %u: sanity check failed.";
    uStack_48 = uVar4;
    goto LAB_0102fe9a;
  }
  uVar1 = FUN_0103ab9c(uVar5);
  uVar3 = FUN_0103ab9c(uVar3 + uVar5 + -1);
  if (uVar1 == uVar3) {
    if ((uVar1 != 0xffffffea) && ((int)uVar1 < (int)param_3)) {
      uVar5 = _DAT_e000eda0 | 0x1f;
      uVar3 = *param_1;
      uVar6 = (param_1[1] + uVar3) - 1;
      _DAT_e000ed98 = uVar1;
      if ((_DAT_e000ed9c & 0xffffffe0) == uVar3) {
        if (uVar5 == uVar6) {
          FUN_0103abae(uVar1 & 0xff,param_1);
          goto LAB_0102fefa;
        }
        _DAT_e000ed9c = _DAT_e000ed9c & 0x1f | param_1[1] + uVar3 & 0xffffffe0;
LAB_0102ff1c:
        iVar2 = FUN_0103abae(param_3 & 0xff,param_1);
LAB_0102ff20:
        if (iVar2 == -0x16) {
          return 0xffffffea;
        }
      }
      else {
        uVar3 = uVar3 - 1 & 0xffffffe0;
        if (uVar5 == uVar6) {
          _DAT_e000eda0 = _DAT_e000eda0 & 0x1f | uVar3;
          goto LAB_0102ff1c;
        }
        _DAT_e000eda0 = uVar3 | _DAT_e000eda0 & 0x1f;
        iVar2 = FUN_0103abae(param_3 & 0xff,param_1);
        if (iVar2 == -0x16) {
          return 0xffffffea;
        }
        local_30 = (byte)_DAT_e000ed9c & 0x1f | (byte)((_DAT_e000eda0 >> 1 & 7) << 5);
        local_38[0] = *param_1 + param_1[1];
        uVar3 = iVar2 + 1U & 0xff;
        local_2c = ((local_38[0] & 0xffffffe0) + (uVar5 - 1)) - uVar6 & 0xffffffe0;
        if (7 < uVar3) {
          _DAT_e000ed98 = uVar1;
          iVar2 = FUN_0102fdfc(uVar3);
          goto LAB_0102ff20;
        }
        _DAT_e000ed98 = uVar1;
        iVar2 = FUN_0102fdc8(uVar3,local_38);
      }
      param_3 = iVar2 + 1;
      goto LAB_0102fefa;
    }
  }
  else {
    uVar1 = 0xffffffea;
  }
  local_4c = "Invalid underlying region index %u";
  uStack_48 = uVar1;
LAB_0102fe9a:
  local_50[0] = 3;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  FUN_0102ea44(0x103c064,0x1840,local_50,(undefined1 *)0x0);
  return 0xffffffea;
}


