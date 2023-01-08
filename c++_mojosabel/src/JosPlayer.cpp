#include "JosPlayer.h"
#include "JosDiggingBullet.h"
#include "Constants.h"

void JosPlayer::fire(int x, int y)
    {
        JosDiggingBullet *bullet = new JosDiggingBullet(rect.x, rect.y, 0, 0);
        instantiate(bullet);
    }