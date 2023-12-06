#include "Object.h" 
 
Object::Object() 
{
    // �����������
}

Object::~Object() 
{
    // ³��������� ����������

    if (isDestroyed == false)
    {
        Destroy();
    }
}

void Object::BeginPlay() 
{
    // ��������� ������� BeginPlay
}

void Object::Tick(float deltaTime) 
{
    // ��������� ������� Tick
}

void Object::Destroy() 
{
    isDestroyed = true;
}

void Object::DrawTriangle(Vector2 Center, float Radius, float Rotation, Color InColor) const
{
    DrawPolyLines(Center, 3, 64, Rotation, InColor);
}



