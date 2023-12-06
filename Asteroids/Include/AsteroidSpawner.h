#pragma once 
 
#include "Object.h" 
#include "Delegate.h"
#include "Asteroid.h"
 

class AsteroidSpawner : public Object 
{ 
public: 
    AsteroidSpawner(); 
    // Add more members and functions as needed
    // 
    
    virtual void BeginPlay() override;
    virtual void Tick(const float DeltaTime) override;

    void Update();
    void SpawnAsteroid();

    std::vector<class Asteroid>& GetAsteroids()
    {
        return Asteroids;
    }

private: 
    // Add private members as needed 


    struct Mouse
    {
        class AsteroidSpawner* AsteroidSpawnerPtr;
        void OnLeftMouseClick(const Mouse& MouseEvent)
        {
            AsteroidSpawnerPtr->SpawnAsteroid();
        }

        Mouse() = default;

        Mouse(AsteroidSpawner* ptr) : AsteroidSpawnerPtr(ptr)
        {

        }
    };

    class Mouse MouseEvent{this};
    Delegate<Mouse> OnMouseClickDelegateMouseEvent{};

    std::vector<class Asteroid> Asteroids;
}; 
