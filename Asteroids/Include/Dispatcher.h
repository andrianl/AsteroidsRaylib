#pragma once 

#include <entt/entt.hpp>

template<typename EventType, typename ListenerType>
class EventDispatcher 
{ 
public: 
    EventDispatcher();
    // Add more members and functions as needed 



private: 
    // Add private members as needed 
    entt::dispatcher Dispatcher;
    ListenerType Listener;
}; 

template<typename EventType, typename ListenerType>
inline EventDispatcher<EventType, ListenerType>::EventDispatcher()
{
}
