#pragma once

#include "Core/Position.hpp"
#include "IO/System/EventLog.hpp"
#include <optional>
#include <cstdint>

namespace sw::core
{
    class IObservable {
    public:
        virtual ~IObservable() = default;

        void addObserver(EventLog* obs) { 
            observers.push_back(obs); 
        }
        
        void removeObserver(EventLog* obs) {
            observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
        }

    protected:
        template <typename TEvent>
        void notify(uint64_t tick, TEvent&& event) {
            for (auto* obs : observers) {
                obs->log(tick, std::forward<TEvent>(event));
            }
        }

    private:
        std::vector<EventLog*> observers;
    };

} // namespace sw::core

