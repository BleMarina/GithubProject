
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>  
     
void *thread_main(void *a);

int main(int argc, char *argv[]) 
{    int i,n;
	printf("nombre de threads à creer:");
	scanf("%d",&n);

	pthread_t tid[n];
	int tab[n];
	
	for (i=0;i<n;i++)
	{    
		tab[i]=i;
		 pthread_create(&tid[i], NULL,&thread_main,&tab[i]);
		 
		
	}
	for (i=0;i<n;i++)
	{
		pthread_join(tid[i], NULL);
	}
}
	

void *thread_main(void *a)
{
	printf("Bonjour je suis le thread numero %d",*((int*)a));
	printf("\n");
		
}


