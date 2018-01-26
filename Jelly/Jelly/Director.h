#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <SFML\Graphics.hpp>
#include "NonCopyable.h"

class Director : public NonCopyable
{
public:
    Director();
    ~Director();

    void Run();

    void Update();
    void Render();

private:
    sf::WindowHandle m_HWND;
    sf::RenderWindow m_RenderWindow;
    sf::RenderStates m_RenderStates;
};

#endif // !DIRECTOR_H
