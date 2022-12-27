#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int input, steps;
    string prevDir, instruction;
    vector<string> instructions;
    do
    {
        scanf("%d", &input);
        if (input == 99999)
        {
            break;
        }
        steps = input % 1000;
        if ((input / 10'000 + input / 1000) == 0)
        {
            instruction = prevDir + to_string(steps);
            instructions.push_back(instruction);
        }
        else if ((input / 10'000 + input / 1000) % 2 == 0)
        {
            prevDir = "right ";
            instruction = prevDir + to_string(steps);
            instructions.push_back(instruction);
        }
        else
        {
            prevDir = "left ";
            instruction = prevDir + to_string(steps);
            instructions.push_back(instruction);
        }
    } while (input != 99999);

    for (string s : instructions)
    {
        printf("%s\n", s.c_str());
    }
}