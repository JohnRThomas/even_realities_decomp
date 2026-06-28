/*
 * Function: ?_local_store_delete
 * Entry:    000240dc
 * Prototype: undefined __stdcall ?_local_store_delete(char * param_1)
 */


void __local_store_delete(char *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char local_98 [4];
  undefined4 auStack_94 [6];
  undefined1 auStack_7c [104];
  
  pcVar5 = "ar_glass_userdata_settings/";
  pcVar1 = local_98;
  do {
    pcVar4 = pcVar1;
    uVar2 = *(undefined4 *)pcVar5;
    uVar3 = *(undefined4 *)(pcVar5 + 4);
    pcVar5 = pcVar5 + 8;
    *(undefined4 *)pcVar4 = uVar2;
    *(undefined4 *)(pcVar4 + 4) = uVar3;
    pcVar1 = pcVar4 + 8;
  } while (pcVar5 != "gs/");
  builtin_strncpy(pcVar4 + 8,"gs/",4);
  memset(auStack_7c,0,100);
  ____strncpy(local_98,param_1,128);
  settings_delete(local_98);
  return;
}


