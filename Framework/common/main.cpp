#include <stdio.h>
#include "BaseApplication.hpp"

using namespace My;
namespace My
{
    extern IApplication* g_pApp;
}

int main(int argc, char** argv)
{
    int ret;
    if((ret == g_pApp->Initialize()) != 0)
    {
        printf("App initialization failed, exiting now.");
        return ret;
    }
    while(!g_pApp->IsQuit())
    {
        g_pApp->Tick();
    }
    g_pApp->Finalize();
    return 0;
}