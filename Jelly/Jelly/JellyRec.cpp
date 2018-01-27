#include "JellyRec.h"
#include "Animation.h"
#include "Globals.h"
#include "MathHelp.h"

#define REC_WIDTH   50
#define REC_HEIGHT  50

JellyRec::JellyRec()
{
    // Animation Setup
    m_Animation = new Animation();

    float Left      = REC_WIDTH;
    float Right     = Global::Resolution.x - REC_WIDTH;
    float Top       = REC_HEIGHT;
    float Bottom    = Global::Resolution.y - REC_HEIGHT;

    KeyFrame frame;
    frame.Init(sf::Vector2f(Left, Top), sf::seconds(1.f));
    m_Animation->AddKeyFrame(frame);

    frame.Init(sf::Vector2f(Right, Bottom), sf::seconds(1.f));
    m_Animation->AddKeyFrame(frame);

    frame.Init(sf::Vector2f(Left, Bottom), sf::seconds(1.f));
    m_Animation->AddKeyFrame(frame);

    frame.Init(sf::Vector2f(Right, Top), sf::seconds(1.f));;
    m_Animation->AddKeyFrame(frame);

    // Rectangle Setup
    m_Rectangle.setFillColor(sf::Color::White);
    m_Rectangle.setSize(sf::Vector2f(REC_WIDTH, REC_HEIGHT));
    m_Rectangle.setOutlineThickness(1.f);
    m_Rectangle.setOutlineColor(sf::Color::Black);
    m_Rectangle.setOrigin(m_Rectangle.getSize() * 0.5f);
    m_Rectangle.setPosition(sf::Vector2f(Global::Resolution.x * 0.5f, Global::Resolution.y * 0.5f));

    m_Acceleration      = sf::Vector2f(0, 0);
    m_Deacceleration    = sf::Vector2f(0, 0);
}

JellyRec::~JellyRec() { }

void JellyRec::Update(sf::Time dt)
{
    m_Animation->Update(dt);

    sf::Vector2f startPosition      = m_Animation->GetPreviousFrame()->Position;
    sf::Vector2f targetPosition     = m_Animation->GetCurrentFrame()->Position;

    sf::Time total                  = m_Animation->GetCurrentFrame()->StartTime;
    sf::Time elapsed                = m_Animation->GetCurrentFrame()->CurrentTime;

    float progress = 1.f - (elapsed.asSeconds() / total.asSeconds());
    sf::Vector2f difference = targetPosition - startPosition;
    m_Rectangle.setPosition(startPosition + progress * sf::Vector2f(targetPosition.x - startPosition.x, targetPosition.y - startPosition.y));
}

void JellyRec::Draw(sf::RenderTarget& window, sf::RenderStates states)
{
    window.draw(m_Rectangle, states);
}
