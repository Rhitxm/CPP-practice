/*
================================================================================
PROBLEM 07: Console Boot & Shutdown Tracer (Constructor/Destructor Order)
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate the deterministic execution order of constructors and destructors
in Multiple Inheritance. Prove that:
1. Base constructors execute from left-to-right based on the class declaration.
2. Destructors execute in exact reverse order upon scope exit.

HIERARCHY:
    PowerSupply     GraphicsUnit     AudioUnit
         \               |              /
          \              |             /
           \             |            /
             GamingConsole (Derived)

REQUIREMENTS:
1. Base Class 1: 'PowerSupply'
   - Protected Member:
     - float voltage;
   - Public Methods:
     - PowerSupply(float v = 12.0f);
       // Sets voltage and prints:
       // "[1] PowerSupply: Rails initialized to <voltage>V."
     - ~PowerSupply();
       // Prints: "[-1] PowerSupply: Voltage cut off safely."

2. Base Class 2: 'GraphicsUnit'
   - Protected Member:
     - string resolution;
   - Public Methods:
     - GraphicsUnit(const string& res = "1080p");
       // Sets resolution and prints:
       // "[2] GraphicsUnit: Display pipeline configured for <resolution>."
     - ~GraphicsUnit();
       // Prints: "[-2] GraphicsUnit: Framebuffers flushed and display off."

3. Base Class 3: 'AudioUnit'
   - Protected Member:
     - int sampleRateKhz;
   - Public Methods:
     - AudioUnit(int rate = 48);
       // Sets sampleRateKhz and prints:
       // "[3] AudioUnit: Audio synthesizer active at <sampleRateKhz> kHz."
     - ~AudioUnit();
       // Prints: "[-3] AudioUnit: Amplifiers muted and audio deallocated."

4. Derived Class: 'GamingConsole'
   - Publicly inherits in this EXACT order:
     'public PowerSupply, public GraphicsUnit, public AudioUnit'
   - Private Member:
     - string consoleModel;
   - Public Methods:
     - GamingConsole(const string& model, float v, const string& res, int rate);
       // Uses constructor initialization list to pass parameters to:
       // PowerSupply(v), GraphicsUnit(res), and AudioUnit(rate),
       // and initializes consoleModel.
       // Inside the constructor body, prints:
       // "[4] GamingConsole: <consoleModel> OS boot complete! Ready to play."
     - ~GamingConsole();
       // Prints:
       // "[-4] GamingConsole: <consoleModel> OS saving state and shutting down..."

5. In main():
   - Print: "=== Starting System Boot Test ==="
   - Open a local scope using curly braces: { ... }
   - Inside that scope, create an instance:
     GamingConsole mySwitch("Nintendo Switch OLED", 15.0f, "720p Handheld", 48);
   - Print: ">>> User is currently playing The Legend of Zelda..."
   - Close the curly brace.
   - Print: "=== System Test Completed ==="
================================================================================
*/

#include <iostream>
#include <string>
using namespace std;

class PowerSupply
{
protected:
  float voltage;

public:
  PowerSupply(float v = 12.0f) : voltage(v)
  {
    cout << "[1] PowerSupply: Rails initialized to " << voltage << "V." << endl;
  }

  ~PowerSupply()
  {
    cout << "[-1] PowerSupply: Voltage cut off safely." << endl;
  }
};

class GraphicsUnit
{
protected:
  string resolution;

public:
  GraphicsUnit(const string &res = "1080p") : resolution(res)
  {
    cout << "[2] GraphicsUnit: Display pipeline configured for " << resolution << "." << endl;
  }

  ~GraphicsUnit()
  {
    cout << "[-2] GraphicsUnit: Framebuffers flushed and display off." << endl;
  }
};

class AudioUnit
{
protected:
  int sampleRateKhz;

public:
  AudioUnit(int rate = 48) : sampleRateKhz(rate)
  {
    cout << "[3] AudioUnit: Audio synthesizer active at " << sampleRateKhz << " kHz." << endl;
  }

  ~AudioUnit()
  {
    cout << "[-3] AudioUnit: Amplifiers muted and audio deallocated." << endl;
  }
};

class GamingConsole : public PowerSupply, public GraphicsUnit, public AudioUnit
{
  string consoleModel;

public:
  GamingConsole(const string &model, float v, const string &res, int rate)
      : PowerSupply(v), GraphicsUnit(res), AudioUnit(rate), consoleModel(model)
  {
    cout << "[4] GamingConsole: " << consoleModel << " OS boot complete! Ready to play.";
  }

  void print() const
  {
    cout << endl
         << "Model : " << consoleModel << endl;
    cout << "Voltage : " << voltage << endl;
    cout << "Sample rate : " << sampleRateKhz << endl;
    cout << "Resolution : " << resolution << endl;
  }

  ~GamingConsole()
  {
    cout << "[-4] GamingConsole: " << consoleModel << " OS saving state and shutting down...";
  }
};

int main()
{
  cout << "=== Starting System Boot Test ===" << endl;

  {
    GamingConsole c("Ninetendo Switch", 15.0f, "720p Handeled", 48);
    cout << endl;

    c.print();

    cout << endl;
    cout << "\n>>> User is currently playing The Legend of Zelda...\n"
         << endl;
  }

  cout << "=== System Test Completed ===" << endl;

  return 0;
}