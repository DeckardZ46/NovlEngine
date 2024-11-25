/**
 * < Novl Engine > Event.h
 * Author: DeckardZ46
 * Date: 2024/11/16
 * Note: Event system for Novl Engine
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */
#pragma once 

namespace Novl{
class EventDispatcher {
    template<typename... Args>
    using EventHandler = std::function<bool(Args...)>;
public:
    EventDispatcher();
    ~EventDispatcher();

    template<typename... Args>
    inline void subscribeEvent(n_string event_str, EventHandler<Args...> handler){
        size_t eventID = nHashString(event_str);
        m_eventHandlers<Args...>[eventID] = handler;
    }

    template<typename... Args>
    inline void unsubscribeEvent(n_string event_str){
        size_t eventID = nHashString(event_str);
        m_eventHandlers<Args...>.erase(eventID);
    }

    template<typename... Args>
    inline bool checkAndHandleEvent(n_string event_str,Args&& ...args){
        size_t eventID = nHashString(event_str);
        auto it = m_eventHandlers<Args...>.find(eventID);

        if(it != m_eventHandlers<Args...>.end()){
            it->second(std::forward<Args>(args)...);
            return true;
        }

        return false;
    }

private:
    template<typename... Args>
    n_hashmap<size_t,EventHandler<Args...>> m_eventHandlers;
};
} // namespace Novl