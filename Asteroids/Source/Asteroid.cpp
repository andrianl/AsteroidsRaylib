#include "Asteroid.h"
#include "raymath.h"
#include "iostream"

// Asteroid::Asteroid()
//{
//     // Constructor implementation goes here
// }

Asteroid::Asteroid(Vector2 InLocation, Vector2 InVelocity)
    : Object(),
      Location(InLocation), Velocity(InVelocity), AsteroidSize(AsteroidSizeEnum::Big),
      Rotation(GetRandomValue(-360, 360)),
      RotationSpeed(GetRandomValue(-MaxRotationSpeed, MaxRotationSpeed))
{
}

bool Asteroid::CheckCollisionWithAsteroids(Asteroid& LHS, Asteroid& RHS)
{
    const auto Location1 = LHS.GetLocation();
    const auto Location2 = RHS.GetLocation();
    constexpr float Radius = 64;

    const bool isColliding = CheckCollisionCircles(Location1, Radius, Location2, Radius);

    if (isColliding)
    {
        LHS.SetIsDestroyed(true);
        RHS.SetIsDestroyed(true);
    }

    return isColliding;
}


Asteroid Asteroid::CreateAsteroid(Vector2 InLocation, Vector2 InVelocity)
{
    return Asteroid(InLocation, InVelocity);
}

void Asteroid::BeginPlay()
{
}

void Asteroid::Tick(const float DeltaTime)
{
    if (!GetIsDestroyed())
    {
        Update(DeltaTime);
        Draw();
    }
}

void Asteroid::Update(const float DeltaTime)
{
    Vector2 ScaledVelocity = Vector2Scale(Velocity, DeltaTime);
    Location = Vector2Add(Location, ScaledVelocity);
    Rotation += RotationSpeed * DeltaTime;
}

void Asteroid::Draw() const
{
  DrawTriangle(Location, Radius, Rotation, WHITE); 
}
