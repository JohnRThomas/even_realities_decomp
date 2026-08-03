/*
 * Function: settings_nvs_src
 * Entry:    00051660
 * Prototype: int __stdcall settings_nvs_src(settings_nvs * cf)
 */


/* exclude_from_export */

int settings_nvs_src(settings_nvs *cf)

{
  cf->cf_store = 0;
  if (DAT_2000aae8 == (settings_nvs *)0x0) {
    DAT_2000aae4 = cf;
    DAT_2000aae8 = cf;
    return (int)cf;
  }
  *(settings_nvs **)DAT_2000aae8 = cf;
  DAT_2000aae8 = cf;
  return (int)cf;
}


