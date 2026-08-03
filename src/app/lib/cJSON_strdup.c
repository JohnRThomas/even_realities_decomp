/*
 * Function: cJSON_strdup
 * Entry:    000678e8
 * Prototype: uchar * __stdcall cJSON_strdup(uchar * string, cjson_internal_hooks * hooks)
 */


/* exclude_from_export_ai */

uchar * cJSON_strdup(uchar *string,cjson_internal_hooks *hooks)

{
  size_t sVar1;
  uchar *d;
  
  if (string != (uchar *)0x0) {
    sVar1 = strlen((char *)string);
    d = (*cjson_global_hooks.allocate)(sVar1 + 1);
    if (d != (uchar *)0x0) {
      memcpy(d,string,sVar1 + 1);
      return d;
    }
  }
  return (uchar *)0x0;
}


