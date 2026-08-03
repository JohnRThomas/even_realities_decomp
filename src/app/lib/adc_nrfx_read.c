/*
 * Function: adc_nrfx_read
 * Entry:    00062a0c
 * Prototype: int __stdcall adc_nrfx_read(device * dev, adc_sequence * sequence)
 */


/* exclude_from_export */

int adc_nrfx_read(device *dev,adc_sequence *sequence)

{
  byte bVar1;
  longlong lVar2;
  log_msg_desc desc;
  log_msg_desc desc_00;
  log_msg_desc desc_01;
  uint extraout_r0;
  int iVar3;
  uint uVar4;
  uint extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar5;
  undefined4 extraout_r1_01;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  k_timeout_t timeout;
  k_timeout_t duration;
  k_timeout_t timeout_00;
  dword in_stack_ffffffa8;
  uint8_t *in_stack_ffffffac;
  void *in_stack_ffffffb0;
  undefined4 local_40;
  char *local_3c;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_20;
  char *local_1c;
  
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = sequence;
  z_impl_k_sem_take((k_sem *)&DAT_200021d0,timeout);
  uVar9 = sequence[1];
  if (uVar9 - 1 < 0xff) {
    uVar4 = 0;
    uVar6 = 0;
    do {
      if ((uVar9 >> (uVar4 & 0xff) & 1) == 0) {
        *(undefined4 *)(&Peripherals::SAADC_S.field_0x510 + uVar4 * 0x10) = 0;
      }
      else {
        bVar1 = (&DAT_20002230)[uVar4];
        if (bVar1 == 0) {
          local_3c = "Channel %u not configured";
          goto LAB_00062a72;
        }
        *(uint *)(&Peripherals::SAADC_S.field_0x518 + uVar4 * 0x10) =
             *(uint *)(&Peripherals::SAADC_S.field_0x518 + uVar4 * 0x10) & 0xfeffffff |
             (uint)(*(char *)((int)sequence + 0x11) != '\0') << 0x18;
        *(uint *)(&Peripherals::SAADC_S.field_0x510 + uVar4 * 0x10) = (uint)bVar1;
        uVar6 = uVar6 + 1 & 0xff;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != 8);
    switch((char)sequence[4]) {
    case '\b':
      uVar9 = 0;
      break;
    default:
      local_3c = "ADC resolution value %d is not valid";
      goto LAB_00062a72;
    case '\n':
      uVar9 = 1;
      break;
    case '\f':
      uVar9 = 2;
      break;
    case '\x0e':
      uVar9 = 3;
    }
    Peripherals::SAADC_S.RESOLUTION = uVar9;
    uVar9 = (uint)*(byte *)((int)sequence + 0x11);
    if (1 < uVar6) {
      if (uVar9 != 0) {
        local_1c = "Oversampling is supported for single channel only";
        goto LAB_00062a2e;
      }
LAB_00062b20:
      Peripherals::SAADC_S.OVERSAMPLE = uVar9;
      uVar9 = uVar6 * 2;
      if (*sequence != 0) {
        uVar9 = *(ushort *)(*sequence + 0xc) * uVar9 + uVar9;
      }
      if ((uint)sequence[3] < uVar9) {
        local_3c = "Provided buffer is too small (%u/%u)";
        local_40 = 4;
        desc.level = (dword)&local_40;
        desc.domain = 0x2040;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = in_stack_ffffffa8;
        z_impl_z_log_msg_static_create
                  (&PTR_s_adc_nrfx_saadc_0008b890,desc,in_stack_ffffffac,in_stack_ffffffb0);
        iVar8 = -0xc;
        goto LAB_00062a82;
      }
      DAT_5000e62c = sequence[2];
      DAT_5000e630 = uVar6;
      DAT_20002204 = (undefined4 *)*sequence;
      DAT_20002208 = sequence[1];
      DAT_2000220c = sequence[2];
      DAT_20002210 = sequence[3];
      DAT_20002214 = sequence[4];
      DAT_20002200 = 0;
      puVar7 = (uint *)*sequence;
      if (puVar7 == (uint *)0x0) {
LAB_00062bf4:
        adc_context_start_sampling((adc_context *)&DAT_20002190);
        uVar5 = extraout_r1_01;
      }
      else {
        DAT_20002218 = *puVar7;
        DAT_2000221c = puVar7[1];
        DAT_20002220 = puVar7[2];
        DAT_20002224 = puVar7[3];
        DAT_20002204 = &DAT_20002218;
        DAT_20002228 = 0;
        if (DAT_20002218 == 0) goto LAB_00062bf4;
        DAT_20002190 = 0;
        lVar2 = (ulonglong)DAT_20002218 * 0x8000 + 999999;
        __aeabi_uldivmod((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),1000000,0);
        duration.ticks._4_4_ = 0;
        duration.ticks._0_4_ = extraout_r1;
        k_timer_start((k_timer *)&DAT_20002198,duration,
                      (k_timeout_t)((ulonglong)extraout_r0 << 0x20));
        uVar5 = extraout_r1_00;
      }
      timeout_00.ticks._4_4_ = 0xffffffff;
      timeout_00.ticks._0_4_ = uVar5;
      iVar3 = z_impl_k_sem_take((k_sem *)&DAT_200021e8,timeout_00);
      iVar8 = DAT_20002200;
      if (iVar3 != 0) {
        iVar8 = iVar3;
        DAT_20002200 = iVar3;
      }
      goto LAB_00062a82;
    }
    if (uVar9 < 9) goto LAB_00062b20;
    local_3c = "Oversampling value %d is not valid";
LAB_00062a72:
    local_40 = 3;
    desc_00.level = (dword)&local_40;
    desc_00.domain = 0x1840;
    desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_00.data_len = in_stack_ffffffa8;
    z_impl_z_log_msg_static_create
              (&PTR_s_adc_nrfx_saadc_0008b890,desc_00,in_stack_ffffffac,in_stack_ffffffb0);
  }
  else {
    local_1c = "Invalid selection of channels";
LAB_00062a2e:
    local_20 = 2;
    desc_01.level = (dword)&local_20;
    desc_01.domain = 0x1040;
    desc_01.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_01.data_len = in_stack_ffffffc8;
    z_impl_z_log_msg_static_create
              (&PTR_s_adc_nrfx_saadc_0008b890,desc_01,in_stack_ffffffcc,in_stack_ffffffd0);
  }
  iVar8 = -0x16;
LAB_00062a82:
  k_sem_give((k_sem *)&DAT_200021d0);
  return iVar8;
}


