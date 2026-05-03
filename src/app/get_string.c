/*
 * Function: get_string
 * Entry:    00080aa6
 * Prototype: char * __stdcall get_string(uint string_id)
 */


char * get_string(uint string_id)

{
  byte language;
  char *pcVar1;
  
  language = get_current_language();
  if (language < 0xf) {
    if ((0x40e4U >> language & 1) == 0) {
      language = 2;
    }
  }
  else {
    language = 2;
  }
  pcVar1 = get_string_in_language(language,string_id);
  return pcVar1;
}


