#include <stdio.h>

/**
 * main - Prints the alphabet.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char alp[26] = "abcdefghijklmnopqrstuvwxyz";
int i;
for (i = 25; i > -1; i--)
{
putchar(alp[i]);
}
putchar('\n');
return (0);
}
