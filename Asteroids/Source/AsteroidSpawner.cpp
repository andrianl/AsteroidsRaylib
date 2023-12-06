#include "AsteroidSpawner.h" 
#include <raymath.h>
#include "Asteroid.h" 
#include <iostream>

AsteroidSpawner::AsteroidSpawner() 
{ 
    // Constructor implementation goes here 
}
void AsteroidSpawner::BeginPlay()
{
    OnMouseClickDelegateMouseEvent.Connect<&Mouse::OnLeftMouseClick>(MouseEvent);
}

void AsteroidSpawner::Tick(const float DeltaTime)
{
    Update();
}

void AsteroidSpawner::Update()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        OnMouseClickDelegateMouseEvent.Trigger(MouseEvent);
    }
}

void AsteroidSpawner::SpawnAsteroid()
{
    const int Width = GetScreenWidth();
    const int Height = GetScreenHeight();

    const int randomOffset = 500;
    const Vector2 centerScreen = { Width / 2, Height / 2 };

    Vector2 RandomVectorsArray[4];

    for (int i = 0; i < 4; ++i)
    {
        int randomX = (i % 2 == 0) ? GetRandomValue(-randomOffset, 0) : GetRandomValue(Width, Width + randomOffset);
        int randomY = ((i >> 1) % 2 == 0) ? GetRandomValue(-randomOffset, 0) : GetRandomValue(Height, Height + randomOffset);

        RandomVectorsArray[i] = { static_cast<float>(randomX), static_cast<float>(randomY) };
    }

    Vector2 NewLocation = RandomVectorsArray[GetRandomValue(0, 3)];

    Vector2 NewVelocity = Vector2Subtract(centerScreen, NewLocation);
    NewVelocity = Vector2Normalize(NewVelocity);
    NewVelocity = Vector2Scale(NewVelocity, GetRandomValue(50, 100)); 

    auto AsteroidRef = Asteroid::CreateAsteroid(NewLocation, NewVelocity);

    if (&AsteroidRef != nullptr)
    {
        Asteroids.push_back(AsteroidRef);

       // std::cout << "Spawned New Asteroid" << std::endl;
       // std::cout << "Number of Asteroids: " << Asteroids.size() << std::endl;
    }
    else
    {
       // std::cout << "Asteroid is not Spawned" << std::endl;
    }
}

