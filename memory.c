#include<stdio.h>


int bsize[5] = {100,500,200,300,600};
int psize[5] = {212,417,112,462};
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
	int flags[5], allocation[5], i, j, frag[4];
 
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
	int i,j,lowest, frag[4],temp;
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(bsize[j]!=1)
			{
				temp=b[j]-p[i];
				if(temp>=0)
					if(lowest>temp)
					{
						psize[i]=j;
						lowest=temp;
					}
			}
		}
		
		frag[i]=lowest;
		bsize[psize[i]]=1;
		lowest=10000;
	}
	
	/*printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
	for(i=0;i<4 && psize[i]!=0;i++)
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],psize[i],b[psize[i]],frag[i]);*/
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
	int frag[4],i,j,temp,highest=0;
 	printf("\n\tMemory Management Scheme - Worst Fit");

 	for(i=0;i<4;i++)
 	{
  		for(j=0;j<5;j++)
  		{
   			if(b[j]!=1)    //if bf[j] is not allocated
   			{
    				temp=bsize[j]-psize[i];
    				if(temp>=0)
    				if(highest<temp)
    				{
     					p[i]=j;
     					highest=temp;
    				}
   			}
  		}
  	frag[i]=highest;
  	b[p[i]]=1;
  	highest=0;
 	}
 	/*printf("\nFile_no:\tProcess_size :\tBlock_no:\tBlock_size:\tFragement");
 	for(i=0;i<4;i++)
 	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,psize[i],p[i],b[p[i]],frag[i]);*/
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






