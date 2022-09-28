# Project Description

This project consists of solving the batmanacci challenge problem from Kattis.com

The Fibonacci sequence can be defined as follows:

f_1 = 1 <br />
f_2 = 1 <br />
f_n = f_(n-2) + f_(n-1)

The batmanacci sequence is a generalization of the Fibonacci sequence and can be defined as follows:

s_1 = N <br />
s_2 = A <br />
s_n = s_(n-2) + s_(n-1)

Where + is used for string concatenation (i.e. N, A, NA, ANA, NAANA, ...).

Given N and K, the goal is to find the K-th letter in the N-th string of the batmanacci sequence.

To solve this problem, a divide and conquer algorithm is used.

# Running and Testing the Project

You can run and test the project by running the following command:

- `if ($?) { g++ Source.cpp -o Source } ; if ($?) { .\Source }`

- Note: after running the command above, you need to provide the following line of user input
    - Input N (1 ≤ N ≤ 10^5) and K (0 ≤ K ≤ 10^18) in a single line separated by a single space
    - It is guaranteed that K is at most the length of the N-th string in the batmanacci sequence

- Note: `{ g++ Source.cpp -o Source }` compiles the Source.cpp file, producing a Source executable file

Example:
- Input <br />
`5 1` <br />

- Output <br />
`N` <br />

Example:
- Input <br />
`5 2` <br />

- Output <br />
`A`

Example:
- Input <br />
`7 7` <br />

- Output <br />
`N` <br />

Example:
- Input <br />
`777 777` <br />

- Output <br />
`A`