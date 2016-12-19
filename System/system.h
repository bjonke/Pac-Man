#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <SDL.h>

#include <iostream>
using namespace std;

#include "error_manager.h"

class System
{
    public:
        static bool Init();
        static void Free();

        static SDL_Window *Window;
        class Window
        {
            public:
                static bool Init();

                static void Clear();
                static void Update();

                static int GetWidth();
                static int GetHeight();

            private:
                static int width;
                static int height;
        };

        static SDL_Renderer *Renderer;

    private:
        static bool InitSDL();
        static bool CreateTheRenderer();
};


#endif // SYSTEM_H_INCLUDED