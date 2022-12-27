#include <stdio.h>
#include <string>

// #define LOCAL

int main()
{
    goto teststring;
    // explicit number of cases
    int cases, x, y;
    scanf("%d", &cases);
    while (cases > 0)
    {
        cases--;
        scanf("%d %d", &x, &y);
        printf("%d\n", x + y);
    }

    // termination marker
    while (1)
    {
        scanf("%d %d", &x, &y);
        if (x == -1 && y == -1)
            break;
        printf("%d\n", x + y);
    }

    while (scanf("%d %d", &x, &y) && (x != -1 && y != -1))
    {
        printf("%d\n", x + y);
    }

#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    // end of file
    while (scanf("%d %d", &x, &y) != EOF)
    {
        if (x == -1 && y == -1)
        {
            printf("break in if\n");
            break;
        }
        printf("%d\n", x + y);
    }

#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
#endif

    while (scanf("%d %d", &x, &y) != EOF)
    {
        if (x == -1 && y == -1)
        {
            printf("break in if\n");
            break;
        }
        printf("%d\n", x + y);
    }

    // scanf expressions
    // will read "(10,20)"

    fflush(stdin);

    int n1, n2;
    scanf("(%d,%d)", &n1, &n2);
    printf("(%d,%d)\n", n1, n2);
    // will read "(10,20)", " ( 10, 20 )", but not "(10 ,20)"
    scanf(" ( %d, %d )", &n1, &n2);
    printf(" ( %d, %d )\n", n1, n2);

    fflush(stdin);

teststring:
    // printf("will read \"110101 eieio\"\n");
    // std::string s1 = "s1", s2 = "s2";
    // scanf("%[01]s %[aeiou]s", &s1, &s2);
    // printf("%s %s", s1.c_str(), s2.c_str());
}