#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to find the K-th letter in the N-th string in the Batmanacci sequence:
string findKthLetter(long *myBatmanacciSequence, int n, long k) 
{
	// Base cases of batmanacci sequence:
	if (n == 1)
		return "N";
	if (n == 2)
		return "A";

	// Note: it is guaranteed that K is at most the length of the N-th string in the Batmanacci sequence.
	long length = myBatmanacciSequence[n - 2];

	// Recursive calls to find the K-th letter of the N-th string:
	if (length >= k)
		return findKthLetter(myBatmanacciSequence, n - 2, k); // This is the recurrance relation
	else
		return findKthLetter(myBatmanacciSequence, n - 1, k - length); // This is the recurrance relation
}

int main()
{
	// Declaring variables for user input:
	int n;
	long k;

	// Reading user input:
	cin >> n >> k;

	// Declaring array to represent the batmanacci sequence:
	long batmanacciSequence[95];

	// Initialize base cases of batmanacci sequence:
	batmanacciSequence[0] = 0;
	batmanacciSequence[1] = 1;

	// Loop to create the batmanacci sequence:
	for (int i = 2; i < 95; ++i)
	{
		batmanacciSequence[i] = batmanacciSequence[i - 1] + batmanacciSequence[i - 2];
	}

	// Checking to make sure we do not go out of the sequence range:
	if (n > 95)
		n = 95;
	else
		n = n;

	// Function to find the K-th letter in the N-th string in the Batmanacci sequence:
	cout << findKthLetter(batmanacciSequence, n, k);

	return 0;
}