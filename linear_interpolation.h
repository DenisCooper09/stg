#pragma once

#include <SFML/Graphics.hpp>

[[maybe_unused]] sf::Vector2f linear_interpolation_vector2f(const sf::Vector2f &a,
															const sf::Vector2f &b,
															const float &t) {
	return {a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t};
}
