#include <stdint.h>

#define WIDTH 1920
#define HEIGHT 1080

void put_pixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void flush();
void init();
int is_window_opened();
long long get_time_milliseconds();