/*
 * Function: pin_is_task_output
 * Entry:    000888ca
 * Prototype: bool __stdcall pin_is_task_output(uint32_t pin)
 */


/* exclude_from_export */

bool pin_is_task_output(uint32_t pin)

{
  bool bVar1;
  bool bVar2;
  uint32_t pin_00;
  
  bVar1 = pin_is_output(pin);
  bVar2 = false;
  if (bVar1) {
    bVar2 = pin_in_use_by_te(pin_00);
  }
  return bVar2;
}


