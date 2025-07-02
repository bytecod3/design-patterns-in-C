
/**
 * This is the signal 
 * Emitted by objects and actions
 */

 #include <functional>

template <typename ...Args>
class signal
{
private:
    /* data */
public:
    signal() = default;
    ~signal() = default;

    void emit(Args... parameters);
};


/**
 * This is the slot
 * Called when connected signal is called
 * 
 */
template <typename ...Args>
class slot {
    public:
    slot() = default;
    ~slot() = default;

    void operator()(Args... parameters); /* allow the object to be called as a function */
    void call(Args... parameters);

    void setSlotFunction(std::function<void(Args...)> callback);
};
