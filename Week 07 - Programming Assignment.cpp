// Week 07 - Programming Assignment.cpp created by Joshua Nichols.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
// Declared Constant Variables.
const int NUMBER_OF_BOWLERS = 10; // Columns.
const int NUMBER_OF_SCORES = 5; // Rows.
// Struct Data Structure.
struct Bowler {
    string bowlerName{};
    int bowlerScore[NUMBER_OF_SCORES]{};
    double average = 0;
};
// Declared Void Functions.
void GetBowlingData(struct Bowler arrBowler[]);
void GetAverageScore(struct Bowler arrBowler[]);
void PrettyPrintResults(struct Bowler arrBowler[]);
int main() {
    cout << setw(25) << setfill('*') << "" << endl;
    cout << setw(4) << setfill('*') << "" << " Bowler's Scores " << setw(4) << setfill('*') << "" << endl;
    cout << setw(25) << setfill('*') << "" << endl;
    // Declaring a Struct.
    Bowler arrBowler[NUMBER_OF_BOWLERS];
    // Calling Void Functions.
    GetBowlingData(arrBowler);
    GetAverageScore(arrBowler);
    PrettyPrintResults(arrBowler);
}
void GetBowlingData(struct Bowler arrBowler[]) {
    ifstream inFile("BowlingScores.txt");
    // Extracts Variables from a txt file and puts them into a One-Dimensional Array.
    for (int i = 0; i < NUMBER_OF_BOWLERS; i++) {
        inFile >> arrBowler[i].bowlerName;
        for (int j = 0; j < NUMBER_OF_SCORES; j++) {
            inFile >> arrBowler[i].bowlerScore[j];
        }
    }
    inFile.close();
}
void GetAverageScore(struct Bowler arrBowler[]) {
    // Averages Bowler's Score by Total Amount and Dividing it by the  Number of Scores.
    for (int i = 0; i < NUMBER_OF_BOWLERS; i++) {
        double total = 0.0;
        for (int j = 0; j < NUMBER_OF_SCORES; j++) {
            total = total + arrBowler[i].bowlerScore[j];
        }
        double average = total / NUMBER_OF_SCORES;
        arrBowler[i].average = average;
    }
}
void PrettyPrintResults(struct Bowler arrBowler[]) {
    // Displays Bowler's Final Results. 
    for (int i = 0; i < NUMBER_OF_BOWLERS; i++) {
        cout << setw(25) << setfill('*') << "" << endl;
        cout << "Bowler's Name: " << arrBowler[i].bowlerName << endl;
        cout << "Score: ";
        for (int j = 0; j < NUMBER_OF_SCORES; j++) {
            cout << arrBowler[i].bowlerScore[j] << " ";
        }
        cout << endl;
        cout << "Average Score: " << arrBowler[i].average << endl;
        cout << setw(25) << setfill('*') << "" << endl;
    }
    cout << setw(7) << setfill('*') << "" << " COMPLETED " << setw(7) << setfill('*') << "" << endl;
}
// Visuals weren't present previously in instructions.
// Program functions properly with sturct; data sturture as illustrated in instructions.
