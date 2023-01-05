#ifndef GAMEOBJECTGENERATOR_H
#define GAMEOBJECTGENERATOR_H

#include "Level.h"
#include "Session.h"

namespace mojosabel{
    template <typename T>
    void generateGameObjects(Level* level, int amount)
    {
        for(int i = 0; i < amount; i++)
        {
        Vector2 spawnPos = level->generateSpawnPosition();
        int spawnX = spawnPos.x;
        int spawnY = spawnPos.y;
        T* object = new T(spawnX, spawnY);
        object->loadTexture(constants::gResPath + "images/Spaceship.png");
        object->setCollision(true);
        ses.add(object);
        }
    }

    template <typename T>
    void generateGameObjects(Level* level, int lowest, int highest)
    {
        int i = rand() % (highest - lowest) + lowest;
        generateGameObjects<T>(level, i);
    }
}

#endif