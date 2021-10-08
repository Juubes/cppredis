#pragma once

#include <unordered_map>
#include <string>

using namespace std;

namespace Redis
{
    string get(const string &key);

    int set(const string &key, const string &value);
}