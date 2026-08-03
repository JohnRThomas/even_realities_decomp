/*
 * Function: smp_reassembly_expected
 * Entry:    000842ea
 * Prototype: int __stdcall smp_reassembly_expected(smp_transport * smpt)
 */


/* exclude_from_export_ai */

int smp_reassembly_expected(smp_transport *smpt)

{
  if (*(int *)((int)&smpt[2].__reassembly + 2) != 0) {
    return (uint)*(ushort *)((int)&smpt[3].work + 2);
  }
  return -0x16;
}


