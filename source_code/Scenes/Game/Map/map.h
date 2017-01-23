#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "fstream"

#include "../../../System/system.h"

#include "../game_panel.h"
#include "walls_manager.h"
#include "points_manager.h"
#include "../Entities/pac_man.h"

#define WALL '#'
#define POINT '*'
#define PACMAN '@'

class Map
{
    public:
        bool Load(string file_path);
        void Render();
};

#endif // MAP_H_INCLUDED
