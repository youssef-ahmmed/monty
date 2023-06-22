#include "monty.h"

/**
 * open_file - opnens the file
 * @file_name: file name
 * Return: FILE pointer of the opened file
*/
FILE *open_file(char *file_name)
{
	FILE *file_pointer;

	file_pointer = fopen(file_name, "r");

	if (file_pointer == NULL)
	{
		open_error(file_name);
	}

	return (file_pointer);
}

/**
 * read_line - reads line from file using file pointer
 * @buffer_size: size of the buffer
 * Return: number of characters tha have been read or -1 on failure
*/
ssize_t read_line(size_t *buffer_size)
{
	ssize_t characters;

	characters = getline(&execution_env.line_buffer,
						 buffer_size,
						 execution_env.file_pointer);

	return (characters);
}


/**
 * tokenize_string - tokenize a string according to a delimiter
 * @delim: space delimiter
 * Return: array of pointer characters to the tokenized string
*/
char **tokenize_string(const char *delim)
{
	char *token = NULL;
	char **tokenized_str = NULL;
	int idx = 0;

	tokenized_str = malloc(sizeof(char *) * MAX_TOKENIZED_SIZE);
	if (tokenized_str == NULL)
	{
		malloc_error();
	}

	token = strtok(execution_env.line_buffer, delim);
	while (idx < MAX_TOKENIZED_SIZE - 1 && token != NULL)
	{
		tokenized_str[idx] = malloc(strlen(token) + 1);
		if (tokenized_str[idx] == NULL)
		{
			malloc_error();
		}

		strcpy(tokenized_str[idx], token);
		token = strtok(NULL, delim);
		idx++;
	}

	tokenized_str[idx] = NULL;
	return (tokenized_str);
}
