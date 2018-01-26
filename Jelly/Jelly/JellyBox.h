#ifndef JELLYBOX_H
#define JELLYBOX_H

#include <SFML\Graphics.hpp>
#include <vector>

class JellyRec;
class JellyBox
{
public:
    JellyBox();
    ~JellyBox();

    void Update(sf::Time dt);
    void Draw(sf::RenderTarget& target, sf::RenderStates states);

private:
    std::vector<JellyRec> m_JellyRectangles;
};


#endif // !JELLYBOX_H
