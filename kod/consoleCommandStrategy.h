#pragma once
class consoleCommandStrategy : public commandStrategy {
public:
    virtual string getCommand() {
        string cmd;
        cin >> cmd;
        cout << "\nconsole";
        return cmd;
    }
}
