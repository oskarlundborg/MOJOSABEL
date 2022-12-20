#ifndef COLLISION_H
#define COLLISION_H

namespace mojosabel {

    template <typename T>
    class Collision
    {
    public:
        const std::string tag;
        T* t;
        Collision(T* t, std::string tag) : t(t), tag(tag) {}
    };
}

#endif