#include <stdio.h>
#include <stdlib.h>
/*
int MIN_INT()
{
	int min = -1, minimum = 0;
	while (min < 0)
		{
			minimum = min;
			min--; 
		}
	return minimum;
}
*/
int tabel[1000000]; // zaradi prostora inicaliziramo izven main 

int main ()
{
	int length; // dolzina nase tabele
	int s_start = 0; //zacetni index
	int s_end = 0; //koncni index
	int i; // za for zanko
	int s_start_cur=0; //trenutni zacetni index
	int s_end_cur = 0; //trenutni koncni index
	int maxsum = 0; //MIN_INT(); // v maxsum vstavimo najnizjo vrednost int-a (-2^31)
	int sum = 0; // zacetna vsota je 0
	int length_sequence; //dolzina nasega zaporedja

	scanf ("%d", &length);	// pogledamo koliko elementov imamo
	for (i = 0; i < length; ++i)
		{
			scanf ("%d", &tabel[i]); //v to tabelo vstavimo elemente
		}

	//iscemo najdaljse zaporedje 
	// 10 -50 30 -43 29 -21 -31 -33 6 35 -38
	// izpis
	// 7 2 41

  for ( i = 0; i < length; i++) // gremo cez use elemente
	{
				///////////////////////////////////////////////////////////////////////////////////////////////////
				//CE SO POZITIVNA STEVILA//////////////////////////////////////////////////////////////////////////
				if (tabel[i] > 0 )  //ce je element tabele pozitiven
				{
						s_end_cur = i;	// spremenimo zadnji element zaporedja
						sum = sum + tabel[i];	//sestejemo sum z vrednostjo tabele
					
					if (sum > maxsum) // ce je sum vecji od nasega maxsum-a
					{
								maxsum = sum;  //maxsum dobi vrednost sum-a
								s_start = s_start_cur; //zacetni index dobi vrednost trenutnega zacetnega indexa
								s_end = s_end_cur; //koncni index dobi vrednost trenutnega koncnega indexa
					}
				}
				///////////////////////////////////////////////////////////////////////////////////////////////////
				//GLEDANJE ELEMENTOV NAPREJ ///////////////////////////////////////////////////////////////////////
				if (tabel[i] < 0)   // ce (tabel[i]) je manjsa ali enka (0) 
				{
						if (sum + tabel[i] <= 0) // ce je sestevek sum in trenutna vrednost tabele manjsa ali enaka 0
						{
								s_start_cur = i + 1 ; // ker je negativna vrednost jo preskoci in gre na naslednjega
								sum = 0; // sum gre na 0
						
						}
						else 
						{
							sum = sum + tabel[i]; //drugace se v sum pristeje vrednost trenutne tabele
							s_end_cur = i; //konec trenutnega zaporedja nastavimo na i
						}
				}
				//////////////////////////////////////////////////////////////////////////////////////////////////
	}

	length_sequence = (s_end - s_start) + 1; //pristejemo enko ker se ena odsteje

	printf("%d %d %d", s_start, length_sequence, maxsum); // izpis (zacetek indexa, dolzina max_zaporedja, najvecje podzaporedje)
	printf("\n");// skok v novo vrsto
	
	return 0; 
}

