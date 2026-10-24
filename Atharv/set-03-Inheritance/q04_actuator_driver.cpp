/*
================================================================================
PROBLEM 04: Motor Drive Current Limiter (Private Inheritance as Implementation)
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate private inheritance to enforce hardware safety. Low-level primitives
must be completely inaccessible from main(), only callable via safe high-level
derived member functions that guard against motor burn-out.

HIERARCHY:
    RawHBridge (Base)
        ▲
        │  (private inheritance)
   StepperMotor (Derived)
================================================================================
*/

#include <iostream>

using namespace std;

class RawHBridge
{
protected:
    float currentDutyCycle;

public:
    RawHBridge() : currentDutyCycle(0.0f) {}

    void setRawPWM(float duty)
    {
        currentDutyCycle = duty;
        cout << "[HW] PWM set to " << currentDutyCycle << "%" << endl;
    }

    void reversePolarity()
    {
        cout << "[HW] Direction polarity inverted" << endl;
    }

    void emergencyCutoff()
    {
        currentDutyCycle = 0.0f;
        cout << "[HW] EMERGENCY CUTOFF: Coils unpowered" << endl;
    }
};

class StepperMotor : private RawHBridge
{
private:
    int currentStepPosition;
    const float MAX_SAFE_PWM;

public:
    StepperMotor(float maxSafeDuty = 85.0f);

    void stepForward(int steps, float requestedPWM);

    void emergencyStop();

    int getPosition() const;
};

StepperMotor::StepperMotor(float maxSafeDuty)
    : MAX_SAFE_PWM(maxSafeDuty), currentStepPosition(0) {}

void StepperMotor::stepForward(int steps, float requestedPWM)
{
    float safePWM = requestedPWM;
    if (requestedPWM > MAX_SAFE_PWM)
    {
        cout << "[SAFETY]: PWM clamped from " << requestedPWM
             << "% to " << MAX_SAFE_PWM << "%" << endl;
        safePWM = MAX_SAFE_PWM;
    }

    setRawPWM(safePWM);

    currentStepPosition += steps;
    cout << "[STEPPER]: Advanced " << steps
         << " steps. Current position: " << currentStepPosition << endl;
}

void StepperMotor::emergencyStop()
{
    emergencyCutoff();
    cout << "[STEPPER]: System stopped safely." << endl;
}

int StepperMotor::getPosition() const
{
    return currentStepPosition;
}

int main()
{
    cout << "--- Motor Initialization & Step Test ---" << endl;
    StepperMotor motor(80.0f);

    motor.stepForward(200, 95.0f);
    cout << endl;

    motor.stepForward(50, 60.0f);
    cout << endl;

    cout << "--- Emergency Sequence ---" << endl;
    motor.emergencyStop();

    return 0;
}