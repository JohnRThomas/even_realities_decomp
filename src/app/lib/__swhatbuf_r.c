/*
 * Function: __swhatbuf_r
 * Entry:    0008a32e
 * Prototype: undefined4 __stdcall __swhatbuf_r(int * param_1, int param_2, undefined4 * param_3, uint * param_4)
 */


/* exclude_from_export */

undefined4 __swhatbuf_r(int *param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  stat sStack_68;
  
  if ((*(short *)(param_2 + 0xe) < 0) ||
     (iVar1 = _fstat_r(param_1,(int)*(short *)(param_2 + 0xe),&sStack_68), iVar1 < 0)) {
    uVar2 = 0;
    if ((*(ushort *)(param_2 + 0xc) & 0x80) == 0) {
      uVar3 = 0x400;
    }
    else {
      uVar3 = 0x40;
    }
  }
  else {
    uVar2 = (uint)((sStack_68.st_dev._4_4_ & 0xf000) == 0x2000);
    uVar3 = 0x400;
  }
  *param_4 = uVar2;
  *param_3 = uVar3;
  return 0;
}


