/*
 * Function: metal_linux_bus_finish
 * Entry:    0006b418
 * Prototype: void __stdcall metal_linux_bus_finish(void)
 */


/* exclude_from_export_ai */

void metal_linux_bus_finish(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_r0;
  char *name;
  int iVar3;
  
  if ((((in_r0 != (undefined4 *)0x0) && (name = (char *)*in_r0, name != (char *)0x0)) &&
      (*name != '\0')) && (iVar3 = metal_bus_find(name,(metal_bus **)0x0), iVar3 != 0)) {
    in_r0[7] = in_r0 + 7;
    in_r0[8] = in_r0 + 7;
    puVar1 = DAT_2000be18;
    puVar2 = in_r0 + 9;
    in_r0[10] = DAT_2000be18;
    DAT_2000be18 = puVar2;
    in_r0[9] = &DAT_2000be14;
    *puVar1 = in_r0 + 9;
    if ((6 < DAT_2000be0c) && (DAT_2000be10 != (code *)0x0)) {
      (*DAT_2000be10)(7,"registered %s bus\n",*in_r0);
    }
  }
  return;
}


