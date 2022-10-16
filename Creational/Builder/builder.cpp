#include <iostream>
#include <unordered_map>
using namespace std;

/////////////////////////////////////////////////// Product /////////////////////////////
/*
    Represents a computer
*/
class Computer {
public:
    // Stores the specifications of computer
    unordered_map<string, string> specs;

    void showComputerSpecs() {
        cout << "Computer Specifications\n";
        for(auto [prop, spec]: specs)
            cout << prop << " : " << spec << endl;
    }
};

/////////////////////////////////////////////// Builder ///////////////////////////////////
/*
    Builder is responsible for creating a computer instance.
    It has methods to configure the different hardware requirements
    as per requirement.
*/
class ComputerBuilderBase {
public:
    Computer* computer;

    ComputerBuilderBase() {
        computer = new Computer();
    }

    ~ComputerBuilderBase() {
        delete computer;
    }

    // Deletes the current computer instance and creates a 
    // new instance
    void resetComputer() {
        delete computer;
        computer = new Computer();
    }

    // Get the configured instance of computer
    Computer* getComputer() {
        return this->computer;
    }

    virtual void addRAM(int gb) {
        this->computer->specs["RAM"] = to_string(gb);
    } 

    virtual void addStorage(int gb) {
        this->computer->specs["Storage"] = to_string(gb);
    }

    virtual void addCPUCores(int cores) {
        this->computer->specs["CPU"] = to_string(cores);
    }
};

class GamingComputerBuilder: public ComputerBuilderBase {
public:
    // Below are the additional specs related to a gaming computer

    void setGPUMemory(int gb) {
        this->computer->specs["GPU_Memory"] = to_string(gb);
    }

    void addSSDStorage(int gb) {
        this->computer->specs["SSD_Storage"] = to_string(gb);
    }

    void addRGB(bool use) {
        this->computer->specs["RGB"] = to_string(use);
    }
};

///////////////////////////////////////////////////////////// Director //////////////////////////////////
/*
    Director has a blueprint (pre-determined specs) for creating specific kinds of computer.
    Gaming computer has specs related for gaming.
    Normal computer has standard specs only.
*/
class ComputerBuilderDirector {
public:
    void createGamingComputer(GamingComputerBuilder& computerBuilder) {
        // reset any specs if set
        computerBuilder.resetComputer();

        computerBuilder.addCPUCores(8);
        computerBuilder.addRAM(16);
        computerBuilder.addStorage(1024);
        computerBuilder.addRGB(true);
        computerBuilder.addSSDStorage(true);
        computerBuilder.addSSDStorage(512);
    }

    void createNormalComputer(ComputerBuilderBase& computerBuilder) {
        // reset any specs if set
        computerBuilder.resetComputer();

        computerBuilder.addCPUCores(4);
        computerBuilder.addRAM(8);
        computerBuilder.addStorage(1024);
    }
};

int main() {
    ///////////////////////// Builder Usage /////////////////////////
    /*
        Using a builder, client can create and configure a computer on its own
    */
    // Creating a gaming and normal computer by the client using the builder alone
    GamingComputerBuilder computerBuilder;
    computerBuilder.addCPUCores(8);
    computerBuilder.addRAM(16);
    computerBuilder.addStorage(1024);
    computerBuilder.addRGB(true);
    computerBuilder.addSSDStorage(true);
    computerBuilder.addSSDStorage(512);

    Computer* gamingComputer = computerBuilder.getComputer();
    gamingComputer->showComputerSpecs();
    cout << endl;

    // reset the computer so that a normal computer can be created
    computerBuilder.resetComputer();

    computerBuilder.addCPUCores(4);
    computerBuilder.addRAM(8);
    computerBuilder.addStorage(1024);

    Computer* normalComputer = computerBuilder.getComputer();
    normalComputer->showComputerSpecs();
    cout << endl;

    //////////////////////// Director usage ///////////////////////////////
    // Using a director to create a computer. Director already has 
    // a blueprint for creating computers
    ComputerBuilderDirector computerDirector;
    // get a gaming computer
    computerDirector.createGamingComputer(computerBuilder);
    computerBuilder.getComputer()->showComputerSpecs();
    cout << endl;
    
    // create a normal computer
    computerDirector.createNormalComputer(computerBuilder);
    computerBuilder.getComputer()->showComputerSpecs();
}