#include<stdio.h>

int bsize[5] = {100,500,200,300,600}; //size of the available blocks
int psize[5] = {212,417,112,462}; //size of the upcoming processes
int b[5],p[4];
void First_fit();
void Best_fit();
void Worst_fit();



int main()
{	
	printf("Memory Partitions\n");
	printf("=====First_fit()======\n");
	First_fit();
	printf("\n\n=====Best_fit()======\n");
	Best_fit();
	printf("\n\n=====Worst_fit()======\n");
	Worst_fit();
	return 0;
}



void First_fit()
{
	int flags[5], allocation[5], i, j;
 
	for(i = 0; i < 5; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
	}

	for(i = 0; i < 4; i++)         //allocation as per first fit
		for(j = 0; j < 5; j++)
			if(flags[j] == 0 && bsize[j] >= psize[i])
			{
				allocation[j] = i;
				flags[j] = 1;
				break;
			}
	
	//display allocation details
	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
	for(i = 0; i < 5; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
		if(flags[i] == 1)
			printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
		else
			printf("Not allocated");
	}
}




void Best_fit()
{
	int flags[5], allocation[5], i, j;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(bsize[j]>bsize[i])
			{
				int t = bsize[i];
				bsize[i] = bsize[j];
				bsize[j] = t;
			}
		}
	}
	for(i = 0; i < 5; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
	}

	for(i = 0; i < 4; i++)         //allocation as per best fit
		for(j = 0; j < 5; j++)
			if(flags[j] == 0 && bsize[j] >= psize[i])
			{
				allocation[j] = i;
				flags[j] = 1;
				break;
			}
	//display allocation details
	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
	for(i = 0; i < 5; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
		if(flags[i] == 1)
			printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
		else
			printf("Not allocated");
	}
	
}



void Worst_fit()
{
	int flags[5], allocation[5], i, j;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(bsize[j]<bsize[i])
			{
				int t = bsize[i];
				bsize[i] = bsize[j];
				bsize[j] = t;
			}
		}
	}
	for(i = 0; i < 5; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
	}

	for(i = 0; i < 4; i++)         //allocation as per worst fit
		for(j = 0; j < 5; j++)
			if(flags[j] == 0 && bsize[j] >= psize[i])
			{
				allocation[j] = i;
				flags[j] = 1;
				break;
			}
	//display allocation details
	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
	for(i = 0; i < 5; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
		if(flags[i] == 1)
			printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
		else
			printf("Not allocated");
	}
	
}






