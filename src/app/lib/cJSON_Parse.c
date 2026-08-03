/*
 * Function: cJSON_Parse
 * Entry:    000887bc
 * Prototype: cJSON * __stdcall cJSON_Parse(char * value)
 */


/* exclude_from_export_ai */

cJSON * cJSON_Parse(char *value)

{
  cJSON *pcVar1;
  
  pcVar1 = cJSON_ParseWithOpts(value,(char **)0x0,0);
  return pcVar1;
}


