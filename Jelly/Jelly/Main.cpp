#include "Director.h"
#include <crtdbg.h>

int main()
{
    srand(unsigned int(time(NULL)));
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Director director;
    director.Run();
    return 0;
}