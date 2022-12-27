#include <iostream>
#include <string>

bool isPalindrome(std::string input)
{
    std::string reverse;
    for (int i = input.size() - 1; i >= 0; i--)
    {
        reverse += input[i];
    }

    if (reverse == input)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool findPalindromeSubstr(std::string input, int substrLength)
{
    bool isFound = false;
    for (int startPos = 0; startPos <= input.length() - substrLength; startPos++)
    {
        if (isPalindrome(input.substr(startPos, substrLength)))
        {
            isFound = true;
        }
    }
    return isFound;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string input;
    std::cin >> input;
    bool isFound = false;

    int substrLength = input.length();

    do
    {
        if (findPalindromeSubstr(input, substrLength))
        {
            isFound = true;
        }
        substrLength -= 1;
    } while (substrLength > 0 && !isFound);

    std::cout << substrLength + 1;
}