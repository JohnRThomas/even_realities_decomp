/*
 * Function: cJSON_ParseWithOpts
 * Entry:    0008879c
 * Prototype: cJSON * __stdcall cJSON_ParseWithOpts(char * value, char * * return_parse_end, cJSON_bool require_null_terminated)
 */


/* exclude_from_export_ai */

cJSON * cJSON_ParseWithOpts(char *value,char **return_parse_end,cJSON_bool require_null_terminated)

{
  size_t sVar1;
  cJSON *pcVar2;
  
  if (value != (char *)0x0) {
    sVar1 = strlen(value);
    pcVar2 = cJSON_ParseWithLengthOpts(value,sVar1 + 1,return_parse_end,require_null_terminated);
    return pcVar2;
  }
  return (cJSON *)0x0;
}


