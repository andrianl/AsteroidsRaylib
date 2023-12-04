#include "Asteroid.h" 
#include "raymath.h"
 
//Asteroid::Asteroid() 
//{ 
//    // Constructor implementation goes here 
//} 

Asteroid::Asteroid(Vector2 InLocation, Vector2 InVelocity)
    : Location(InLocation), Velocity(InVelocity), AsteroidSize(AsteroidSizeEnum::Big),
    Rotation(GetRandomValue(0, 360)), 
    RotationSpeed(GetRandomValue(MinRotationSpeed, MaxRotationSpeed)), IsActive(true)
{

}

Asteroid Asteroid::CreateAsteroid(Vector2 InLocation, Vector2 InVelocity)
{
    return Asteroid(InLocation, InVelocity);
}

void Asteroid::Update(const float DeltaTime)
{
    Vector2 ScaledVelocity = Vector2Scale(Velocity, DeltaTime);
    Location = Vector2Add(Location, ScaledVelocity);
    Rotation += RotationSpeed * DeltaTime;
}

void Asteroid::Draw() const
{
    if (IsActive)
    {
        DrawPolyLines(Location, 3, 64, Rotation, WHITE);
    }
}
