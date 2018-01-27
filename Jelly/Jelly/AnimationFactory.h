#ifndef ANIMATIONFACTORY_H
#define ANIMATIONFACTORY_H

#include "NonCopyable.h"
#include <SFML\Graphics.hpp>

struct ShapeData
{
    ShapeData(sf::Vector2f inSize) : Size(inSize), Offset(sf::Vector2f()) { }
    ShapeData(float inSizeX, float inSizeY) : Size(inSizeX, inSizeY), Offset(sf::Vector2f()) { }
    ShapeData(sf::Vector2f inSize, sf::Vector2f inOffset) : Size(inSize), Offset(inOffset) { }
    ShapeData(float inSizeX, float inSizeY, sf::Vector2f inOffset) : Size(inSizeX, inSizeY), Offset(inOffset) { }
    ShapeData(float inSizeX, float inSizeY, float inOffsetX, float inOffsetY) : Size(inSizeX, inSizeY), Offset(inOffsetX, inOffsetY) { }
    
    sf::Vector2f Size;
    sf::Vector2f Offset;
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
