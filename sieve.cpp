#include <cstdio>
#include <string.h>

// marks all mutiples of 'a' ( greater than 'a' but less than equal to 'n') as 1.
void markMultiples(bool arr[], int no, int n)
{

   for(int i=no;i<n;i+=no)
    {
        arr[ i ] = 1; // minus 1 because index starts from 0.

    }
}

// A function to print all prime numbers smaller than n
int SieveOfEratosthenes(int n)
{
    int count =0;
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        bool arr[n];
        memset(arr, 0, sizeof(arr));

        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=2; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                count++;
                //(i+1) is prime, print it and mark its multiples
                //printf("%d ", i+1);
                markMultiples(arr, i, n);
            }
        }
    }
    return count;
}

// Driver Program to test above function
int main()
{
    int n = 30;
    printf("Following are the prime numbers below %d\n", n);
    printf("%d",SieveOfEratosthenes(n));
    return 0;
}
