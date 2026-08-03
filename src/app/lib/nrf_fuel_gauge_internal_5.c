/*
 * Function: nrf_fuel_gauge_internal_5
 * Entry:    0000ea18
 * Prototype: undefined __stdcall nrf_fuel_gauge_internal_5(int param_1, int param_2, undefined4 * param_3)
 */


/* exclude_from_export */

void nrf_fuel_gauge_internal_5(int param_1,int param_2,undefined4 *param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  pcVar1 = (char *)(param_1 + -1);
  *param_3 = 1;
  while( true ) {
    pcVar1 = pcVar1 + 1;
    iVar3 = iVar4 + 1;
    iVar2 = iVar2 + 1;
    if ((*pcVar1 != '\0') && (*(int *)(param_2 + iVar4 * 4) = iVar2, iVar4 = iVar3, 2 < iVar3))
    break;
    if (iVar2 == 3) {
      param_3[1] = iVar4;
      return;
    }
  }
  param_3[1] = iVar3;
  return;
}


