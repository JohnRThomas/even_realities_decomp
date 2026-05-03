/*
 * Function: FUN_0100c7b8
 * Entry:    0100c7b8
 * Prototype: undefined4 __stdcall FUN_0100c7b8(uint param_1, byte * param_2, uint * param_3, uint * param_4)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0100c7b8(uint param_1,byte *param_2,uint *param_3,uint *param_4)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  bool bVar8;
  byte *pbVar9;
  char cVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  byte bVar14;
  uint uVar15;
  undefined4 uVar16;
  undefined8 uVar17;
  
  bVar14 = DAT_21000d18;
  uVar15 = (uint)DAT_21000d18;
  if (uVar15 == 0) {
    if (7 < DAT_21000d19) {
      return 7;
    }
    DAT_21000d18 = 1;
    iVar13 = 0x153;
    iVar11 = 0;
LAB_0100cb00:
    *(undefined4 *)(&DAT_21000d18 + iVar13) = *(undefined4 *)param_2;
    *(undefined2 *)(iVar13 + 0x21000d1c) = *(undefined2 *)(param_2 + 4);
    uVar12 = (uint)DAT_21000d19;
    (&DAT_21000e6a)[iVar11 - uVar15] = (char)param_1;
  }
  else {
    bVar4 = *param_2;
    bVar5 = param_2[1];
    bVar6 = param_2[2];
    bVar1 = param_2[3];
    bVar2 = param_2[4];
    bVar7 = param_2[5];
    if ((uint)(bVar7 ^ DAT_21000e70) +
        (uint)(bVar2 ^ DAT_21000e6f) +
        (uint)(bVar6 ^ DAT_21000e6d) +
        (uint)(bVar4 ^ DAT_21000e6b) + (param_1 ^ DAT_21000e6a) + (uint)(bVar5 ^ DAT_21000e6c) +
        (uint)(bVar1 ^ DAT_21000e6e) == 0) {
      bVar14 = 0;
    }
    else {
      if (uVar15 == 1) {
LAB_0100cae8:
        if (7 < DAT_21000d19) {
          return 7;
        }
        uVar12 = uVar15 + 1;
        DAT_21000d18 = (byte)uVar12;
        if (7 < uVar15) {
LAB_0100cba2:
          uVar17 = FUN_01009500(0x28,0x43,(uint)bVar1,uVar12);
          pbVar9 = (byte *)((ulonglong)uVar17 >> 0x20);
          uVar15 = (uint)uVar17;
          cVar10 = *_FUN_0100ced4;
          if (cVar10 == '\0') {
            return 0;
          }
          bVar5 = *pbVar9;
          bVar14 = pbVar9[1];
          bVar6 = pbVar9[4];
          bVar1 = pbVar9[2];
          bVar2 = pbVar9[3];
          bVar4 = pbVar9[5];
          if ((uint)(byte)(_FUN_0100ced4[0x158] ^ bVar4) +
              (uint)(byte)(bVar2 ^ _FUN_0100ced4[0x156]) +
              (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x155]) +
              (uint)(byte)(_FUN_0100ced4[0x154] ^ bVar14) +
              (uint)(byte)(bVar5 ^ _FUN_0100ced4[0x153]) + ((byte)_FUN_0100ced4[0x152] ^ uVar15) +
              (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x157]) == 0) {
            cVar10 = '\0';
          }
          else {
            if (cVar10 == '\x01') {
              return 0;
            }
            if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x15f]) +
                (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x15e]) +
                (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x15c]) +
                (uint)(byte)(bVar5 ^ _FUN_0100ced4[0x15a]) +
                (uint)(byte)(bVar14 ^ _FUN_0100ced4[0x15b]) + (uVar15 ^ (byte)_FUN_0100ced4[0x159])
                + (uint)(byte)(_FUN_0100ced4[0x15d] ^ bVar2) == 0) {
              cVar10 = '\x01';
            }
            else {
              if (cVar10 == '\x02') {
                return 0;
              }
              if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x166]) +
                  (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x165]) +
                  (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x163]) +
                  (uint)(byte)(bVar5 ^ _FUN_0100ced4[0x161]) +
                  (uint)(byte)(bVar14 ^ _FUN_0100ced4[0x162]) +
                  (uVar15 ^ (byte)_FUN_0100ced4[0x160]) + (uint)(byte)(_FUN_0100ced4[0x164] ^ bVar2)
                  == 0) {
                cVar10 = '\x02';
              }
              else {
                if (cVar10 == '\x03') {
                  return 0;
                }
                if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x16d]) +
                    (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x16c]) +
                    (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x16a]) +
                    (uint)(byte)(bVar5 ^ _FUN_0100ced4[0x168]) +
                    (uint)(byte)(bVar14 ^ _FUN_0100ced4[0x169]) +
                    (uVar15 ^ (byte)_FUN_0100ced4[0x167]) +
                    (uint)(byte)(_FUN_0100ced4[0x16b] ^ bVar2) == 0) {
                  cVar10 = '\x03';
                }
                else {
                  if (cVar10 == '\x04') {
                    return 0;
                  }
                  if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x174]) +
                      (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x173]) +
                      (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x171]) +
                      (uint)(byte)(bVar5 ^ _FUN_0100ced4[0x16f]) +
                      (uint)(byte)(bVar14 ^ _FUN_0100ced4[0x170]) +
                      (uVar15 ^ (byte)_FUN_0100ced4[0x16e]) +
                      (uint)(byte)(_FUN_0100ced4[0x172] ^ bVar2) == 0) {
                    cVar10 = '\x04';
                  }
                  else {
                    if (cVar10 == '\x05') {
                      return 0;
                    }
                    if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x17b]) +
                        (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x17a]) +
                        (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x178]) +
                        (uint)(byte)(bVar5 ^ _FUN_0100ced4[0x176]) +
                        (uint)(byte)(bVar14 ^ _FUN_0100ced4[0x177]) +
                        (uVar15 ^ (byte)_FUN_0100ced4[0x175]) +
                        (uint)(byte)(_FUN_0100ced4[0x179] ^ bVar2) == 0) {
                      cVar10 = '\x05';
                    }
                    else {
                      if (cVar10 == '\x06') {
                        return 0;
                      }
                      if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x182]) +
                          (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x181]) +
                          (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x17f]) +
                          (uint)(byte)(bVar5 ^ _FUN_0100ced4[0x17d]) +
                          (uint)(byte)(bVar14 ^ _FUN_0100ced4[0x17e]) +
                          (uVar15 ^ (byte)_FUN_0100ced4[0x17c]) +
                          (uint)(byte)(_FUN_0100ced4[0x180] ^ bVar2) == 0) {
                        cVar10 = '\x06';
                      }
                      else {
                        if (cVar10 == '\a') {
                          return 0;
                        }
                        if ((uint)(byte)(bVar4 ^ _FUN_0100ced4[0x189]) +
                            (uint)(byte)(bVar6 ^ _FUN_0100ced4[0x188]) +
                            (uVar15 ^ (byte)_FUN_0100ced4[0x183]) +
                            (uint)(byte)(bVar5 ^ _FUN_0100ced4[0x184]) +
                            (uint)(byte)(bVar14 ^ _FUN_0100ced4[0x185]) +
                            (uint)(byte)(bVar1 ^ _FUN_0100ced4[0x186]) +
                            (uint)(byte)(bVar2 ^ _FUN_0100ced4[0x187]) != 0) {
                          return 0;
                        }
                        cVar10 = '\a';
                      }
                    }
                  }
                }
              }
            }
          }
          cVar3 = _FUN_0100ced4[1];
          if (cVar3 == '\0') {
            return 0;
          }
          if (_FUN_0100ced4[0x102] == cVar10) {
            uVar15 = 0;
          }
          else {
            if (cVar3 == '\x01') {
              return 0;
            }
            if (_FUN_0100ced4[0x103] == cVar10) {
              uVar15 = 1;
            }
            else {
              if (cVar3 == '\x02') {
                return 0;
              }
              if (_FUN_0100ced4[0x104] == cVar10) {
                uVar15 = 2;
              }
              else {
                if (cVar3 == '\x03') {
                  return 0;
                }
                if (_FUN_0100ced4[0x105] == cVar10) {
                  uVar15 = 3;
                }
                else {
                  if (cVar3 == '\x04') {
                    return 0;
                  }
                  if (_FUN_0100ced4[0x106] == cVar10) {
                    uVar15 = 4;
                  }
                  else {
                    if (cVar3 == '\x05') {
                      return 0;
                    }
                    if (_FUN_0100ced4[0x107] == cVar10) {
                      uVar15 = 5;
                    }
                    else {
                      if (cVar3 == '\x06') {
                        return 0;
                      }
                      if (_FUN_0100ced4[0x108] == cVar10) {
                        uVar15 = 6;
                      }
                      else {
                        if (cVar3 == '\a') {
                          return 0;
                        }
                        if (_FUN_0100ced4[0x109] != cVar10) {
                          return 0;
                        }
                        uVar15 = 7;
                      }
                    }
                  }
                }
              }
            }
          }
          FUN_0100c22c(uVar15);
          return 1;
        }
LAB_0100caf6:
        iVar11 = uVar15 << 3;
        iVar13 = uVar15 * 7 + 0x153;
        goto LAB_0100cb00;
      }
      if ((uint)(bVar7 ^ DAT_21000e77) +
          (uint)(bVar4 ^ DAT_21000e72) + (uint)(bVar5 ^ DAT_21000e73) + (param_1 ^ DAT_21000e71) +
          (uint)(bVar6 ^ DAT_21000e74) + (uint)(bVar1 ^ DAT_21000e75) + (uint)(bVar2 ^ DAT_21000e76)
          == 0) {
        bVar14 = 1;
      }
      else {
        if (uVar15 == 2) goto LAB_0100cae8;
        if ((uint)(bVar7 ^ DAT_21000e7e) +
            (uint)(bVar5 ^ DAT_21000e7a) + (uint)(bVar4 ^ DAT_21000e79) + (param_1 ^ DAT_21000e78) +
            (uint)(bVar6 ^ DAT_21000e7b) + (uint)(bVar1 ^ DAT_21000e7c) +
            (uint)(bVar2 ^ DAT_21000e7d) == 0) {
          bVar14 = 2;
          goto LAB_0100ca76;
        }
        if (uVar15 == 3) goto LAB_0100cae8;
        if ((uint)(bVar7 ^ DAT_21000e85) +
            (uint)(bVar5 ^ DAT_21000e81) + (uint)(bVar4 ^ DAT_21000e80) + (param_1 ^ DAT_21000e7f) +
            (uint)(bVar6 ^ DAT_21000e82) + (uint)(bVar1 ^ DAT_21000e83) +
            (uint)(bVar2 ^ DAT_21000e84) == 0) {
          bVar14 = 3;
          goto LAB_0100ca76;
        }
        if (uVar15 == 4) goto LAB_0100cae8;
        if ((uint)(bVar7 ^ DAT_21000e8c) +
            (uint)(bVar5 ^ DAT_21000e88) + (uint)(bVar4 ^ DAT_21000e87) + (param_1 ^ DAT_21000e86) +
            (uint)(bVar6 ^ DAT_21000e89) + (uint)(bVar1 ^ DAT_21000e8a) +
            (uint)(bVar2 ^ DAT_21000e8b) == 0) {
          bVar14 = 4;
          goto LAB_0100ca76;
        }
        if (uVar15 == 5) goto LAB_0100cae8;
        if ((uint)(bVar7 ^ DAT_21000e93) +
            (uint)(bVar5 ^ DAT_21000e8f) + (uint)(bVar4 ^ DAT_21000e8e) + (param_1 ^ DAT_21000e8d) +
            (uint)(bVar6 ^ DAT_21000e90) + (uint)(bVar1 ^ DAT_21000e91) +
            (uint)(bVar2 ^ DAT_21000e92) == 0) {
          bVar14 = 5;
          goto LAB_0100ca76;
        }
        if (uVar15 == 6) goto LAB_0100cae8;
        if ((uint)(bVar7 ^ DAT_21000e9a) +
            (uint)(bVar5 ^ DAT_21000e96) + (uint)(bVar4 ^ DAT_21000e95) + (param_1 ^ DAT_21000e94) +
            (uint)(bVar6 ^ DAT_21000e97) + (uint)(bVar1 ^ DAT_21000e98) +
            (uint)(bVar2 ^ DAT_21000e99) == 0) {
          bVar14 = 6;
        }
        else {
          if (uVar15 == 7) {
            if (7 < DAT_21000d19) {
              return 7;
            }
            DAT_21000d18 = 8;
            goto LAB_0100caf6;
          }
          if ((uint)(bVar7 ^ DAT_21000ea1) +
              (uint)(bVar2 ^ DAT_21000ea0) +
              (uint)(bVar1 ^ DAT_21000e9f) +
              (uint)(bVar4 ^ DAT_21000e9c) + (uint)(bVar5 ^ DAT_21000e9d) + (param_1 ^ DAT_21000e9b)
              + (uint)(bVar6 ^ DAT_21000e9e) != 0) {
            uVar12 = (uint)DAT_21000d19;
            if (7 < uVar12) {
              return 7;
            }
            DAT_21000d18 = DAT_21000d18 + 1;
            bVar1 = DAT_21000ea1;
            goto LAB_0100cba2;
          }
          bVar14 = 7;
        }
      }
    }
LAB_0100ca76:
    uVar12 = (uint)DAT_21000d19;
    if (uVar12 != 0) {
      if (DAT_21000e1a == bVar14) {
        return 0x12;
      }
      if (uVar12 != 1) {
        if (DAT_21000e1b == bVar14) {
          return 0x12;
        }
        if (uVar12 != 2) {
          if (DAT_21000e1c == bVar14) {
            return 0x12;
          }
          if (uVar12 != 3) {
            if (DAT_21000e1d == bVar14) {
              return 0x12;
            }
            if (uVar12 != 4) {
              if (DAT_21000e1e == bVar14) {
                return 0x12;
              }
              if (uVar12 != 5) {
                if (DAT_21000e1f == bVar14) {
                  return 0x12;
                }
                if (uVar12 != 6) {
                  if (DAT_21000e20 == bVar14) {
                    return 0x12;
                  }
                  if (uVar12 != 7) {
                    if (DAT_21000e21 == bVar14) {
                      uVar16 = 0x12;
                    }
                    else {
                      uVar16 = 7;
                    }
                    return uVar16;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  DAT_21000d19 = (char)uVar12 + '\x01';
  FUN_0100dba0((int)(&DAT_21000d1a + uVar12 * 0x10),(int)param_3,0x10);
  FUN_0100dba0((int)(&DAT_21000d9a + uVar12 * 0x10),(int)param_4,0x10);
  bVar8 = FUN_0100dac8(param_4,0x10);
  (&DAT_21000e5a)[uVar12] = bVar8;
  bVar8 = FUN_0100dac8(param_3,0x10);
  (&DAT_21000e1a)[uVar12] = bVar14;
  (&DAT_21000e62)[uVar12] = bVar8;
  (&DAT_21000e52)[uVar12] = 0;
  return 0;
}


