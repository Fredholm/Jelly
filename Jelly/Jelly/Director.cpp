#include "Director.h"
#include "Globals.h"

#define BACK_COLOR 91, 176, 195

Director::Director()
{
    // Setup of Render States
    m_RenderStates.blendMode = sf::BlendAlpha;

    // Setup of Render Window
    m_RenderWindow.create(sf::VideoMode(Global::Resolution.x, Global::Resolution.y), "Jelly");
    m_RenderWindow.setVerticalSyncEnabled(true);
    m_HWND = m_RenderWindow.getSystemHandle();
}

Director::~Director() { }

void Director::Run()
{
    while (!Global::Exit)
    {
        Update();
        Render();
    }
}

void Director::Update()
{

}

void Director::Render()
{
    m_RenderWindow.clear(sf::Color(BACK_COLOR));

    // Draw things here.

    m_RenderWindow.display();
}
