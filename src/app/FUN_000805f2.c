/*
 * Function: FUN_000805f2
 * Entry:    000805f2
 * Prototype: undefined4 __stdcall FUN_000805f2(int param_1, st25dv_context * param_2, undefined4 * param_3, uint * param_4)
 */


/* WARNING: Removing unreachable block (ram,0x00027b04) */
/* WARNING: Removing unreachable block (ram,0x00027b22) */
/* WARNING: Removing unreachable block (ram,0x00027b38) */
/* WARNING: Removing unreachable block (ram,0x00027b16) */

undefined4 FUN_000805f2(int param_1,st25dv_context *param_2,undefined4 *param_3,uint *param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  char cVar3;
  uint n;
  byte *pbVar4;
  uint uVar5;
  byte *d;
  int iVar6;
  
  if ((((param_2 == (st25dv_context *)0x0) || (param_3 == (undefined4 *)0x0)) ||
      (param_4 == (uint *)0x0)) || (param_1 == 2)) {
    uVar2 = 0xffffffff;
  }
  else {
    if (param_1 == 0) {
      if (((param_2 == (st25dv_context *)0x0) || (param_3 == (undefined4 *)0x0)) ||
         (param_4 == (uint *)0x0)) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar5 = __eeprom_st25dv_read(param_2,0x2006,&stack0xffffffeb,1);
        if (uVar5 == 0) {
          uVar2 = 0xfffffffd;
        }
        else {
          printk("eeprom_st25dv_read ST25DV_REG_MB_CTRL_DYN is failed\n");
          uVar2 = 0xfffffffe;
        }
      }
      return uVar2;
    }
    if (param_1 == 1) {
      if (((param_2 == (st25dv_context *)0x0) || (param_3 == (undefined4 *)0x0)) ||
         (param_4 == (uint *)0x0)) {
        uVar2 = 0xffffffff;
      }
      else {
        if (DAT_2001adf7 != 0) {
          uVar5 = 0;
          do {
            if (((((&DAT_2001adf8)[uVar5] == 'Z') && ((&DAT_2001adf9)[uVar5] == -0x5b)) &&
                ((&DAT_2001adfa)[uVar5] == '\x7f')) &&
               (n = (uint)(byte)(&DAT_2001adfb)[uVar5], (int)(n + 4) < (int)(0x100 - uVar5))) {
              cVar3 = '\0';
              iVar6 = 0;
              pcVar1 = &DAT_2001adf8 + uVar5;
              do {
                iVar6 = iVar6 + 1;
                cVar3 = cVar3 + *pcVar1;
                pcVar1 = pcVar1 + 1;
              } while (iVar6 <= (int)(n + 3));
              if ((&DAT_2001adfc)[n + uVar5] == cVar3) {
                d = (byte *)*param_3;
                memcpy(d,&DAT_2001adfc + uVar5,n);
                *param_4 = n;
                printk("use read_serial_data:");
                pbVar4 = d + n;
                for (; pbVar4 != d; d = d + 1) {
                  printk("%02x ",(uint)*d);
                }
                printk("\n");
                if ((int)uVar5 <= (int)(0x100 - (uint)DAT_2001adf7)) {
                  DAT_2001adf7 = 0;
                  return 0;
                }
LAB_00034c0a:
                DAT_2001adf7 = 0;
                printk("Err:serial recv data does not meet the protocol\n");
                return 0xfffffffd;
              }
            }
            uVar5 = uVar5 + 1 & 0xffff;
            if ((int)(0x100 - (uint)DAT_2001adf7) < (int)uVar5) goto LAB_00034c0a;
          } while( true );
        }
        uVar2 = 0xfffffffe;
      }
      return uVar2;
    }
    uVar2 = 0;
  }
  return uVar2;
}


