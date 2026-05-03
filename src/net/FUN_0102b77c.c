/*
 * Function: FUN_0102b77c
 * Entry:    0102b77c
 * Prototype: undefined4 __stdcall FUN_0102b77c(void)
 */


undefined4 FUN_0102b77c(void)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 in_stack_ffffffdc;
  
  FUN_010304ac(&DAT_2100095c);
  FUN_01036760((undefined4 *)&DAT_21001da0,0x21006cc0,0x600,0x102b56d,0,0,0,-9,0,in_stack_ffffffdc,0
               ,0);
  FUN_0103b916();
  FUN_01036760((undefined4 *)&DAT_21001d08,0x21006480,0x800,0x102b4b5,0,0,0,-9,0,in_stack_ffffffdc,0
               ,0);
  FUN_0103b916();
  iVar1 = FUN_0102dd18(0x103bf6c);
  if (((iVar1 < 0) && (iVar1 != -0x78)) && (0 < DAT_21000580)) {
    FUN_01039ee2((byte *)"IPC service init failed %d\n\n",iVar1,extraout_r2,DAT_21000580);
  }
  iVar1 = FUN_0102dd74(0x103bf6c,(int *)&DAT_21004608,0x2100059c);
  if ((iVar1 != 0) && (0 < DAT_21000580)) {
    FUN_01039ee2((byte *)"IPC reg endpoint failed %d\n",iVar1,extraout_r2_00,DAT_21000580);
  }
  return 0;
}


