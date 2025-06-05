file(GLOB_RECURSE srcs
    *.c
    ui/*.c
    ui/components/*.c
    ui/screens/*.c
)

set(include_dirs
    .
    ui
)

idf_component_register(
    SRCS ${srcs}
    INCLUDE_DIRS ${include_dirs}
    INCLUDE_DIRS "." "../config" # add this to make sure TinyUSB sees tusb_config.h
    REQUIRES esp_lcd_touch_gt911 lvgl tinyusb 
)
idf_component_get_property(tusb_lib espressif__tinyusb COMPONENT_LIB)
target_include_directories(${tusb_lib} PRIVATE path_to_your_tusb_config)

idf_component_get_property(lvgl_lib lvgl__lvgl COMPONENT_LIB)
target_compile_options(${lvgl_lib} PRIVATE -Wno-format)
