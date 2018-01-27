#include "Animation.h"

Animation::Animation() 
{
    m_CurrentIndex = -1;
    m_CurrentFrame = KeyFrame();
}

Animation::~Animation() { }

void Animation::AddKeyFrame(KeyFrame frame)
{
    m_KeyFrames.push_back(frame);
}

bool Animation::FirstRunCheck()
{
    // Only if we haven't started the animation
    if (!m_KeyFrames.empty())
    {
        m_CurrentIndex = 0;
        m_CurrentFrame = m_KeyFrames[m_CurrentIndex];
        m_PreviousFrame = m_KeyFrames[m_CurrentIndex];
    }
    else
    {
        return false;
    }

    return true;
}

void Animation::Update(sf::Time dt)
{
    static bool ready = FirstRunCheck();
    if (ready)
    {
        m_CurrentFrame.CurrentTime -= dt;
        if (m_CurrentFrame.CurrentTime < sf::Time::Zero)
        {
            m_PreviousFrame = m_KeyFrames[m_CurrentIndex];
            m_CurrentIndex++;
            if (m_CurrentIndex >= m_KeyFrames.size())
                m_CurrentIndex = 0;

            m_CurrentFrame.Reset();
            m_CurrentFrame = m_KeyFrames[m_CurrentIndex];
        }
    }
}

KeyFrame* Animation::GetCurrentFrame()
{
    return &m_CurrentFrame;
}

KeyFrame* Animation::GetPreviousFrame()
{
    return &m_PreviousFrame;
}
