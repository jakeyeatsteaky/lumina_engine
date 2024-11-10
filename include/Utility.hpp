#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <cstdint>

namespace util
{
    void TimeDelay_ms(uint32_t ms, bool use_rote = false);

}

namespace core
{
    constexpr uint8_t FPS = 240;
    constexpr int16_t MPF = 1000 / FPS; // milliseconds_per_frame
}

#endif // end utility hpp