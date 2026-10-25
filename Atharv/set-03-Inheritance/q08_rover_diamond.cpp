/*
================================================================================
PROBLEM 08: Space Rover Power Mesh (Virtual Base Class & Diamond Problem)
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate how virtual inheritance resolves the Diamond Problem, ensuring
only ONE shared copy of a common grandparent base class exists in memory,
eliminating ambiguity and saving memory.

HIERARCHY:
               PowerSource (Grandparent)
                 /                   \
        NavigationUnit            RoboticArm
                 \                   /
                  \                 /
                   MarsRover (Child)

REQUIREMENTS:
1. Base Class (Grandparent): 'PowerSource'
   - Protected Member:
     - float batteryChargePercent; // 0.0 to 100.0%
   - Public Methods:
     - PowerSource(float initialCharge = 100.0f);
     - void consumePower(float amount); // Deducts power and prints consumption
     - float getBatteryCharge() const;

2. Derived Class 1: 'NavigationUnit' (VIRTUAL public inheritance from PowerSource)
   - Protected Member:
     - string sensorType; // e.g., "Stereo Vision Lidar"
   - Public Methods:
     - NavigationUnit(const string& sensor, float initialCharge);
     - void scanTerrain(); // Deducts 5.0% power via consumePower(5.0f)

3. Derived Class 2: 'RoboticArm' (VIRTUAL public inheritance from PowerSource)
   - Protected Member:
     - int numJoints; // e.g., 6 DOF
   - Public Methods:
     - RoboticArm(int joints, float initialCharge);
     - void drillRockSample(); // Deducts 12.0% power via consumePower(12.0f)

4. Most Derived Class: 'MarsRover' (inherits NavigationUnit and RoboticArm)
   - Private Member:
     - string roverName;
   - Public Methods:
     - MarsRover(const string& name, const string& sensor, int joints, float initialCharge);
       // CRITICAL RULE OF VIRTUAL BASES:
       // The MOST DERIVED CLASS (MarsRover) is directly responsible for initializing
       // the virtual base class (PowerSource) in its initialization list!
     - void printStatus() const;
       // Directly accesses batteryChargePercent without any ambiguity!

5. In main():
   - Create 'MarsRover curiosity("Curiosity", "Lidar + HD Cams", 6, 100.0f);'
   - Call curiosity.scanTerrain();
   - Call curiosity.drillRockSample();
   - Call curiosity.printStatus();
   - Verify: battery starts at 100%, drops by 5% (95%), then drops by 12% (83%).
================================================================================
*/

#include <iostream>
#include <string>

using namespace std;

class PowerSource
{
protected:
    float batteryChargePercent;

public:
    PowerSource(float initialCharge = 100.0f) : batteryChargePercent(initialCharge) {}

    void consumePower(float amount)
    {
        batteryChargePercent -= amount;
        if (batteryChargePercent < 0.0f)
        {
            batteryChargePercent = 0.0f;
        }
    }

    float getBatteryCharge() const
    {
        return batteryChargePercent;
    }
};

class NavigationUnit : virtual public PowerSource
{
protected:
    string sensorType;

public:
    NavigationUnit(const string &sensor, float initialCharge)
        : PowerSource(initialCharge), sensorType(sensor) {}

    void scanTerrain()
    {
        consumePower(5.0f);
    }
};

class RoboticArm : virtual public PowerSource
{
protected:
    int numJoints;

public:
    RoboticArm(int joints, float initialCharge)
        : PowerSource(initialCharge), numJoints(joints) {}

    void drillRockSample()
    {
        consumePower(12.0f);
    }
};

class MarsRover : public NavigationUnit, public RoboticArm
{
    string roverName;

public:
    MarsRover(const string &name, const string &sensor, int joints, float initialCharge)
        : PowerSource(initialCharge),
          NavigationUnit(sensor, initialCharge),
          RoboticArm(joints, initialCharge),
          roverName(name) {}

    void printdata() const
    {
        cout << "Rover name        : " << roverName << endl;
        cout << "Sensors           : " << sensorType << endl;
        cout << "Arm Joints        : " << numJoints << endl;
        cout << "Battery remaining : " << batteryChargePercent << "%" << endl;
    }
};

int main()
{
    MarsRover rover("Curiosity", "Lidar + HD Cams", 6, 100.0f);
    rover.scanTerrain();
    rover.drillRockSample();
    rover.printdata();

    return 0;
}