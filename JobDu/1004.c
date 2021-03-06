// http://ac.jobdu.com/problem.php?pid=1004
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1, n2;
	int *array1, *array2, *array3;
	int i, j, k, length;
	//freopen("1004.in","r",stdin);
	while(1)
	{
		if(scanf("%d",&n1) == EOF)
			return 0;
		array1 = (int *)malloc(n1 * sizeof(int));
		for(i = 0;i < n1;i++)
			scanf("%d",&array1[i]);

		scanf("%d",&n2);
		array2 = (int *)malloc(n2 * sizeof(int));
		for(i = 0;i < n2;i++)
			scanf("%d",&array2[i]);
			
		array3 = (int *)malloc((n1 + n2) * sizeof(int));
		
		i = 0;
		j = 0;
		k = 0;
		while(i < n1 || j < n2)
		{
			if(i < n1 && j < n2)
			{
				if(array1[i] <= array2[j])
				{
					array3[k] = array1[i];
					k++;
					i++;
				}
				else
				{
					array3[k] = array2[j];
					k++;
					j++;
				}
			}
			else if(i == n1 && j < n2)
			{
				array3[k] = array2[j];
				k++;
				j++;
			}
			else if(j == n2 && i < n1)
			{
				array3[k] = array1[i];
				k++;
				i++;
			}
		}
		if(k % 2 == 0)
			printf("%d\n",array3[(k - 1) / 2]);
		else
			printf("%d\n",array3[k / 2]);

		//printf("%d\n",array3[k/2 - 1 ]);
		// for(i = 0;i < k;i++)
		//	printf("%d ",array3[i]);
		free(array1);
		free(array2);
		free(array3);
	}
	//fclose(stdin);
	return 0;
}