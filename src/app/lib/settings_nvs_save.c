/*
 * Function: settings_nvs_save
 * Entry:    000829c0
 * Prototype: int __stdcall settings_nvs_save(settings_store * cs, char * name, char * value, size_t val_len)
 */


/* exclude_from_export_ai */

int settings_nvs_save(settings_store *cs,char *name,char *value,size_t val_len)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ssize_t sVar4;
  int iVar5;
  uint uVar6;
  size_t len;
  uint16_t id;
  uint16_t uVar7;
  uint16_t uVar8;
  nvs_fs *pnVar9;
  char acStack_74 [80];
  
  if (name == (char *)0x0) {
    return -0x16;
  }
  bVar1 = value == (char *)0x0;
  bVar2 = val_len == 0;
  bVar3 = bVar1 || bVar2;
  pnVar9 = (nvs_fs *)(cs + 2);
  id = (short)cs[0xe] + 1;
  uVar8 = id;
  do {
    while( true ) {
      uVar7 = id;
      id = uVar7 - 1;
      if (id == 0x8000) {
        if (bVar1 || bVar2) {
          return 0;
        }
        bVar3 = true;
        id = uVar8;
        goto LAB_00082a7a;
      }
      sVar4 = nvs_read(pnVar9,id,acStack_74,0x4a);
      if (-1 < sVar4) break;
      if (sVar4 == -2) {
        uVar8 = id;
      }
    }
    acStack_74[sVar4] = '\0';
    iVar5 = strcmp(name,acStack_74);
  } while (iVar5 != 0);
  if (bVar1 || bVar2) {
    if (*(uint16_t *)(cs + 0xe) == id) {
      *(uint16_t *)(cs + 0xe) = uVar7 - 2;
      sVar4 = nvs_write(pnVar9,0x8000,cs + 0xe,2);
      if (sVar4 < 0) {
        return sVar4;
      }
    }
    iVar5 = nvs_delete(pnVar9,id);
    if (iVar5 < 0) {
      return iVar5;
    }
    uVar6 = nvs_delete(pnVar9,uVar7 + 0x3fff);
  }
  else {
LAB_00082a7a:
    if (id == 0xc000) {
      return -0xc;
    }
    pnVar9 = (nvs_fs *)(cs + 2);
    sVar4 = nvs_write(pnVar9,id + 0x4000,value,val_len);
    if (sVar4 < 0) {
      return sVar4;
    }
    if (bVar3) {
      len = strlen(name);
      sVar4 = nvs_write(pnVar9,id,name,len);
      if (sVar4 < 0) {
        return sVar4;
      }
    }
    if (id <= *(ushort *)(cs + 0xe)) {
      return 0;
    }
    *(uint16_t *)(cs + 0xe) = id;
    uVar6 = nvs_write(pnVar9,0x8000,cs + 0xe,2);
  }
  return uVar6 & (int)uVar6 >> 0x1f;
}


