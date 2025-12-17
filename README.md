# Hangman Game 🎮

A command-line implementation of the classic Hangman game in C with multiple difficulty levels and an extensive word list.

## 📋 Overview

This is an interactive text-based Hangman game where players guess letters to reveal a hidden word. The game features four difficulty levels that adjust the number of allowed wrong guesses, making it suitable for casual players and hardcore enthusiasts alike.

## ✨ Features

- **4 Difficulty Levels:**
  - **EASY** - Unlimited wrong guesses
  - **MEDIUM** - 6 wrong guesses allowed
  - **HARD** - 3 wrong guesses allowed
  - **IMPOSSIBLE** - Only 1 wrong guess allowed (0 tolerance)

- **500+ Words** across multiple categories:
  - Fruits & Vegetables
  - Animals
  - Countries & Cities
  - Sports
  - Music & Arts
  - Food & Drinks
  - Weather & Nature
  - Vehicles
  - Superheroes
  - And more!

- **Smart Game Mechanics:**
  - Tracks guessed letters to prevent repetition
  - Real-time word reveal as letters are guessed correctly
  - Input validation (only accepts a-z)
  - Case-insensitive letter matching

## 🚀 Getting Started

### Prerequisites

- GCC compiler (or any C compiler)
- Linux/Unix terminal or Windows Command Prompt/PowerShell

### Compilation

```bash
gcc main.c -o hangman
```

### Running the Game

```bash
./hangman
```

Or on Windows:
```bash
hangman.exe
```

## 🎯 How to Play

1. **Start the game** - Run the executable
2. **Choose difficulty level** - Select 1-4 based on your skill level
3. **View the word** - The word appears as underscores: `_ _ _ _ _`
4. **Make your guess** - Enter a single letter (a-z)
5. **Watch it reveal** - Correct guesses fill in the word blanks
6. **Win condition** - Guess all letters before running out of attempts
7. **Lose condition** - Run out of attempts before completing the word

### Example Gameplay

```
=== HANGMAN GAME - MEDIUM ===
Guess the word letter by letter!
Wrongs allowed: 6
Enter a letter (a-z) per guess
Repeated guesses don't count

Word: _ _ _ _ _
Wrongs left: 6/6
Guessed:
Enter your guess (a-z): E

Good! 'E' is in the word.

Word: _ _ _ _ E
Wrongs left: 6/6
Guessed: E
Enter your guess (a-z): A

Good! 'A' is in the word.

Word: A _ _ _ E
Wrongs left: 6/6
Guessed: A E
Enter your guess (a-z): P

Good! 'P' is in the word.

Word: A P P _ E
Wrongs left: 6/6
Guessed: A E P
Enter your guess (a-z): L

Good! 'L' is in the word.

Word: A P P L E
Wrongs left: 6/6

=== GAME OVER ===
MEDIUM MODE

CONGRATULATIONS! YOU WON!
The word was: APPLE
Wrongs used: 0
```

## 📊 Game Mechanics

### Difficulty Selection

| Difficulty | Max Wrong Guesses | Recommended For |
|-----------|------------------|-----------------|
| EASY | Unlimited | Learning, casual play |
| MEDIUM | 6 | Standard gameplay |
| HARD | 3 | Experienced players |
| IMPOSSIBLE | 1 | Challenge seekers |

### Word Selection

- Words are randomly selected from a pool of 500 words
- Each game run selects a different word (uses `srand()` with `time()`)
- Words are uppercase for consistency

### Input Handling

- Only accepts letters a-z (case-insensitive)
- Rejects repeated guesses with feedback
- Invalid input prompts the user to try again

## 🏗️ Code Structure

### Main Functions

- `main()` - Game loop and core logic
- `selectDifficulty()` - Gets user's difficulty selection
- `getMaxAttempts()` - Returns max attempts based on difficulty
- `getDifficultyName()` - Returns string name of difficulty level
- `printInstructions()` - Displays game rules and difficulty info

### Key Variables

- `word[]` - The hidden word to guess
- `display[]` - Current state showing blanks and guessed letters
- `guessed[]` - Array tracking which letters have been guessed
- `attemptsLeft` - Remaining wrong guesses
- `maxAttempts` - Total allowed wrong guesses for selected difficulty

## 🔧 Technical Details

### Constants

```c
#define MAX_WORD_LEN 20      // Maximum word length
#define NUM_WORDS 500        // Total words in database
#define EASY 1               // Difficulty level constants
#define MEDIUM 2
#define HARD 3
#define IMPOSSIBLE 4
```

### Libraries Used

- `stdio.h` - Standard I/O operations
- `string.h` - String manipulation functions
- `stdlib.h` - Random number generation, memory operations
- `time.h` - Time-based seeding for randomization
- `ctype.h` - Character type checking and conversion

## 💡 Tips for Players

1. **Start with common letters** - E, A, R, O, T are frequent in English
2. **Try EASY first** - Get familiar with the game mechanics
3. **Observe patterns** - Look for vowels and common consonant combinations
4. **Challenge yourself** - Progress to higher difficulties as you improve
5. **Speed challenge** - Try to win with minimum wrong guesses

## 🐛 Known Limitations

- No persistent scoring or leaderboard
- No replay option within same session (must restart)
- Word list is hardcoded (no external file loading)
- No graphics/ASCII art for hangman stages

## 🎓 Learning Concepts

This code demonstrates:

- Array usage and manipulation
- String handling in C
- Function modularity and reusability
- Input validation and error handling
- Game state management
- Random number generation
- Control flow (loops, conditionals)

## 📝 Future Enhancements

- [ ] Add scoring system with leaderboard
- [ ] Implement ASCII art hangman stages
- [ ] Load words from external file
- [ ] Add hint system
- [ ] Multiplayer mode
- [ ] Game statistics tracking
- [ ] Category selection for themed words
- [ ] Difficulty progression system

## 👨‍💻 Author

Created as an educational project demonstrating fundamental C programming concepts by Arham Shah.

## 📄 License

Free to use and modify for educational purposes.

---

**Enjoy the game and have fun guessing! 🎉**
