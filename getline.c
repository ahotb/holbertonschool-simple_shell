#include "hsh.h"
#define BUFFER_SIZE 1024
/**
 * _getline - reads a line from stdin using read
 * @lineptr: pointer to store the allocated line
 *
 * Return: number of characters read, or -1 on EOF/error
 */
ssize_t _getline(char **lineptr)
{
	static char buffer[BUFFER_SIZE];
	static ssize_t buf_len, buf_pos;
	char *line, *new;
	ssize_t len = 0, i, j;

	if (!lineptr)
		return (-1);

	line = malloc(1);
	if (!line)
		return (-1);

	while (1)
	{
		if (buf_pos >= buf_len)
		{
			buf_len = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_len <= 0)
			{
				if (len > 0)
					break;
				free(line);
				return (-1);
			}
		}

		for (i = buf_pos; i < buf_len; i++)
		{
			new = malloc(len + 2);
			if (!new)
				return (-1);

			for (j = 0; j < len; j++)
				new[j] = line[j];
			new[len++] = buffer[i];
			new[len] = '\0';
			free(line);
			line = new;

			if (buffer[i] == '\n')
			{
				i++;
				break;
			}
		}
		buf_pos = i;
		if (line[len - 1] == '\n')
			break;
	}
	*lineptr = line;
	return (len);
}
