/*
 * Function: bound_cb
 * Entry:    0005019c
 * Prototype: void __stdcall bound_cb(void * priv)
 */


/* exclude_from_export_ai */

void bound_cb(void *priv)

{
  if (priv != (void *)0x0) {
    rpmsg_send_offchannel_raw
              ((int)priv,*(undefined4 *)((int)priv + 0x24),*(int *)((int)priv + 0x28),
               (int)&DAT_000aad90,0);
  }
  if ((code *)**(undefined4 **)((int)priv + 0x68) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000501c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)**(undefined4 **)((int)priv + 0x68))(*(undefined4 *)((int)priv + 0x6c));
    return;
  }
  return;
}


