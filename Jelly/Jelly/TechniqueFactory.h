#ifndef TECHNIQUEFACTORY_H
#define TECHNIQUEFACTORY_H

#include <SFML\Graphics.hpp>
#include "NonCopyable.h"
#include "Technique.h"

class JellyRec;
class TechniqueFactory : public NonCopyable
{
public:
    Technique* BuildTechnique(TechniqueType type, JellyRec* rec);
private:
    Technique* BuildTechniqueSS(TechniqueType type, JellyRec* rec);
    Technique* BuildTechniquePoseToPose(TechniqueType type, JellyRec* rec);
};


#endif // !TECHNIQUEFACTORY_H
