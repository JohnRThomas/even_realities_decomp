/*
 * Function: metal_init
 * Entry:    0006b4e8
 * Prototype: int __stdcall metal_init(metal_init_params * params)
 */


/* exclude_from_export_ai */

int metal_init(metal_init_params *params)

{
  undefined1 *puVar1;
  
  puVar1 = memset(&DAT_2000be0c,0,0x20);
  *(dword *)(puVar1 + 4) = params->log_handler;
  *puVar1 = (char)params->log_level;
  *(undefined1 **)(puVar1 + 8) = puVar1 + 8;
  *(undefined1 **)(puVar1 + 0xc) = puVar1 + 8;
  *(undefined1 **)(puVar1 + 0x10) = puVar1 + 0x10;
  *(undefined1 **)(puVar1 + 0x14) = puVar1 + 0x10;
  *(undefined1 **)(puVar1 + 0x18) = puVar1 + 0x18;
  *(undefined1 **)(puVar1 + 0x1c) = puVar1 + 0x18;
  metal_linux_bus_finish();
  return 0;
}


