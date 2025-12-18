#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LEN 20
#define NUM_WORDS 500

#define EASY 1
#define MEDIUM 2
#define HARD 3
#define IMPOSSIBLE 4

const char *words[NUM_WORDS] = {
    "APPLE", "BANANA", "CHERRY", "DATE", "ELDERBERRY", "FIG", "GRAPE", "HONEYDEW",
    "KIWI", "LEMON", "MANGO", "NECTARINE", "ORANGE", "PEACH", "QUINCE", "RASPBERRY",
    "STRAWBERRY", "TANGERINE", "UGLI", "VANILLA", "WATERMELON", "YAM", "ZUCCHINI",
    "CARROT", "POTATO", "ONION", "TOMATO", "CUCUMBER", "LETTUCE", "SPINACH",
    "BROCCOLI", "CAULIFLOWER", "PEPPER", "EGGPLANT", "SQUASH", "PUMPKIN", "CABBAGE",
    "CELERY", "RADISH", "BEETROOT", "ASPARAGUS", "ARTICHOKE", "OKRA", "LION",
    "TIGER", "BEAR", "WOLF", "FOX", "DEER", "ELEPHANT", "GIRAFFE", "ZEBRA",
    "RHINOCEROS", "HIPPO", "CROCODILE", "ALLIGATOR", "MONKEY", "RABBIT", "SQUIRREL",
    "KANGAROO", "PANDA", "CAMEL", "LEOPARD", "CHEETAH", "JAGUAR", "BUFFALO",
    "DOLPHIN", "WHALE", "SHARK", "OCTOPUS", "SQUID", "EAGLE", "OWL", "PARROT",
    "PENGUIN", "FLAMINGO", "PEACOCK", "SWAN", "DUCK", "GOOSE", "DOG", "PUPPY",
    "CAT", "KITTEN", "HORSE", "COW", "PIG", "SHEEP", "GOAT", "CHICKEN", "ROOSTER",
    "TURKEY", "DONKEY", "ENGLAND", "FRANCE", "GERMANY", "ITALY", "SPAIN", "JAPAN",
    "CHINA", "INDIA", "BRAZIL", "CANADA", "AUSTRALIA", "RUSSIA", "MEXICO", "EGYPT",
    "GREECE", "TURKEY", "SWEDEN", "NORWAY", "DENMARK", "POLAND", "PORTUGAL",
    "BELGIUM", "SWITZERLAND", "AUSTRIA", "HUNGARY", "ROMANIA", "BULGARIA",
    "LONDON", "PARIS", "BERLIN", "ROME", "MADRID", "TOKYO", "BEIJING", "DELHI",
    "MUMBAI", "SYDNEY", "TORONTO", "MOSCOW", "CAIRO", "ATHENS", "ISTANBUL",
    "DUBAI", "SINGAPORE", "NEWYORK", "CHICAGO", "LOSANGELES", "BASEBALL",
    "FOOTBALL", "BASKETBALL", "TENNIS", "SOCCER", "CRICKET", "GOLF", "BOXING",
    "SWIMMING", "RUNNING", "CYCLING", "SKATING", "SURFING", "SKIING", "SNOWBOARD",
    "VOLLEYBALL", "RUGBY", "HOCKEY", "WRESTLING", "KARATE", "JUDO", "ARCHERY",
    "FENCING", "MOVIE", "CINEMA", "THEATER", "MUSIC", "CONCERT", "DANCE", "BALLET",
    "OPERA", "SYMPHONY", "JAZZ", "ROCK", "CLASSICAL", "BLUES", "COUNTRY", "RAP",
    "HIPHOP", "REGGAE", "SALSA", "PIANO", "GUITAR", "DRUMS", "VIOLIN", "FLUTE",
    "TRUMPET", "SAXOPHONE", "HARP", "SCHOOL", "COLlege", "UNIVERSITY", "LIBRARY",
    "BOOKSTORE", "MUSEUM", "PARK", "ZOO", "BEACH", "MOUNTAIN", "RIVER", "LAKE",
    "FOREST", "DESERT", "ISLAND", "CITY", "VILLAGE", "TOWN", "HIGHWAY", "BRIDGE",
    "TUNNEL", "AIRPORT", "STATION", "HOSPITAL", "DOCTOR", "NURSE", "POLICE",
    "FIREMAN", "TEACHER", "STUDENT", "ENGINEER", "PILOT", "COOK", "WAITER",
    "ARTIST", "PAINTER", "SCULPTOR", "WRITER", "POET", "SINGER", "ACTOR",
    "DIRECTOR", "KING", "QUEEN", "PRINCE", "PRINCESS", "PRESIDENT", "SENATOR",
    "JUDGE", "LAWYER", "SUPERMAN", "BATMAN", "SPIDERMAN", "WONDERWOMAN",
    "IRONMAN", "THOR", "HULK", "FLASH", "AQUAMAN", "WOLVERINE", "DEADPOOL",
    "PIZZA", "BURGER", "SUSHI", "PASTA", "SALAD", "SOUP", "STEAK", "CHICKEN",
    "FISH", "RICE", "BREAD", "CHEESE", "BUTTER", "YOGURT", "EGG", "MILK",
    "COFFEE", "TEA", "JUICE", "WATER", "SODA", "LEMONADE", "WINE", "BEER",
    "CHOCOLATE", "CANDY", "CAKE", "COOKIE", "BROWNIE", "ICECREAM", "DONUT",
    "PANCAKE", "WAFFLE", "MUFFIN", "SUN", "MOON", "STAR", "PLANET", "COMET",
    "GALAXY", "RAINBOW", "CLOUD", "THUNDER", "LIGHTNING", "STORM", "RAIN",
    "SNOW", "WIND", "FOG", "HOUSE", "GARDEN", "KITCHEN", "BEDROOM", "BATHROOM",
    "LIVINGROOM", "WINDOW", "DOOR", "FLOOR", "CEILING", "TABLE", "CHAIR",
    "SOFA", "COUCH", "CARPET", "CURTAIN", "LAMP", "CLOCK", "PENCIL", "PEN",
    "ERASER", "SHARPNER", "NOTEBOOK", "PAPER", "RULER", "SCISSORS", "GLUE",
    "MARKER", "CRAYON", "BACKPACK", "TRAIN", "BUS", "CAR", "BICYCLE",
    "MOTORCYCLE", "TRUCK", "BOAT", "SHIP", "SUBWAY", "TRAM", "AIRPLANE",
    "HELICOPTER", "FAMILY", "MOTHER", "FATHER", "PARENT", "SISTER", "BROTHER",
    "UNCLE", "AUNT", "COUSIN", "GRANDFATHER", "GRANDMOTHER", "BABY", "CHILD",
    "FRIEND", "NEIGHBOR", "HAPPY", "SAD", "ANGRY", "SCARED", "EXCITED",
    "BORED", "SURPRISED", "PROUD", "TIRED", "HUNGRY", "THIRSTY", "SUMMER",
    "WINTER", "SPRING", "AUTUMN", "MORNING", "NOON", "EVENING", "NIGHT",
    "GAME", "PUZZLE", "CHESS", "CHECKERS", "CARDGAME", "HANGMAN", "SUDOKU",
    "RIDDLE", "MAZE"
};

