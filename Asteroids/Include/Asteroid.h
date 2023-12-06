#pragma once 
 
#include "Object.h" 
#include "raylib.h"
#include <vector>
#include "Delegate.h"
 

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

    virtual void BeginPlay() override;
    virtual void Tick(const float DeltaTime) override;
    void Update(const float DeltaTime);
    void Draw() const;

    Vector2 GetLocation() const
    {
        return Location;
    } 

    static bool CheckCollisionWithAsteroids(Asteroid& LHS, Asteroid& RHS);
    
    static Asteroid CreateAsteroid(Vector2 InLocation, Vector2 InVelocity);

private: 
    // Add private members as needed 

    Vector2 Location;
    Vector2 Velocity;
    AsteroidSizeEnum AsteroidSize;
    float Rotation;
    float RotationSpeed;
    float Radius = 64;

    static constexpr float MinRotationSpeed = 10;
    static constexpr float MaxRotationSpeed = 360;
}; 