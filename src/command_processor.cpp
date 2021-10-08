#include <iostream>

#include "command_processor.hpp"
#include "data_storage.hpp"

using namespace std;

namespace Redis
{
    /**
     * @returns the string response to the client
    */
    string process_command(string command_name, vector<string> args)
    {
        if (command_name == "get")
        {
            if (args.size() == 0)
            {
                return "Usage: GET <key>";
            }

            return get(args.at(0));
        }
        if (command_name == "set")
        {
            if (args.size() < 2 || args.size() % 2 == 1)
            {
                return "Usage: SET <key> <value> [<key> <value>]...";
            }

            set(args.at(0), args.at(0));
            return "";
        }
        return "Invalid command";
    }

    int process_command_get(vector<string> args)
    {
        return 0;
    }
}