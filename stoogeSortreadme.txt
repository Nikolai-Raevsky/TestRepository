I spent half of class working on this thing and I know that Jeremy witnessed me working on it for half of class so I'm going to move on to the rest of my work. I guess here's the pseudocode I worked on (I don't think it's entirely right though).
StoogeSort(array, begin, end)
{
  if (array[begin] > array[end-1])
  {
	int index0Copy = array[begin];
	array[begin] = array[end-1];
	array[end-1] = index0copy;
    
  }
  
  if (sizeof(array) > 2)
  {
    	int oneThird = round((end-begin)/3);
	for (int i = 0; i < sizeof(array); i++)
	{
		for (int j = 0; i < oneThird*2, i++)
		{
			StoogeSort(array, [i], oneThird);
		}
		

	}
    recursively stooge sort the last 2/3rds of the array
    recursively stooge sort the initial 2/3rds again
  }
}