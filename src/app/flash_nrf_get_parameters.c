/*
 * Function: flash_nrf_get_parameters
 * Entry:    000644a0
 * Prototype: flash_parameters * __stdcall flash_nrf_get_parameters(device * dev)
 */


flash_parameters * flash_nrf_get_parameters(device *dev)

{
  return &flash_nrf_parameters;
}


