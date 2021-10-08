#pragma once

#include <string>
#include <vector>

namespace Redis
{
    std::string process_command(std::string command, std::vector<std::string> args);
}