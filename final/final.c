// Link to video
// 

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>


// Constants
#define MAX_PLAYERS 2
#define MAX_ANIMALS 20
#define MAX_NAME_LENGTH 50
#define MAX_GUESS_LENGTH 50
#define MAX_CLUE_LENGTH 100

// Global Variables
int game_state = 0; // 0 = game not started, 1 = game started, 2 = game over, 3 = game won
int *state_Ptr = &game_state;
int current_Turn = 0; // 0 = player 1, 1 = player 2
int *turn_Ptr = &current_Turn;
int guess_Count = 0; // 0 = new animal, 1-3 = current animal
int *guess_Ptr = &guess_Count;
int current_Animal_Index = 0; // index of current animal
int *animal_Index_Ptr = &current_Animal_Index; // 0-24 for array of animals

// Player Struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    int turn; // var to control whos turn it is
    int score;
    int lives;
} Player;

// Player array to hold each player's information that will be loaded from a file
Player *players;


// Animal Struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    char clue[MAX_CLUE_LENGTH];
} Animal;

// Function Prototypes
void input_New_Player();    
void flip_Coin();
void change_Turn();
void save_Player_Info(char *filename,Player *players);
void load_Players(char *filename);
void list_Players();
void make_Guess();
void check_If_Dead();
void print_Instructions();

// Array of structs to hold each endangered land mammal
Animal animals[MAX_ANIMALS] = {
    {"Amur Leopard", 1, "This big cat has a beautiful spotted fur and is found in the Russian Far East."},
    {"Black Rhino", 2, "Known for its two horns, this animal is a critically endangered species from Africa."},
    {"Bornean Orangutan", 3, "This red-haired ape is native to an island in Southeast Asia."},
    {"Cross River Gorilla", 4, "A great ape with a very limited range in the African rainforest."},
    {"Eastern Lowland Gorilla", 5, "The largest of the four gorilla subspecies, found in the mountainous forests of eastern Congo."},
    {"Javan Rhino", 6, "A rare member of the rhino family, found only in Indonesia."},
    {"Malayan Tiger", 7, "A tiger subspecies that is found in the southern and central parts of the Malay Peninsula."},
    {"Mountain Gorilla", 8, "This majestic ape is found in the mountains of central Africa and is known for its thick fur."},
    {"Orangutan", 9, "An ape known for its intelligence, found in the rainforests of Borneo and Sumatra."},
    {"Saola", 10, "Sometimes called the 'Asian Unicorn', this rarely-seen animal is found around Vietnam and Laos."},
    {"South China Tiger", 11, "A tiger subspecies that is critically endangered and possibly extinct in the wild."},
    {"Sumatran Elephant", 12, "A smaller elephant species with smaller ears, native to the Indonesian island of Sumatra."},
    {"Sumatran Orangutan", 13, "This critically endangered ape is known for its long red hair."},
    {"Sumatran Rhino", 14, "The smallest of all rhino species, known for its hairy body."},
    {"Sumatran Tiger", 15, "This tiger species is distinguished by its dark, thick stripes."},
    {"Western Lowland Gorilla", 16, "A subspecies of gorilla that lives in the rainforests of Central Africa."},
    {"Yangtze Finless Porpoise", 17, "This unique mammal is known for its intelligence and lives in the Yangtze River."},
    {"African Wild Dog", 18, "Also known as the painted wolf, this canine is known for its unique coat of fur."},
    {"Asian Elephant", 19, "This animal is known for its large ears, which it uses to regulate body temperature."},
    {"Bengal Tiger", 20, "One of the largest tiger subspecies, known for its unique orange and black stripes."}
};


// DONE Gets input for players name and flips coin to see who goes first
void input_New_Player(Player *players){
    printf("Enter player 1's name: \n");
    scanf("%49s", players[0].name);
    players[0].turn = 0;
    players[0].score = 0;
    players[0].lives = 5;
    printf("Enter player 2's name: \n");
    scanf("%49s", players[1].name);

    // Clear input buffer so that the next fgets() call doesn't read in a newline character and skip the input
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("\n\n");
    players[1].turn = 0;
    players[1].score = 0;
    players[1].lives = 5;
    // Flips coin to see who goes first
    flip_Coin(players);
}


// DONE Function to flip a coin to see who goes first
void flip_Coin(Player *players){
    printf("Flipping coin to see who goes first...\n");
    printf("----------------------------------------------\n");
    // generate random number
    srand(time(NULL));
    // Generate a random number (either 1 or 2)
    int randomNumber = (rand() % 2) + 1;
    // If the random number is 1, player 1 goes first
    if (randomNumber == 1){
        players[0].turn = 1;
        players[1].turn = 2;
    }
    else{
        players[0].turn = 2;
        players[1].turn = 1;
    }
}

// DONE Change the current player position to the next player, call after every move is done
void change_Turn(Player *players){
    if (players[0].turn == 1){
        players[0].turn = 2;
        players[1].turn = 1;
    }
    else{
        players[0].turn = 1;
        players[1].turn = 2;
    }
}

