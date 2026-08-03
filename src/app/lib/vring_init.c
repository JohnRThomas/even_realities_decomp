/*
 * Function: vring_init
 * Entry:    00088bf2
 * Prototype: void __stdcall vring_init(vring * vr, uint num, uint8_t * p, ulong align)
 */


/* exclude_from_export_ai */

void vring_init(vring *vr,uint num,uint8_t *p,ulong align)

{
  vring vVar1;
  vring vVar2;
  vring vVar3;
  uint in_stack_00000000;
  vring in_stack_00000004;
  vring *in_stack_00000008;
  vring local_40 [9];
  
  memset(local_40,0,0x20);
  if (in_stack_00000000 < 0x20) {
    vVar2 = (1 << (in_stack_00000000 & 0xff)) + -1;
  }
  else {
    vVar2 = -1;
  }
  vr[4] = vVar2;
  *vr = num;
  vr[1] = (vring)p;
  vr[2] = align;
  vr[3] = in_stack_00000000;
  vr[5] = in_stack_00000004;
  if (in_stack_00000008 == (vring *)0x0) {
    in_stack_00000008 = local_40;
  }
  vVar2 = in_stack_00000008[1];
  vVar1 = in_stack_00000008[2];
  vVar3 = in_stack_00000008[3];
  vr[6] = *in_stack_00000008;
  vr[7] = vVar2;
  vr[8] = vVar1;
  vr[9] = vVar3;
  vVar2 = in_stack_00000008[5];
  vVar1 = in_stack_00000008[6];
  vVar3 = in_stack_00000008[7];
  vr[10] = in_stack_00000008[4];
  vr[0xb] = vVar2;
  vr[0xc] = vVar1;
  vr[0xd] = vVar3;
  return;
}


