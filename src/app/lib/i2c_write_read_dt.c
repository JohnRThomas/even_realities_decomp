/*
 * Function: i2c_write_read_dt
 * Entry:    0008756a
 * Prototype: int __stdcall i2c_write_read_dt(i2c_dt_spec * spec, void * write_buf, size_t num_write, void * read_buf, size_t num_read)
 */


/* exclude_from_export_ai */

int i2c_write_read_dt(i2c_dt_spec *spec,void *write_buf,size_t num_write,void *read_buf,
                     size_t num_read)

{
  int iVar1;
  
  iVar1 = i2c_write_read((device *)spec,(uint16_t)write_buf,(void *)num_write,(size_t)read_buf,
                         &DAT_00000001,(size_t)write_buf);
  return iVar1;
}


