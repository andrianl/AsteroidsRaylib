#pragma once 
 
#include "raylib.h"

class Object 
{
public:
    Object();
    virtual ~Object();  // Віртуальний деструктор
    // Додайте інші віртуальні функції за потребою
    virtual void BeginPlay();
    virtual void Tick(const float DeltaTime);
    virtual void Destroy();

    bool GetIsDestroyed() const
    {
        return isDestroyed;
    }

    void SetIsDestroyed(const bool InDestroyed)
    {
        isDestroyed = InDestroyed;
    }

    void DrawTriangle(Vector2 Center, float Radius, float Rotation, Color InColor) const;

private:
    // Додайте приватні члени за потребою

    bool isDestroyed = false;
};
