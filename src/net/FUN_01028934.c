/*
 * Function: FUN_01028934
 * Entry:    01028934
 * Prototype: int __stdcall FUN_01028934(uint param_1, int param_2, undefined4 param_3)
 */


int FUN_01028934(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint *local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  local_18 = (uint *)0x0;
  uStack_14 = 0;
  uStack_10 = param_3;
  do {
    iVar1 = FUN_0100a5d8((int *)&local_18);
    if (iVar1 != 0) {
      local_18 = (uint *)0x0;
      uStack_14 = 0x10000;
      do {
        iVar1 = FUN_0100a5d8((int *)&local_18);
        if (iVar1 != 0) {
          local_18 = (uint *)0x0;
          uStack_14 = 0x30000;
          do {
            iVar1 = FUN_0100a5d8((int *)&local_18);
            if (iVar1 != 0) {
              local_18 = (uint *)0x0;
              uStack_14 = 0x40000;
              do {
                iVar1 = FUN_0100a5d8((int *)&local_18);
                if (iVar1 != 0) {
                  local_18 = (uint *)0x0;
                  uStack_14 = 0x80000;
                  do {
                    iVar1 = FUN_0100a5d8((int *)&local_18);
                    if (iVar1 != 0) {
                      local_18 = (uint *)0x0;
                      uStack_14 = 0xa0000;
                      do {
                        iVar1 = FUN_0100a5d8((int *)&local_18);
                        if (iVar1 != 0) {
                          local_18 = (uint *)0x0;
                          uStack_14 = 0x90000;
                          do {
                            iVar1 = FUN_0100a5d8((int *)&local_18);
                            if (iVar1 != 0) {
                              return 0;
                            }
                            iVar1 = FUN_01028912(param_1,local_18[0x45],param_2);
                          } while (iVar1 == 0);
                          return iVar1;
                        }
                        iVar1 = FUN_01028912(param_1,local_18[0x3a],param_2);
                      } while (iVar1 == 0);
                      return iVar1;
                    }
                    iVar1 = FUN_01028912(param_1,local_18[0x62],param_2);
                  } while (iVar1 == 0);
                  return iVar1;
                }
                iVar1 = FUN_01028912(param_1,*local_18,param_2);
              } while (iVar1 == 0);
              return iVar1;
            }
            iVar1 = FUN_01028912(param_1,*local_18,param_2);
          } while (iVar1 == 0);
          return iVar1;
        }
        iVar1 = FUN_01028912(param_1,local_18[6],param_2);
      } while (iVar1 == 0);
      return iVar1;
    }
    iVar1 = FUN_01028912(param_1,local_18[6],param_2);
  } while (iVar1 == 0);
  return iVar1;
}


