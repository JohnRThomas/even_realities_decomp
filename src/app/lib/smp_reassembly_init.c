/*
 * Function: smp_reassembly_init
 * Entry:    000842e0
 * Prototype: void __stdcall smp_reassembly_init(smp_transport * smpt)
 */


/* exclude_from_export */

void smp_reassembly_init(smp_transport *smpt)

{
  *(undefined4 *)((int)&smpt[2].__reassembly + 2) = 0;
  *(undefined2 *)((int)&smpt[3].work + 2) = 0;
  return;
}


