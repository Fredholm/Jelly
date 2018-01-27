#ifndef TECHNIQUE_H
#define TECHNIQUE_H

#include <SFML\Graphics.hpp>

enum TechniqueType
{
    Nothing,
    SquashAndStretch,
    PoseToPose
};

class JellyRec;
class Technique
{
public:
    Technique(TechniqueType inType, JellyRec* inJelly) : m_Jelly(inJelly), m_Type(inType) { }
    virtual ~Technique() { m_Jelly = nullptr; }
    virtual void Update(sf::Time dt) = 0;

    TechniqueType GetType() { return m_Type; }
    JellyRec* GetJelly() { return m_Jelly; }

protected:
    TechniqueType m_Type;
    JellyRec* m_Jelly;
};


#endif // !TECHNIQUE_H
