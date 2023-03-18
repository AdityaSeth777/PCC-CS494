#include <stdio.h>
void display(int * arr)
{
	int i;
	for(i=0;i<10;i++)
		printf(" %d ",arr[i]);
	printf("\n");
}
int is_valid(int *arr)
{
	int i,j,flag=1,n,count,c2;
	for (i=0;i<10&&flag;i++)
	{
		count=0;
		for(j=0;j<10;j++)
		{
			if(arr[j]==i)
				count++;
		}
		if(arr[i]!=count)
			flag=0;
		
	}
	if(flag)
		return 1;
	
	for(i=0;i<9;i++)
	{
		
		n=arr[i];
		count=0;
		c2=1;
		for(j=i+1;j<10;j++)
		{
			if(arr[j]==i)
			{
				count++;
			}
			else if(arr[j]==arr[i])
				c2++;
		}
		if(n!=count || arr[n]!=c2 && arr[i])
		{
			arr[arr[i]]=0;
			 if(count!=n && count)
				arr[i]=count;
			arr[arr[i]]=c2;
			return 0;
		}
		
		//display(arr);
	}
	return 0;
}

int main()
{
	int arr[]={9,0,0,0,0,0,0,0,0,0};
	int valid=is_valid(arr);
	while(!valid)
	{
		valid=is_valid(arr);
	}
	printf("The only possible number is: ");
	display(arr);
}
