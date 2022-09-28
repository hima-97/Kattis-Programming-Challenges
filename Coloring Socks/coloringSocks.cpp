#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    // Declaring input variables:
    int  numberOfSocks;
    int  capacityOfMachine;
    int  maxColorDifference;

    // Reading the input from the user:
    cin >> numberOfSocks >> capacityOfMachine >> maxColorDifference;

    // This creates an empty vector of type "int" and size "numberOfSocks":
    vector<int> socksColors(numberOfSocks);

    // This assigns the color values from the input to every sock in the vector:
    for (int i = 0; i < socksColors.size(); i++)
    {
        cin >> socksColors[i];
    }

    // This sorts the vector in increasing order of sock color value:
    sort(socksColors.begin(), socksColors.end());

    int  numberOfMachines = 1;
    int  socksInsideMachine = 1;
    int  previousSockColor = socksColors[0]; // Variable to keep track of the previous sock color value

    // For loop to find the number of machines needed:
    for (int i = 1; i < numberOfSocks; i++)
    {
        // If machine reaches max capacity, then we increment the number of machines and track the color of the current sock for the next iteration: 
        if (socksInsideMachine == capacityOfMachine)
        {
            numberOfMachines++;
            socksInsideMachine = 0; // i.e. New empty washing machine
            previousSockColor = socksColors[i];
        }
        // If difference of sock color values (Di - Dj) is greater than the max difference,
        // then we increment the number of machines and track the color of the current sock for the next iteration:
        else if (socksColors[i] - previousSockColor > maxColorDifference)
        {
            numberOfMachines++;
            socksInsideMachine = 0;
            previousSockColor = socksColors[i];
        }

        // This increments the number of socks inside the current machine:
        socksInsideMachine++;
    }

    cout << numberOfMachines << endl;

    return 0;
}