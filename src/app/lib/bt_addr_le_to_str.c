/*
 * Function: bt_addr_le_to_str
 * Entry:    00055f88
 * Prototype: int __stdcall bt_addr_le_to_str(bt_addr_le_t * addr, char * str, size_t len)
 */


/* exclude_from_export */

int bt_addr_le_to_str(bt_addr_le_t *addr,char *str,size_t len)

{
  char *s;
  char acStack_1c [16];
  
  switch(addr->type) {
  case '\0':
    s = "public";
    break;
  case '\x01':
    s = "random";
    break;
  case '\x02':
    s = "public-id";
    break;
  case '\x03':
    s = "random-id";
    break;
  default:
    snprintk(acStack_1c,10,"0x%02x");
    goto LAB_00055fa6;
  }
  strcpy(acStack_1c,s);
LAB_00055fa6:
  snprintk(&DAT_2001e1c6,0x1e,"%02X:%02X:%02X:%02X:%02X:%02X (%s)",(uint)(addr->a).val[5],
           (uint)(addr->a).val[4],(uint)(addr->a).val[3],(uint)(addr->a).val[2],
           (uint)(addr->a).val[1],(uint)(addr->a).val[0],acStack_1c);
  return 0x2001e1c6;
}


