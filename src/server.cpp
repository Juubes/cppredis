#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <curses.h>

#include "server.hpp"
#include "cstring"
#include "command_processor.hpp"

#define BUFFER_SIZE 4096

using namespace std;





namespace Redis
{

    /**
     * @returns false if CLI input loop should be exited 
    */
    bool Server::readCommand()
    {
        std::cout << "RedisClone > ";

        std::string input;

        getline(std::cin, input);

        if (input == "quit" || std::cin.eof())
            return false;

        std::istringstream is(input);
        std::vector<std::string> splits;
        std::string part;

        // Split args into list
        while (getline(is, part, ' '))
        {
            if (part.length() > 0)
                splits.push_back(part);
        }

        if (splits.size() == 0)
            return true;

        string command = splits[0];
        vector<string> args;

        // Make args
        copy(splits.begin() + 1, splits.end(), back_inserter(args));

        transform(command.begin(), command.end(), command.begin(), ::tolower);

        string response = process_command(command, args);


        cout << response << endl;

        return true;
    };

}
