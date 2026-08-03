/*
 * Function: signal_poll_event
 * Entry:    00089f8a
 * Prototype: int __stdcall signal_poll_event(k_poll_event * event, uint32_t state)
 */


/* exclude_from_export */

int signal_poll_event(k_poll_event *event,uint32_t state)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  k_work_q *queue;
  
  pbVar3 = event->poller;
  if (pbVar3 == (byte *)0x0) goto LAB_00089fa8;
  if (pbVar3[1] == 1) {
    bVar1 = pbVar3[-0x53] & 2;
    if ((pbVar3[-0x53] & 2) != 0) {
      if (*(int *)(pbVar3 + -0x34) == -1 && *(int *)(pbVar3 + -0x38) == -2) {
        *pbVar3 = 0;
        return -0xb;
      }
      z_unpend_thread((k_poll_event *)(pbVar3 + -0x60),state);
      if (state == 8) {
        uVar2 = 0xfffffffc;
      }
      else {
        uVar2 = 0;
      }
      *(undefined4 *)(pbVar3 + 0x30) = uVar2;
      if (((pbVar3[-0x53] & 0x1f) != 0) || (*(int *)(pbVar3 + -0x48) != 0)) goto LAB_00089ffe;
      z_ready_thread((k_thread *)(pbVar3 + -0x60));
LAB_00089ff6:
      *pbVar3 = 0;
      goto LAB_00089fa8;
    }
  }
  else {
    if (pbVar3[1] == 2) {
      if (*pbVar3 == 0) goto LAB_00089fa8;
      queue = *(k_work_q **)(pbVar3 + -4);
      if (queue != (k_work_q *)0x0) {
        z_abort_timeout((_timeout *)(pbVar3 + 0x14));
        pbVar3[0x2c] = 0;
        pbVar3[0x2d] = 0;
        pbVar3[0x2e] = 0;
        pbVar3[0x2f] = 0;
        z_work_submit_to_queue(queue,(k_work *)(pbVar3 + -0x14));
        *pbVar3 = 0;
        goto LAB_00089fa8;
      }
      goto LAB_00089ff6;
    }
LAB_00089ffe:
    bVar1 = 0;
  }
  *pbVar3 = bVar1;
LAB_00089fa8:
  event->poller = (undefined *)0x0;
  event->tag = event->tag & 0xffe03fff | (state & 0x7f | (event->tag & 0x1fffff) >> 0xe) << 0xe;
  return 0;
}


