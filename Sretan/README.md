# Project Description

This project consists of solving the sretan challenge problem from Kattis.com

Digits 4 and 7 are lucky, while all others are unlucky. <br />
An integer is lucky if it contains only lucky digits in decimal notation. <br />
The goal is to find the -th lucky positive integer.

To solve this challenge, a greedy algorithm with the following strategy is used:
- First, notice there are always 2^d lucky numbers with d-digits 
    - For example, 4 and 7 are the two 1-digit lucky numbers

- Next, you find the number of digits in the K-th lucky number

- Next, notice that the K-th lucky number is the K2-th d-digit lucky number 
    - For example, the 7th lucky number is the 0th 3-digit lucky number
    - The K2-th lucky number is found by doing k2 = K - (2^d - 1)

- With number of digits in K-th lucky number and value of K2-th number, you can now find the K-th lucky number
    - The K-th lucky number is here initialized as an empty string
    - A for loop repeats as many times as the number of digits in the K-th lucky number
        - In the loop, each digit's value is assigned greedily (i.e. 4s before 7s)
        - This is done by considering digits as binary numbers and mapping them to 4s and 7s
        - A left bit shift is performed (i.e. exctracting a bit)
        - If the extracted bit is not 0 then you append '4' to the lucky number string, otherwise append '7'

# Running and Testing the Project

You can run and test the project by running the following command:

- `if ($?) { g++ Source.cpp -o Source } ; if ($?) { .\Source }` if ($?) { g++ Source.cpp -o Source } ; if ($?) { .\Source }

- Note: after running the command above, you need to provide the K-th lucky number as a user input

- Note: `{ g++ Source.cpp -o Source }` compiles the Source.cpp file, producing a Source executable file

Example:
- Input <br />
`1` <br />

- Output <br />
`4` <br />

Example:
- Input <br />
`2` <br />

- Output <br />
`7` <br />

Example:
- Input <br />
`3` <br />

- Output <br />
`44` <br />

Example:
- Input <br />
`7` <br />

- Output <br />
`444`