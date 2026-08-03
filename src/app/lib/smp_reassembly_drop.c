/*
 * Function: smp_reassembly_drop
 * Entry:    0008439a
 * Prototype: int __stdcall smp_reassembly_drop(smp_transport * smpt)
 */


/* exclude_from_export_ai */

int smp_reassembly_drop(smp_transport *smpt)

{
  net_buf *buf;
  int iVar1;
  
  buf = *(net_buf **)((int)&smpt[2].__reassembly + 2);
  if (buf == (net_buf *)0x0) {
    iVar1 = -0x16;
  }
  else {
    net_buf_unref(buf);
    iVar1 = 0;
    *(undefined2 *)((int)&smpt[3].work + 2) = 0;
    *(undefined4 *)((int)&smpt[2].__reassembly + 2) = 0;
  }
  return iVar1;
}


