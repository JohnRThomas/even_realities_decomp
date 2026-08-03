/*
 * Function: nrf_fuel_gauge_internal_3
 * Entry:    0000ea4c
 * Prototype: undefined4 __stdcall nrf_fuel_gauge_internal_3(int param_1, int param_2)
 */


/* exclude_from_export */

undefined4 nrf_fuel_gauge_internal_3(int param_1,int param_2)

{
  char *pcVar1;
  
  if (*(int *)(param_2 + 4) == 0) {
    return 0;
  }
  pcVar1 = (char *)(param_1 + -1);
  do {
    if (*(int *)(param_2 + 4) <= (int)(pcVar1 + (1 - param_1))) {
      return 1;
    }
    pcVar1 = pcVar1 + 1;
  } while (*pcVar1 != '\0');
  return 0;
}


