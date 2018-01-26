#include "JellyRec.h"
#include "Animation.h"
#include "Globals.h"

#define REC_WIDTH   50
#define REC_HEIGHT  50

JellyRec::JellyRec()
{
    // Animation Setup
    m_Animation = new Animation();

    float Left = REC_WIDTH;
    float Right = Global::Resolution.x - REC_WIDTH;
    float Top = REC_HEIGHT;
    float Bottom = Global::Resolution.y - REC_HEIGHT;

    KeyFrame frame;
    frame.Position = sf::Vector2f(Left, Top);
    frame.TravelTime = sf::seconds(1.f);
    m_Animation->AddKeyFrame(frame);

    frame.Position = sf::Vector2f(Right, Bottom);
    frame.TravelTime = sf::seconds(1.f);
    m_Animation->AddKeyFrame(frame);

    frame.Position = sf::Vector2f(Left, Bottom);
    frame.TravelTime = sf::seconds(1.f);
    m_Animation->AddKeyFrame(frame);

    frame.Position = sf::Vector2f(Right, Top);
    frame.TravelTime = sf::seconds(1.f);
    m_Animation->AddKeyFrame(frame);

    // Rectangle Setup
    m_Rectangle.setFillColor(sf::Color::White);
    m_Rectangle.setSize(sf::Vector2f(50, 50));
    m_Rectangle.setOutlineThickness(1.f);
    m_Rectangle.setOutlineColor(sf::Color::Black);
    m_Rectangle.setOrigin(m_Rectangle.getSize() * 0.5f);
    m_Rectangle.setPosition(sf::Vector2f(Global::Resolution.x * 0.5f, Global::Resolution.y * 0.5f));
}

JellyRec::~JellyRec() { }

void JellyRec::Update(sf::Time dt)
{
    m_Animation->Update(dt);
    m_Rectangle.setPosition(m_Animation->GetCurrentFrame()->Position);
}

void JellyRec::Draw(sf::RenderTarget& window, sf::RenderStates states)
{
    window.draw(m_Rectangle, states);
}
