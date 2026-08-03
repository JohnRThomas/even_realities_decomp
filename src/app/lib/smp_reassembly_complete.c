/*
 * Function: smp_reassembly_complete
 * Entry:    0008436a
 * Prototype: int __stdcall smp_reassembly_complete(smp_transport * smpt, bool force)
 */


/* exclude_from_export_ai */

int smp_reassembly_complete(smp_transport *smpt,bool force)

{
  net_buf *nb;
  uint uVar1;
  
  nb = *(net_buf **)((int)&smpt[2].__reassembly + 2);
  if (nb == (net_buf *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = (uint)*(ushort *)((int)&smpt[3].work + 2);
    if ((uVar1 == 0) || (force)) {
      smp_rx_req(smpt,nb);
      *(undefined2 *)((int)&smpt[3].work + 2) = 0;
      *(undefined4 *)((int)&smpt[2].__reassembly + 2) = 0;
    }
    else {
      uVar1 = 0xffffffc3;
    }
  }
  return uVar1;
}


