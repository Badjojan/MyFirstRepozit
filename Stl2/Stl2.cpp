

#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <atomic>
#include <future>
using namespace std;

std::mutex g_print_mutex;

atomic_int g_counter = 0;
void print_n(int n) {
    g_print_mutex.lock();
    cout << "n = " << n <<", in thread"<<this_thread::get_id()<< endl;
    cout.flush();
    g_print_mutex.unlock();
}

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return factorial(n - 1) + n;
}
int factorial_helper(int n) {
    int v = factorial(n);
    cout << "factorial(" << n << ") is " << v << " , thread id = " << this_thread::get_id() << endl;
    return v;
}

int main()
{
    /*cout << "main thread is " << this_thread::get_id() << endl;

    auto f30 = async(factorial_helper, 30);
    cout << "!!!" << endl;
    auto f15 = async(factorial_helper, 15);

    cout << "all threads done" << " f30 = " << f30.get() << " , f15 = " << f15.get() << endl;
    return 0;*/



    print_n(10);
    thread t0(bind(print_n, 56));
    cout << "t0 thread is " << t0.get_id() << endl;
    thread t1([]() {
        
        for (int i = 0; i < 10; i++) {
            int msecs =500+ rand() % 100;
            g_counter++;
            g_print_mutex.lock();
            cout << "2>i= " << i << ", in thread" << this_thread::get_id() << endl;
            cout.flush();
            g_print_mutex.unlock();
            this_thread::sleep_for(chrono::milliseconds(msecs));
           
        }
        });
    cout << "t1 thread is " << t1.get_id() << endl;
    t1.detach();
    for (int i = 0; i < 10; i++) {
        int msecs = 500 + rand() % 100;
        g_counter++;
        g_print_mutex.lock();
        cout << "1>i= " << i << ", in thread" << this_thread::get_id() << endl;
        cout.flush();
        g_print_mutex.unlock();
        this_thread::sleep_for(chrono::milliseconds(msecs));
    
    }

    if (t0.joinable())
        t0.join();
    if (t1.joinable())
        t1.join();
    cout << "all threads are done "<<g_counter << endl;

    return 0;
}


