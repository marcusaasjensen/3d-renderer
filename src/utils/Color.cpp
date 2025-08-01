#include <cstdlib>
#include "Color.h"

Color::Color() : r{ 0 }, g{ 0 }, b{ 0 } {}
Color::Color(float r, float g, float b) : r{ r }, g{ g }, b{ b } {}

const Color& Color::random() {
	return Color(rand() % 256, rand() % 256, rand() % 256);
}
