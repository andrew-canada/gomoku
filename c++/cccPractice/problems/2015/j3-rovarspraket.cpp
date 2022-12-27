#include <iostream>
#include <string>

const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
const std::string VOWELS = "aeiou";

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::string input;
    std::cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        // self
        std::cout << input[i];

        if (VOWELS.find(input[i]) == std::string::npos)
        {
            // closest vowel
            for (int j = 1; j <= 13; j++)
            {
                if (VOWELS.find(ALPHABET[ALPHABET.find(input[i]) - j]) != std::string::npos)
                {
                    std::cout << ALPHABET[ALPHABET.find(input[i]) - j];
                    break;
                }
                else if (VOWELS.find(ALPHABET[ALPHABET.find(input[i]) + j]) != std::string::npos)
                {
                    std::cout << ALPHABET[ALPHABET.find(input[i]) + j];
                    break;
                }
            }
            // closest consonant
            if (input[i] == 'z')
            {
                std::cout << 'z';
            }
            else if (VOWELS.find(ALPHABET[ALPHABET.find(input[i]) + 1]) == std::string::npos)
            {
                std::cout << ALPHABET[ALPHABET.find(input[i]) + 1];
            }
            else
            {
                std::cout << ALPHABET[ALPHABET.find(input[i]) + 2];
            }
        }
    }
}