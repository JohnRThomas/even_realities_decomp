/*
 * Function: FUN_01032cf0
 * Entry:    01032cf0
 * Prototype: undefined __stdcall FUN_01032cf0(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_01032cf0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar6;
  char cVar7;
  uint *puVar8;
  byte local_20 [4];
  char *local_1c;
  
  if (DAT_21004998 == 2) {
    iVar1 = 0;
  }
  else {
    if (DAT_21004998 != 4) {
      if (DAT_21004998 != 1) {
        local_1c = "Unknown command";
        local_20[0] = 2;
        local_20[1] = 0;
        local_20[2] = 0;
        local_20[3] = 0;
        FUN_0102ea44(0x103bffc,0x1080,local_20,(undefined1 *)0x0);
        DAT_21004998 = 0;
        return;
      }
      do {
        do {
          iVar1 = FUN_01032bb8(&DAT_210051f6);
          if (iVar1 != 0) {
            cVar7 = '\x1f';
            uVar6 = extraout_r1;
            goto LAB_01032d34;
          }
          iVar1 = FUN_0103bd20(&DAT_210051f6,0x103e315,0x20);
        } while (iVar1 == 0);
        uVar2 = FUN_01039228((uint *)&DAT_21005216,(uint *)&DAT_210051f6);
        cVar7 = '\0';
        uVar6 = extraout_r1_00;
      } while (uVar2 != 0);
LAB_01032d34:
      puVar3 = FUN_01030390(1,uVar6,0xffffffff,(uint *)0xffffffff);
      puVar8 = puVar3 + 3;
      puVar4 = (undefined1 *)FUN_01030844((int *)puVar8,2);
      *puVar4 = 0x3e;
      puVar4[1] = 0x42;
      puVar4 = (undefined1 *)FUN_01030844((int *)puVar8,1);
      *puVar4 = 8;
      pcVar5 = (char *)FUN_01030844((int *)puVar8,0x41);
      *pcVar5 = cVar7;
      if (cVar7 == '\0') {
        FUN_01032c00(pcVar5 + 1,&DAT_21005216);
        FUN_01032c00(pcVar5 + 0x21,&DAT_21005236);
      }
      else {
        FUN_0103bdee(pcVar5 + 1,0,0x40);
      }
      goto LAB_01032d7c;
    }
    iVar1 = 1;
  }
  puVar3 = FUN_01032c48(iVar1,param_2,param_3,DAT_21004998);
LAB_01032d7c:
  iVar1 = DAT_21004998;
  DAT_21004998 = 0;
  if (puVar3 == (uint *)0x0) {
    DAT_21004998 = 0;
    return;
  }
  FUN_01030484(puVar3,0,iVar1);
  return;
}


