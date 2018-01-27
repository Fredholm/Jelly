#ifndef JELLYREC_H
#define JELLYREC_H

#include <SFML\Graphics.hpp>
#include "AnimationFactory.h"
#include "TechniqueFactory.h"

class Technique;
class TechniqueSS;
class TechniquePoseToPose;
class Animation;
class JellyRec
{
public:
    friend Technique;
    friend TechniqueSS;
    friend TechniquePoseToPose;

    JellyRec();
    virtual ~JellyRec();

    void InitAnimation(ShapeData shapeData, AnimationFactory::AnimationType type);
    void AddTechnique(TechniqueType type);

    void Update(sf::Time dt);
    void Draw(sf::RenderTarget& window, sf::RenderStates states);

protected:
    std::vector<Technique*> m_Techniques;
    Animation*              m_Animation;
    sf::RectangleShape      m_Rectangle;
    sf::Vector2f            m_Acceleration;
    sf::Vector2f            m_Deacceleration;
};


#endif // !JELLYREC_H
