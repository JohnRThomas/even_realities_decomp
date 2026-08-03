/*
 * Function: smp_reassembly_get_ud
 * Entry:    000843b6
 * Prototype: void * __stdcall smp_reassembly_get_ud(smp_transport * smpt)
 */


/* exclude_from_export_ai */

void * smp_reassembly_get_ud(smp_transport *smpt)

{
  void *pvVar1;
  
  pvVar1 = *(void **)((int)&smpt[2].__reassembly + 2);
  if (pvVar1 != (void *)0x0) {
    pvVar1 = (void *)((int)pvVar1 + 0x18);
  }
  return pvVar1;
}


