/*
 * Function: FUN_01014248
 * Entry:    01014248
 * Prototype: undefined __stdcall FUN_01014248(void)
 */


void FUN_01014248(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 uVar4;
  int extraout_r3;
  undefined4 extraout_r3_00;
  int extraout_r3_01;
  int extraout_r3_02;
  int local_30;
  undefined4 uStack_2c;
  ushort *local_28;
  undefined4 uStack_24;
  
  local_30 = 0;
  uStack_2c = 0x20000;
LAB_0101425c:
  iVar2 = FUN_0100a5d8(&local_30);
  iVar3 = local_30;
  do {
    local_30 = iVar3;
    if (iVar2 != 0) {
      DAT_21000f64 = 1;
      while( true ) {
        local_28 = (ushort *)0x0;
        uStack_24 = 0x10000;
        do {
          iVar2 = FUN_0100a5d8((int *)&local_28);
          if (iVar2 != 0) {
            DAT_21000f64 = 0;
            return;
          }
        } while ((local_28 == (ushort *)0x0) || ((char)local_28[0x1b2] == ' '));
        if (*local_28 == 0xffff) {
          DAT_21000f64 = 0;
          return;
        }
        iVar3 = FUN_0100a518(*local_28,1);
        uVar4 = extraout_r2_01;
        iVar2 = extraout_r3_01;
        if (iVar3 == 0) break;
        FUN_0102491c((uint)*(byte *)(iVar3 + 0x364),extraout_r1_00,extraout_r2_01,extraout_r3_01);
        *(undefined1 *)(iVar3 + 0x31c) = 0;
        FUN_010236bc((uint)*(byte *)(iVar3 + 0x364));
        *(undefined1 *)(iVar3 + 0x364) = 0x20;
      }
LAB_01014322:
      FUN_01009500(0x30,0x122,uVar4,iVar2);
      DAT_21000f5c = 0;
      DAT_21000f66 = 10000;
      DAT_21000f54 = 1;
      DAT_21000f64 = 0;
      FUN_01014248();
      return;
    }
    if (*(char *)(iVar3 + 0x120) == '\0') goto LAB_0101425c;
    *(undefined1 *)(iVar3 + 0x148) = 1;
    FUN_01013160(iVar3,1);
    if (*(char *)(iVar3 + 0x120) == '\0') goto LAB_0101425c;
    FUN_01023fb0((uint)*(byte *)(iVar3 + 0x100));
    FUN_0102491c((uint)*(byte *)(iVar3 + 0x100),extraout_r1,extraout_r2,extraout_r3);
    cVar1 = FUN_010236bc((uint)*(byte *)(iVar3 + 0x100));
    if (cVar1 == '\0') {
      FUN_01009500(0x30,0x20a,extraout_r2_00,extraout_r3_00);
      uVar4 = extraout_r2_02;
      iVar2 = extraout_r3_02;
      goto LAB_01014322;
    }
    *(undefined1 *)(iVar3 + 0x120) = 0;
    iVar2 = FUN_0100a5d8(&local_30);
    iVar3 = local_30;
  } while( true );
}


