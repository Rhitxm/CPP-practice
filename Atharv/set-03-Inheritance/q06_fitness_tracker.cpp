/*
================================================================================
PROBLEM 06: Smartwatch Fitness Tracker (Protected Data & Derived Processing)
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate how protected arrays and variables can be accessed and processed
directly by a derived class to compute health metrics, while keeping internal
sensor details encapsulated from main().

HIERARCHY:
    RawStepSensor (Base)
           ▲
           │ (public inheritance)
   SmartwatchTracker (Derived)

REQUIREMENTS:
1. Base Class: 'RawStepSensor'
   - Protected Data Members:
     - const string deviceModel;
     - int hourlySteps[4]; // Steps recorded over a 4-hour workout window
     - int averageHeartRate; // In beats per minute (BPM)
   - Public Methods:
     - RawStepSensor(const string& model, int s1, int s2, int s3, int s4, int hr)
       // Initialize deviceModel using initialization list,
       // and populate hourlySteps[4] and averageHeartRate.

2. Derived Class: 'SmartwatchTracker' (publicly inherits RawStepSensor)
   - Private Data Members:
     - float strideLengthMeters; // Average step distance (e.g., 0.75 meters)
   - Public Methods:
     - SmartwatchTracker(const string& model, int s1, int s2, int s3, int s4,
                         int hr, float stride = 0.75f)
       // Passes parameters to RawStepSensor via initialization list,
       // and initializes strideLengthMeters.
     - int getTotalSteps() const;
       // Loops through protected hourlySteps[] and returns total sum.
     - float getTotalDistanceKm() const;
       // Formula: (totalSteps * strideLengthMeters) / 1000.0
     - float getCaloriesBurned() const;
       // Formula: totalSteps * 0.045 (approx 0.045 kcal burned per step)
     - string getActivityZone() const;
       // Based on averageHeartRate:
       // - If hr < 100: "Warm-Up / Rest"
       // - If hr >= 100 and hr < 140: "Fat Burn Zone"
       // - If hr >= 140: "Cardio Peak Zone"
     - void displayWorkoutSummary() const;
       // Prints a clean workout report showing: Device Model, Total Steps,
       // Total Distance (in km), Calories Burned (in kcal), Avg Heart Rate,
       // and Activity Zone.

3. In main():
   - Create a tracker:
     SmartwatchTracker watch("Apple Watch Series 10", 1200, 2400, 3100, 1800, 135);
   - Call watch.displayWorkoutSummary();
================================================================================
*/


// use const after function which tells the compiler that this function will not modify any member variables of the class. This is important for functions that are meant to be read-only, as it allows the compiler to optimize the code and also helps prevent accidental modifications of member variables. In this case, all the getter functions and the displayWorkoutSummary() function are marked as const because they do not modify any member variables of the SmartwatchTracker class.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class RawStepSensor
{
protected:
  const string deviceModel;
  int hourlySteps[4];
  int averageHeartRate;

public:
  RawStepSensor(const string &model, int s1, int s2, int s3, int s4, int hr) : deviceModel(model), averageHeartRate(hr)
  {
    hourlySteps[0] = s1;
    hourlySteps[1] = s2;
    hourlySteps[2] = s3;
    hourlySteps[3] = s4;
  }
};

class SmartwatchTracker : public RawStepSensor
{
  float strideLengthMeters;

public:
  SmartwatchTracker(const string &model, int s1, int s2, int s3, int s4, int hr, float stride = 0.75f) : RawStepSensor(model, s1, s2, s3, s4, hr), strideLengthMeters(stride) {}

  int totalSteps() const
  {

    int a = 0;
    for (int i = 0; i < 4; i++)
    {
      a += hourlySteps[i];
    }

    return a;
  }

  float totaldistance() const
  {
    return (totalSteps() * strideLengthMeters) / 1000.00f;
  }

  float getCaloriesBurned() const
  {
    return totalSteps() * 0.045;
  }

  string getActivityZone() const
  {
    if (averageHeartRate < 100)
    {
      return "Warm-Up / Rest";
    }
    else if (averageHeartRate < 140)
    {
      return "Fat Burn Zone";
    }
    else
    {
      return "Cardio Peak Zone";
    }
  }

  void displayWorkoutSummary() const
  {
    cout << fixed << setprecision(2);
    cout << "======= FITNESS WORKOUT REPORT =======" << endl;
    cout << "Device Model   : " << deviceModel << endl;
    cout << "Total Steps    : " << totalSteps() << " steps" << endl;
    cout << "Total Distance : " << totaldistance() << " km" << endl;
    cout << "Calories Burned: " << getCaloriesBurned() << " kcal" << endl;
    cout << "Avg Heart Rate : " << averageHeartRate << " bpm" << endl;
    cout << "Activity Zone  : " << getActivityZone() << endl;
    cout << "=======================================" << endl;
  }
};

int main()
{
  SmartwatchTracker watch("Apple Watch Series 10", 1200, 2400, 3100, 1800, 135);
  watch.displayWorkoutSummary();

  return 0;
}
