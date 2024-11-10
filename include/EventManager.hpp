#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <functional>
#include <vector>
class App;

class EventManager
{
public:
    using EventCallback = std::function<void(const SDL_Event&)>;
    using DeltaTimeCallback = std::function<void(const double&)>;
    
    EventManager();
    ~EventManager();
    void Poll();

    void addEventListener(EventCallback callback);
    void addDeltaTimeEvent(DeltaTimeCallback dtcb);
    void UpdateDeltaTime(const double& dt);

    friend class App;

private:
    bool m_quit = false;
    std::vector<EventCallback> m_callbacks;
    std::vector<DeltaTimeCallback> m_dtcbs;
    
};

#endif // end event manager hpp