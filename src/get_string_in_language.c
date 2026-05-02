/*
 * Function: get_string_in_language
 * Entry:    00047dbc
 * Prototype: char * __stdcall get_string_in_language(byte language, uint string_id)
 */


char * get_string_in_language(byte language,uint string_id)

{
  undefined **ppuVar1;
  
  if (string_id < 0x61) {
    switch(language) {
    case 1:
      ppuVar1 = &PTR_s__0008e4a8;
      break;
    default:
      ppuVar1 = &PTR_s_English_0008e62c;
      break;
    case 3:
      ppuVar1 = &PTR_s__0008dd14;
      break;
    case 4:
      ppuVar1 = &PTR_s__0008db90;
      break;
    case 5:
      ppuVar1 = &PTR_s_Fran_ais_0008e01c;
      break;
    case 6:
      ppuVar1 = &PTR_s_Deutsch_0008e324;
      break;
    case 7:
      ppuVar1 = &PTR_s_Espa_ol_0008e1a0;
      break;
    case 0xe:
      ppuVar1 = &PTR_s_Italiano_0008de98;
    }
    return ppuVar1[string_id];
  }
  return "ERR_STRING";
}


