/*
 * Function: FUN_0102bbb0
 * Entry:    0102bbb0
 * Prototype: undefined __stdcall FUN_0102bbb0(int param_1)
 */


void FUN_0102bbb0(int param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined4 local_10c;
  undefined1 auStack_108 [248];
  
  local_10c = 0;
  puVar2 = (undefined1 *)FUN_0103bdee(auStack_108,0,0xf7);
  if (param_1 != 0) {
    DAT_21004ca1 = 0;
    puVar3 = (undefined1 *)FUN_0102ac68();
    uVar6 = SUB41(puVar3,0);
    if (puVar3 == (undefined1 *)0x0) {
      if (DAT_21004fa2 == '\0') {
        uVar5 = 0x11;
      }
      else {
        uVar5 = 0x10;
      }
      local_10c = CONCAT31(local_10c._1_3_,uVar5);
      DAT_21004ca2 = uVar6;
      DAT_21004ca4 = uVar6;
      FUN_0103bdd4(0x21004ca6,(undefined1 *)&local_10c,0xfb);
      uVar6 = 0x20;
    }
    else {
      DAT_21004ca2 = 0;
      DAT_21004ca4 = 0;
      FUN_0103bcfa(&DAT_21004ca6,&DAT_21004b9f,puVar3,&UNK_000000fb);
    }
    DAT_21004ca1 = uVar6;
    iVar4 = FUN_01033e20(&DAT_21004ca1);
    if (iVar4 != 0) {
      return;
    }
    puVar2 = (undefined1 *)0x0;
    if (DAT_21004fa2 == '\x01') {
      bVar1 = FUN_01034190();
      puVar2 = (undefined1 *)(uint)bVar1;
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = (undefined1 *)FUN_01033e20(&DAT_21004ca1);
      }
    }
    if (puVar3 == (undefined1 *)0x0) {
      DAT_21004c9b = 2;
    }
    else {
      DAT_21004c9b = 1;
    }
  }
  if ((DAT_21004fa2 == '\0') && (iVar4 = FUN_01034018(puVar2), iVar4 == 0)) {
    DAT_21004614 = DAT_21004614 + 1;
  }
  return;
}


