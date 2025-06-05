
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define CFG_TUSB_MCU                OPT_MCU_ESP32S3
#define CFG_TUSB_OS                 OPT_OS_FREERTOS
#define CFG_TUSB_RHPORT0_MODE       OPT_MODE_DEVICE
#define CFG_TUSB_DEBUG              0

#define CFG_TUSB_MEM_SECTION
#define CFG_TUSB_MEM_ALIGN          __attribute__ ((aligned(4)))

#define CFG_TUD_ENDPOINT0_SIZE      64

#define CFG_TUD_HID                 1
#define CFG_TUD_HID_EP_BUFSIZE      16

#ifdef __cplusplus
}
#endif
