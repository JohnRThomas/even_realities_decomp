/*
 * Function: extract_decimal
 * Entry:    0008a856
 * Prototype: int __stdcall extract_decimal(char * param_1, int param_2)
 */


/* exclude_from_export_ai */

int extract_decimal(char *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = param_1;
  do {
    pcVar2 = pcVar1;
    if (pcVar2 == param_1 + param_2) break;
    pcVar1 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  return (int)pcVar2 - (int)param_1;
}


