#include <iostream>
#include "commandStrategy.h"
#include "consoleCommandStrategy.h"
#include "netCommandStrategy.h"

using namespace std;

enum States {
    on, off, error, readcoor, movefor, turning, turnr, turnl, startcl, stopcl
};

class Human {
public:

    int x = 0, y = 0;

    void enterCoor() {
        cout << "Enter coordinats: ";
        cin >> x >> y;
        States state = on;
        switch (state) {
            if (!(cin >> x >> y) || (x < 0 && y < 0))
                States state = error;
            States state = readcoor;
        }
    }
};

class Robot : public Human {
    commandStrategy* cmdprocessor;

public:
    Robot(commandStrategy* cmdprocessor) {

    }
    string getCommand() {
        return cmdprocessor->getCommand();
    }

    int a = 0;

    void move(int x1 = 0, int y1 = 0) {
        turn();
        while (x1 != x && y1 != y) {
            if (a == 0)
            {
                States state = movefor;
                y1 = y;
                x1 = x;
            }
            if (a == 1 || a == 3)
            {
                States state = turnr;
                if (y == 0)
                    break;
                else a = 0;
            }
            if (a == 2)
            {
                States state = movefor;
                if (x == 0)
                    break;
                else a = 0;

            }
        }
    }
    void turn() {
        if (x > 0 && y == 0)
        {
            a = 1;
        }
        if (x > 0 && y == 5)
        {
            a = 2;
        }
        if (x == 5 && y > 0)
        {
            a = 3;
        }
        States state = turning;
    }
    void clean() {
        States state = startcl;
    }
    void stop() {
        States state = stopcl;
    }
    void offf() {
        States state = off;
    }
    void onn() {
        States state = on;
    }
};



int main() {
    Human man;
    Robot robo;
    States state = off;
    man.enterCoor();
    while (state == error)
    {
        state = off;
        man.enterCoor();
    }
    while (state != off)
    {
        string cmd = robo.getCommand();
    }

    while (true)
    {
        int x = 1;
        switch (x)
        {
        case 1:

            robo.turn();
            break;

        case 2:

            robo.move();
            break;

        case 3:

            robo.clean();
            break;

        case 4:

            robo.stop();
            break;

        case 5:

            robo.offf();
            break;

        case 6:

            robo.onn();
            break;
        }
    }


}
