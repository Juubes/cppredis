#include <iostream>
#include <fstream>

#include "ctrlchandler.hpp"

using namespace std;

void signal_callback_handler(int signum)
{
    cout << "Caught signal " << signum << endl;

    // Save data
    std::ofstream stream("saved-data.txt");

    stream.close();

    // Terminate program
    exit(0);
}