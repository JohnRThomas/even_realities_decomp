/*
 * Function: __swsetup_r
 * Entry:    0007affc
 * Prototype: int __stdcall __swsetup_r(int * param_1, int * param_2)
 */


/* exclude_from_export */

int __swsetup_r(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  _IO_FILE *p_Var2;
  char *pcVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  
  puVar1 = _REENT;
  if ((_REENT != (undefined4 *)0x0) && (_REENT[6] == 0)) {
    __sinit(_REENT);
  }
  if (param_2 == (int *)&DAT_0009c2ac) {
    param_2 = (int *)puVar1[1];
  }
  else if (param_2 == (int *)&DAT_0009c28c) {
    param_2 = (int *)puVar1[2];
  }
  else if (param_2 == (int *)&DAT_0009c26c) {
    param_2 = (int *)puVar1[3];
  }
  uVar4 = *(ushort *)&((FILE *)param_2)->_IO_read_base;
  iVar5 = (int)(short)uVar4;
  if (-1 < iVar5 << 0x1c) {
    if (-1 < iVar5 << 0x1b) {
      *param_1 = 9;
      goto LAB_0007b02a;
    }
    if (iVar5 << 0x1d < 0) {
      p_Var2 = ((FILE *)param_2)->_chain;
      if (p_Var2 != (_IO_FILE *)0x0) {
        if (p_Var2 != (_IO_FILE *)&((FILE *)param_2)->_cur_column) {
          _free_r(param_1,(int)p_Var2);
        }
        ((FILE *)param_2)->_chain = (_IO_FILE *)0x0;
      }
      *(ushort *)&((FILE *)param_2)->_IO_read_base =
           *(ushort *)&((FILE *)param_2)->_IO_read_base & 0xffdb;
      ((FILE *)param_2)->_IO_read_ptr = (char *)0x0;
      ((FILE *)param_2)->_flags = (int)((FILE *)param_2)->_IO_write_base;
    }
    *(ushort *)&((FILE *)param_2)->_IO_read_base = *(ushort *)&((FILE *)param_2)->_IO_read_base | 8;
  }
  if ((((FILE *)param_2)->_IO_write_base == (char *)0x0) &&
     (((uint)((FILE *)param_2)->_IO_read_base & 0x280) != 0x200)) {
    __smakebuf_r(param_1,(FILE *)param_2);
  }
  uVar4 = *(ushort *)&((FILE *)param_2)->_IO_read_base;
  uVar6 = (uint)(short)uVar4;
  if ((uVar6 & 1) == 0) {
    pcVar3 = (char *)0x0;
    if (-1 < (int)(uVar6 << 0x1e)) {
      pcVar3 = ((FILE *)param_2)->_IO_write_ptr;
    }
    ((FILE *)param_2)->_IO_read_end = pcVar3;
  }
  else {
    ((FILE *)param_2)->_IO_read_end = (char *)0x0;
    ((FILE *)param_2)->_IO_write_end = (char *)-(int)((FILE *)param_2)->_IO_write_ptr;
  }
  if (((FILE *)param_2)->_IO_write_base != (char *)0x0) {
    return 0;
  }
  if ((uVar6 & 0x80) == 0) {
    return 0;
  }
LAB_0007b02a:
  *(ushort *)&((FILE *)param_2)->_IO_read_base = uVar4 | 0x40;
  return -1;
}


