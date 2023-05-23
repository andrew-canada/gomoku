#include <stdio.h>
#include <cstring>
#include <vector>
#include <ctype.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

char line[100];
char str[1000];
bool first = true;
bool curDash, prevDash;
vector<int> ind;

bool isvowel(char c)
{
    char vowelArr[6] = "aeiou";
    for (char v : vowelArr)
    {
        if (c == v)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    char *tok;

    // 1
    while (1)
    {
        fgets(line, 100, stdin);
        line[(int)strlen(line) - 1] = 0;
        if (strncmp(line, ".......", 7) == 0)
        {
            break;
        }
        if (line[(int)strlen(line) - 1] == '-')
        {
            line[(int)strlen(line) - 1] = 0;
            curDash = true;
        }
        else
        {
            curDash = false;
        }
        if (!first && !prevDash)
        {
            strcat(str, " ");
        }
        strcat(str, line);
        prevDash = curDash;
        first = false;
    }
    printf("%s\n", str);

    // 2
    //  char *str2;
    char str2[1000];
    fgets(str2, 100, stdin);
    printf("%d\n", strstr(str2, "a") - str2);

    // char *substr = "I";
    // while (strstr(str2, substr) != nullptr)
    // {
    // ind.push_back(strstr(str2, substr) - str2);
    // str2 += strlen(substr);
    // }
    // for (int i : ind)
    // {
    //     printf("%d ", i);
    // }

    // 3

    int digits, vowels, alphas;
    for (int i = digits = alphas = vowels = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
        digits += isdigit(str[i]) ? 1 : 0;
        alphas += isalpha(str[i]) ? 1 : 0;
        vowels += isvowel(str[i]);
    }
    int consonants = alphas - vowels;
    printf("%d %d %d\n", digits, consonants, vowels);

    // 4
    vector<string> tokens;
    char str3[] = "I love CS3233 Competitive Programming. i also love AlGoRiThM ";
    for (tok = strtok(str3, " ."); tok; tok = strtok(NULL, " ."))
    {
        tokens.push_back(tok);
    }
    for (string s : tokens)
    {
        printf("%s , ", s.c_str());
    }
    printf("\n");

    // 5
    map<string, int> freq;
    for (string s : tokens)
    {
        freq[s]++;
    }
    auto max = max_element(freq.begin(), freq.end(), [](auto &e1, auto &e2)
                           { return e1.second < e2.second; });
    printf("%s: %d\n", max->first.c_str(), max->second);

    // 6
    char c;
    int totChar = 0, numS = 0, num7 = 0;
    while (scanf("%c", &c), c != '\n')
    {
        totChar++;
        if (c == 's')
        {
            numS++;
        }
        else if (c == '7')
        {
            num7++;
        }
    }
    printf("%d %d %d\n", totChar, numS, num7);
}