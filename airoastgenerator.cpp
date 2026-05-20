#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string name;
    int count;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "How many roasts do you want? (Max 5): ";
    cin >> count;

    // Input validation
    if (count < 1) {
        cout << "Invalid number. Showing 1 roast.\n";
        count = 1;
    } 
    else if (count > 5) {
        cout << "Limit exceeded. Showing 5 roasts.\n";
        count = 5;
    }

    srand(time(0));

    vector<string> roasts = {
        name + ", you are so slow that even buffering looks fast compared to you.",
        name + ", your IQ is like a weak WiFi signal - unstable and unreliable.",
        name + ", if you searched yourself on Google, it would say 'No results found.'",
        name + ", your future is so unclear that even a fog machine would be jealous.",
        name + ", you are so useless that even a calculator would refuse to process you.",
        name + ", if laziness were a competition, you would come second - because winning takes effort.",
        name + ", you are so confusing that even error messages cannot explain you.",
        name + ", your brain seems permanently stuck in airplane mode.",
        name + ", you are so unnecessary that even spam filters would ignore you.",
        name + ", your logic works like random system updates - unexpected and never helpful.",
        name + ", you are so boring that watching paint dry feels like entertainment.",
        name + ", if stupidity had a price, you would be the most expensive person alive.",
        name + ", you are so irrelevant that even background noise gets more attention than you."
    };

    cout << "\nRoasts:\n";

    for (int i = 0; i < count; i++) {
        int randomIndex = rand() % roasts.size();
        cout << i + 1 << ". " << roasts[randomIndex] << endl;
    }

    return 0;
}
