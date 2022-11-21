#include <stdint.h>

#define WIDTH 1920
#define HEIGHT 1080

extern "C" void put_pixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
extern "C" void flush();
extern "C" void init();
extern "C" int is_window_opened();
extern "C" long long get_time_milliseconds();