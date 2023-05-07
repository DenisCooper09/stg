#include <SFML/Graphics.hpp>

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::VideoMode video_mode(1000, 800);

	sf::RenderWindow window(video_mode, "Sierpinski Triangle Generator",sf::Style::Default, settings);

	while (window.isOpen()) {
		sf::Event event{};

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::White);
		window.display();
	}

	return 0;
}