// DONE Loads player from file into player array
void load_Players(char *filename) {
    int playerCount = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
    }
    Player temp;
    while (fscanf(file, "%49s %d %d %d", temp.name, &temp.lives, &temp.turn, &temp.score) == 4) {
        players[playerCount++] = temp;
        if (playerCount >= MAX_PLAYERS) break;
    }
    fclose(file);
}

// DONE (CHECK) Function to check if a save file exists. If not, create a new one.
void check_New_File(char *filename){
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
    }
    int ch = fgetc(file);
    if(ch == EOF){
        printf("No previous save file found. Creating new save file.\n");
        save_Player_Info(filename, players);
    }
    else{
        printf("Save file found. Loading previous save file.\n");
        load_Players(filename);
    }
    fclose(file);
}

// DONE (MAYBE CHANGE) Lists out the current players with score, turn, etc.
void list_Players(Player *players) {
    printf("Currently Saved Data:\n");
    printf("----------------------------------------------\n");
    printf("Name\tLives\tScore\n");
    printf("\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s\t%d\t%d\n", players[i].name, players[i].lives, players[i].score);
    }
    printf("\n\n\n");
}

void check_Win(Player *players){
    if (players[0].score == 100){
        printf("Player 1 wins!\n\n");
        *state_Ptr = 3;
    }
    else if (players[1].score == 100){
        printf("Player 2 wins!\n\n");
        *state_Ptr = 3;
    }
}

// (DONE CHECK) Saves player array into file, overwriting existing file contents
void save_Player_Info(char *filename, Player *players) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < MAX_PLAYERS; i++) {
        fprintf(file, "%s %d %d %d\n", players[i].name, players[i].lives, players[i].turn, players[i].score);
    }
    fclose(file);
    printf("Progress saved.\n\n\n");
}

// Prompts user to enter a guess for the current animal
// GuessCount is the number of guesses left for the current animal
// If the user guesses correctly, the guess count is reset to 0
// If the user guesses incorrectly, the guess count is decremented
// If the user runs out of guesses, the guess count is reset to 0
void make_Guess(Animal *animals, Player *players, int *currentAnimalIndex, int *guessCount) {
    if (*guessCount == 0) {
        *currentAnimalIndex = rand() % MAX_ANIMALS; // Select a new random animal
        *guessCount = 3; // Reset the guess count for this animal
        printf("Generating a new random animal...\n");
    }

    Animal *current_Animal = &animals[*currentAnimalIndex];

    while (*guessCount > 0) {
        printf("----------------------------------------------\n");
        printf("Clue: %s\n", current_Animal->clue);
        printf("----------------------------------------------\n");
        printf("Enter your guess: \n");

        char guess[MAX_NAME_LENGTH];
        fgets(guess, MAX_NAME_LENGTH, stdin);
        size_t len = strlen(guess);
        if (len > 0 && guess[len - 1] == '\n') {
            guess[len - 1] = '\0';
        }

        // Convert both guess and animal name to lower case for case-insensitive comparison
        char animalNameLower[MAX_NAME_LENGTH];
        char guessLower[MAX_NAME_LENGTH];
        strcpy(animalNameLower, current_Animal->name);
        strcpy(guessLower, guess);
        for (int i = 0; animalNameLower[i]; i++) {
            animalNameLower[i] = tolower(animalNameLower[i]);
        }
        for (int i = 0; guessLower[i]; i++) {
            guessLower[i] = tolower(guessLower[i]);
        }

        int currentPlayerIndex = (players[0].turn == 1) ? 0 : 1;

        if (strcmp(guessLower, animalNameLower) == 0) {
            printf("----------------------------------------------\n");
            printf("Correct!\n");
            printf("----------------------------------------------\n\n");
            players[currentPlayerIndex].score += 20;
            printf("Player %d scored!\n", currentPlayerIndex + 1);
            printf("Player %d's score: %d\n\n", currentPlayerIndex + 1, players[currentPlayerIndex].score);
            *guessCount = 0; // Reset for the next animal
            break; // Exit the loop as the player guessed correctly
        } else {
            (*guessCount)--;
            printf("----------------------------------------------\n");
            printf("Incorrect! The correct characters you guessed are: ");
            for (int i = 0; guessLower[i] && animalNameLower[i]; i++) {
                if (guessLower[i] == animalNameLower[i]) {
                    printf("%c", guess[i]); // Show the original case
                } else {
                    printf("_");
                }
            }
            printf("\n");
            printf("----------------------------------------------\n\n");

            if (*guessCount > 0) {
                printf("You have %d guess(es) left for this animal.\n", *guessCount);
            } else {
                printf("No guesses left for this animal. Moving to the next one.\n");
                players[currentPlayerIndex].lives--;
                printf("Player %d's (%s) lives: %d\n\n", currentPlayerIndex + 1, players[currentPlayerIndex].name, players[currentPlayerIndex].lives);
                break; // Exit the loop as the player is out of guesses
            }
        }
    }
}

// Checks if player is dead, if so end the game and display the winner
void check_If_Dead(Player *players, int *state_Ptr){
    // if player lives = 0, end the game and display the winner
    if (players[0].lives == 0){
        printf("Player 2 wins!\n");
        *state_Ptr = 2;
    }
    else if (players[1].lives == 0){
        printf("Player 1 wins!\n");
        *state_Ptr = 2;
    }
}

