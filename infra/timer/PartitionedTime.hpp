#ifndef INFRA_TIMER_PARTITIONED_TIME_HPP
#define INFRA_TIMER_PARTITIONED_TIME_HPP

#include <cstdint>
#include <time.h>
#include "infra/timer/Timer.hpp"

namespace infra
{
    struct PartitionedTime
    {
        PartitionedTime(infra::TimePoint time);
        PartitionedTime(time_t unixTime);
        PartitionedTime(uint16_t years, uint8_t months, uint8_t days, uint8_t hours, uint8_t minutes, int8_t seconds);

        time_t ToTimeT() const;
        infra::TimePoint ToTimePoint() const;

        uint8_t seconds; // seconds after the minute - [0, 59]
        uint8_t minutes; // minutes after the hour - [0, 59]
        uint8_t hours;   // hours since midnight - [0, 23]
        uint8_t days;    // day of the month - [1, 31]
        uint8_t months;  // months since January - [1, 12]
        uint16_t years;  // years since 1900
    };
}

#endif
