#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declare variables
    string name = get_string("What is your name?");

    printf("hello, %s\n", name);
}
