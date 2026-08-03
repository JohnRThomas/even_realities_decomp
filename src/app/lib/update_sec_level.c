/*
 * Function: update_sec_level
 * Entry:    000845f0
 * Prototype: bool __stdcall update_sec_level(bt_conn * conn)
 */


/* exclude_from_export_ai */

bool update_sec_level(bt_conn *conn)

{
  byte bVar1;
  undefined *puVar2;
  
  puVar2 = (conn->le).keys;
  if ((puVar2 == (undefined *)0x0) || (-1 < (int)((uint)(byte)puVar2[0xd] << 0x1f))) {
    bVar1 = 2;
  }
  else if ((int)((uint)(byte)puVar2[0xd] << 0x1b) < 0) {
    if (puVar2[0xc] == '\x10') {
      bVar1 = 4;
    }
    else {
      bVar1 = 3;
    }
  }
  else {
    bVar1 = 3;
  }
  conn->sec_level = bVar1;
  return conn->required_sec_level <= bVar1;
}


