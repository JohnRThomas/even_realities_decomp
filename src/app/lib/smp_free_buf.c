/*
 * Function: smp_free_buf
 * Entry:    000842c6
 * Prototype: void __stdcall smp_free_buf(void * buf, void * arg)
 */


/* exclude_from_export_ai */

void smp_free_buf(void *buf,void *arg)

{
  if (buf != (void *)0x0) {
    if (*(code **)((int)arg + 0x38) != (code *)0x0) {
      (**(code **)((int)arg + 0x38))((int)buf + 0x18);
    }
    net_buf_unref(buf);
    return;
  }
  return;
}


