#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <SFML\Graphics.hpp>
#include "NonCopyable.h"
#include "imgui.h"
#include "imgui-sfml.h"

#include <imgui.h>
#include <imgui-sfml.h>

class JellyBox;
class Director : public NonCopyable
{
public:
    Director();
    virtual ~Director();

    void Run();

    void Events();
    void Update();
    void Render();

private:
    JellyBox*        m_JellyBox;
    sf::WindowHandle m_HWND;
    sf::RenderWindow m_RenderWindow;
    sf::RenderStates m_RenderStates;
    sf::Clock        m_DeltaClock;

    void SetImGuiTheme();
};

#endif // !DIRECTOR_H
