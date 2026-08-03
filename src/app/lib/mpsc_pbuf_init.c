/*
 * Function: mpsc_pbuf_init
 * Entry:    0004eec8
 * Prototype: void __stdcall mpsc_pbuf_init(mpsc_pbuf_buffer * buffer, mpsc_pbuf_buffer_config * config)
 */


/* exclude_from_export_ai */

void mpsc_pbuf_init(mpsc_pbuf_buffer *buffer,mpsc_pbuf_buffer_config *config)

{
  int iVar1;
  dword dVar2;
  uint uVar3;
  
  memset(buffer,0,0x20);
  buffer->get_wlen = (undefined *)config[3];
  buffer->notify_drop = (undefined *)config[2];
  buffer->buf = (undefined *)*config;
  uVar3 = config[1];
  buffer->max_usage = 0;
  buffer->size = uVar3;
  dVar2 = config[4];
  if ((uVar3 != 0) && ((uVar3 - 1 & uVar3) == 0)) {
    dVar2 = dVar2 | 1;
  }
  buffer->flags = dVar2;
  iVar1 = z_impl_k_sem_init(&buffer->sem,0,1);
  if (iVar1 != 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0","WEST_TOPDIR/zephyr/lib/os/mpsc_pbuf.c",46);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  return;
}


