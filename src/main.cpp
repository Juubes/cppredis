#include <iostream>
#include <string>
#include <ios>
#include <signal.h>

#include "./ctrlchandler.hpp"
#include "./server.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Starting redis server" << endl;

    for (auto i = 0; i < NSIG; i++)
        signal(i, signal_callback_handler);

    bool exit = false;

    Redis::Server server;

    while (!exit)
    {
        if (server.readCommand() == false)
            break;
    }

    return 0;
}
