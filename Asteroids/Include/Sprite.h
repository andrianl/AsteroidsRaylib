#pragma once 
 
#include "Object.h" 

class Sprite : public Object 
{ 
public: 
    Sprite();
    Sprite(const char* Filename);
    ~Sprite();

    // Add more members and functions as needed 

    void Draw(Vector2 Position, float Rotation) const;


private: 
    // Add private members as needed 

    Texture2D Texture{};
}; 
