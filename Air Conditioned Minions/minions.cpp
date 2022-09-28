#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to place minions in a "pair<int, int>" type vector:
vector<pair<int, int>> createMinionsVector(int myTotalMinions)
{
    // This creates a "pair<int, int>" type vector to hold the minions and their temperature preferences:
    vector<pair<int, int>> myMinionsVector;

    // The first pair/slot of the vector will contain the temperature interval for the first minion, while
    // the second pair/slot of the vector will contain the temperature interval for the second minion, and so on ...
    for (int i = 0; i < myTotalMinions; i++)
    {
        pair<int, int> myPair;
        cin >> myPair.first >> myPair.second;
        myMinionsVector.push_back(myPair);
    }

    return myMinionsVector;
}

// Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool.
// The value returned indicates which element goes before/after based on the criteria defined:
bool compareTemperatures(pair<int, int> temperatures_1, pair<int, int> temperatures_2)
{
    /* 
    To solve this challenge, I used the concept of greedy algorithm with the following strategy:
    - Sort the minions in the increasing order of their max preferred temperature
    - If two minions have same max preferred temperature, then sort them by their min preferred temperature
    */

    // Sorting by preferred min temperatures of two different minions, in case their preferred max temp is same:
    if (temperatures_1.second == temperatures_2.second)
    {
        return temperatures_1.first < temperatures_2.first;
    }

    // Sorting by preferred max temperatures of two different minions:
    return temperatures_1.second < temperatures_2.second;
}

// Function to sort vector of minions in increasing order based on their temperature intervals:
vector<pair<int, int>> sortMinionsVector(vector<pair<int, int>> myMinionsVector)
{
    vector<pair<int, int>> sortedVector = myMinionsVector;

    // Function to sort the vector according to the "compareTemperatures" binary function:
    sort(sortedVector.begin(), sortedVector.end(), compareTemperatures);

    return sortedVector;
}

int main(int argc, char* argv[])
{
    /*
    For C++ there are known issues related to performance.
    If input file is 1MB or more, then the C++ cin function could be too slow.
    Therefore, for C++ you can paste the following line:
    */
    ios_base::sync_with_stdio(false);

    // This gets the total number of minions from the input:
    int totalMinions;
    cin >> totalMinions;

    // Placing minions in a "pair<int, int>" type vector:
    vector<pair<int, int>> minionsVector = createMinionsVector(totalMinions);

    // Sorting vector of minions in increasing order based on their temperature preferences:
    vector<pair<int, int>> sortedMinions = sortMinionsVector(minionsVector);

    int room = 1;
    int roomTemperature = sortedMinions[0].second;

    // For loop to determine minimum number of rooms required to fit all the minions:
    for (int i = 1; i < sortedMinions.size(); i++)
    {
        // If the preferred min temperature of the next minion is greater than the current room's temperature, then we create a new room:
        if (sortedMinions[i].first > roomTemperature)
        {
            // This updates the current room's temperature:
            roomTemperature = sortedMinions[i].second;
            room++;
        }
    }

    // This prints the total number of rooms:
    cout << room << endl;
}