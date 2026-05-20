#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    srand(time(0));

    vector<string> excuses = {
        name + " could not complete the assignment because the internet connection stopped working unexpectedly.",
        name + " was unwell last night and could not focus on the work.",
        name + " experienced a power outage at home, which delayed progress.",
        name + " misunderstood the deadline and believed it was due later.",
        name + " faced a system crash and lost all progress.",
        name + " had a family emergency that required immediate attention.",
        name + " was occupied helping a relative and could not find time to complete the task.",
        name + " accidentally worked on the wrong file and realized it too late.",
        name + " was preparing for another exam and mismanaged time.",
        name + " encountered technical issues with the required software.",
        name + " was unable to access the necessary resources in time.",
        name + " started late due to personal reasons and could not finish on time."
    };

    int randomIndex = rand() % excuses.size();

    cout << "\nGenerated Excuse:\n";
    cout << excuses[randomIndex] << endl;

    return 0;
}
