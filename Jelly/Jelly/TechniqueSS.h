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

    void Update(sf::Time dt);
};


#endif // !TECHNIQUESS_H
