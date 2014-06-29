#include <stdio.h>
#include <stdlib.h>

int tabel[1000000]; // inicialization out of main

int main ()
{
	int length; // length of zable
	int s_start = 0; //start index
	int s_end = 0; //end index
	int i; 
	int s_start_cur=0; //current start index
	int s_end_cur = 0; //current end index
	int maxsum = 0; //the biggest sum
	int sum = 0; // sum
	int length_sequence; //length of sequence

	scanf ("%d", &length);	//read elements
	
	for (i = 0; i < length; ++i)
			scanf ("%d", &tabel[i]); //inset elemetns in table

	for ( i = 0; i < length; i++) // going through all elemets
	{
		//POSITIVE NUMBERS
		if (tabel[i] >= 0 ) 
		{
			s_end_cur = i;	// change last element of sequence
			sum = sum + tabel[i];	//sum
					
			if (sum > maxsum) // if sum is bigger than our maxsum
			{
				maxsum = sum;  // maxsum get value of sum
				s_start = s_start_cur; //start index get value of current start index
				s_end = s_end_cur; //end index get value of current end index
			}
		}
				
		//NEGATIVE NUMBERS
		if (tabel[i] < 0) 
		{
			if (sum + tabel[i] <= 0) // if sum and tabel[i] is lover or equal 0
			{
				s_start_cur = i + 1 ; // if it is negative pass it
				sum = 0; // sum go to 0
			}
			else 
			{
				sum = sum + tabel[i]; // sum add value of tabele[i]
				s_end_cur = i; //end of current sequence set to i
			}
		}
	}

	length_sequence = (s_end - s_start) + 1; //add one because we one subtract

	printf("%d %d %d", s_start, length_sequence, maxsum); 
	printf("\n");//new line
	
	return 0; 
}

