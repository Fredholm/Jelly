#ifndef JELLYREC_H
#define JELLYREC_H

#include <SFML\Graphics.hpp>
#include "AnimationFactory.h"

class Animation;
class JellyRec
{
public:
    JellyRec();
    virtual ~JellyRec();

    void InitAnimation(ShapeData shapeData, AnimationFactory::AnimationType type);

    void Update(sf::Time dt);
    void Draw(sf::RenderTarget& window, sf::RenderStates states);

private:
    Animation*          m_Animation;
    sf::RectangleShape  m_Rectangle;
    sf::Vector2f        m_Acceleration;
    sf::Vector2f        m_Deacceleration;
};


#endif // !JELLYREC_H
