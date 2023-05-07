#include <random>
#include <SFML/Graphics.hpp>
#include "linear_interpolation.h"

const float RADIUS = 1.0f;
const int ITERATIONS_COUNT = 10000;

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::VideoMode video_mode(1000, 800);

	sf::RenderWindow window(video_mode, "Sierpinski Triangle Generator", sf::Style::Default, settings);

	std::vector<sf::CircleShape> vertices;

	sf::CircleShape a(RADIUS);
	a.setPosition(500, 100);
	a.setFillColor(sf::Color::Red);

	sf::CircleShape b(RADIUS);
	b.setPosition(250, 700);
	b.setFillColor(sf::Color::Red);

	sf::CircleShape c(RADIUS);
	c.setPosition(750, 700);
	c.setFillColor(sf::Color::Red);

	vertices.push_back(a);
	vertices.push_back(b);
	vertices.push_back(c);

	std::vector<sf::CircleShape> circles;

	sf::CircleShape start_circe(RADIUS);
	start_circe.setPosition((float) window.getSize().x / 2, (float) window.getSize().y / 2);
	start_circe.setFillColor(sf::Color::Red);

	circles.push_back(start_circe);

	std::random_device random_device;
	std::default_random_engine default_random_engine(random_device());
	std::uniform_int_distribution<int> uniform_int_distribution(0, (int) vertices.size() - 1);

	int iteration = 0;

	while (window.isOpen()) {
		sf::Event event{};

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (iteration < ITERATIONS_COUNT) {
			int random_number = uniform_int_distribution(default_random_engine);

			sf::Vector2f new_point_position(linear_interpolation_vector2f(circles[iteration].getPosition(),
																		  vertices[random_number].getPosition(),
																		  0.5f));

			sf::CircleShape new_circle(RADIUS);
			new_circle.setPosition(new_point_position);
			new_circle.setFillColor(sf::Color::Green);
			circles.push_back(new_circle);

			iteration++;
		}

		window.clear(sf::Color::White);

		for (const sf::CircleShape &circle: vertices) {
			window.draw(circle);
		}

		for (const sf::CircleShape &circle: circles) {
			window.draw(circle);
		}

		window.display();
	}

	return 0;
}
