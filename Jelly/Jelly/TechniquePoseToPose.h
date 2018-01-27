#ifndef TECHNIQUEPOSETOPOSE_H
#define TECHNIQUEPOSETOPOSE_H

#include "Technique.h"

class TechniquePoseToPose : public Technique
{
public:
    TechniquePoseToPose(TechniqueType inType, JellyRec* inJelly);
    virtual ~TechniquePoseToPose();

    void Update(sf::Time dt);
};


#endif // !TECHNIQUEPOSETOPOSE_H
