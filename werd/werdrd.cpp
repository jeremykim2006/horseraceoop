#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

class Horse {
public:
    Horse(char name) : name(name), position(0) {}

    void move() {
        position += rand() % 2 + 1;
    }

    char getName() const {
        return name;
    }

    int getPosition() const {
        return position;
    }

    void display() const {
        cout << name << ": ";
        for (int b = 0; b <= position; b++)
            cout << " ";
        cout << "~n-n^" << endl << endl;
    }

private:
    char name;
    int position;
};

class Race {
public:
    Race() {
        srand(static_cast<unsigned int>(time(0))); 
    }

    void addHorse(const Horse& horse) {
        horses.push_back(horse);
    }

    void start() {
        for (int a = 0; a <= 25; a++) {
            system("cls");
            for (auto& horse : horses) {
                horse.move();
                horse.display();
            }
            for (int timer = 0; timer <= 100000000; timer++); // Delay
        }
    }

    char determineWinner() {
        return max_element(horses.begin(), horses.end(), [](const Horse& a, const Horse& b) {
            return a.getPosition() < b.getPosition();
        })->getName();
    }

private:
    vector<Horse> horses;
};

int main() {
    Race race;
    race.addHorse(Horse('A'));
    race.addHorse(Horse('B'));
    race.addHorse(Horse('C'));
    race.addHorse(Horse('D'));

    char bethorse;
    double betcash = 0;
    cout << "Who do you think is going to win?\nPlace your Bet and find out!\n> $";
    cin >> betcash;
    cout << "On what horse? A, B, C, or D?\n> ";
    cin >> bethorse;
    bethorse = toupper(bethorse);

    race.start();

    char winner = race.determineWinner();
    cout << "Winning Horse: Horse " << winner << endl;
    if (winner == bethorse) {
        cout << "You Won!" << endl;
    } else {
        cout << "You Lost!" << endl;
    }

    system("pause");
    return 0;
}
