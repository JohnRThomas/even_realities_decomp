/*
 * Function: settings_nvs_load
 * Entry:    00051a20
 * Prototype: int __stdcall settings_nvs_load(settings_store * cs, settings_load_arg * arg)
 */


/* exclude_from_export_ai */

int settings_nvs_load(settings_store *cs,settings_load_arg *arg)

{
  ssize_t sVar1;
  size_t len;
  int iVar2;
  uint16_t id;
  uint16_t uVar3;
  uint16_t id_00;
  nvs_fs *fs;
  undefined1 uStack_75;
  nvs_fs *local_74;
  uint16_t local_70;
  char acStack_6c [76];
  
  fs = (nvs_fs *)(cs + 2);
  id_00 = (short)cs[0xe] + 1;
  do {
    while( true ) {
      uVar3 = id_00;
      id_00 = uVar3 - 1;
      if (id_00 == 0x8000) {
        return 0;
      }
      sVar1 = nvs_read(fs,id_00,acStack_6c,0x4a);
      id = uVar3 + 0x3fff;
      len = nvs_read(fs,id,&uStack_75,1);
      if (0 < sVar1) break;
      if (0 < (int)len) {
LAB_00051a78:
        if (*(uint16_t *)(cs + 0xe) == id_00) {
          *(uint16_t *)(cs + 0xe) = uVar3 - 2;
          nvs_write(fs,0x8000,cs + 0xe,2);
        }
        nvs_delete(fs,id_00);
        nvs_delete(fs,id);
      }
    }
    if ((int)len < 1) goto LAB_00051a78;
    acStack_6c[sVar1] = '\0';
    local_74 = fs;
    local_70 = id;
    iVar2 = settings_call_set_handler(acStack_6c,len,(settings_read_cb)0x829a9,&local_74,arg);
    if (iVar2 != 0) {
      return iVar2;
    }
  } while( true );
}


