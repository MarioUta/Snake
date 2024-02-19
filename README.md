Snake-like game in C++.

To compile use "g++ -o main main.cpp colors.h Game.cpp Game.h Snake.cpp Snake.h" in the command line.

The colors.h file is from this repository: https://github.com/ShakaUVM/colors

The code has only been tested on Linux, I am almost certain it doesn't run on Windows or Mac.

The code has the following problems that may be fixed in the future:

1.The input is not registered 100% of the time, sometimes(rarely tho) it is missed. (It is explained in ShakaUVM's repository)
2.The apple spawning mechanism is very simplistic, causing it to sometimes spawn on the snake's body.
3.The terminal where you run the game won't display any text you write in the console after the game ends. You can still run commands and display information, but you won't see any input you enter. Closing the terminal solves the issue.
    
