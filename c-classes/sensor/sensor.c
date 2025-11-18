#include "sensor.h"

void sensor_init(Sensor* const me) {

}

void sensor_cleanup(Sensor* const me) {

}

int sensor_get_filter_frequency(const Sensor* const me) {
    return me->filter_frequency;
}

void sensor_set_filter_frequency(Sensor* const me, int p_filter_frequency) {
    me->filter_frequency = p_filter_frequency;
}

int sensor_get_update_frequency(const Sensor* const me) {
    return me->update_frequency;
}

int sensor_get_value(const Sensor* const me) {
    return me->value;
}