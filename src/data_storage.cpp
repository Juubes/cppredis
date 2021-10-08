#include <unordered_map>
#include <string>

using namespace std;

namespace Redis
{
    unordered_map<string, string> storage;

    string get(const string &key)
    {
        return storage[key];
    }

    int set(const string &key, const string &value)
    {
        storage[key] = value;
        return 1;
    }
}