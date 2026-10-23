/*
================================================================================
PROBLEM 02: Multi-Sensor Telemetry Packet (Multilevel & Protected Inheritance)
--------------------------------------------------------------------------------
OBJECTIVE:
Model a robotics Inertial Measurement Unit (IMU) telemetry hierarchy.
Demonstrate multilevel inheritance where protected members flow down the chain,
and derived constructors properly initialize base layers.

HIERARCHY:
SensorNode (Base) ---> Accelerometer (Derived) ---> IMUPacket (Most Derived)

REQUIREMENTS:
1. Base Class: 'SensorNode'
   - Protected Data Members:
     - int nodeID;
     - unsigned long timestamp; // In milliseconds
   - Public Constructor:
     - SensorNode(int id, unsigned long ts);

2. Intermediate Class: 'Accelerometer' (publicly inherits SensorNode)
   - Protected Data Members:
     - float ax, ay, az; // Raw acceleration components (in m/s^2)
   - Public Constructor:
     - Accelerometer(int id, unsigned long ts, float x, float y, float z);
       (Passes id and ts up to SensorNode)

3. Most Derived Class: 'IMUPacket' (publicly inherits Accelerometer)
   - Private Data Member:
     - float pitch; // Calculated tilt angle in degrees
   - Public Member Functions:
     - IMUPacket(int id, unsigned long ts, float x, float y, float z);
       (Passes parameters up to Accelerometer, then calculates pitch using:
        pitch = atan2(ay, sqrt(ax * ax + az * az)) * (180.0 / M_PI); )
     - void printPacket(); // Neatly prints Node ID, Timestamp, ax, ay, az, and Pitch

4. In main():
   - Create an instance: IMUPacket imu(101, 1729728000, 0.0f, 4.9f, 8.487f);
   - Call imu.printPacket();
================================================================================
*/

#include <iostream>
#include <cmath>

using namespace std;

// Level 1: Base Class
class SensorNode
{
protected:
    int nodeID;
    unsigned long timestamp; // In milliseconds

public:
    SensorNode(int id, unsigned long ts) : nodeID(id), timestamp(ts) {}
};

// Level 2: Intermediate Class
class Accelerometer : public SensorNode
{
protected:
    float ax, ay, az; // Acceleration along X, Y, Z axes in m/s^2

public:
    Accelerometer(int id, unsigned long ts, float x, float y, float z)
        : SensorNode(id, ts), ax(x), ay(y), az(z) {}
};

// Level 3: Most Derived Class
class IMUPacket : public Accelerometer
{
private:
    float pitch; // Tilt angle in degrees

public:
    IMUPacket(int id, unsigned long ts, float x, float y, float z)
        : Accelerometer(id, ts, x, y, z)
    {

        // Pitch calculation in degrees:
        // atan2(ay, sqrt(ax^2 + az^2)) converts radians to degrees via (180 / PI)
        pitch = atan2(ay, sqrt(ax * ax + az * az)) * (180.0 / M_PI);
    }

    void printPacket()
    {
        cout << "--- IMU Telemetry Packet ---" << endl;
        cout << "Sensor Node ID : " << nodeID << endl;
        cout << "Timestamp      : " << timestamp << " ms" << endl;
        cout << "Acceleration X : " << ax << " m/s^2" << endl;
        cout << "Acceleration Y : " << ay << " m/s^2" << endl;
        cout << "Acceleration Z : " << az << " m/s^2" << endl;
        cout << "Computed Pitch : " << round(pitch) << " degrees" << endl;
    }
};

int main()
{
    // Instantiating the most derived class:
    // Pass Node ID = 101, Timestamp = 1729728000, ax = 0.0, ay = 4.9, az = 8.487
    IMUPacket imu(101, 1729728000, 0.0f, 4.9f, 8.487f);

    imu.printPacket();

    return 0;
}