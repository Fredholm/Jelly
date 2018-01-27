#include "TechniquePoseToPose.h"
#include "JellyRec.h"
#include "Animation.h"
#include <imgui.h>
#include <imgui-SFML.h>

TechniquePoseToPose::TechniquePoseToPose(TechniqueType inType, JellyRec* inJelly)
    : Technique(inType, inJelly)
{

}

TechniquePoseToPose::~TechniquePoseToPose()
{
}

void TechniquePoseToPose::Update(sf::Time dt)
{
    sf::Vector2f    startPosition = m_Jelly->m_Animation->GetPreviousFrame()->Position;
    sf::Vector2f    targetPosition = m_Jelly->m_Animation->GetCurrentFrame()->Position;
    float           progress = m_Jelly->m_Animation->GetProgress();
    sf::Vector2f    difference = m_Jelly->m_Animation->GetDifference();
    m_Jelly->m_Rectangle.setPosition(startPosition + progress * sf::Vector2f(targetPosition.x - startPosition.x, targetPosition.y - startPosition.y));
}
