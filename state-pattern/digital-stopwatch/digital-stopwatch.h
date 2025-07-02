typedef enum {
    stopped,
    started
} State;

struct DigitalStopWatch {
    State state; /* store state in a data state type */
}