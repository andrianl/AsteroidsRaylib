#pragma once 
#include "entt/entt.hpp" 
#include <vector>

template <typename EventT, typename ReturnT = void, typename... Args>
class Delegate 
{
public:
    Delegate() = default;

    template <auto Candidate, typename Type>
    void Connect(Type& value_or_instance) 
    {
        // Connect the function to the delegate
        Del.template connect<Candidate>(value_or_instance);
    }

    // Trigger method should forward the arguments to the delegate
    ReturnT Trigger(const EventT& InEvent, const Args&... args) 
    {
        return Del(InEvent, args...);
    }

private:
    // Delegate with the correct signature for EventT and Args
    entt::delegate<ReturnT(const EventT&, const Args&...)> Del;
};

