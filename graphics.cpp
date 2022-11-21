#include "graphics.hpp"
#include <chrono>
#include <SFML/Graphics.hpp>

std::unique_ptr<sf::RenderWindow> sfml_window;
sf::Image sfml_image;
std::chrono::time_point<std::chrono::high_resolution_clock> timer = std::chrono::high_resolution_clock::now();

extern "C" void put_pixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    sf::Color color{r, g, b, a};
    sfml_image.setPixel(x, y, color);
}

extern "C" void flush()
{
    sf::Texture texture;
    texture.loadFromImage(sfml_image);
    sf::Sprite sprite(texture);
    sfml_window->clear();
    sfml_window->draw(sprite);
    sfml_window->display();
}

extern "C" long long get_time_milliseconds()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - timer).count();
}

extern "C" void init()
{
    sfml_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "FRACTALS");
    sfml_image.create(WIDTH, HEIGHT);
}

extern "C" int is_window_opened()
{
    sf::Event event;
    while(sfml_window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            sfml_window->close();
        }
    }

    return static_cast<int>(sfml_window->isOpen());
}
