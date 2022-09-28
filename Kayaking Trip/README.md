# Project Description

This project consists of solving the kayaking trip challenge problem from Kattis.com

Assume you are leading a kayaking trip with kayaks of different types and with different amounts of packing. <br />
Each kayak has its own speed factor C, since some kayaks are more easily paddled than others. <br />
However, the final speed V of a kayak is also determined by the strengths S1 and S2 of the two people in the kayak. <br />
Therefore, the final speed of a kayak is given by the relation V = C(S1 + S2). <br />
You have some beginner participants with strength S_b, normal with strength S_n, and experienced with strenght S_e. <br />
The goal is to find the maximum speed the slowest kayak can get by distributing the participants two in each kayak.

To solve this challenge, a greedy algorithm is used.

# Running and Testing the Project

You can run and test the project by running the following command:

- `if ($?) { g++ Source.cpp -o Source } ; if ($?) { .\Source }`

- Note: after running the command above, you need to provide the following three lines of user input
    - The first line contains three non-negative integers b, n, and e
        - b = number of beginner participants
        - n = number of normal participants
        - e = number of experienced participants
        - Note that (b + n + e) is even and 2 ≤ (b + n + e) ≤ 100,000
    - The second line contains three integers S_b, S_n, and S_e
        - S_b = strength of beginner participants
        - S_n = strength of normal participants
        - S_e = strength of experienced participants
        - Note that 1 ≤ S_b ≤ S_n ≤ S_e ≤ 1000
    - The third line contains m = (b + n + e)/2 integers C_1, ..., C_m
        - Each C_i gives the speed factor of one kayak
        - Note that 1 ≤ C_i ≤ 100,000 for each i

- Note: `{ g++ Source.cpp -o Source }` compiles the Source.cpp file, producing a Source executable file

Example:
- Input <br />
`3 1 0` <br />
`40 60 90` <br />
`18 20`

- Output <br />
`1600` <br />

Example:
- Input <br />
`7 0 7` <br />
`5 10 500` <br />
`1 1 1 1 1 1 1`

- Output <br />
`505`