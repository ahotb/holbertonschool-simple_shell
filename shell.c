#include "hsh.h"

/**
 * main - Entry point of the simple shell
 * @ac: argument count (unused)
 * @av: argument vector (program name)
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	(void)ac;

	shell_loop(av);

	return (0);
}
