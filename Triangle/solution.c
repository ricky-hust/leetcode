int minimumTotal(int **triangle, int numRows) {
	int i;
	int *result=(int *)malloc(numRows*sizeof(int));
	int min;
	for(i=0;i<numRows;i++)
	{
		result[i]=triangle[numRows-1][i];
	}
	for(i=numRows-2;i>=0;i--)
	{
		int j;
		for(j=0;j<=i;j++)
		{
			int p=triangle[i][j]+result[j];
			int k=triangle[i][j]+result[j+1];
			result[j]=p<k?p:k;
		}
	}
	min=result[0];
	free(result);
	return min;
}
