/*
 * Function: FUN_0100c45c
 * Entry:    0100c45c
 * Prototype: byte __stdcall FUN_0100c45c(uint param_1, byte * param_2, undefined1 * param_3)
 */


byte FUN_0100c45c(uint param_1,byte *param_2,undefined1 *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  
  if (DAT_21000d18 != '\0') {
    bVar4 = *param_2;
    bVar6 = param_2[1];
    bVar5 = param_2[4];
    bVar1 = param_2[2];
    bVar2 = param_2[3];
    bVar3 = param_2[5];
    cVar7 = '\0';
    if ((uint)(DAT_21000e70 ^ bVar3) +
        (uint)(bVar2 ^ DAT_21000e6e) +
        (uint)(bVar1 ^ DAT_21000e6d) +
        (uint)(DAT_21000e6c ^ bVar6) + (uint)(bVar4 ^ DAT_21000e6b) + (DAT_21000e6a ^ param_1) +
        (uint)(bVar5 ^ DAT_21000e6f) != 0) {
      if (DAT_21000d18 == '\x01') {
        return 1;
      }
      if ((uint)(bVar3 ^ DAT_21000e77) +
          (uint)(bVar5 ^ DAT_21000e76) +
          (uint)(bVar1 ^ DAT_21000e74) +
          (uint)(bVar4 ^ DAT_21000e72) + (uint)(bVar6 ^ DAT_21000e73) + (param_1 ^ DAT_21000e71) +
          (uint)(DAT_21000e75 ^ bVar2) == 0) {
        cVar7 = '\x01';
      }
      else {
        if (DAT_21000d18 == '\x02') {
          return 1;
        }
        if ((uint)(bVar3 ^ DAT_21000e7e) +
            (uint)(bVar5 ^ DAT_21000e7d) +
            (uint)(bVar1 ^ DAT_21000e7b) +
            (uint)(bVar4 ^ DAT_21000e79) + (uint)(bVar6 ^ DAT_21000e7a) + (param_1 ^ DAT_21000e78) +
            (uint)(DAT_21000e7c ^ bVar2) == 0) {
          cVar7 = '\x02';
        }
        else {
          if (DAT_21000d18 == '\x03') {
            return 1;
          }
          if ((uint)(bVar3 ^ DAT_21000e85) +
              (uint)(bVar5 ^ DAT_21000e84) +
              (uint)(bVar1 ^ DAT_21000e82) +
              (uint)(bVar4 ^ DAT_21000e80) + (uint)(bVar6 ^ DAT_21000e81) + (param_1 ^ DAT_21000e7f)
              + (uint)(DAT_21000e83 ^ bVar2) == 0) {
            cVar7 = '\x03';
          }
          else {
            if (DAT_21000d18 == '\x04') {
              return 1;
            }
            if ((uint)(bVar3 ^ DAT_21000e8c) +
                (uint)(bVar5 ^ DAT_21000e8b) +
                (uint)(bVar1 ^ DAT_21000e89) +
                (uint)(bVar4 ^ DAT_21000e87) + (uint)(bVar6 ^ DAT_21000e88) +
                (param_1 ^ DAT_21000e86) + (uint)(DAT_21000e8a ^ bVar2) == 0) {
              cVar7 = '\x04';
            }
            else {
              if (DAT_21000d18 == '\x05') {
                return 1;
              }
              if ((uint)(bVar3 ^ DAT_21000e93) +
                  (uint)(bVar5 ^ DAT_21000e92) +
                  (uint)(bVar1 ^ DAT_21000e90) +
                  (uint)(bVar4 ^ DAT_21000e8e) + (uint)(bVar6 ^ DAT_21000e8f) +
                  (param_1 ^ DAT_21000e8d) + (uint)(DAT_21000e91 ^ bVar2) == 0) {
                cVar7 = '\x05';
              }
              else {
                if (DAT_21000d18 == '\x06') {
                  return 1;
                }
                if ((uint)(bVar3 ^ DAT_21000e9a) +
                    (uint)(bVar5 ^ DAT_21000e99) +
                    (uint)(bVar1 ^ DAT_21000e97) +
                    (uint)(bVar4 ^ DAT_21000e95) + (uint)(bVar6 ^ DAT_21000e96) +
                    (param_1 ^ DAT_21000e94) + (uint)(DAT_21000e98 ^ bVar2) == 0) {
                  cVar7 = '\x06';
                }
                else {
                  if (DAT_21000d18 == '\a') {
                    return 1;
                  }
                  if ((uint)(bVar3 ^ DAT_21000ea1) +
                      (uint)(bVar5 ^ DAT_21000ea0) +
                      (param_1 ^ DAT_21000e9b) +
                      (uint)(bVar4 ^ DAT_21000e9c) + (uint)(bVar6 ^ DAT_21000e9d) +
                      (uint)(bVar1 ^ DAT_21000e9e) + (uint)(bVar2 ^ DAT_21000e9f) != 0) {
                    return 1;
                  }
                  cVar7 = '\a';
                }
              }
            }
          }
        }
      }
    }
    if (DAT_21000d19 != 0) {
      if (DAT_21000e1a == cVar7) {
        uVar8 = 0;
      }
      else {
        if (DAT_21000d19 == 1) {
          return 1;
        }
        if (DAT_21000e1b == cVar7) {
          uVar8 = 1;
        }
        else {
          if (DAT_21000d19 == 2) {
            return 1;
          }
          if (DAT_21000e1c == cVar7) {
            uVar8 = 2;
          }
          else {
            if (DAT_21000d19 == 3) {
              return 1;
            }
            if (DAT_21000e1d == cVar7) {
              uVar8 = 3;
            }
            else {
              if (DAT_21000d19 == 4) {
                return 1;
              }
              if (DAT_21000e1e == cVar7) {
                uVar8 = 4;
              }
              else {
                if (DAT_21000d19 == 5) {
                  return 1;
                }
                if (DAT_21000e1f == cVar7) {
                  uVar8 = 5;
                }
                else {
                  if (DAT_21000d19 == 6) {
                    return 1;
                  }
                  if (DAT_21000e20 == cVar7) {
                    uVar8 = 6;
                  }
                  else {
                    if (DAT_21000d19 == 7) {
                      return 1;
                    }
                    if (DAT_21000e21 != cVar7) {
                      return 1;
                    }
                    uVar8 = 7;
                  }
                }
              }
            }
          }
        }
      }
      if ((param_3 == (undefined1 *)0x0) || (*param_3 = (char)uVar8, uVar8 < DAT_21000d19)) {
        bVar6 = (&DAT_21000e62)[uVar8];
        if ((&DAT_21000e52)[uVar8] == '\x01') {
          bVar6 = bVar6 | 1;
        }
        return bVar6;
      }
    }
  }
  return 1;
}


