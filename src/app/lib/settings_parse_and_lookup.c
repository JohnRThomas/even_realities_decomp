/*
 * Function: settings_parse_and_lookup
 * Entry:    000517e0
 * Prototype: settings_handler_static * __stdcall settings_parse_and_lookup(char * name, char * * next)
 */


/* exclude_from_export */

settings_handler_static * settings_parse_and_lookup(char *name,char **next)

{
  int iVar1;
  char *test;
  char *file;
  int line;
  undefined **ppuVar2;
  int *piVar3;
  undefined **ppuVar4;
  char *pcVar5;
  char **local_24 [2];
  
  if (next != (char **)0x0) {
    *next = (char *)0x0;
  }
  ppuVar4 = (undefined **)0x0;
  ppuVar2 = &PTR_s_bt_0008ba60;
  local_24[0] = next;
  while( true ) {
    if (&PTR_img_mgmt_register_group_1_0008bad8 < ppuVar2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","ch <= _settings_handler_static_list_end",
              "WEST_TOPDIR/zephyr/subsys/settings/src/settings.c",0x94);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    piVar3 = DAT_2000aaec;
    if ((undefined **)((int)&PTR_0008bad4 + 3U) < ppuVar2) break;
    pcVar5 = *ppuVar2;
    iVar1 = settings_name_steq(name,pcVar5,(char **)local_24);
    if (((iVar1 != 0) &&
        ((ppuVar4 == (undefined **)0x0 ||
         (iVar1 = settings_name_steq(pcVar5,*ppuVar4,(char **)0x0), iVar1 != 0)))) &&
       (ppuVar4 = ppuVar2, next != (char **)0x0)) {
      *next = (char *)local_24[0];
    }
    ppuVar2 = ppuVar2 + 5;
  }
  for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    pcVar5 = (char *)piVar3[-5];
    iVar1 = settings_name_steq(name,pcVar5,(char **)local_24);
    if ((iVar1 != 0) &&
       (((ppuVar4 == (undefined **)0x0 ||
         (iVar1 = settings_name_steq(pcVar5,*ppuVar4,(char **)0x0), iVar1 != 0)) &&
        (ppuVar4 = (undefined **)(piVar3 + -5), next != (char **)0x0)))) {
      *next = (char *)local_24[0];
    }
  }
  return (settings_handler_static *)ppuVar4;
}


