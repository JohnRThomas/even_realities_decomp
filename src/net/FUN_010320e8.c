/*
 * Function: FUN_010320e8
 * Entry:    010320e8
 * Prototype: int __stdcall FUN_010320e8(void)
 */


int FUN_010320e8(void)

{
  bool bVar1;
  int iVar2;
  byte local_28 [4];
  char *local_24;
  undefined *puStack_20;
  int local_1c;
  undefined1 *local_14;
  
  FUN_0103036c(0x103ca90);
  FUN_010095dc(0x103ae8f);
  iVar2 = FUN_01009878();
  if ((((((iVar2 == 0) && (iVar2 = FUN_0100989c(), iVar2 == 0)) &&
        (iVar2 = FUN_010098c0(), iVar2 == 0)) &&
       ((iVar2 = FUN_01009918(), iVar2 == 0 && (iVar2 = FUN_010098f4(), iVar2 == 0)))) &&
      ((iVar2 = FUN_0100993c(), iVar2 == 0 &&
       ((iVar2 = FUN_01009984(), iVar2 == 0 && (iVar2 = FUN_010099a8(), iVar2 == 0)))))) &&
     ((iVar2 = FUN_01009960(), iVar2 == 0 &&
      ((iVar2 = FUN_01009984(), iVar2 == 0 && (iVar2 = FUN_010099a8(), iVar2 == 0)))))) {
    local_14._0_1_ = 1;
    local_1c = FUN_01009674(0,1,(ushort *)&local_14);
    if (-1 < local_1c) {
      local_14 = (undefined1 *)CONCAT31(local_14._1_3_,1);
      local_1c = FUN_01009674(0,2,(ushort *)&local_14);
      if (-1 < local_1c) {
        local_14 = (undefined1 *)CONCAT22(local_14._2_2_,8);
        local_1c = FUN_01009674(0,7,(ushort *)&local_14);
        if (-1 < local_1c) {
          local_14 = &DAT_0203fbfb;
          local_1c = FUN_01009674(0,3,(ushort *)&local_14);
          if (-1 < local_1c) {
            local_14 = (undefined1 *)CONCAT31(local_14._1_3_,1);
            local_1c = FUN_01009674(0,4,(ushort *)&local_14);
            if (-1 < local_1c) {
              local_14 = (undefined1 *)CONCAT22(local_14._2_2_,0x1f);
              local_1c = FUN_01009674(0,6,(ushort *)&local_14);
              if (-1 < local_1c) {
                local_14 = (undefined1 *)CONCAT31(local_14._1_3_,3);
                local_1c = FUN_01009674(0,5,(ushort *)&local_14);
                if (-1 < local_1c) {
                  if (local_1c < 0x16c4) {
                    local_1c = 0;
                  }
                  else {
                    local_24 = "Allocated memory too low: %u < %u";
                    puStack_20 = &DAT_000016c3;
                    local_28[0] = 4;
                    local_28[1] = 0;
                    local_28[2] = 0;
                    local_28[3] = 0;
                    FUN_0102ea44(0x103c004,0x2040,local_28,(undefined1 *)0x0);
                    bVar1 = (bool)isCurrentModePrivileged();
                    if (bVar1) {
                      setBasePriority(0);
                    }
                    software_interrupt(2);
                    local_1c = -0xc;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    local_1c = -0x86;
  }
  return local_1c;
}


