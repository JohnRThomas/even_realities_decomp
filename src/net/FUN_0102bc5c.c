/*
 * Function: FUN_0102bc5c
 * Entry:    0102bc5c
 * Prototype: undefined __stdcall FUN_0102bc5c(void)
 */


void FUN_0102bc5c(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 local_10c;
  undefined1 auStack_108 [252];
  
  local_10c = 0;
  FUN_0103bdee(auStack_108,0,0xf7);
  DAT_21004ea2 = 0;
  DAT_21004ea4 = 0;
  local_10c = CONCAT31(local_10c._1_3_,0x11);
  FUN_0103bdd4(0x21004ea6,(undefined1 *)&local_10c,0xfb);
  DAT_21004ea1 = 0xfb;
  puVar1 = (undefined1 *)FUN_01033e20(&DAT_21004ea1);
  if ((puVar1 != (undefined1 *)0x0) && (0 < DAT_21000580)) {
    puVar1 = (undefined1 *)
             FUN_01039ee2((byte *)"esb_write_payload failed\n",extraout_r1,extraout_r2,DAT_21000580)
    ;
  }
  iVar2 = FUN_01034018(puVar1);
  if ((iVar2 != 0) && (0 < DAT_21000580)) {
    FUN_01039ee2((byte *)"esb_start_tx failed\n",extraout_r1_00,extraout_r2_00,DAT_21000580);
    return;
  }
  return;
}


