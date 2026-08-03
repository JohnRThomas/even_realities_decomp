/*
 * Function: settings_commit_subtree
 * Entry:    00051948
 * Prototype: int __stdcall settings_commit_subtree(char * subtree)
 */


/* exclude_from_export */

int settings_commit_subtree(char *subtree)

{
  int iVar1;
  char *test;
  char *file;
  int line;
  undefined **ppuVar2;
  int *piVar3;
  int iVar4;
  
  ppuVar2 = &PTR_s_bt_0008ba60;
  iVar4 = 0;
  while( true ) {
    if (&PTR_img_mgmt_register_group_1_0008bad8 < ppuVar2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","ch <= _settings_handler_static_list_end",
              "WEST_TOPDIR/zephyr/subsys/settings/src/settings.c",244);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    piVar3 = DAT_2000aaec;
    if ((undefined **)((int)&PTR_0008bad4 + 3U) < ppuVar2) break;
    if (((subtree != (char *)0x0) &&
        (iVar1 = settings_name_steq(*ppuVar2,subtree,(char **)0x0), iVar1 == 0)) ||
       (((code *)ppuVar2[3] == (code *)0x0 || (iVar1 = (*(code *)ppuVar2[3])(), iVar4 != 0)))) {
      iVar1 = iVar4;
    }
    ppuVar2 = ppuVar2 + 5;
    iVar4 = iVar1;
  }
  for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    if ((((subtree == (char *)0x0) ||
         (iVar1 = settings_name_steq((char *)piVar3[-5],subtree,(char **)0x0), iVar1 != 0)) &&
        ((code *)piVar3[-2] != (code *)0x0)) && (iVar1 = (*(code *)piVar3[-2])(), iVar4 == 0)) {
      iVar4 = iVar1;
    }
  }
  return iVar4;
}


