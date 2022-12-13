#ifndef VECTOR3_H
#define VECTOR3_H

namespace mojosabel {
    class Vector3 {
    private:
        float posX;
        float posY;
        float posZ;

    public:
        float X() const { return posX; } 
        float Y() const { return posY; } 
        float Z() const { return posZ; } 

        void SetX(const float x) { posX = x; }
        void SetY(const float y) { posY = y; }
        void SetZ(const float z) { posZ = z; }
    };
}


#endif