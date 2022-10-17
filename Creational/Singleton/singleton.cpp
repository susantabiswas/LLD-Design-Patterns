#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Singleton {
private:
    // This is the only instance of this class and should be reused
    static Singleton* instance_;
    // Used for acquiring the lock when an instance is needed
    static mutex mtx_; 
    string val_;
    
    Singleton(string val) : val_(val) {}
    ~Singleton() {}

public:
    /**
     * @brief To prevent the singleton from being copied
     * 
     */
    Singleton(Singleton& singleton) = delete;

    /**
     * @brief To prevent the singleton from being assigned
     * 
     */
    void operator=(Singleton& singleton) = delete;

    /**
     * @brief Get the Instance object of this class     
     * 
     * @param val: dummy value used for identification
     * @return Singleton* 
     */
    static Singleton *getInstance(string val) {
        // acquiring a lock is important, so that multiple threads
        // don't enter the object creation section concurrently
        lock_guard<mutex> lock(mtx_);

        if(instance_ == nullptr)
            instance_ = new Singleton(val);
        return instance_;
    }

    string getValue() {
        return this->val_;
    }
};

Singleton* Singleton::instance_{nullptr};
mutex Singleton::mtx_;

/**
 * @brief Creates an instance of Singleton class and print its value
 * 
 * @param val 
 */
void testSingletonObjectCreation(string val) {
    this_thread::sleep_for(chrono::milliseconds(1000));
    auto singleton = Singleton::getInstance("Alpha");
    cout << singleton->getValue() << endl;
}

int main() {
    // If the singleton is reusing the 1st creating instance, then
    // it should have the same value from its getValue() method
    thread t1(testSingletonObjectCreation, "Alpha");
    thread t2(testSingletonObjectCreation, "Beta");

    t1.join();
    t2.join();
    return 0;
}