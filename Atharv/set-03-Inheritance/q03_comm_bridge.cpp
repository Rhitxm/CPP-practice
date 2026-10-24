/*
================================================================================
PROBLEM 03: Dual-Port Embedded Comm Channel (Multiple Inheritance & Ambiguity)
--------------------------------------------------------------------------------
OBJECTIVE:
Model an embedded gateway device bridging two distinct communication buses
(UART and CANBus). Both base protocols share identical method names. Demonstrate
how to resolve ambiguity explicitly and implement custom routing logic.

HIERARCHY:
       UART          CANBus
         \            /
          \          /
       CommBridge (Derived)

REQUIREMENTS:
1. Base Class 1: 'UART'
   - Protected Member:
     - int baudRate;
   - Public Methods:
     - UART(int baud = 115200);
     - void transmit(const string& payload);
       // Prints: "[UART @ <baudRate> baud TX]: <payload>"

2. Base Class 2: 'CANBus'
   - Protected Member:
     - int nodeID; // Hex-style CAN identifier
   - Public Methods:
     - CANBus(int id = 0x1F);
     - void transmit(const string& payload);
       // Prints: "[CANBus Node 0x<nodeID> TX]: <payload>"

3. Derived Class: 'CommBridge' (publicly inherits UART and CANBus)
   - Public Methods:
     - CommBridge(int baud, int id); // Initializes both base classes
     - void routeMessage(const string& msg, int busChannel);
       // If busChannel == 1: explicitly call UART::transmit(msg)
       // If busChannel == 2: explicitly call CANBus::transmit(msg)
       // Otherwise: print error "Invalid channel ID!"
     - void transmit(const string& payload);
       // Ambiguity resolution override:
       // Broadcasts the payload across BOTH buses by explicitly invoking
       // UART::transmit(payload) followed by CANBus::transmit(payload).

4. In main():
   - Create an instance: CommBridge bridge(9600, 0x2A);
   - Call bridge.routeMessage("System Boot OK", 1);
   - Call bridge.routeMessage("Motor RPM: 3200", 2);
   - Call bridge.transmit("EMERGENCY STOP BROADCAST");
================================================================================
*/

#include <iostream>
#include <iomanip>
using namespace std;

class UART
{
protected:
    int budrate;

public:
    UART(int bud) : budrate(bud) {}

    void transmit(const string &payload);
};

void UART ::transmit(const string &payload)
{
    cout << "[UART @ " << budrate << " baud TX]: " << payload << endl;
}

class CANBus
{
protected:
    int nodeId;

public:
    CANBus(int id = 0x1F) : nodeId(id) {}

    void transmit(const string &payload);
};
void CANBus::transmit(const string &payload)
{
    cout << "[CANBus Node 0x" << hex << uppercase << nodeId << dec << " TX]: " << payload << endl;
}

class CommBridge : public UART, public CANBus
{
public:
    CommBridge(int bud, int id) : UART(bud), CANBus(id) {}
    void routeMessage(const string &msg, int busChannel);
    void transmit(const string &payload);
};
void CommBridge::transmit(const string &payload)
{
    UART::transmit(payload);
    CANBus::transmit(payload);
}

void CommBridge::routeMessage(const string &msg, int busChannel)
{
    if (busChannel == 1)
    {
        UART::transmit(msg);
    }
    else if (busChannel == 2)
    {
        CANBus::transmit(msg);
    }
    else
    {
        cout << "Invalid channel ID!";
    }
}

int main()
{
    CommBridge c1(9600, 0x2A);
    c1.routeMessage("System Boot OK", 1);
    c1.routeMessage("Motor RPM: 3200", 2);
    c1.transmit("EMERGENCY STOP BROADCAST");
}