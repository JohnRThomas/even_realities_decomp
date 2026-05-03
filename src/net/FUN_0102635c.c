/*
 * Function: FUN_0102635c
 * Entry:    0102635c
 * Prototype: undefined __stdcall FUN_0102635c(void)
 */


void FUN_0102635c(void)

{
  Peripherals::RADIO_NS.PUBLISH_READY = 0x80000004;
  Peripherals::RADIO_NS.PUBLISH_ADDRESS = 0x80000005;
  Peripherals::RADIO_NS.PUBLISH_END = 0x80000006;
  Peripherals::RADIO_NS.PUBLISH_DISABLED = 0x80000007;
  Peripherals::RADIO_NS.PUBLISH_PHYEND = 0x8000000c;
  Peripherals::RADIO_NS.SUBSCRIBE_DISABLE = 0x8000000b;
  return;
}


