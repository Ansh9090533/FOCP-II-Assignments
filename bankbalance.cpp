#include <iostream>
using namespace std;

class Bank {
private:
    int users[100];
    float bal[100];

public:
    Bank() {
        for (int i = 0; i < 100; i++) {
            users[i] = -1;
            bal[i] = 0;
        }
    }

    int getUserIndex(int userID) {
        for(int i = 0; i < 100; i++) {
            if(users[i] == userID) return i;
        }
        return -1;
    }

    int getEmptyIndex() {
        for(int i = 0; i < 100; i++) {
            if(users[i] == -1) return i;
        }
        return -1;
    }

    void CREATE(int u, float b) {
        int idx = getUserIndex(u);

        if (idx != -1) {
            bal[idx] += b;
            cout << "false\n";
        } else {
            int empty = getEmptyIndex();
            users[empty] = u;
            bal[empty] = b;
            cout << "true\n";
        }
    }

    void DEBIT(int u, float b) {
        int idx = getUserIndex(u);

        if (idx == -1 || bal[idx] < b) {
            cout << "false\n";
        } else {
            bal[idx] -= b;
            cout << "true\n";
        }
    }

    void CREDIT(int u, float b) {
        int idx = getUserIndex(u);

        if (idx == -1) {
            cout << "false\n";
        } else {
            bal[idx] += b;
            cout << "true\n";
        }
    }

    void BALANCE(int u) {
        int idx = getUserIndex(u);

        if (idx == -1) {
            cout << "-1\n";
        } else {
            cout << bal[idx] << "\n";
        }
    }
};

int main() {
    Bank bank;

    int Q;
    cin >> Q;

    while(Q--) {
        string query;
        cin >> query;

        if(query == "CREATE") {
            int X;
            float Y;
            cin >> X >> Y;
            bank.CREATE(X, Y);
        }
        else if(query == "DEBIT") {
            int X;
            float Y;
            cin >> X >> Y;
            bank.DEBIT(X, Y);
        }
        else if(query == "CREDIT") {
            int X;
            float Y;
            cin >> X >> Y;
            bank.CREDIT(X, Y);
        }
        else if(query == "BALANCE") {
            int X;
            cin >> X;
            bank.BALANCE(X);
        }
    }

    return 0;
}
