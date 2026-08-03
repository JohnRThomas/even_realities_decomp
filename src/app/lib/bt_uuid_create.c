/*
 * Function: bt_uuid_create
 * Entry:    00084552
 * Prototype: bool __stdcall bt_uuid_create(bt_uuid * uuid, uint8_t * data, uint8_t data_len)
 */


/* exclude_from_export */

bool bt_uuid_create(bt_uuid *uuid,uint8_t *data,uint8_t data_len)

{
  bt_uuid *pbVar1;
  uint8_t *puVar2;
  uint8_t *puVar3;
  
  if (data_len == '\x04') {
    uuid->type = '\x01';
    *(undefined4 *)(uuid + 4) = *(undefined4 *)data;
  }
  else if (data_len == '\x10') {
    uuid->type = '\x02';
    pbVar1 = uuid + 1;
    puVar3 = data;
    do {
      puVar2 = puVar3 + 4;
      *(undefined4 *)pbVar1 = *(undefined4 *)puVar3;
      pbVar1 = pbVar1 + 4;
      puVar3 = puVar2;
    } while (puVar2 != data + 0x10);
  }
  else {
    if (data_len != '\x02') {
      return false;
    }
    uuid->type = '\0';
    *(undefined2 *)(uuid + 2) = *(undefined2 *)data;
  }
  return true;
}


