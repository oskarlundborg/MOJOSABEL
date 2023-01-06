#ifndef GCROCODILE_H
#define GCROCODILE_H

#include "Enemy.h"
#include "Player.h"

using namespace mojosabel;

class GCrocodile : public Enemy
{
private:
    bool hasPlayer;
    Player* playerPtr;
public:
    
    GCrocodile(int x, int y) : Enemy(x, y) {}
    void update();
    void move();
    void onCollision(Collision<Entity> collision);
    void attack();
    
    void setHasPlayer(bool toSet) { hasPlayer = toSet; }
    bool getHasPlayer() { return hasPlayer; }
    void setPlayer(Player* ptr) { playerPtr = ptr; }
    Player* getPlayer() { return playerPtr; }
};

#endif