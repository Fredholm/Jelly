#ifndef MATHHELP_H
#define MATHHELP_H

#include <SFML\Graphics.hpp>

namespace Math
{
    // Returns a random variable between the low & high variables
    template <typename T>
    T Random(const T& low, const T& high)
    {
        return ((high - low) * ((T)rand() / RAND_MAX)) + low;
    }

    // Returns a clamped variable between the lower and upper variables
    template <typename T>
    T Clamp(const T& n, const T& lower, const T& upper)
    {
        return std::max(lower, std::min(n, upper));
    }

    float CalculateDistance(const sf::Vector2f& p1, const sf::Vector2f& p2)
    {
        float diffY = p1.y - p2.y;
        float diffX = p1.x - p2.x;
        return sqrt((diffY * diffY) + (diffX * diffX));
    }
}

#endif // !MATHHELP_H
