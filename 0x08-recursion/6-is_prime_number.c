#include "main.h"

/**
 * is_divisible - Checks if a number is divisible.
 * @num: The number to be checked.
 * @div: The divisor.
 *
 * Return: If the number is divisible - 0.
 *         If the number is not divisible - 1.
 */

int is_prime(int n, int divisor)
{
if (n == divisor)
return (1);
if (n % divisor == 0)
return (0);
return (is_prime(n, divisor + 1));

}

/**
* is_prime_number - check if prime
* @n: number to check
* Return: 1 if prime, 0 if not
*/

int is_prime_number(int n)
{
int divisor = 3;

if (n % 2 == 0 || n < 2)
return (0);
if (n == 2)
return (1);

return (is_prime(n, divisor));
}
