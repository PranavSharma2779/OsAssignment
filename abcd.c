#include<stdio.h>

#define N 10 

typedef struct
{ 
	int process__id, arrival__time, burst__time, priority;
	int q, ready; 
}process__structure; 

int Queue(int t1) 
{ 
	if (t1 == 0 || t1 == 1 || t1 == 2 || t1 == 3) 
	{ 
		return 1; 
	} 
	else
	{
		return 2; 
	}
} 

int main() 
{ 
	int limit, c, temp__process, time, j, y; 
	process__structure temp; 
	printf("Enter Total Number of Processes:\t"); 
	scanf("%d", &limit);  
	process__structure process[limit]; 
	for(c = 0; c < limit; c++) 
	{ 
		printf("\nProcess ID :\t"); 
		scanf("%d", &process[c].process__id); 
		printf("Arrival Time :\t"); 
		scanf("%d", &process[c].arrival__time); 
		printf("Burst Time :\t"); 
		scanf("%d", &process[c].burst__time); 
		printf("Process Priority :\t"); 
		scanf("%d", &process[c].priority); 
		temp__process = process[c].priority; 
		process[c].q = Queue(temp__process);
		process[c].ready = 0; 
	}
	time = process[0].burst__time; 
	for(y = 0; y < limit; y++) 
	{ 
		for(c = y; c < limit; c++) 
		{ 
			if(process[c].arrival__time< time) 
			{
				process[c].ready = 1; 
			} 
		} 
		for(c = y; c < limit - 1; c++) 
		{
			for(j = c + 1; j < limit; j++) 
			{ 
				if(process[c].ready == 1 && process[j].ready == 1) 
				{ 
					if(process[c].q == 2 && process[j].q == 1) 
					{ 
						temp = process[c]; 
						process[c] = process[j]; 
						process[j] = temp; 
					} 
				} 
			} 
		} 
		for(c = y; c < limit - 1; c++) 
		{ 
			for(j = c + 1; j < limit; j++) 
			{
				if(process[c].ready == 1 && process[j].ready == 1) 
				{ 
					if(process[c].q == 1 && process[j].q == 1) 
					{ 
						if(process[c].burst__time> process[j].burst__time) 
						{ 
							temp = process[c]; 
							process[c] = process[j]; 
							process[j] = temp; 
						} 
						else
						{ 
							break; 
						} 
					} 
				} 
			} 
		} 
		printf("\nProcess[%d]:\tTime:\t%d To %d\n", process[y].process__id, time, time + process[y].burst__time); 
		time = time + process[y].burst__time; 
		for(c = y; c < limit; c++) 
		{ 
			if(process[c].ready == 1) 
			{ 
				process[c].ready = 0; 
			} 
		} 
	} 
	return 0; 
}
