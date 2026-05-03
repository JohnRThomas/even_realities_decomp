/*
 * Function: FUN_0100d420
 * Entry:    0100d420
 * Prototype: bool __stdcall FUN_0100d420(uint param_1, uint * param_2, undefined1 param_3)
 */


bool FUN_0100d420(uint param_1,uint *param_2,undefined1 param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  bool bVar7;
  char cVar8;
  int iVar9;
  
  bVar7 = FUN_0100dac8(param_2,6);
  if (bVar7) {
    if (DAT_21000d19 != 0) {
      FUN_01026284((undefined4 *)&DAT_21000e52,param_3,(uint)DAT_21000d19);
    }
  }
  else if (DAT_21000d18 != '\0') {
    bVar1 = (byte)*param_2;
    bVar5 = *(byte *)((int)param_2 + 1);
    bVar6 = *(byte *)((int)param_2 + 2);
    bVar2 = *(byte *)((int)param_2 + 3);
    bVar3 = (byte)param_2[1];
    bVar4 = *(byte *)((int)param_2 + 5);
    cVar8 = bVar7;
    if ((uint)(bVar4 ^ DAT_21000e70) +
        (uint)(bVar3 ^ DAT_21000e6f) +
        (uint)(bVar2 ^ DAT_21000e6e) +
        (uint)(bVar5 ^ DAT_21000e6c) + (uint)(DAT_21000e6b ^ bVar1) + (DAT_21000e6a ^ param_1) +
        (uint)(bVar6 ^ DAT_21000e6d) != 0) {
      if (DAT_21000d18 == '\x01') {
        return bVar7;
      }
      if ((uint)(bVar4 ^ DAT_21000e77) +
          (uint)(bVar3 ^ DAT_21000e76) +
          (uint)(bVar6 ^ DAT_21000e74) +
          (uint)(bVar1 ^ DAT_21000e72) + (uint)(bVar5 ^ DAT_21000e73) + (param_1 ^ DAT_21000e71) +
          (uint)(bVar2 ^ DAT_21000e75) == 0) {
        cVar8 = '\x01';
      }
      else {
        if (DAT_21000d18 == '\x02') {
          return bVar7;
        }
        if ((uint)(bVar4 ^ DAT_21000e7e) +
            (uint)(bVar3 ^ DAT_21000e7d) +
            (uint)(bVar6 ^ DAT_21000e7b) +
            (uint)(bVar1 ^ DAT_21000e79) + (uint)(bVar5 ^ DAT_21000e7a) + (param_1 ^ DAT_21000e78) +
            (uint)(bVar2 ^ DAT_21000e7c) == 0) {
          cVar8 = '\x02';
        }
        else {
          if (DAT_21000d18 == '\x03') {
            return bVar7;
          }
          if ((uint)(bVar4 ^ DAT_21000e85) +
              (uint)(bVar3 ^ DAT_21000e84) +
              (uint)(bVar6 ^ DAT_21000e82) +
              (uint)(bVar1 ^ DAT_21000e80) + (uint)(bVar5 ^ DAT_21000e81) + (param_1 ^ DAT_21000e7f)
              + (uint)(bVar2 ^ DAT_21000e83) == 0) {
            cVar8 = '\x03';
          }
          else {
            if (DAT_21000d18 == '\x04') {
              return bVar7;
            }
            if ((uint)(bVar4 ^ DAT_21000e8c) +
                (uint)(bVar3 ^ DAT_21000e8b) +
                (uint)(bVar6 ^ DAT_21000e89) +
                (uint)(bVar1 ^ DAT_21000e87) + (uint)(bVar5 ^ DAT_21000e88) +
                (param_1 ^ DAT_21000e86) + (uint)(bVar2 ^ DAT_21000e8a) == 0) {
              cVar8 = '\x04';
            }
            else {
              if (DAT_21000d18 == '\x05') {
                return bVar7;
              }
              if ((uint)(bVar4 ^ DAT_21000e93) +
                  (uint)(bVar3 ^ DAT_21000e92) +
                  (uint)(bVar6 ^ DAT_21000e90) +
                  (uint)(bVar1 ^ DAT_21000e8e) + (uint)(bVar5 ^ DAT_21000e8f) +
                  (param_1 ^ DAT_21000e8d) + (uint)(bVar2 ^ DAT_21000e91) == 0) {
                cVar8 = '\x05';
              }
              else {
                if (DAT_21000d18 == '\x06') {
                  return bVar7;
                }
                if ((uint)(bVar4 ^ DAT_21000e9a) +
                    (uint)(bVar3 ^ DAT_21000e99) +
                    (uint)(bVar6 ^ DAT_21000e97) +
                    (uint)(bVar1 ^ DAT_21000e95) + (uint)(bVar5 ^ DAT_21000e96) +
                    (param_1 ^ DAT_21000e94) + (uint)(bVar2 ^ DAT_21000e98) == 0) {
                  cVar8 = '\x06';
                }
                else {
                  if (DAT_21000d18 == '\a') {
                    return bVar7;
                  }
                  if ((uint)(bVar4 ^ DAT_21000ea1) +
                      (uint)(bVar3 ^ DAT_21000ea0) +
                      (uint)(bVar2 ^ DAT_21000e9f) +
                      (param_1 ^ DAT_21000e9b) +
                      (uint)(bVar1 ^ DAT_21000e9c) + (uint)(bVar5 ^ DAT_21000e9d) +
                      (uint)(bVar6 ^ DAT_21000e9e) != 0) {
                    return bVar7;
                  }
                  cVar8 = '\a';
                }
              }
            }
          }
        }
      }
    }
    if (DAT_21000d19 != 0) {
      if (DAT_21000e1a == cVar8) {
        iVar9 = 0;
      }
      else {
        if (DAT_21000d19 == 1) {
          return bVar7;
        }
        if (DAT_21000e1b == cVar8) {
          iVar9 = 1;
        }
        else {
          if (DAT_21000d19 == 2) {
            return bVar7;
          }
          if (DAT_21000e1c == cVar8) {
            iVar9 = 2;
          }
          else {
            if (DAT_21000d19 == 3) {
              return bVar7;
            }
            if (DAT_21000e1d == cVar8) {
              iVar9 = 3;
            }
            else {
              if (DAT_21000d19 == 4) {
                return bVar7;
              }
              if (DAT_21000e1e == cVar8) {
                iVar9 = 4;
              }
              else {
                if (DAT_21000d19 == 5) {
                  return bVar7;
                }
                if (DAT_21000e1f == cVar8) {
                  iVar9 = 5;
                }
                else {
                  if (DAT_21000d19 == 6) {
                    return bVar7;
                  }
                  if (DAT_21000e20 == cVar8) {
                    iVar9 = 6;
                  }
                  else {
                    if (DAT_21000d19 == 7) {
                      return bVar7;
                    }
                    if (DAT_21000e21 != cVar8) {
                      return bVar7;
                    }
                    iVar9 = 7;
                  }
                }
              }
            }
          }
        }
      }
      (&DAT_21000e52)[iVar9] = param_3;
      return true;
    }
  }
  return bVar7;
}


