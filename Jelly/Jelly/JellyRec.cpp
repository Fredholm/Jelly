#include "JellyRec.h"
#include "Animation.h"
#include "Globals.h"
#include "MathHelp.h"
#include "Technique.h"
#include "TechniqueFactory.h"

#define REC_WIDTH   50
#define REC_HEIGHT  50

JellyRec::JellyRec()
{
    // Animation Setup
    m_Animation = new Animation();

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

JellyRec::~JellyRec() 
{
    if (m_Animation)
    {
        delete m_Animation;
        m_Animation = nullptr;
    }
}

void JellyRec::InitAnimation(ShapeData shapeData, AnimationFactory::AnimationType type)
{
    AnimationFactory factory;
    factory.BuildAnimation(type, m_Animation, shapeData);
    m_Rectangle.setSize(shapeData.Size);
}

void JellyRec::AddTechnique(TechniqueType type)
{
    TechniqueFactory factory;
    Technique* teq = factory.BuildTechnique(type, this);
    m_Techniques.push_back(teq);
}

void JellyRec::Update(sf::Time dt)
{
    // Update Animation's position
    m_Animation->Update(dt);
    sf::Vector2f    startPosition      = m_Animation->GetPreviousFrame()->Position;
    sf::Vector2f    targetPosition     = m_Animation->GetCurrentFrame()->Position;
    float           progress           = m_Animation->GetProgress();
    sf::Vector2f    difference         = m_Animation->GetDifference();
    m_Rectangle.setPosition(startPosition + progress * sf::Vector2f(targetPosition.x - startPosition.x, targetPosition.y - startPosition.y));

    // Update Techniques
    for (Technique* teq : m_Techniques)
        teq->Update(dt);
}

void JellyRec::Draw(sf::RenderTarget& window, sf::RenderStates states)
{
    window.draw(m_Rectangle, states);
}
