/*
 * Function: check_if_power_state_allowed
 * Entry:    00066e50
 * Prototype: bool __stdcall check_if_power_state_allowed(power_manager_level lvl)
 */


/* exclude_from_export */

bool check_if_power_state_allowed(power_manager_level lvl)

{
  power_manager_level pVar1;
  int iVar2;
  
  iVar2 = -1;
  do {
    pVar1 = iVar2 + POWER_MANAGER_LEVEL_OFF;
    if ((&power_mode_restrict_flags)[pVar1] != 0) {
      return false;
    }
    iVar2 = 0;
  } while (pVar1 < lvl);
  return true;
}


