#include <stdint.h>

#define WIDTH 1920
#define HEIGHT 1080

void put_pixel(uint32_t x, uint32_t y, uint32_t r, uint32_t g, uint32_t b, uint32_t a);
void flush();
void init();
int is_window_opened();
int get_time_milliseconds();