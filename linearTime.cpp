/**************************************************************
 * *  Filename: linearTime.cpp
 * *  Coded by: Dustin Dinh, Benjamin Fisher, Christina Nock
 * *  Purpose:  To run the nonrecursive linear time algorithm for the 
 * *			max subarray problem.
 * *
 * ***************************************************************/
#include <vector>
#include <algorithm> // For std::max

#include "linearTime.h"

/**************************************************************
 * *  Function name: linearMaxSub
 * *  Parameters: integer vector as input to run algorithm on
 * *  Return value: int representing sum of	the max subarray
 * *  Description: Function will find the sub array with the max sum 
 * *  in the array arg
 * ***************************************************************/
int linearMaxSub( std::vector<int>  &v )
{
    int localSum = 0;			//current sum of current subarray
    int maxSum = 0;				//maximum sum subarray calculated so far
	/* Iterate over the array once */
    for( int i = 0; i < v.size(); i++ )
    {
        localSum = std::max( 0, localSum + v[i] );
		maxSum = std::max( localSum, maxSum );
    }
    return maxSum;
}

/**************************************************************
 * *  Function name: linearMaxSub
 * *  Parameters: integer vector as input to run algorithm on
 * *  Return value: int representing sum of	the max subarray
 * *  Description: Function will find the sub array with the max sum 
 * *  in the array arg
 * ***************************************************************/
int linearMaxSub( std::vector<int> &v, int &start, int &end )
{
    int localSum = 0;			//current sum of current subarray
    int maxSum = 0;				//maximum sum subarray calculated so far
	int lowIndex = 0;			//set the lower index to start summing from
	int highIndex = 0;			//set the higher index to end summing from
    /* Iterate over the array once */
    for( int i = 0; i < v.size(); i++ )
    {
        /* If current sum is neg so discard the sub array and start again */
		if(( localSum + v[i]) < 0)
        {
            localSum = 0;
            lowIndex = i + 1;
        }
		/* If current sum is positive so keep adding elements */
        else
        {
            localSum = localSum + v[i];
        }
		/* Check is the result is less than the cur if so update result */
        if( maxSum < localSum )
        {
            maxSum = localSum;
            highIndex = i;
        }
    }
    return maxSum;
}
