#ifndef ANIMATIONFACTORY_H
#define ANIMATIONFACTORY_H

#include "NonCopyable.h"
#include <SFML\Graphics.hpp>

struct ShapeData
{
    ShapeData(sf::Vector2f inSize)          : Size(inSize) { }
    ShapeData(float inSizeX, float inSizeY) : Size(inSizeX, inSizeY) { }
    
    sf::Vector2f Size;
};

class Animation;
class AnimationFactory : public NonCopyable
{
public:
    enum AnimationType
    {
        Nothing,
        UpAndDown
    };

    void BuildAnimation(AnimationType type, Animation* animation, ShapeData shapeData);

private:
    void BuildUpAndDown(Animation* animation, ShapeData shapeData);

};


#endif // !ANIMATIONFACTORY_H
