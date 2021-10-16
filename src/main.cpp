#include <iostream>
#include <string>
#include <ios>
#include <signal.h>
#include <curses.h>

#include "./ctrlchandler.hpp"
#include "./server.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Starting redis server" << endl;

    for (auto i = 0; i < NSIG; i++)
        signal(i, signal_callback_handler);

    Redis::Server server;

    initscr();
    cbreak();
    noecho();

    while (1)
    {
        if (server.readCommand() == false)
            break;
    }

    endwin();
    return 0;
}
