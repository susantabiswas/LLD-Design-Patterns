#include <iostream>
using namespace std;

/////////////////////////////// Base Product classes //////////////////////////
/* 
* Abstract base class to represent an App specific
* to Windows, Mac and Linux platform.
* This is the same app released for multiple platforms

An App undergoes multiple cycles during development: Test, Alpha, Beta, Public etc.
Each stage incorporates changes and feedbacks received from previous stage and hence the
app might be very different in the sense that initially we might have a lot of bloatware code
to trace and monitor the fuunctionality. Slowly we remove a lot of it as we move towards a 
public release.
*/
class WindowsApp {
public:
    virtual void info() = 0;
};

class MacApp {
public:
    virtual void info() = 0;
};

class LinuxApp {
public:
    virtual void info() = 0;
};

/////////////////////////// Implementation of base product classes /////////////////////
/*
    For the app, we have an Aplha version with lots of debug loggers and other metrics.
    This is present across all three platforms.
    Below are the Aplha variants of the App across platforms
*/
class WindowsAppAlpha: public WindowsApp {
public:
    void info() override {
        cout << "Alpha version of Windows App\n";
    }
};

class MacAppAlpha: public MacApp {
public:
    void info() override {
        cout << "Alpha version of Mac App\n";
    }
};

class LinuxAppAlpha: public LinuxApp {
public:
    void info() override {
        cout << "Alpha version of Linux App\n";
    }
};

/*
    After alpha version, we have the beta version with improvements made from Alpha version and
    lot lesser tracing and loggers.
    This is present across all three platforms.
    Below are the Beta variants of the App across platforms
*/
class WindowsAppBeta: public WindowsApp {
public:
    void info() override {
        cout << "Beta version of Windows App\n";
    }
};

class MacAppBeta: public MacApp {
public:
    void info() override {
        cout << "Beta version of Mac App\n";
    }
};

class LinuxAppBeta: public LinuxApp {
public:
    void info() override {
        cout << "Beta version of Linux App\n";
    }
};

//////////////////////////////// Abstract Base Factory class to create app variants ///////////
class AppFactory {
public:
    virtual WindowsApp* createWindowsApp() = 0;
    virtual MacApp* createMacApp() = 0;
    virtual LinuxApp* createLinuxApp() = 0;
};

////////////////////////// Implementation of creators that create Apps for diff development stages: Alpha, Beta /////////////
class AlphaVersionAppFactory: public AppFactory {
public:
    WindowsAppAlpha* createWindowsApp() override {
        return new WindowsAppAlpha();
    }

    MacAppAlpha* createMacApp() override {
        return new MacAppAlpha();
    }

    LinuxAppAlpha* createLinuxApp() {
        return new LinuxAppAlpha();
    }
};

class BetaVersionAppFactory: public AppFactory {
public:
    WindowsAppBeta* createWindowsApp() override {
        return new WindowsAppBeta();
    }

    MacAppBeta* createMacApp() override {
        return new MacAppBeta();
    }

    LinuxAppBeta* createLinuxApp() {
        return new LinuxAppBeta();
    }
};

///////////////////////////////// Driver Client code //////////////////////////////////

int main() {
    // Create Alpha variants of app for the diff platforms
    AlphaVersionAppFactory alphaFactory;
    WindowsAppAlpha* windows_alpha_app = alphaFactory.createWindowsApp();
    MacAppAlpha* mac_alpha_app = alphaFactory.createMacApp();
    LinuxAppAlpha* linux_alpha_app = alphaFactory.createLinuxApp();

    windows_alpha_app->info();
    mac_alpha_app->info();
    linux_alpha_app->info();
    
    cout << endl;
    
    // Create beta variants of app for the diff platforms
    BetaVersionAppFactory betaFactory;
    WindowsAppBeta* windows_beta_app = betaFactory.createWindowsApp();
    MacAppBeta* mac_beta_app = betaFactory.createMacApp();
    LinuxAppBeta* linux_beta_app = betaFactory.createLinuxApp();

    windows_beta_app->info();
    mac_beta_app->info();
    linux_beta_app->info();
    
    return 0;
}