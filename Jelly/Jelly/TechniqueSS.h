#ifndef TECHNIQUESS_H
#define TECHNIQUESS_H

#include "Technique.h"

/* 
    Technique Class for Squash and Stretching Animation
*/

class TechniqueSS : public Technique
{
public:
    friend JellyRec;

    TechniqueSS(TechniqueType inType, JellyRec* inJelly);
    virtual ~TechniqueSS();

    void ShowEditor();
    void Update(sf::Time dt);

private:
    sf::Vector2f m_SizeTarget;
    sf::Vector2f m_SizeProgressor;
};


#endif // !TECHNIQUESS_H
