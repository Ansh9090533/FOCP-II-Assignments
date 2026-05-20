#include <iostream>
using namespace std;

class MovieTicket {
private:
    int movie_ids[5] = {1,2,3,4,5};

    bool booked[100][5];
    int countBooked[5];

public:
    MovieTicket() {
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 5; j++) {
                booked[i][j] = false;
            }
        }
        for(int j = 0; j < 5; j++) {
            countBooked[j] = 0;
        }
    }

    int getMovieIndex(int movieID) {
        for(int i = 0; i < 5; i++) {
            if(movie_ids[i] == movieID) return i;
        }
        return -1;
    }

    void BOOK(int user, int movie) {
        int m = getMovieIndex(movie);

        if(m == -1 || booked[user - 1][m] || countBooked[m] >= 100) {
            cout << "false\n";
        } else {
            booked[user - 1][m] = true;
            countBooked[m]++;
            cout << "true\n";
        }
    }

    void CANCEL(int user, int movie) {
        int m = getMovieIndex(movie);

        if(m == -1 || !booked[user - 1][m]) {
            cout << "false\n";
        } else {
            booked[user - 1][m] = false;
            countBooked[m]--;
            cout << "true\n";
        }
    }

    void IS_BOOKED(int user, int movie) {
        int m = getMovieIndex(movie);

        if(m != -1 && booked[user - 1][m]) cout << "true\n";
        else cout << "false\n";
    }

    void AVAILABLE_TICKETS(int movie) {
        int m = getMovieIndex(movie);

        if(m == -1) cout << "0\n";
        else cout << (100 - countBooked[m]) << "\n";
    }
};

int main() {
    MovieTicket mt;

    int Q;
    cin >> Q;

    while(Q--) {
        string query;
        cin >> query;

        if(query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            mt.BOOK(X, Y);
        }
        else if(query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            mt.CANCEL(X, Y);
        }
        else if(query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            mt.IS_BOOKED(X, Y);
        }
        else if(query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            mt.AVAILABLE_TICKETS(Y);
        }
    }

    return 0;
}
