/*
 * Function: chan_tx_complete
 * Entry:    00085a74
 * Prototype: void __stdcall chan_tx_complete(bt_conn * conn, void * user_data, int err)
 */


/* exclude_from_export_ai */

void chan_tx_complete(bt_conn *conn,void *user_data,int err)

{
  ushort uVar1;
  ushort uVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  if (err == 0) {
    tx_meta_data(conn,user_data);
    pcVar3 = *(code **)((int)user_data + 8);
    uVar1 = *(ushort *)((int)user_data + 4);
    uVar4 = *(undefined4 *)((int)user_data + 0xc);
    tx_meta_data_free(user_data);
    uVar2 = 0;
    if (pcVar3 != (code *)0x0) {
      for (; uVar2 < uVar1; uVar2 = uVar2 + 1) {
        (*pcVar3)(conn,uVar4);
      }
    }
    return;
  }
  tx_meta_data_free(user_data);
  return;
}


