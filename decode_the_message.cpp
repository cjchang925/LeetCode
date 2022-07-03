#include <string>
#include <map>
#include <iostream>
using namespace std;

string decodeMessage(string key, string message) {
    map<char, char> mapping;
    int counter = 0;
    for(const auto& ele : key) {
        if(ele == ' ')
            continue;
        if(mapping.count(ele) == 0) {
            mapping[ele] = counter + 97;
            counter++;
        }
    }

    for(auto& ele : message) {
        if(ele == ' ')
            continue;
        ele = mapping[ele];
    }

    return message;
}
