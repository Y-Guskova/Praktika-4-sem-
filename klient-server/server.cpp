#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>

using namespace std;

enum States {
    on, off, error, readcoor, movefor, turn, turnr, turnl, startcl, stopcl
};

class Human {
public:

    int x = 0, y = 0;

    int enterCoor() {
        cout << "Enter coordinats: ";
        cin >> x >> y;
        switch (state) {
            if (!(cin >> x >> y) || (x < 0 && y < 0))
                States state = error;
            States state = readcoor;
        }
    }
};

class Robot : public Human {

    commandStrategy* commandStrategy;
public:
    void getCommand() {
        void command = commandStrategy->getCommand();
    }

    int a = 0;

    int move(int x1 = 0, int y1 = 0) {
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
        sendServerMessage("Robot is moving");
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
        States state = turn;
        sendServerMessage("Robot is turning");
    }
    int clean() {
        States state = startcl;
        sendServerMessage("Robot is cleaning");
    }
    int stop() {
        States state = stopcl;
        sendServerMessage("Robot stopped");
    }
    int off() {
        States state = off;
        sendServerMessage("Robot is off");
    }
    int on() {
        States state = on;
        sendServerMessage("Robot is on");
    }
    virtual void AnswerCheck(string answer) {
        if (answer == "1")
            turn();
        if (answer == "2")
            move();
        if (answer == "3")
            cleanl();
        if (answer == "4")
            stop();
        if (answer == "5")
            off());
        if (answer == "6")
            on();
    }
    void sendServerMessage(string replyy)
    {
        int sock;
        struct sockaddr_in addr;
        sock = socket(AF_INET, SOCK_DGRAM, 0);

        addr.sin_family = AF_INET;
        addr.sin_port = htons(3425);
        addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        sendto(sock, replyy.c_str(), sizeof(replyy), 0, (struct sockaddr*)&addr, sizeof(addr));
        close(sock);
    }
    void process() {
        string reply{};
        while (reply != "stop") {
            reply = getCommand();
            AnswerCheck(reply);
        }
    }
};

class commandStrategy {
public:
    virtual void getCommand() = 0;
};

class consoleCommandStrategy : public commandStrategy {
public:
    void getCommand() {
        cout << "\nconsole";
    }

};

class netCommandStrategy : public commandStrategy {
public:
    void getCommand() {
        cout << "\nnet";
    }

}


int main() {
    Human man;
    man.enterCoor();
    while (States state == error)
    {
        States state = off;
        man.enterCoor();
    }
    Robot* p = new Robot(new consoleCommandStrategy);
    p->process();
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

            robo.off();
            break;

        case 6:

            robo.on();
