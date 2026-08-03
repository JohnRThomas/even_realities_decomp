/*
 * Function: log_source_name_get
 * Entry:    00050b7c
 * Prototype: char * __stdcall log_source_name_get(uint32_t domain_id, uint32_t source_id)
 */


/* exclude_from_export */

char * log_source_name_get(uint32_t domain_id,uint32_t source_id)

{
  char *pcVar1;
  
  if (source_id < 0x46) {
    pcVar1 = (&PTR_s_LSM6DSO_0008b820)[source_id * 2];
  }
  else {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}


