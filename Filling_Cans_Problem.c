/*
*				Filling Cans
*				------------
*
*	Two cans are with capacity X and y liters.
*	The program must determine the number of steps required to obtain exactly Z liters
*	of liquid one of the cans.
*
*	At the beginning both the cans are empty.The following operations are countered as “steps”:
*
*		->emptying a vessel
*		->filling a vessel
*		->pouring liquid from larger can to the smaller, 
*		  without spilling untill one of the cans is either full or empty.
*
*	If it is not possible to obtain Z liters exactly then the output must be -1.
*
*	Example 1:
*
*		Input:
*			5
*			2
*			3
*		Output:
*			2
*
*		Explanation:	
*			Here X=5,Y=2
*			Step 1:Pour 5 liters of liquid into 5 liter can
*			step 2:Pour 2 liter from 5 liter can into 2 liter can
*			Now the 5 liter can will have 3 liter which is Z.Hence 2 steps are required.
*
*	Example 2:
*
*		Input:
*			2
*			3
*			4
*		Output:
*			-1
*
*		Explanation:
*		Z is greater than X and Y.
*		Hence it is not possible to have 4 liters in any one of the cans.
*		Hence output is -1.
*
*/

#include <stdio.h>

int main()
{
	int x, y, z;
	int count = 1, check = 0, res = 0;

	scanf("%d %d %d",&x,&y,&z);
 
	if( z > x && z > y )
	{
		printf("%d",-1);
		return 0;
	}
	
	if( x < y )
	{
		int temp = x;
		x = y; 
		y = temp;
	}
	
	else{
	
		do
		{
			if( x == z )
			{
				check = 1;
				break;
			}

			x = x-y;

			if( res )
			{
				count += 2;
			}
			else
			{
				count++;
				res = 1;
			}

		}while( x >= z );
	}
	

	printf("%d", (check) ? count : -1 );
		
	return 0;
}
