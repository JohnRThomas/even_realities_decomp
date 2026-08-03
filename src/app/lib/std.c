/*
 * Function: std
 * Entry:    00079df0
 * Prototype: void __stdcall std(FILE * ptr, int flags, int file)
 */


/* exclude_from_export */

void std(FILE *ptr,int flags,int file)

{
  ptr->_IO_read_end = (char *)0x0;
  *(short *)&ptr->_IO_read_base = (short)flags;
  ptr->__pad4 = (void *)0x0;
  *(short *)((int)&ptr->_IO_read_base + 2) = (short)file;
  ptr->_IO_write_end = (char *)0x0;
  ptr->_flags = 0;
  ptr->_IO_read_ptr = (char *)0x0;
  ptr->_IO_write_base = (char *)0x0;
  ptr->_IO_write_ptr = (char *)0x0;
  memset(&ptr->__pad2,0,8);
  ptr->_IO_buf_end = (char *)ptr;
  ptr->_IO_save_base = (char *)0x8a6e5;
  ptr->_IO_backup_base = (char *)0x8a70b;
  ptr->_IO_save_end = (char *)0x8a743;
  ptr->_markers = (_IO_marker *)0x8a767;
  return;
}


