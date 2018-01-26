#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "NonCopyable.h"

struct KeyFrame
{
    KeyFrame() : Position(0, 0), TravelTime(sf::Time::Zero) { }

    sf::Vector2f Position;
    sf::Time TravelTime;
};

class Animation : public NonCopyable
{
public:
    Animation();
    virtual ~Animation();

    void AddKeyFrame(KeyFrame frame);
    void Update(sf::Time dt);

    KeyFrame* GetCurrentFrame();

private:
    bool FirstRunCheck();

    int                     m_CurrentIndex;
    KeyFrame                m_CurrentFrame;
    std::vector<KeyFrame>   m_KeyFrames;
};


#endif // !ANIMATION_H
