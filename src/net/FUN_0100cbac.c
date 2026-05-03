/*
 * Function: FUN_0100cbac
 * Entry:    0100cbac
 * Prototype: undefined1 __stdcall FUN_0100cbac(uint param_1, byte * param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0100cbac(uint param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  char cVar9;
  
  cVar9 = *_FUN_0100ced4;
  if (cVar9 == '\0') {
    return 0;
  }
  bVar6 = *param_2;
  bVar1 = param_2[1];
  bVar7 = param_2[4];
  bVar2 = param_2[2];
  bVar3 = param_2[3];
  bVar4 = param_2[5];
  if ((uint)(byte)(_FUN_0100ced4[0x158] ^ bVar4) +
      (uint)(byte)(bVar3 ^ _FUN_0100ced4[0x156]) +
      (uint)(byte)(bVar2 ^ _FUN_0100ced4[0x155]) +
      (uint)(byte)(_FUN_0100ced4[0x154] ^ bVar1) + (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x153]) +
      ((byte)_FUN_0100ced4[0x152] ^ param_1) + (uint)(byte)(bVar7 ^ _FUN_0100ced4[0x157]) == 0) {
    cVar9 = '\0';
  }
  else {
    if (cVar9 == '\x01') {
      return 0;
    }
    if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x15f]) +
        (uint)(byte)(bVar7 ^ _FUN_0100ced4[0x15e]) +
        (uint)(byte)(bVar2 ^ _FUN_0100ced4[0x15c]) +
        (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x15a]) + (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x15b]) +
        (param_1 ^ (byte)_FUN_0100ced4[0x159]) + (uint)(byte)(_FUN_0100ced4[0x15d] ^ bVar3) == 0) {
      cVar9 = '\x01';
    }
    else {
      if (cVar9 == '\x02') {
        return 0;
      }
      if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x166]) +
          (uint)(byte)(bVar7 ^ _FUN_0100ced4[0x165]) +
          (uint)(byte)(bVar2 ^ _FUN_0100ced4[0x163]) +
          (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x161]) + (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x162]) +
          (param_1 ^ (byte)_FUN_0100ced4[0x160]) + (uint)(byte)(_FUN_0100ced4[0x164] ^ bVar3) == 0)
      {
        cVar9 = '\x02';
      }
      else {
        if (cVar9 == '\x03') {
          return 0;
        }
        if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x16d]) +
            (uint)(byte)(bVar7 ^ _FUN_0100ced4[0x16c]) +
            (uint)(byte)(bVar2 ^ _FUN_0100ced4[0x16a]) +
            (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x168]) + (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x169])
            + (param_1 ^ (byte)_FUN_0100ced4[0x167]) + (uint)(byte)(_FUN_0100ced4[0x16b] ^ bVar3) ==
            0) {
          cVar9 = '\x03';
        }
        else {
          if (cVar9 == '\x04') {
            return 0;
          }
          if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x174]) +
              (uint)(byte)(bVar7 ^ _FUN_0100ced4[0x173]) +
              (uint)(byte)(bVar2 ^ _FUN_0100ced4[0x171]) +
              (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x16f]) +
              (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x170]) + (param_1 ^ (byte)_FUN_0100ced4[0x16e]) +
              (uint)(byte)(_FUN_0100ced4[0x172] ^ bVar3) == 0) {
            cVar9 = '\x04';
          }
          else {
            if (cVar9 == '\x05') {
              return 0;
            }
            if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x17b]) +
                (uint)(byte)(bVar7 ^ _FUN_0100ced4[0x17a]) +
                (uint)(byte)(bVar2 ^ _FUN_0100ced4[0x178]) +
                (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x176]) +
                (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x177]) + (param_1 ^ (byte)_FUN_0100ced4[0x175])
                + (uint)(byte)(_FUN_0100ced4[0x179] ^ bVar3) == 0) {
              cVar9 = '\x05';
            }
            else {
              if (cVar9 == '\x06') {
                return 0;
              }
              if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x182]) +
                  (uint)(byte)(bVar7 ^ _FUN_0100ced4[0x181]) +
                  (uint)(byte)(bVar2 ^ _FUN_0100ced4[0x17f]) +
                  (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x17d]) +
                  (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x17e]) +
                  (param_1 ^ (byte)_FUN_0100ced4[0x17c]) +
                  (uint)(byte)(_FUN_0100ced4[0x180] ^ bVar3) == 0) {
                cVar9 = '\x06';
              }
              else {
                if (cVar9 == '\a') {
                  return 0;
                }
                if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x189]) +
                    (uint)(byte)(bVar7 ^ _FUN_0100ced4[0x188]) +
                    (param_1 ^ (byte)_FUN_0100ced4[0x183]) +
                    (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x184]) +
                    (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x185]) +
                    (uint)(byte)(bVar2 ^ _FUN_0100ced4[0x186]) +
                    (uint)(byte)(bVar3 ^ _FUN_0100ced4[0x187]) != 0) {
                  return 0;
                }
                cVar9 = '\a';
              }
            }
          }
        }
      }
    }
  }
  cVar5 = _FUN_0100ced4[1];
  if (cVar5 == '\0') {
    return 0;
  }
  if (_FUN_0100ced4[0x102] == cVar9) {
    uVar8 = 0;
  }
  else {
    if (cVar5 == '\x01') {
      return 0;
    }
    if (_FUN_0100ced4[0x103] == cVar9) {
      uVar8 = 1;
    }
    else {
      if (cVar5 == '\x02') {
        return 0;
      }
      if (_FUN_0100ced4[0x104] == cVar9) {
        uVar8 = 2;
      }
      else {
        if (cVar5 == '\x03') {
          return 0;
        }
        if (_FUN_0100ced4[0x105] == cVar9) {
          uVar8 = 3;
        }
        else {
          if (cVar5 == '\x04') {
            return 0;
          }
          if (_FUN_0100ced4[0x106] == cVar9) {
            uVar8 = 4;
          }
          else {
            if (cVar5 == '\x05') {
              return 0;
            }
            if (_FUN_0100ced4[0x107] == cVar9) {
              uVar8 = 5;
            }
            else {
              if (cVar5 == '\x06') {
                return 0;
              }
              if (_FUN_0100ced4[0x108] == cVar9) {
                uVar8 = 6;
              }
              else {
                if (cVar5 == '\a') {
                  return 0;
                }
                if (_FUN_0100ced4[0x109] != cVar9) {
                  return 0;
                }
                uVar8 = 7;
              }
            }
          }
        }
      }
    }
  }
  FUN_0100c22c(uVar8);
  return 1;
}


