/*
 * Function: FUN_0100cf44
 * Entry:    0100cf44
 * Prototype: undefined4 __stdcall FUN_0100cf44(uint param_1, byte * param_2)
 */


undefined4 FUN_0100cf44(uint param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  undefined4 uVar8;
  
  if (DAT_21000d18 != '\0') {
    bVar5 = *param_2;
    bVar1 = param_2[1];
    bVar2 = param_2[2];
    bVar6 = param_2[4];
    bVar3 = param_2[3];
    bVar4 = param_2[5];
    if ((uint)(DAT_21000e70 ^ bVar4) +
        (uint)(bVar6 ^ DAT_21000e6f) +
        (uint)(bVar3 ^ DAT_21000e6e) +
        (uint)(DAT_21000e6c ^ bVar1) + (uint)(bVar5 ^ DAT_21000e6b) + (DAT_21000e6a ^ param_1) +
        (uint)(bVar2 ^ DAT_21000e6d) == 0) {
      cVar7 = '\0';
    }
    else {
      if (DAT_21000d18 == '\x01') {
        return 8;
      }
      if ((uint)(bVar4 ^ DAT_21000e77) +
          (uint)(bVar6 ^ DAT_21000e76) +
          (uint)(bVar2 ^ DAT_21000e74) +
          (uint)(DAT_21000e73 ^ bVar1) + (uint)(bVar5 ^ DAT_21000e72) + (param_1 ^ DAT_21000e71) +
          (uint)(DAT_21000e75 ^ bVar3) == 0) {
        cVar7 = '\x01';
      }
      else {
        if (DAT_21000d18 == '\x02') {
          return 8;
        }
        if ((uint)(bVar4 ^ DAT_21000e7e) +
            (uint)(bVar6 ^ DAT_21000e7d) +
            (uint)(bVar2 ^ DAT_21000e7b) +
            (uint)(bVar5 ^ DAT_21000e79) + (uint)(bVar1 ^ DAT_21000e7a) + (param_1 ^ DAT_21000e78) +
            (uint)(DAT_21000e7c ^ bVar3) == 0) {
          cVar7 = '\x02';
        }
        else {
          if (DAT_21000d18 == '\x03') {
            return 8;
          }
          if ((uint)(bVar4 ^ DAT_21000e85) +
              (uint)(bVar6 ^ DAT_21000e84) +
              (uint)(bVar2 ^ DAT_21000e82) +
              (uint)(bVar5 ^ DAT_21000e80) + (uint)(bVar1 ^ DAT_21000e81) + (param_1 ^ DAT_21000e7f)
              + (uint)(DAT_21000e83 ^ bVar3) == 0) {
            cVar7 = '\x03';
          }
          else {
            if (DAT_21000d18 == '\x04') {
              return 8;
            }
            if ((uint)(bVar4 ^ DAT_21000e8c) +
                (uint)(bVar6 ^ DAT_21000e8b) +
                (uint)(bVar2 ^ DAT_21000e89) +
                (uint)(bVar5 ^ DAT_21000e87) + (uint)(bVar1 ^ DAT_21000e88) +
                (param_1 ^ DAT_21000e86) + (uint)(DAT_21000e8a ^ bVar3) == 0) {
              cVar7 = '\x04';
            }
            else {
              if (DAT_21000d18 == '\x05') {
                return 8;
              }
              if ((uint)(bVar4 ^ DAT_21000e93) +
                  (uint)(bVar6 ^ DAT_21000e92) +
                  (uint)(bVar2 ^ DAT_21000e90) +
                  (uint)(bVar5 ^ DAT_21000e8e) + (uint)(bVar1 ^ DAT_21000e8f) +
                  (param_1 ^ DAT_21000e8d) + (uint)(DAT_21000e91 ^ bVar3) == 0) {
                cVar7 = '\x05';
              }
              else {
                if (DAT_21000d18 == '\x06') {
                  return 8;
                }
                if ((uint)(bVar4 ^ DAT_21000e9a) +
                    (uint)(bVar6 ^ DAT_21000e99) +
                    (uint)(bVar2 ^ DAT_21000e97) +
                    (uint)(bVar5 ^ DAT_21000e95) + (uint)(bVar1 ^ DAT_21000e96) +
                    (param_1 ^ DAT_21000e94) + (uint)(DAT_21000e98 ^ bVar3) == 0) {
                  cVar7 = '\x06';
                }
                else {
                  if (DAT_21000d18 == '\a') {
                    return 8;
                  }
                  if ((uint)(bVar4 ^ DAT_21000ea1) +
                      (uint)(bVar6 ^ DAT_21000ea0) +
                      (param_1 ^ DAT_21000e9b) +
                      (uint)(bVar5 ^ DAT_21000e9c) + (uint)(bVar1 ^ DAT_21000e9d) +
                      (uint)(bVar2 ^ DAT_21000e9e) + (uint)(bVar3 ^ DAT_21000e9f) != 0) {
                    return 8;
                  }
                  cVar7 = '\a';
                }
              }
            }
          }
        }
      }
    }
    if (DAT_21000d19 != '\0') {
      if (DAT_21000e1a == cVar7) {
        return 0;
      }
      if (DAT_21000d19 != '\x01') {
        if (DAT_21000e1b == cVar7) {
          return 1;
        }
        if (DAT_21000d19 != '\x02') {
          if (DAT_21000e1c == cVar7) {
            return 2;
          }
          if (DAT_21000d19 != '\x03') {
            if (DAT_21000e1d == cVar7) {
              return 3;
            }
            if (DAT_21000d19 != '\x04') {
              if (DAT_21000e1e == cVar7) {
                return 4;
              }
              if (DAT_21000d19 != '\x05') {
                if (DAT_21000e1f == cVar7) {
                  return 5;
                }
                if (DAT_21000d19 != '\x06') {
                  if (DAT_21000e20 == cVar7) {
                    return 6;
                  }
                  if (DAT_21000d19 != '\a') {
                    if (DAT_21000e21 == cVar7) {
                      uVar8 = 7;
                    }
                    else {
                      uVar8 = 8;
                    }
                    return uVar8;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 8;
}


