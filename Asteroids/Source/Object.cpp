#include "Object.h" 
 
Object::Object() 
{
    // Конструктор
}

Object::~Object() 
{
    // Віртуальний деструктор

    if (isDestroyed == false)
    {
        Destroy();
    }
}

void Object::BeginPlay() 
{
    // Реалізація функції BeginPlay
}

void Object::Tick(float deltaTime) 
{
    // Реалізація функції Tick
}

void Object::Destroy() 
{
    isDestroyed = true;
}

void Object::DrawTriangle(Vector2 Center, float Radius, float Rotation, Color InColor) const
{
    DrawPolyLines(Center, 3, 64, Rotation, InColor);
}



