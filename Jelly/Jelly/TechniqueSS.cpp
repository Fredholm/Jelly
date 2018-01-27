#include "TechniqueSS.h"
#include "JellyRec.h"
#include "Animation.h"

TechniqueSS::TechniqueSS(TechniqueType inType, JellyRec* inJelly)
: Technique(inType, inJelly)
{

}

TechniqueSS::~TechniqueSS() { }

void TechniqueSS::Update(sf::Time dt)
{
    m_Jelly->m_Rectangle.setFillColor(sf::Color::Black);
}
