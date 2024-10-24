#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP
class App;

class EventManager
{
    bool m_quit = false;
    SDL_Event m_event;
public:
    EventManager();
    ~EventManager();
    void Poll();

    friend class App;
};

#endif // end event manager hpp