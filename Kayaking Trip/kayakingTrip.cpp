#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Checking if there are enough participants to make a valid combination to fit the speed criteria:
bool enoughParticipants(string participantsCombination, int myBeginners, int myNormal, int myExperienced)
{
    // For loop to make a valid combination of participants to fit the speed criteria:
    for (char i : participantsCombination)
    {
        if (i == 'B')
        {
            myBeginners--;
        }
        if (i == 'N')
        {
            myNormal--;
        }
        if (i == 'E')
        {
            myExperienced--;
        }
    }

    return (myBeginners >= 0) && (myNormal >= 0) && (myExperienced >= 0);
}

// Function to check if the speed criteria is met and there is a valid combination of participants to meet this criteria: 
bool isSpeedCriteriaMet(vector<int> kayaksSpeedFactors, vector<pair<int, string>> myStrengths, int speed_criteria, int my_beginners, int my_normal, int my_experienced)
{
    // Variable of "boolean" type to indicate if the speed criteria has been met:
    bool speedCriteriaMet = true;

    for(int speedFactor : kayaksSpeedFactors)
    {
        // Variable of "boolean" type to indicate if current speed is a valid speed:
        bool validSpeed = false;

        // For loop to check if the speed criteria is met and there is a valid combination of participants to meet this criteria: 
        for (auto strengthValue : myStrengths)
        {
            if (speedFactor * strengthValue.first >= speed_criteria && enoughParticipants(strengthValue.second, my_beginners, my_normal, my_experienced))
            {
                // For loop to make a valid combination of participants to fit the speed criteria:
                for (char k : strengthValue.second) // Note: "strengthValue.second" is basically a string representing a "participantsCombination"
                {
                    if (k == 'B')
                    {
                        my_beginners--;
                    }
                    if (k == 'N')
                    {
                        my_normal--;
                    }
                    if (k == 'E')
                    {
                        my_experienced--;
                    }
                }

                validSpeed = true;
                break;
            }
        }
        // Checking if the speed criteria is not met:
        if (!validSpeed) // if (validSpeed == false)
        {
            speedCriteriaMet = false;
            break;
        }
    }

    return speedCriteriaMet;
}

int main() 
{
    // Declaring input variables:
    int beginners, normal, experienced;
    int strength_beginners, strength_normal, strength_experienced;

    // Reading input from user:
    cin >> beginners >> normal >> experienced;
    cin >> strength_beginners >> strength_normal >> strength_experienced;

    // Variable to track the number of kayaks:
    int numberOfKayaks = (beginners + normal + experienced) / 2; // i.e. m = (b + n + e)/2

    // Vector of type "int" and size "numberOfKayaks" used to track each kayak's speed factor:
    vector<int> kayaks_speed_factors(numberOfKayaks);

    // This assigns the speed factors from the input to every kayak in the vector:
    for (int i = 0; i < kayaks_speed_factors.size(); i++)
    {
        cin >> kayaks_speed_factors[i];
    }

    // This sorts the vector "kayaks_speed_factors" in increasing order of speed factor:
    sort(kayaks_speed_factors.begin(), kayaks_speed_factors.end());

    // Vector of type "pair<int, string>" to keep track of the strengths combinations of the participants:
    vector<pair<int, string>> strengths;

    // This fills up the "strengths" vector with each possible combination of strengths (participants on a single kayak): 
    strengths.push_back({ strength_beginners + strength_beginners, "BB" });
    strengths.push_back({ strength_beginners + strength_normal, "BN" });
    strengths.push_back({ strength_normal + strength_normal, "NN" });
    strengths.push_back({ strength_normal + strength_experienced, "NE" });
    strengths.push_back({ strength_experienced + strength_experienced, "EE" });
    strengths.push_back({ strength_experienced + strength_beginners, "EB" });

    // This sorts vector "strengths" in increasing order of strength values:
    sort(strengths.begin(), strengths.end());

    // Declaring and defining speed tresholds:
    int lowTreshold = 0;
    int highTreshold = 10000;

    // This is used to figure out the maximum speed that the slowest kayak can have:
    while (highTreshold - lowTreshold > 1)
    {
        // Defining speed criteria (desired speed):
        int speedCriteria = (highTreshold + lowTreshold) / 2;

        // Checking if the speed criteria is met and there is a valid comnination of participants to meet this criteria.
        // Remeber that the final speed of a kayak is given by V = C(S1 + S2): 
        if (isSpeedCriteriaMet(kayaks_speed_factors, strengths, speedCriteria, beginners, normal, experienced))
        {
            lowTreshold = speedCriteria;
        }
        else 
        {
            highTreshold = speedCriteria;
        }
    }

    // This prints the maximum speed that the slowest kayak can have:
    cout << lowTreshold << endl;

    return 0;
}