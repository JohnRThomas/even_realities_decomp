/*
 * Function: extract_width
 * Entry:    00081a56
 * Prototype: int __stdcall extract_width(undefined * param_1, undefined4 param_2, char * param_3, char * param_4)
 */


/* exclude_from_export_ai */

int extract_width(undefined *param_1,undefined4 param_2,char *param_3,char *param_4)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = param_3;
  while ((pcVar2 < param_4 || ((param_4 == (char *)0x0 && (*pcVar2 != '\0'))))) {
    iVar1 = (*(code *)param_1)(*pcVar2,param_2);
    pcVar2 = pcVar2 + 1;
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  return (int)pcVar2 - (int)param_3;
}


