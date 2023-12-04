#pragma once 
 
#include "Object.h" 
#include "raylib.h"
 
enum class AsteroidSizeEnum
{
    Small = 1,
    Middle = 2,
    Big = 4
};

class Asteroid : public Object 
{ 
public: 
    Asteroid() = default;
    Asteroid(Vector2 InLocation, Vector2 InVelocity);
    // Add more members and functions as needed 
    
    static Asteroid CreateAsteroid(Vector2 InLocation, Vector2 InVelocity);
    void Update(const float DeltaTime);
    void Draw() const;
private: 
    // Add private members as needed 

    Vector2 Location;
    Vector2 Velocity;
    AsteroidSizeEnum AsteroidSize;
    float Rotation;
    float RotationSpeed;
    bool IsActive;

    static constexpr float MinRotationSpeed = 10;
    static constexpr float MaxRotationSpeed = 360;
}; 
