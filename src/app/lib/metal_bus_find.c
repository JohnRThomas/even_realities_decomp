/*
 * Function: metal_bus_find
 * Entry:    0006b3dc
 * Prototype: int __stdcall metal_bus_find(char * name, metal_bus * * bus)
 */


/* exclude_from_export */

int metal_bus_find(char *name,metal_bus **bus)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_2000be14;
  while( true ) {
    if ((undefined4 **)puVar2 == &DAT_2000be14) {
      return -2;
    }
    iVar1 = strcmp((char *)puVar2[-9],name);
    if ((iVar1 == 0) && (bus != (metal_bus **)0x0)) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  *bus = (metal_bus *)(puVar2 + -9);
  return 0;
}


