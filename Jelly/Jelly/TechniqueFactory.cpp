#include "TechniqueFactory.h"
#include "TechniqueSS.h"
#include "TechniquePoseToPose.h"

Technique* TechniqueFactory::BuildTechnique(TechniqueType type, JellyRec* rec)
{
    switch (type)
    {
    case Nothing:           return nullptr;                                 break;
    case SquashAndStretch:  return BuildTechniqueSS(type, rec);             break;
    case PoseToPose:        return BuildTechniquePoseToPose(type, rec);     break;
    default:                return nullptr;                                 break;
    }
}

Technique* TechniqueFactory::BuildTechniqueSS(TechniqueType type, JellyRec* rec)
{
    return new TechniqueSS(type, rec);
}

Technique* TechniqueFactory::BuildTechniquePoseToPose(TechniqueType type, JellyRec* rec)
{
    return new TechniquePoseToPose(type, rec);
}