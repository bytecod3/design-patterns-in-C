#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>

/** state function protoypes  */
void Sm_StateA(void);
void Sm_StateB(void);
void Sm_StateC(void);
void Sm_StateD(void);
void Sm_Run(void);

typedef enum {
    STATE_A,
    STATE_B,
    STATE_C,
    STATE_D,
    NUM_STATES
} StateType;

StateType SmState = STATE_A;

typedef struct {
    StateType State;            /**< Defines the command */
    void (*func)(void);         /**< The function to run when in this state */
} StateMachineType;

/** state machine table */
StateMachineType StateMachine[] = 
{
    {STATE_A, Sm_StateA},
    {STATE_B, Sm_StateB},
    {STATE_C, Sm_StateC},
    {STATE_D, Sm_StateD}

};

/**
 * state machine function definition
 */
void Sm_StateA(void) {
    //  run state machine code 
    std::cout << "In state A" << '\n';
    // transition to next state 
    SmState = STATE_B;
}

void Sm_StateB(void) {
    //  run state machine code 
    std::cout << "In state B" << '\n';
    // transition to next state 
    SmState = STATE_D;
}

void Sm_StateC(void) {
    //  run state machine code 
    std::cout << "In state C" << '\n';
    // transition to next state 
    SmState = STATE_A;
}

void Sm_StateD(void) {
    //  run state machine code 
    std::cout << "In state D" << '\n';
    // transition to next state 
    SmState = STATE_C;
}

void Sm_Run() {
    
        // check to make sure the number of states are not exceeded
        if(SmState < NUM_STATES) {
            // call the function for the state
            (*StateMachine[SmState].func)();
        } else{
            // throw exception
        }

}

int main() {
    while(1) 
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        Sm_Run();
    }

    return 0;
}