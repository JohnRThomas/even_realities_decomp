/*
 * Function: $_?_FUN_0005d580
 * Entry:    0005d580
 * Prototype: undefined4 __stdcall $_?_FUN_0005d580(int param_1, undefined4 param_2, undefined4 * param_3)
 */


undefined4 ____FUN_0005d580(int param_1,undefined4 param_2,undefined4 *param_3)

{
  bt_gatt_ccc_cfg *pbVar1;
  
  if ((*(int *)(param_1 + 8) == 0x5d711) &&
     (pbVar1 = ccc_find_cfg(*(_bt_gatt_ccc **)(param_1 + 0xc),(bt_addr_le_t *)*param_3,
                            *(uint8_t *)(param_3 + 1)), pbVar1 != (bt_gatt_ccc_cfg *)0x0)) {
    *pbVar1 = 0;
    pbVar1[1] = 0;
    *(undefined2 *)(pbVar1 + 2) = 0;
  }
  return 1;
}


