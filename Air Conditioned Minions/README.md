# Project Description

This project consists of solving the air conditioned minions challenge problem from Kattis.com

Assume you are the boss of a company that employees N minions. <br />
You need to construct several work rooms where you can assign minions (a room can hold any number of minions). <br />
You can fix the temperature of each room to any value you want (different rooms may have different temperatures). <br />
Make sure the minions like the temperature of the room they are assigned (each minion likes an interval of temp). <br />
The goal is to construct the minimum number of work rooms possible to fit all minions.

To solve this challenge, a greedy algorithm with the following strategy is used:
- Sort the minions in the increasing order of their max preferred temperature
- If two minions have same max preferred temperature, then sort them by their min preferred temperature

# Running and Testing the Project

You can run and test the project by running the following command:

- `if ($?) { g++ Source.cpp -o Source } ; if ($?) { .\Source }`

- Note: after running the command above, you need to provide the following lines of user inputs
    - The first line will  be a non-negative integer 2 ≤ N ≤ 100, representing the number of total minions
    - The next N lines each desrcibe the temperature preferences of all the minions
        - The i-th line consists of two single space separeted integers L and U (1 ≤ L ≤ U ≤ 2N),
          which denotes that the i-th minion likes any temperature between L and U

- Note: `{ g++ Source.cpp -o Source }` compiles the Source.cpp file, producing a Source executable file

Example:
- Input <br />
`3` <br />
`1 2` <br />
`2 4` <br />
`5 6`

- Output <br />
`2` <br />

Example:
- Input <br />
`5` <br />
`1 2` <br />
`3 5` <br />
`4 6` <br />
`7 9` <br />
`8 10`

- Output <br />
`3`