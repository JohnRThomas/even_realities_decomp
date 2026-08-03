/*
 * Function: cJSON_CreateNumber
 * Entry:    00012b70
 * Prototype: cJSON * __stdcall cJSON_CreateNumber(double num)
 */


/* exclude_from_export_ai */

cJSON * cJSON_CreateNumber(double num)

{
  bool bVar1;
  cJSON *item;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = SUB84(num,0);
  uVar4 = (uint)((ulonglong)num >> 0x20);
  item = cJSON_New_Item((cjson_internal_hooks *)cjson_global_hooks.allocate);
  if (item != (cJSON *)0x0) {
    *(double *)((int)&item->valueint + 4) = num;
    item->type = 8;
    bVar1 = __aeabi_dcmpge(uVar2,uVar4,0xffc00000,0x41dfffff);
    if (bVar1) {
      uVar3 = 0x7fffffff;
    }
    else {
      bVar1 = __ledf2(uVar2,uVar4,0,0xc1e00000);
      if (!bVar1) {
        uVar2 = _cast_double_to_int(uVar2,uVar4);
        *(uint *)&item->valueint = uVar2;
        return item;
      }
      uVar3 = 0x80000000;
    }
    *(undefined4 *)&item->valueint = uVar3;
  }
  return item;
}


