// main method for user input and directions

#include <iostream>
#include "driver.cpp"
#include "number.cpp"
using namespace std;

int main() {
    
    cout << "Welcome to StatHelper" << endl;
    cout << "Type 1 to generate random set of ten numbers" << endl;
    cout << "Type 2 to customize set of numbers" << endl;
    int x;
    cin >> x;
    if (!(x == 2 || x == 1)){
        cout << "INVALID INPUT" << endl;
        return 0;
    }
    else if (x == 1){
        Driver d;
        d.generateRandom();
        cout << "Here are your ten numbers:" << endl;  
        d.printNumbers();
        int y = 1;
        while (y != 0){
            cout << "Type 1 for mean, 2 for standard deviation, 3 for range, 4 for median, 5 for mode, and 0 to quit" << endl;
            cin >> y;
            if (y == 1){
                cout << "Mean: " + to_string(d.mean()) << endl;
            }
            else if (y == 2){
                cout << "Standard Deviation: " + to_string(d.stdv()) << endl;
            }
            else if (y == 3){
                cout << "Range: " + to_string(d.range()) << endl;
            }
            else if (y == 4){
                cout << "Median: " + to_string(d.median()) << endl;
            }
            else if (y == 5){
                cout << "Mode: " + to_string(d.mode()) << endl;
            }
            else if (y != 0){
                cout << "Type a valid number" << endl;
            }
        }
    }
    else if (x == 2){
        Driver d;
        int y;
        cout << "How many numbers? (Max 10)" << endl;
        cin >> y;
        if (y < 1 || y > 10){
            cout << "Invalid quantity of numbers" << endl;
            return 0;
        }
        for (int i = 0; i < y; i++){
            int z;
            cout << "Enter a number" << endl;
            cin >> z;
            try{
                d.addNumber(z);
            }
            catch(...){
                cout << "Invalid number" << endl;
                return 0;
            }
        }
        cout << "Here are your numbers:" << endl;  
        d.printNumbers();
        int w = 1;
        while (w != 0){
            cout << "Type 1 for mean, 2 for standard deviation, 3 for range, 4 for median, 5 for mode, and 0 to quit" << endl;
            cin >> w;
            if (w == 1){
                cout << "Mean: " + to_string(d.mean()) << endl;
            }
            else if (w == 2){
                cout << "Standard Deviation: " + to_string(d.stdv()) << endl;
            }
            else if (w == 3){
                cout << "Range: " + to_string(d.range()) << endl;
            }
            else if (w == 4){
                cout << "Median: " + to_string(d.median()) << endl;
            }
            else if (w == 5){
                cout << "Mode: " + to_string(d.mode()) << endl;
            }
            else if (w != 0){
                cout << "Type a valid number" << endl;
            }
        }



    }

    return 0; 
}