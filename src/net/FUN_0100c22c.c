/*
 * Function: FUN_0100c22c
 * Entry:    0100c22c
 * Prototype: undefined __stdcall FUN_0100c22c(uint param_1)
 */


void FUN_0100c22c(uint param_1)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  
  DAT_21000d19 = DAT_21000d19 - 1;
  bVar2 = (&DAT_21000e1a)[param_1];
  uVar11 = (uint)bVar2;
  uVar5 = (uint)DAT_21000d19;
  uVar4 = param_1;
  if (uVar5 != param_1) {
    iVar6 = uVar5 * 0x10;
    iVar8 = param_1 * 0x10;
    uVar10 = *(undefined4 *)(&DAT_21000d1e + iVar6);
    uVar9 = *(undefined4 *)(&DAT_21000d22 + iVar6);
    uVar7 = *(undefined4 *)(&DAT_21000d26 + iVar6);
    *(undefined4 *)(&DAT_21000d1a + iVar8) = *(undefined4 *)(&DAT_21000d1a + iVar6);
    *(undefined4 *)(&DAT_21000d1e + iVar8) = uVar10;
    *(undefined4 *)(&DAT_21000d22 + iVar8) = uVar9;
    *(undefined4 *)(&DAT_21000d26 + iVar8) = uVar7;
    uVar10 = *(undefined4 *)(&DAT_21000d9e + iVar6);
    uVar9 = *(undefined4 *)(&DAT_21000da2 + iVar6);
    uVar7 = *(undefined4 *)(&DAT_21000da6 + iVar6);
    *(undefined4 *)(&DAT_21000d9a + iVar8) = *(undefined4 *)(&DAT_21000d9a + iVar6);
    *(undefined4 *)(&DAT_21000d9e + iVar8) = uVar10;
    *(undefined4 *)(&DAT_21000da2 + iVar8) = uVar9;
    *(undefined4 *)(&DAT_21000da6 + iVar8) = uVar7;
    (&DAT_21000e1a)[param_1] = (&DAT_21000e1a)[uVar5];
    *(undefined4 *)(&DAT_21000e22 + param_1 * 6) = *(undefined4 *)(&DAT_21000e22 + uVar5 * 6);
    *(undefined2 *)(&DAT_21000e26 + param_1 * 6) = *(undefined2 *)(&DAT_21000e26 + uVar5 * 6);
    uVar4 = (uint)DAT_21000d19;
    (&DAT_21000e52)[param_1] = (&DAT_21000e52)[uVar5];
  }
  if ((uVar4 == 0) ||
     ((DAT_21000e1a != uVar11 &&
      ((uVar4 == 1 ||
       ((DAT_21000e1b != uVar11 &&
        ((uVar4 == 2 ||
         ((DAT_21000e1c != uVar11 &&
          ((uVar4 == 3 ||
           ((DAT_21000e1d != uVar11 &&
            ((uVar4 == 4 ||
             ((DAT_21000e1e != uVar11 &&
              ((uVar4 == 5 ||
               ((DAT_21000e1f != uVar11 &&
                ((uVar4 == 6 ||
                 ((DAT_21000e20 != uVar11 && ((uVar4 == 7 || (DAT_21000e21 != uVar11))))))))))))))))
           )))))))))))))) {
    DAT_21000d18 = DAT_21000d18 - 1;
    if (uVar11 != DAT_21000d18) {
      iVar6 = (uint)DAT_21000d18 * 7;
      iVar8 = uVar11 * 7;
      *(undefined4 *)(&DAT_21000e6a + iVar8) = *(undefined4 *)(&DAT_21000e6a + iVar6);
      bVar3 = DAT_21000d19;
      uVar1 = (&DAT_21000e70)[iVar6];
      *(undefined2 *)(&DAT_21000e6e + iVar8) = *(undefined2 *)(&DAT_21000e6e + iVar6);
      (&DAT_21000e70)[iVar8] = uVar1;
      if (bVar3 != 0) {
        if (DAT_21000e1a == DAT_21000d18) {
          iVar6 = 0;
        }
        else {
          if (bVar3 == 1) {
            return;
          }
          if (DAT_21000e1b == DAT_21000d18) {
            iVar6 = 1;
          }
          else {
            if (bVar3 == 2) {
              return;
            }
            if (DAT_21000e1c == DAT_21000d18) {
              iVar6 = 2;
            }
            else {
              if (bVar3 == 3) {
                return;
              }
              if (DAT_21000e1d == DAT_21000d18) {
                iVar6 = 3;
              }
              else {
                if (bVar3 == 4) {
                  return;
                }
                if (DAT_21000e1e == DAT_21000d18) {
                  iVar6 = 4;
                }
                else {
                  if (bVar3 == 5) {
                    return;
                  }
                  if (DAT_21000e1f == DAT_21000d18) {
                    iVar6 = 5;
                  }
                  else {
                    if (bVar3 == 6) {
                      return;
                    }
                    if (DAT_21000e20 == DAT_21000d18) {
                      iVar6 = 6;
                    }
                    else {
                      if (bVar3 == 7) {
                        return;
                      }
                      if (DAT_21000e21 != DAT_21000d18) {
                        return;
                      }
                      iVar6 = 7;
                    }
                  }
                }
              }
            }
          }
        }
        (&DAT_21000e1a)[iVar6] = bVar2;
        return;
      }
    }
  }
  return;
}


