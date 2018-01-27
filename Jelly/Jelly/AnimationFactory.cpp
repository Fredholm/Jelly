#include "AnimationFactory.h"
#include "Animation.h"
#include "Globals.h"

void AnimationFactory::BuildAnimation(AnimationType type, Animation* animation, ShapeData shapeData)
{
    switch (type)
    {
    case AnimationType::Nothing: break;
    case AnimationType::UpAndDown: BuildUpAndDown(animation, shapeData); break;
    }
}

#define ANIMATION_UPANDDOWN_SEC 1.f
void AnimationFactory::BuildUpAndDown(Animation* animation, ShapeData shapeData)
{
    float CenterX = (Global::Resolution.x * 0.5f) - (shapeData.Size.x * 0.5f) + shapeData.Offset.x;
    float CenterY = (Global::Resolution.y * 0.5f) - (shapeData.Size.y * 0.5f) + shapeData.Offset.y;

    KeyFrame frame;
    frame.Init(sf::Vector2f(CenterX, CenterY - CenterY * 0.33f), sf::seconds(ANIMATION_UPANDDOWN_SEC));
    animation->AddKeyFrame(frame);

    frame.Init(sf::Vector2f(CenterX, CenterY + CenterY * 0.33f), sf::seconds(ANIMATION_UPANDDOWN_SEC));
    animation->AddKeyFrame(frame);
}