int selectDifficulty() {
    int choice;
    printf("\nSelect Difficulty Level:\n");
    printf("1. EASY      - Unlimited wrongs\n");
    printf("2. MEDIUM    - 6 wrongs allowed\n");
    printf("3. HARD      - 3 wrongs allowed\n");
    printf("4. IMPOSSIBLE- 0 wrongs allowed\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);
    
    return choice;
}

int getMaxAttempts(int difficulty) {
    switch(difficulty) {
        case EASY:
            return 999;
        case MEDIUM:
            return 6;
        case HARD:
            return 3;
        case IMPOSSIBLE:
            return 1;
        default:
            return 6; 
    }
}

const char* getDifficultyName(int difficulty) {
    switch(difficulty) {
        case EASY:
            return "EASY";
        case MEDIUM:
            return "MEDIUM";
        case HARD:
            return "HARD";
        case IMPOSSIBLE:
            return "IMPOSSIBLE";
        default:
            return "UNKNOWN";
    }
}

void printInstructions(int difficulty, int maxAttempts) {
    printf("\n=== HANGMAN GAME - %s ===\n", getDifficultyName(difficulty));
    printf("Guess the word letter by letter!\n");
    if (maxAttempts == 999) {
        printf("Wrongs allowed: UNLIMITED\n");
    } else {
        printf("Wrongs allowed: %d\n", maxAttempts);
    }
    printf("Enter a letter (a-z) per guess\n");
    printf("Repeated guesses don't count\n\n");
}

int main() {
    char word[MAX_WORD_LEN], display[MAX_WORD_LEN], guessed[26];
    int wordLen, attemptsLeft, maxAttempts, i, found, gameOver = 0;
    char guess;
    int difficulty;
    
    srand(time(NULL));

    difficulty = selectDifficulty();

    if (difficulty < 1 || difficulty > 4) {
        printf("Invalid choice! Defaulting to MEDIUM.\n");
        difficulty = MEDIUM;
    }
    
    maxAttempts = getMaxAttempts(difficulty);
    attemptsLeft = maxAttempts;

    int wordIndex = rand() % NUM_WORDS;
    strcpy(word, words[wordIndex]);
    wordLen = strlen(word);
    
    memset(display, '_', wordLen);
    display[wordLen] = '\0';
    memset(guessed, 0, sizeof(guessed));
    
    printInstructions(difficulty, maxAttempts);

    while (attemptsLeft > 0 && !gameOver) {
        printf("\nWord: %s\n", display);
        
        if (maxAttempts == 999) {
            printf("Wrongs left: UNLIMITED\n");
        } else {
            printf("Wrongs left: %d/%d\n", attemptsLeft, maxAttempts);
        }
        
        printf("Guessed: ");
        for (i = 0; i < 26; i++) {
            if (guessed[i]) printf("%c ", 'a' + i);
        }
        printf("\n");
        
        printf("Enter your guess (a-z): ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        if (guess < 'A' || guess > 'Z') {
            printf("Please enter a valid letter (a-z)!\n");
            continue;
        }

        if (guessed[guess - 'A']) {
            printf("You already guessed '%c'! Try another.\n", guess);
            continue;
        }
        
        guessed[guess - 'A'] = 1;

        found = 0;
        for (i = 0; i < wordLen; i++) {
            if (word[i] == guess) {
                display[i] = guess;
                found = 1;
            }
        }
        
        if (!found) {
            attemptsLeft--;
            printf("Wrong! '%c' is not in the word.\n", guess);

            if (difficulty == IMPOSSIBLE && attemptsLeft == 0) {
                printf("ONE STRIKE AND YOU'RE OUT!\n");
            }
        } else {
            printf("Good! '%c' is in the word.\n", guess);
        }

        gameOver = 1;
        for (i = 0; i < wordLen; i++) {
            if (display[i] == '_') {
                gameOver = 0;
                break;
            }
        }
    }

    printf("\n=== GAME OVER ===\n");
    printf("%s MODE\n\n", getDifficultyName(difficulty));
    
    if (attemptsLeft > 0) {
        printf("CONGRATULATIONS! YOU WON!\n");
        printf("The word was: %s\n", word);
        printf("Wrongs used: %d\n", maxAttempts - attemptsLeft);
    } else {
        printf("YOU LOST!\n");
        printf("The word was: %s\n", word);
        printf("Better luck next time!\n");
    }
    
    printf("\n");
    
    return 0;
}
