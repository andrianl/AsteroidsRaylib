#include "raylib.h"
#include <entt/entt.hpp>
#include <iostream>
#include "Asteroid.h";
#include <raymath.h>
#include "AsteroidSpawner.h"

int main() 
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Raylib event test");

    //SetTargetFPS(60);


    AsteroidSpawner AsteroidSpawnerInstanse{};
    AsteroidSpawnerInstanse.BeginPlay();

    auto& AsteroidsArrayRef = AsteroidSpawnerInstanse.GetAsteroids();

    while (!WindowShouldClose()) 
    {
        BeginDrawing();

        float FrameTime = GetFrameTime();

        AsteroidSpawnerInstanse.Tick(FrameTime);

        for (size_t i = 0; i < AsteroidsArrayRef.size(); ++i)
        {
            for (size_t j = i + 1; j < AsteroidsArrayRef.size(); ++j)
            {
                bool IsColliding = Asteroid::CheckCollisionWithAsteroids(AsteroidsArrayRef[i], AsteroidsArrayRef[j]);
            }
        }

        for (auto& Asteroid : AsteroidsArrayRef)
        {
            Asteroid.Tick(FrameTime);
        }


        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
