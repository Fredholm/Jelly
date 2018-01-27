#include "TechniqueSS.h"
#include "JellyRec.h"
#include "Animation.h"
#include <imgui.h>
#include <imgui-SFML.h>

TechniqueSS::TechniqueSS(TechniqueType inType, JellyRec* inJelly)
: Technique(inType, inJelly)
{
    m_SizeTarget        = sf::Vector2f(25, 70);
    m_SizeProgressor    = sf::Vector2f(35, 40);
    m_Sturdiness        = 0.01f;
}

TechniqueSS::~TechniqueSS() { }

void TechniqueSS::ShowEditor()
{
    ImGui::Begin("SS Editor");
   
    ImGui::DragFloat2("Target", (float*)&m_SizeTarget, 0.5f);
    ImGui::DragFloat2("Progress", (float*)&m_SizeProgressor, 0.5f);
    ImGui::DragFloat("Sturdiness", (float*)&m_Sturdiness, 0.00001f, 0.0, 0.0, "%.7f");

    ImGui::End();
}

void TechniqueSS::Update(sf::Time dt)
{
    ShowEditor();

    sf::Vector2f targetSize;
    targetSize.x = m_SizeTarget.x + m_SizeProgressor.x * m_Jelly->m_Animation->GetProgress();
    targetSize.y = m_SizeTarget.y - m_SizeProgressor.y * m_Jelly->m_Animation->GetProgress();

    m_Jelly->m_Rectangle.setSize(m_Jelly->m_Rectangle.getSize() + (targetSize - m_Jelly->m_Rectangle.getSize()) * m_Sturdiness);
    m_Jelly->m_Rectangle.setOrigin(m_Jelly->m_Rectangle.getSize() * 0.5f);
}
