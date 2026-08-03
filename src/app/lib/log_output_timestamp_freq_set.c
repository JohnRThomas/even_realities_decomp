/*
 * Function: log_output_timestamp_freq_set
 * Entry:    00051160
 * Prototype: void __stdcall log_output_timestamp_freq_set(uint32_t freq)
 */


/* exclude_from_export */

void log_output_timestamp_freq_set(uint32_t freq)

{
  bool bVar1;
  
  bVar1 = false;
  DAT_2000aac0 = 1;
  for (; " gyroscope full-scale\r\n" < freq; freq = freq >> 1) {
    bVar1 = true;
    DAT_2000aac0 = DAT_2000aac0 << 1;
  }
  if (!bVar1) {
    DAT_2000aac0 = 1;
  }
  DAT_2000aac4 = (char *)freq;
  return;
}


