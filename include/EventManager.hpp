#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <functional>
#include <vector>
class App;

class EventManager
{
public:
    using EventCallback = std::function<void(const SDL_Event&)>;
    EventManager();
    ~EventManager();
    void Poll();

    void addEventListener(EventCallback callback);

    friend class App;

private:
    bool m_quit = false;
    std::vector<EventCallback> m_callbacks;
};

#endif // end event manager hpp