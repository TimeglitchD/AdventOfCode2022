#pragma once
#include "Day.h"
#include <sstream>
#include <fstream>
#include <algorithm>
#include <array>

using namespace std;
class Day01 :
    public Day
{
public:
    Day01():Day("01") {
        string a = this->a();
        this->resetInput();
        string b = this->b();
        this->printSolution(a, b);
    }
private:
    string a() {
        string line;
        int highestElf = 0;
        int currentElf = 0;
        while (getline(this->input, line))
        {
            std::istringstream iss(line);
            int a;
            if (!(iss >> a)) 
            { 
                highestElf = max(highestElf, currentElf);
                currentElf = 0;
            }
            else {
                currentElf += a;
            }
        }
        return to_string(highestElf);

    }

    string b() {
        string line;
        array<int, 3> highestElves= { 0, 0, 0 };
        int currentElf = 0;
        while (getline(this->input, line))
        {
            std::istringstream iss(line);
            int a;
            if (!(iss >> a))
            {
                if (currentElf > highestElves[0]) {
                    highestElves[0] = currentElf;
                }
                currentElf = 0;
                sort(highestElves.begin(), highestElves.end());
            }
            else {
                currentElf += a;
            }
        }

        int total = 0;
        for (int x : highestElves) {
            total += x;
        }
        return to_string(total);

    }
};

