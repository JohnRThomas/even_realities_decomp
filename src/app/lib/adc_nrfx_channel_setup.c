/*
 * Function: adc_nrfx_channel_setup
 * Entry:    00062900
 * Prototype: int __stdcall adc_nrfx_channel_setup(device * dev, adc_channel_cfg * channel_cfg)
 */


/* exclude_from_export */

int adc_nrfx_channel_setup(device *dev,adc_channel_cfg *channel_cfg)

{
  ushort uVar1;
  log_msg_desc desc;
  int iVar2;
  adc_gain uVar6;
  uint uVar3;
  int iVar4;
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 local_18;
  char *local_14;
  
  uVar3 = channel_cfg->channel_id;
  if (7 < uVar3) {
    return -0x16;
  }
  _uVar6 = (uint)channel_cfg->gain;
  switch(_uVar6) {
  case 0:
  case 1:
  case 2:
  case 3:
    break;
  default:
    local_14 = "Selected ADC gain is not valid";
    goto LAB_00062942;
  case 5:
    _uVar6 = 4;
    break;
  case 8:
    _uVar6 = 5;
    break;
  case 9:
    _uVar6 = 6;
    break;
  case 0xb:
    _uVar6 = 7;
  }
  if (channel_cfg->reference == ADC_REF_VDD_1_4) {
    iVar4 = 1;
  }
  else {
    if (channel_cfg->reference != ADC_REF_INTERNAL) {
      local_14 = "Selected ADC reference is not valid";
      goto LAB_00062942;
    }
    iVar4 = 0;
  }
  uVar1 = channel_cfg->acquisition_time;
  if (uVar1 != 0x400a) {
    if (uVar1 < 0x400b) {
      if (uVar1 == 0x4003) {
        iVar2 = 0;
        goto LAB_000629a4;
      }
      if (uVar1 == 0x4005) {
        iVar2 = 1;
        goto LAB_000629a4;
      }
      if (uVar1 == 0) goto LAB_000629ea;
    }
    else {
      if (uVar1 == 0x4014) {
        iVar2 = 4;
        goto LAB_000629a4;
      }
      if (uVar1 == 0x4028) {
        iVar2 = 5;
        goto LAB_000629a4;
      }
      if (uVar1 == 0x400f) {
        iVar2 = 3;
        goto LAB_000629a4;
      }
    }
    local_14 = "Selected ADC acquisition time is not valid";
LAB_00062942:
    local_18 = 2;
    desc.level = (dword)&local_18;
    desc.domain = 0x1040;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffffd8;
    z_impl_z_log_msg_static_create
              (&PTR_s_adc_nrfx_saadc_0008b890,desc,in_stack_ffffffdc,in_stack_ffffffe0);
    return -0x16;
  }
LAB_000629ea:
  iVar2 = 2;
LAB_000629a4:
  *(uint *)(&Peripherals::SAADC_S.field_0x518 + uVar3 * 0x10) =
       _uVar6 << 8 | channel_cfg->differential << 0x14 | iVar4 << 0xc | iVar2 << 0x10;
  *(uint *)(&Peripherals::SAADC_S.field_0x514 + uVar3 * 0x10) = (uint)channel_cfg->input_negative;
  *(undefined4 *)(&Peripherals::SAADC_S.field_0x510 + uVar3 * 0x10) = 0;
  (&DAT_20002230)[uVar3] = channel_cfg->input_positive;
  return 0;
}


