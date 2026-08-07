#include <SFML/Graphics.hpp>

int main() {
    // Create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML Window");

    // Run the program as long as the window is open
    while (window.isOpen()) {
        // Check all events triggered since the last iteration
        while (const std::optional event = window.pollEvent()) {
            // Close the window if the close button is clicked
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
    }

    return 0;
}