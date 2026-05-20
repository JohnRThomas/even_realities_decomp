/*
 * Function: $_?_FUN_0005d5d4
 * Entry:    0005d5d4
 * Prototype: undefined4 __stdcall $_?_FUN_0005d5d4(int param_1, undefined2 param_2, undefined4 * param_3)
 */


undefined4 ____FUN_0005d5d4(int param_1,undefined2 param_2,undefined4 *param_3)

{
  bt_gatt_ccc_cfg *pbVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 8) == 0x5d711) &&
     (pbVar1 = ccc_find_cfg(*(_bt_gatt_ccc **)(param_1 + 0xc),(bt_addr_le_t *)*param_3,
                            *(uint8_t *)(param_3 + 1)), pbVar1 != (bt_gatt_ccc_cfg *)0x0)) {
    iVar2 = param_3[0x32];
    *(undefined2 *)(param_3 + iVar2 + 2) = param_2;
    *(short *)((int)param_3 + iVar2 * 4 + 10) = (short)pbVar1[2];
    param_3[0x32] = iVar2 + 1;
  }
  return 1;
}


