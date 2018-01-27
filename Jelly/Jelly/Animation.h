#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>
#include <vector>
#include "NonCopyable.h"

struct KeyFrame
{
    KeyFrame() : Position(0, 0), CurrentTime(sf::Time::Zero), StartTime(sf::Time::Zero) { }
    
    void Reset()
    {
        CurrentTime = StartTime;
    }

    void Init(sf::Vector2f inPosition, sf::Time inTime)
    {
        Position = inPosition;
        StartTime = CurrentTime = inTime;
    }

    sf::Vector2f Position;
    sf::Time CurrentTime;
    sf::Time StartTime;
};

class Animation : public NonCopyable
{
public:
    Animation();
    virtual ~Animation();

    void AddKeyFrame(KeyFrame frame);
    void Update(sf::Time dt);

    KeyFrame* GetCurrentFrame();
    KeyFrame* GetPreviousFrame();

private:
    bool FirstRunCheck();

    int                     m_CurrentIndex;
    KeyFrame                m_CurrentFrame;
    KeyFrame                m_PreviousFrame;
    std::vector<KeyFrame>   m_KeyFrames;
};


#endif // !ANIMATION_H
