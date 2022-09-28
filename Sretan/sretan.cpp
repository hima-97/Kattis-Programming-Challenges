#include <string>
#include <iostream>
#include <cmath>
using namespace std;

// To solve this problem, notice there are always 2^d lucky numbers with d digits (i.e. 4 and 7 are the two 1 digit lucky numbers)

// Function to find the K-th lucky number:
void find_lucky_kth_value(int kValue)
{
    int temp = 0;
    int digits = 0;

    // Loop to calculate the number of digits in the K-th lucky number:
    while (temp < kValue)
    {
        temp = temp + pow(2, ++digits); // temp = temp + 2^(++digits)
    }

    /*
    The K-th lucky number is the K2-th d digit lucky number:
    For example, the 7th lucky number is the 0th 3 digit lucky number.
    For example, the 3rd lucky number is the 0th 2 digit lucky number.
    Note that k2 = K - (2^d - 1):
    */
    int K2 = kValue - (pow(2, digits) - 1);

    string luckyNumber = "";

    // Loop to assign digits "greedily" (4s before 7s).
    // Take binary digits (i.e. 0, 1) and map them to 4 and 7:
    for (int myDigit = 0; myDigit < digits; myDigit++)
    {
        // This is a bit shift operation.
        // This is basically extracting a bit
        int bit = K2 & (1 << myDigit); // (1 << myDigit) means you left shift 1 by the myDigit value
                                       // (1 << myDigit) is same as 1*(2^myDigit)

        if (!bit)
            luckyNumber = '4' + luckyNumber; // This appends a '4' to the lucky number string
        else
            luckyNumber = '7' + luckyNumber; // This appends a '7' to the lucky number string
    }

    cout << luckyNumber;
}

int main()
{
	// Declaring input variable:
    int k;

	// Reading the input from the user:
	cin >> k;
    
    // Calling the function to find the K-th lucky number:
    find_lucky_kth_value(k);
}