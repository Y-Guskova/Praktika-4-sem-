#include <iostream>

using namespace std;

enum States{
on, off, error, readcoor, movefor, turnr, turnl, startcl, stopcl};

class Robot {
public:
    States state = on;
    int x=0, y=0, a=0;
    cout << "Enter coordinats: ";
    cin >> x >> y;
    switch (state) {
        if (!(cin >> x >> y) || (x<0 && y<0))
            States state = error;
        States state = readcoor;
    }

    
    int move(int x1 = 0, int y1 = 0) {
        turn();
        while (x1 != x && y1 != y) {
            if (a = 0)
            {
                States state = movefor;
                y1 = y;
                x1 = x;
            }
            if (a = 1 || a = 3)
            { 
                States state = turnr; 
                if (y = 0)
                    break;
                else a = 0;
            }
            if (a = 2)
            {
                States state = movefor;
                if (x = 0)
                    break;
                else a = 0;

            }
        }
        clean();
        stop();
    }
    int turn() {
        if (x > 0 && y = 0)
        {
            a = 1;
        }
        if (x > 0 && y = 5)
        {
            a = 2;
        }
        if (x = 5 && y > 0)
        {
            a = 3;
        }
    }
    int clean() {
        States state = startcl;
    }
    int stop() {
        States state = stopcl;
    }

};
int main() {
    Robot first;
    if (States state = error;)
        break;
    States state = off;
}
