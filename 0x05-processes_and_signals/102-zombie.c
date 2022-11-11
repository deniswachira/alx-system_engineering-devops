#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * infinite_while - infinite while
 * Return: always success
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}
/**
 * main - program that creates 5 zombie processes
 * Return: always success
 */
int main(void)
{
	int i;
	pid_t ZOMBIE_PID;

	for (i = 0; i < 5; i++)
	{
		ZOMBIE_PID = fork();

		if (ZOMBIE_PID > 0)
		{
			printf("Zombie process created, PID: %d\n", ZOMBIE_PID);
			sleep(1);
		}
		else
			exit(0);
	}

	infinite_while();

	return (EXIT_SUCCESS);
}

