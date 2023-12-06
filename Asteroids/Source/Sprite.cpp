#include "Sprite.h" 
#include <string>

Sprite::Sprite() : Object(), Texture()
{ 
    // Constructor implementation goes here 
}

Sprite::Sprite(const char* filename) : Object() 
{
    Texture = LoadTexture(("Resources/" + std::string(filename)).c_str());
}

Sprite::~Sprite()
{
    UnloadTexture(Texture);
}

void Sprite::Draw(Vector2 Position, float Rotation) const
{
    DrawTextureEx(Texture, Position, Rotation, 1.0F, WHITE);
}

