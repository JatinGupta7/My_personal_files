 //Harsh Bamotra AC-1216
//Program to compute the factorial of a number using threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int fact; 				/* this data is shared by the thread(s) */
void *runner(void *param); 		/* threads call this function */
int main(int argc, char *argv[])
    {
	pthread_t tid; 				/* the thread identifier */
	pthread_attr_t attr; 			/* set of thread attributes */
	if (argc != 2) 
		{
			fprintf(stderr,"usage: a.out <integer value>\n");
			return -1;
		}
	if (atoi(argv[1]) < 0) 
		{
			fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
			return -1;
		}
					/* get the default attributes */
	pthread_attr_init(&attr);
							/* create the thread */
	pthread_create(&tid,&attr,runner,argv[1]);
							/* wait for the thread to exit */
	pthread_join(tid,NULL);
	printf("Factorial = %d\n",fact);
    }
					/* The thread will begin control in this function */
void *runner(void *param)
	{
		int i, upper = atoi(param);
		fact = 1;
		for (i = 1; i <= upper; i++)
			fact *= i;
		pthread_exit(0);
	}