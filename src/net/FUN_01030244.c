/*
 * Function: FUN_01030244
 * Entry:    01030244
 * Prototype: undefined4 __stdcall FUN_01030244(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Removing unreachable block (ram,0x0103018a) */
/* WARNING: Removing unreachable block (ram,0x0103018e) */
/* WARNING: Removing unreachable block (ram,0x010301ba) */
/* WARNING: Removing unreachable block (ram,0x01030192) */
/* WARNING: Removing unreachable block (ram,0x010301c8) */
/* WARNING: Removing unreachable block (ram,0x0103017a) */

undefined4 FUN_01030244(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  
  FUN_01039ee2((byte *)"* buffer overflow detected *\n",param_2,param_3,param_4);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  software_interrupt(2);
  FUN_0102cdac((uint *)&DAT_2100ae44,0x2100eb00,0x1500,0x20);
                    /* WARNING: Could not recover jumptable at 0x01030274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)0x103024d)(0);
  return uVar2;
}