// Prints the instructions for a brand new game
void print_New_Instructions(){
    printf("Welcome to the Endangered Animal Guessing game!\n");
    printf("The goal of the game is to guess the name of the endangered animal based on the clue provided.\n");
    printf("----------------------------------------------\n");
    printf("Instructions:\n");
    printf("----------------------------------------------\n");
    printf("You will be prompted to enter your name.\n");
    printf("The first player will be chosen at random.\n");
    printf("----------------------------------------------\n");
    printf("Rules:\n");
    printf("----------------------------------------------\n");
    printf("1. You will be given 3 chances to guess the name of the animal, and 5 total lives.\n");
    printf("2. If you fail to guess the animal correctly in 3 tries, you will lose 1 life.\n");
    printf("3. If you guess correctly, you will be awarded 20 points.\n"); // to do
    printf("4. If you reach 100 points (5 guesses), you will win the game!\n");
    printf("5. If you run out of lives, the game will end.\n"); //
    printf("\n");
    printf("Good luck!\n\n\n");
}

// Prints the instructions for a saved game
void print_Saved_Instructions(){
    printf("Welcome back to the Endangered Animal Guessing game!\n");
    printf("----------------------------------------------\n");
    printf("A Quick Review on the Rules:\n");
    printf("----------------------------------------------\n");
    printf("1. You will be given 3 chances to guess the name of the animal, and 5 total lives.\n");
    printf("2. If you fail to guess the animal correctly in 3 tries, you will lose 1 life.\n");
    printf("3. If you guess correctly, you will be awarded 20 points.\n"); // to do
    printf("4. If you reach 100 points (5 guesses), you will win the game!\n");
    printf("5. If you run out of lives, the game will end.\n"); //
    printf("\n");
    printf("Good luck!\n\n\n");
}



// main game loop
int main() {
    //seed rand function
    srand(time(NULL));
    players = malloc(MAX_PLAYERS * sizeof(Player));
    //STATE: 0 = game not started, 1 = game started, 2 = game over, 3 = game won, 4 = game lost, 5 = game quit
    FILE *file = fopen("players.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
    }
    int ch = fgetc(file);
    if(ch == EOF){
        printf("No previous save file found. Creating new save file.\n\n\n");
        // print new game instructions
        print_New_Instructions();
        input_New_Player(players);
        save_Player_Info("players.txt", players);
    }
    else{
        printf("Save file found. Loading previous save file.\n");
        printf("\n");
        // print saved game instructions
        print_Saved_Instructions();
        load_Players("players.txt");
        list_Players(players);
    }
    fclose(file);

    load_Players("players.txt"); // Load existing records at the start
    // Checks to see if the file contains previous player data
    *state_Ptr = 1;

    // GAME PLAYING LOOP
    while (*state_Ptr == 1){
        // If player 1's turn
        // Generate a random number (either 1 or 2)
        int randomNumber = (rand() % 20);
        if (players[0].turn == 1){
            guess_Count = 3;
            printf("Player 1's (%s) turn!\n", players[0].name);
            make_Guess(animals, players, animal_Index_Ptr, guess_Ptr);
            check_If_Dead(players, state_Ptr);
        }
        else{
            guess_Count = 3;
            printf("Player 2's (%s) turn!\n", players[1].name);
            make_Guess(animals, players, animal_Index_Ptr, guess_Ptr);
            check_If_Dead(players, state_Ptr);
        }
        // Change turn to next player, check if game is won, save player info, and reset animal index and guesses
        change_Turn(players);
        check_Win(players);
        animal_Index_Ptr = &randomNumber;
        *guess_Ptr = 3;
        save_Player_Info("players.txt", players);        
    }

    // GAME OVER LOOP
    while(*state_Ptr == 2){
        printf("Game over!\n");
        printf("----------------------------------------------\n");
        printf("Press 'R' to restart the game or 'Q' to quit.\n");
        printf("----------------------------------------------\n");
        char input;
        scanf("%c", &input);
        if (input == 'R' || input == 'r'){
            *state_Ptr = 0;
            remove("players.txt");
            free(players);
            printf("Restarting game...\n\n\n");
            main();
        }
        else if (input == 'Q' || input == 'q'){
            *state_Ptr = 5;
            printf("Quitting game...\n");
            exit(0);
        }
    }
    // GAME WON LOOP
    while(*state_Ptr == 3){
        printf("Game won!\n");
        printf("----------------------------------------------\n");
        printf("Press 'R' to restart the game or 'Q' to quit.\n");
        printf("----------------------------------------------\n");
        char input;
        scanf("%c", &input);
        if (input == 'R' || input == 'r'){
            *state_Ptr = 0;
            remove("players.txt");
            free(players);
            printf("Restarting game...\n\n\n");
            main();
        }
        else if (input == 'Q' || input == 'q'){
            *state_Ptr = 5;
            printf("Quitting game...\n");
            exit(0);
        }
    }
    return 0;
}
