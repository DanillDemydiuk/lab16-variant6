#include <iostream>
#include <string>

using namespace std;

struct Train {
    string dest;
    string num;  
    string time; 
    int total;   
    int coupe;   
    int reserved; 
};

// Функція для виводу інформації про один поїзд
void show(const Train& t) {
    cout << "Train " << t.num << " to " << t.dest << " at " << t.time
        << " - Total: " << t.total << ", Coupe: " << t.coupe
        << ", Reserved: " << t.reserved << endl;
}

// Функція для виводу поїздів до заданого пункту призначення
void showDest(Train* t, int n, const string& dest) {
    for (int i = 0; i < n; ++i) {
        if (t[i].dest == dest) show(t[i]);
    }
}

// Функція для виводу поїздів до заданого пункту призначення після заданого часу
void showDestAfter(Train* t, int n, const string& dest, const string& time) {
    int hCmp, mCmp;
    sscanf_s(time.c_str(), "%d:%d", &hCmp, &mCmp); // Розбір часу відправлення

    for (int i = 0; i < n; ++i) {
        if (t[i].dest == dest) {
            int h, m;
            sscanf_s(t[i].time.c_str(), "%d:%d", &h, &m); // Розбір часу поїзда
            if (h > hCmp || (h == hCmp && m > mCmp)) show(t[i]); // Перевірка часу
        }
    }
}

// Функція для виводу поїздів до заданого пункту призначення із загальними місцями
void showCommon(Train* t, int n, const string& dest) {
    for (int i = 0; i < n; ++i) {
        if (t[i].dest == dest && t[i].total > 0) show(t[i]);
    }
}

int main() {
    const int n = 3;
    Train t[n] = {
        {"Kyiv", "001A", "08:30", 500, 200, 300},
        {"Lviv", "002B", "14:45", 400, 150, 250},
        {"Kyiv", "003C", "18:00", 600, 250, 350}
    };

    string dest, time;

    // Вивід поїздів до заданого пункту призначення
    cout << "Enter destination: ";
    cin >> dest;
    cout << "Trains to " << dest << ":" << endl;
    showDest(t, n, dest);

    // Вивід поїздів до заданого пункту призначення після заданого часу
    cout << "Enter destination and time (HH:MM): ";
    cin >> dest >> time;
    cout << "Trains to " << dest << " after " << time << ":" << endl;
    showDestAfter(t, n, dest, time);

    // Вивід поїздів до заданого пункту призначення із загальними місцями
    cout << "Trains to " << dest << " with common seats:" << endl;
    showCommon(t, n, dest);

    return 0;
}