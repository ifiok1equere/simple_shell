#include "main.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		// Change the current working directory to /home/user
		if (chdir("/home/user") != 0)
		{
			perror("chdir failed");
			exit(EXIT_FAILURE);
		}
	}

	// Get the current working directory
	char cwd[256];
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd failed");
		exit(EXIT_FAILURE);
	}

	// Change the current working directory to the user-specified directory
	if (chdir(argv[1]) != 0)
	{
		perror("chdir failed");
		exit(EXIT_FAILURE);
	}

	// Get the current working directory
	char cwd[256];
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd failed");
		exit(EXIT_FAILURE);
	}
	printf("Current working directory: %s\n", cwd);
	return 0;
}


int main()
{
	// Get the absolute path of the current working directory
	char cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd failed");
		exit(EXIT_FAILURE);
	}

	// Set the PWD environment variable to the current working directory
	if (setenv("PWD", cwd, 1) != 0)
	{
		perror("setenv failed");
		exit(EXIT_FAILURE);
	}

	// Print the updated PWD environment variable
	printf("PWD=%s\n", getenv("PWD"));

	return 0;
}
