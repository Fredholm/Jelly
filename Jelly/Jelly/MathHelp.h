#ifndef MATHHELP_H
#define MATHHELP_H

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
}

#endif // !MATHHELP_H
