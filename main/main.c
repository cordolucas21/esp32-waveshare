#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "waveshare_rgb_lcd_port.h"
#include "ui.h"
#include "tusb.h"


void app_main(void)
{
    ESP_LOGI(TAG, "Initializing Waveshare RGB LCD...");
    waveshare_esp32_s3_rgb_lcd_init();

    ESP_LOGI(TAG, "Initializing TinyUSB stack...");
    tusb_init();

    ESP_LOGI(TAG, "Initializing LVGL UI...");
    // Lock lvgl port because LVGL APIs are not thread-safe
    if (lvgl_port_lock(-1)) {
        ui_init();
        lvgl_port_unlock();
    }

    ESP_LOGI(TAG, "Setup complete, entering main loop...");

    // Your main loop, if needed (or let FreeRTOS run)
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000)); // Idle delay
    }
}
