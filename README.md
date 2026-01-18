# Tic-Tac-Toe
# Tic-Tac-Toe Minimax AI (`minimax.c`)

**What this project is about**
- A small command-line Tic‑Tac‑Toe game where a human (`X`) plays against an AI (`O`) implemented with the Minimax algorithm. The core code is in `minimax.c`. The program prints the board, reads player moves (1–9), and makes optimal AI responses.

**Features / Why it's fun**
- Minimax-based AI: plays optimally using depth-aware scoring.
- Minimal dependencies: builds with any standard C compiler.
- Interactive and educational: useful to study how Minimax evaluates moves.

**Short preview**
- Run the program and you will see the board and the prompt `Enter the position(1-9):`.
- Example quick flow:

```
  |   |  
-----------
  |   |  
-----------
  |   |  

Enter the position(1-9): 5

  |   |  
-----------
  | X |  
-----------
  |   |  

AI moves and the board updates until win/draw.
```

**How to build and run**
- Requirements: `gcc` (MinGW on Windows, or GCC/Clang on other platforms).
- From the folder containing `minimax.c`, compile:

```bash
gcc minimax.c -o minimax
```

- Run the executable:

On PowerShell or Command Prompt (Windows):

```powershell
.\minimax
```

On Git Bash / Unix-like shell:

```bash
./minimax
```

**Controls and notes**
- Enter a number 1–9 to place `X` using this layout:

```
1 | 2 | 3
---------
4 | 5 | 6
---------
7 | 8 | 9
```
- Human is `X` (goes first); AI is `O`.
- The program prints `X wins`, `O wins`, or `Its a Draw You Dumbass` when the game ends (message from the original code).


