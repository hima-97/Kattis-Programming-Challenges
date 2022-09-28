# Project Description

This project consists of solving the coloring socks challenge problem from Kattis.com

Assume you want to do laundry and wash all your socks. <br />
You cannot throw all your socks in one washing machine because the socks will get discolered. <br />
Instead of washing the socks in multiple rounds, you want to buy more washing machine. <br />
Each of your socks have a color Di, which has a number between 0 and 10^9. <br />
You can wash any socks with a max absolute color difference of K in the same machine. <br />
The absolute color difference of two socks i and j is |Di - Dj|. <br />
Each machine takes at most C socks at a time. <br />
The goal is to find the minimum number of washing machines to wash S socks.

To solve this challenge, a greedy algorithm with the following strategy is used:
- Sort the socks in increasing order of sock color value
- If a washing machine reaches max capacity, then add another washing machine
- If difference of sock color values |Di - Dj| is greater than max difference, then add another washing machine

# Running and Testing the Project

You can run and test the project by running the following command:

- `if ($?) { g++ Source.cpp -o Source } ; if ($?) { .\Source }`

- Note: after running the command above, you need to provide the following lines of user inputs
    - The first line consists of three integers separated by a single space
        - S ≥ 1, which represents the number of total socks you need to wash
        - C ≥ 10^5, which represents the capacity of a laundry machine
        - 0 ≤ K ≤ 10^9, which represents the maximum color difference
    - The next line consists of S integers separated by a single space, representing the color values Di of every sock

- Note: `{ g++ Source.cpp -o Source }` compiles the Source.cpp file, producing a Source executable file

Example:
- Input <br />
`5 3 0` <br />
`0 0 1 1 2`

- Output <br />
`3` <br />

Example:
- Input <br />
`5 3 1` <br />
`0 0 1 1 2`

- Output <br />
`2`