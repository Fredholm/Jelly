#include "JellyBox.h"
#include "JellyRec.h"

JellyBox::JellyBox()
{
    m_JellyRectangles.push_back(JellyRec());
}

JellyBox::~JellyBox() { }

void JellyBox::Update(sf::Time dt)
{
    for (JellyRec& rec : m_JellyRectangles)
        rec.Update(dt);
}

void JellyBox::Draw(sf::RenderTarget & target, sf::RenderStates states)
{
    for (JellyRec& rec : m_JellyRectangles)
        rec.Draw(target, states);
}
