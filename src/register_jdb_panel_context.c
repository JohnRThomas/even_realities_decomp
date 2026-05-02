/*
 * Function: register_jdb_panel_context
 * Entry:    0004aab8
 * Prototype: undefined __stdcall register_jdb_panel_context(undefined4 * param_1)
 */


void register_jdb_panel_context(undefined4 *param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  
  z_impl_k_mutex_init(&lcd_mutex);
  *param_1 = 0x4a979;
  param_1[1] = 0x4a781;
  param_1[2] = 0x4a8ad;
  param_1[3] = 0x4a721;
  param_1[4] = 0x4a7cd;
  param_1[5] = 0x36e11;
  param_1[6] = 0x80b9f;
  param_1[7] = 0x80b93;
  param_1[8] = 0x4a6dd;
  pvVar1 = malloc(0xfa08);
  iVar3 = (int)pvVar1 + 5;
  param_1[0xd1] = iVar3;
  piVar2 = param_1 + 8;
  do {
    piVar2 = piVar2 + 1;
    *piVar2 = iVar3;
    iVar3 = iVar3 + 0x140;
  } while (iVar3 != (int)pvVar1 + 0xfa05);
  param_1[0xd4] = 64000;
  return;
}


