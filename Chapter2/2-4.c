#include <stdio.h>


void squeeze(char a[],char b[])
{
	int i,j,k;
	int flag;
	for (i = j = 0;a[i] != '\0';i++)
	{
		flag = 0;	//Flag for later condition check
		for(k = 0; b[k] != '\0';k++)
		{
			if(b[k] == a[i])
			{
				flag= 1;
				break;
			}
			else{/*Still does nothing*/}
		}
		if (!flag)
		{
			a[j++] = a[i]; 
		}

	
	}
	a[j] = '\0';
}



int main(void)
{

	char arr[] = "am i gay tho";
	char arr2[] = "test";

	squeeze(arr,arr2);
	printf("%s\n",arr);




	return(0);
}
