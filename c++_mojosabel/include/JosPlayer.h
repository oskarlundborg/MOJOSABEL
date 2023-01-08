#ifndef JOSPLAYER_H
#define JOSPLAYER_H

#include "Player.h"

using namespace mojosabel;

class JosPlayer : public Player {

public:
    JosPlayer(int x, int y) : Player(x, y, 32, 32, 3, 4) {}
    void fire(int x, int y);
    bool levelCompleted();
};
#endif