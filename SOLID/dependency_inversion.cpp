#include<iostream>
using namespace std;

///////////// Without Dependency Inversion Principle ///////////////
namespace WithoutDependencyInversion {
    class LowLevel {
    public:
        void doSomething() {
            cout << "LowLevel::doSomething()" << endl;
        }
    };

    /*
        This class directly uses the low level class.
        We cannot use any other class in place of LowLevel without
        making changes in the definition.
    */
    class HighLevel {
    public:
        void UseLowLevel(LowLevel lowLevel) {
            lowLevel.doSomething();
        }
    };
}

//////////// With Dependency Inversion //////////////////
namespace WithDependencyInversion {
    class LowLevelBase {
    public:
        virtual void doSomething() = 0;
    };

    class LowLevel1: public LowLevelBase {
    public:
        void doSomething() {
            cout << "LowLevel1::doSomething()" << endl;
        }
    };

    class LowLevel2: public LowLevelBase {
    public:
        void doSomething() {
            cout << "LowLevel2::doSomething()" << endl;
        }
    };

    /*
        This class uses the base class, so we can use any class
        derived from the base class in place of LowLevel.
    */
    class HighLevel {
    public:
        void UseLowLevel(LowLevelBase* lowLevel) {
            lowLevel->doSomething();
        }
    };
}

int main() {
    cout << "Without Dependency Inversion Principle" << endl;
    WithoutDependencyInversion::HighLevel highLevel;
    highLevel.UseLowLevel(WithoutDependencyInversion::LowLevel());

    cout << "With Dependency Inversion Principle" << endl;
    WithDependencyInversion::HighLevel highLevel2;
    highLevel2.UseLowLevel(new WithDependencyInversion::LowLevel1());
    highLevel2.UseLowLevel(new WithDependencyInversion::LowLevel2());

    return 0;
}