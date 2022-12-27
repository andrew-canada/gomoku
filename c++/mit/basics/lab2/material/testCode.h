// testCode.h - header
// contains prototypes
int square(int);
int cube(int);

int square(int x)
{
    return x * x;
}

int cube(int x)
{
    return x * square(x);
}