#include <iostream>
#include <thread>
#include <functional>

using std::cout;
using std::thread;

//----------
void func1() 
{
    cout << "In func1() \n";
}
//------------
class Functor1
{
public:
    void operator()(int x)
    {
        cout << "In Functor1(), x = " << x << "\n";
    }
};
//--------------
void run_code ()
{
    // Create thread using function
    thread thread1(func1);
    thread1.join(); // Force serial

    // Create thread using class with function call operator
    Functor1 function_obj;
    function_obj(3);                // Regular functor usage in main thread
    thread thread2(function_obj,2); // Use functor in a thread
    thread2.join(); // Force serial

    // Create thread using lambda expression
    thread thread3([] {
        cout << "In lamabda \n";
    });
    thread3.join(); // Force serial

    // Join threads
    //thread1.join();
    //thread2.join();
    //thread3.join();

    cout << "In main thread \n";
}
//--------
//--------
int main()
{
    run_code();
    
    return 0;
}