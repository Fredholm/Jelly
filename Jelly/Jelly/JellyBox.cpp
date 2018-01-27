#include "JellyBox.h"
#include "JellyRec.h"

JellyBox::JellyBox()
{
    m_JellyRectangles.push_back(new JellyRec());
    m_JellyRectangles.push_back(new JellyRec());
    m_JellyRectangles.push_back(new JellyRec());

    m_JellyRectangles[0]->InitAnimation(ShapeData(50, 50, -100, 0), AnimationFactory::UpAndDown);

    m_JellyRectangles[1]->InitAnimation(ShapeData(50, 50, 0, 0), AnimationFactory::UpAndDown);
    m_JellyRectangles[1]->AddTechnique(TechniqueType::PoseToPose);

    m_JellyRectangles[2]->InitAnimation(ShapeData(50, 50, 100, 0), AnimationFactory::UpAndDown);
    m_JellyRectangles[2]->AddTechnique(TechniqueType::SquashAndStretch);
    m_JellyRectangles[2]->AddTechnique(TechniqueType::PoseToPose);
}

JellyBox::~JellyBox() 
{
    while (!m_JellyRectangles.empty())
    {
        delete m_JellyRectangles[m_JellyRectangles.size() - 1];
        m_JellyRectangles.pop_back();
    }
}

void JellyBox::Update(sf::Time dt)
{
    for (JellyRec* rec : m_JellyRectangles)
        rec->Update(dt);
}

void JellyBox::Draw(sf::RenderTarget & target, sf::RenderStates states)
{
    for (JellyRec* rec : m_JellyRectangles)
        rec->Draw(target, states);
}
