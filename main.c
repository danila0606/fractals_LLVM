// graphics
#include "graphics.h"

// clang++ main_gen.ll ../graphics.cpp -lsfml-graphics -lsfml-window -lsfml-system -O2

void sdl_draw_mandelbrot(uint32_t max_iterations) {

    for (uint32_t col = 0; col < WIDTH; ++col) {
        for (uint32_t row = 0; row < HEIGHT; ++row) {
            int x_square = 0;
            int y_square = 0;

            int c_real = (2 * (col) * 1000 / WIDTH - 1000);
            int c_imag = (2 * (row) * 1000/ HEIGHT - 1000);
            int x = 0, y = 0;

            uint32_t i = 0;
            while ((i < max_iterations) && ((x_square + y_square) / 1000 < 4000)) {
                x_square = x * x ;
                y_square = y * y ;
                y = 2 * x * y / 1000 + c_imag;
                x = x_square / 1000 - y_square / 1000 + c_real;
                i++;
            }
            uint8_t color = 0;
            if (i >= max_iterations) {
                color = 255;
            }
            else {
                color = (unsigned char)(255 * i / max_iterations);
            }
            put_pixel(col, row, color, color, color, 255);
        }
    }
    
}

int main() {
    init();
    uint32_t max_iter = 1;

    while (is_window_opened()) {   
        max_iter += get_time_milliseconds() / 1000;

        sdl_draw_mandelbrot(max_iter);

        flush();
    }
    return 0;
}