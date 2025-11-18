#ifndef SENSOR_H
#define SENSOR_H

typedef struct Sensor Sensor;

struct Sensor {
    int filter_frequency;
    int update_frequency;
    int value;
};

void sensor_init(Sensor* const me);
void sensor_cleanup(Sensor* const me);
int sensor_get_filter_frequency(const Sensor* const me);
void sensor_set_filter_frequency(Sensor* const me, int p_filter_frequency);
int sensor_get_update_frequency(const Sensor* const me);
void sensor_set_update_frequency(Sensor* const me, int p_updated_frequency);
int sensor_get_value(const Sensor* const me);
Sensor* sensor_create(void);
void sensor_destroy(Sensor* const me);

#endif