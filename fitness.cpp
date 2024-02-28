#include <iostream>
#include <iomanip>

using namespace std;

class FitnessTracker {
private:
  int steps;
  double calories;
  double distance;

public:
  FitnessTracker() {
    steps = 0;
    calories = 0.0;
    distance = 0.0;
  }

  void addSteps(int numSteps) {
    steps += numSteps;
    calories += numSteps * 0.05; // Assuming 1 step burns 0.05 calories
    distance += numSteps * 0.0008; // Assuming average step length is 0.0008 km
  }

  void displayStats() {
    cout << "Fitness Tracker Stats:" << endl;
    cout << "Steps taken: " << steps << endl;
    cout << "Calories burned: " << fixed << setprecision(2) << calories << endl;
    cout << "Distance covered (in km): " << fixed << setprecision(2) << distance << endl;
  }
};

int main() {
  FitnessTracker tracker;
  int choice, steps;

  while (true) {
    cout << "\n1. Add steps" << endl;
    cout << "2. Display stats" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter the number of steps taken: ";
        cin >> steps;
        tracker.addSteps(steps);
        break;
      case 2:
        tracker.displayStats();
        break;
      case 3:
        cout << "Exiting the program." << endl;
        return 0; // Exit the program
      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0; // This line is unreachable due to the infinite loop, but it's good practice to include it for completeness.
}