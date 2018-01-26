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
    frame.Position      = sf::Vector2f(Left, Top);
    frame.TravelTime    = sf::seconds(1.f);
    m_Animation->AddKeyFrame(frame);

    frame.Position      = sf::Vector2f(Right, Bottom);
    frame.TravelTime    = sf::seconds(1.f);
    m_Animation->AddKeyFrame(frame);

    frame.Position      = sf::Vector2f(Left, Bottom);
    frame.TravelTime    = sf::seconds(1.f);
    m_Animation->AddKeyFrame(frame);

    frame.Position      = sf::Vector2f(Right, Top);
    frame.TravelTime    = sf::seconds(1.f);
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

    sf::Vector2f currentPosition = m_Rectangle.getPosition();
    sf::Vector2f targetPosition = m_Animation->GetCurrentFrame()->Position;

    float distanceToTarget = Math::CalculateDistance(currentPosition, targetPosition);
//    m_Acceleration = sf::Vector2f(1.f, 1.f) * distanceToTarget;
//    m_Deacceleration = sf::Vector2f(1.f, 1.f) / distanceToTarget;

    sf::Vector2f before = currentPosition;
    currentPosition += (targetPosition - currentPosition) * 0.001f;
    sf::Vector2f after = currentPosition;
    m_Rectangle.setPosition(currentPosition);

    // Calculate the speed of the current movement
    sf::Vector2f result = sf::Vector2f(abs(before.x - after.x), abs(before.y - after.y));
    m_Acceleration = result;

    printf("Acceleration: X: %f, Y: %f\n", m_Acceleration.x, m_Acceleration.y);
}

void JellyRec::Draw(sf::RenderTarget& window, sf::RenderStates states)
{
    window.draw(m_Rectangle, states);
}
