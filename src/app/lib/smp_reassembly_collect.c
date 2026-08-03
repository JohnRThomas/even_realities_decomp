/*
 * Function: smp_reassembly_collect
 * Entry:    000842fa
 * Prototype: int __stdcall smp_reassembly_collect(smp_transport * smpt, void * buf, uint16_t len)
 */


/* exclude_from_export_ai */

int smp_reassembly_collect(smp_transport *smpt,void *buf,uint16_t len)

{
  net_buf *pnVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (uint)len;
  if (*(int *)((int)&smpt[2].__reassembly + 2) == 0) {
    if (uVar2 < 8) {
      return -0x3d;
    }
    uVar3 = ((*(ushort *)((int)buf + 2) & 0xff) << 8 | (uint)(*(ushort *)((int)buf + 2) >> 8)) + 8;
    uVar4 = uVar3 & 0xffff;
    if ((0x9ab < uVar2) || (0x9ab < uVar4)) {
      return -0x3f;
    }
    if (uVar4 < uVar2) {
      return -0x8b;
    }
    pnVar1 = smp_packet_alloc();
    *(net_buf **)((int)&smpt[2].__reassembly + 2) = pnVar1;
    if (pnVar1 == (net_buf *)0x0) {
      return -0xc;
    }
    *(short *)((int)&smpt[3].work + 2) = (short)uVar3;
  }
  else if (*(ushort *)((int)&smpt[3].work + 2) < uVar2) {
    return -0x8b;
  }
  net_buf_add_mem((net_buf *)(*(int *)((int)&smpt[2].__reassembly + 2) + 0xc),buf,uVar2);
  uVar2 = *(ushort *)((int)&smpt[3].work + 2) - uVar2;
  *(short *)((int)&smpt[3].work + 2) = (short)uVar2;
  return uVar2 & 0xffff;
}


