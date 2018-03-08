# CS420_AI_ClassCompetition
AI program utilizing MiniMax created by Jacob Lepere and Tho Nguyen to play a modified version of Connect 4. The game will end when one player gets 4 in a row, either horizontally or vertically. We will not consider any diagonals.

# Before Compiling Setup
Make sure `g++` is in your PATH variable.

# How to Compile
Go into the "Connect4" folder, then type `make` into your terminal.

**NOTE:** This makefile will NOT work with Windows! If  you are running Windows, consider installing a bash shell such as Cygwin or use the alternative compiling method mentioned below.

# Alternative Compiling Method
Go into the "Connect4" folder, and copy in the following command into your terminal:
```
g++ -g -std=gnu++11 -o p3 algorithms/human/*.cpp algorithms/minimax/*.cpp algorithms/minimax/hash_tables/*.cpp algorithms/minimax/heuristic_functions/*.cpp algorithms/minimax/successor_functions/*.cpp game/*.cpp player/*.cpp src/*.cpp
```

# How To Run
* On Mac/Linux/Windows PowerShell: `./p3`
* On Windows Command Prompt: `p3`
