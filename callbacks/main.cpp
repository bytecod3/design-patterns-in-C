#include <iostream>
#include <cstdio>

class MyClass{
    public:

        /**
         * This is the callback handler for when a message is received
         */
        void onMsg(int num1, int num2){
            printf("onMsg() called with num1=%i, num2=%i\n", num1, num2);
        }
   
};

class LibraryClass {
    public:
        void passACallbackToMe(MyClass* myClass, void (MyClass::* onMsg)(int num1, int num2)) {
            // call the callback function 
            (myClass->*onMsg)(1, 2);
        }
};

int main() {

    MyClass myClass;
    LibraryClass libraryClass;

    // provide an instance and function to call
    libraryClass.passACallbackToMe(&myClass, &MyClass::onMsg);

    return 0;
}