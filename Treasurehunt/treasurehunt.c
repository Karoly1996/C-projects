#define _CRT_SECURE_NO_WARNINGS

//Macros
#define MIN_LIVES 1 
#define MAX_LIVES 10
#define MIN_PATH 10
#define MAX_PATH 70
#define MULTIPLE 5


#include <stdio.h>

//Struct's to define user defined data types
struct Playerinfo {
    int lives;
    char symbol;
    int treasure;
    int pastPositions[MAX_PATH];
};
struct Gameinfo {
    int moves;
    int path;
    int bombs[MAX_PATH];
    int treasureLocation[MAX_PATH];
};



int main(void)
{
    //Declare player and game and variables
    struct Playerinfo player;
    struct Gameinfo game;
    int movesLeft, livesLeft;
    int playerMove = MAX_PATH + 1;
    

    //start header
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    //Player configuration and request player symbol
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    //loop for player lives to be between 1-10
    do {
        //input lives
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        //Print error message if invalid
        if (player.lives < 1 || player.lives > 10) {
            printf("     Must be between 1 and 10!\n");
        }
    } while (player.lives < MIN_LIVES || player.lives > MAX_LIVES);
    //display complete message
    printf("Player configuration set-up is complete\n\n");

    //start game config
    printf("GAME Configuration\n");
    printf("------------------\n");

    //request input for path lenght
    do {
        //input path lenght
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.path);
        //display error & Split line
        if (game.path % MULTIPLE != 0 
            || game.path < MIN_PATH || game.path > MAX_PATH) {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
        //Split line to stay under 80 characters
    } while (game.path % MULTIPLE != 0 
            || game.path < MIN_PATH || game.path > MAX_PATH);

    //request input for moves
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
        //print error message if moves are not valid
       if (game.moves < player.lives || game.moves > 0.75 * game.path) {
        printf("    Value must be between %d and %d"
        "\n", player.lives, (int)(game.path * 0.75));
       }
    } while (game.moves < player.lives || game.moves > 0.75 * game.path);
    printf("\n");

    //Request input for bomb placement
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    //displaying the exact number inputted into game path
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path);
    
    //start loop for bomb
    int i; 
    for (i = 0; i < game.path; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        //get user input for bomb placement 
        scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], 
        &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);
    } 
    printf("BOMB placement set\n\n");

    //start treasure placement 
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path);

    //Begin loop for treasure
    int j;
    for (j = 0; j < game.path; j += 5) {
        printf("   Positions [%2d-%2d]: ", j + 1, j + 5);
        //get input for treasure locations
        //split line to stay under 80 character
        scanf("%d %d %d %d %d", 
        &game.treasureLocation[j], &game.treasureLocation[j + 1], 
        &game.treasureLocation[j + 2], 
        &game.treasureLocation[j + 3], &game.treasureLocation[j + 4]);
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    
    //display summary 
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    //Player summary
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    //Game summary
    printf("Game:\n");
    //display path lenght
    printf("   Path Length: %d\n", game.path);

    //bomb
    printf("   Bombs      : ");
    //start a loop to display bomb input
    int b;
    for (b = 0; b < game.path; b++) {
        printf("%d", game.bombs[b]);
    }
    printf("\n");
    
    //treasure 
    printf("   Treasure   : ");
     //start loop to display treasure input
    int t;
    for (t = 0; t < game.path; t++) {
        printf("%d", game.treasureLocation[t]);
    }
    printf("\n\n");

    //display ending summary for part1
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    //Starting part 2

    //declare values for part2
    movesLeft = game.moves;
    livesLeft = player.lives;
    player.treasure = 0;
    int symCount = 0;
    char playerPosition[MAX_PATH], itemPosition[MAX_PATH];

    //Current position initialization
    for (t = 0; t < game.path; t++) {
        playerPosition[t] = ' ';
    }
    //position history initialization 
    for (j = 0; j < game.path; j++) {
        player.pastPositions[j] = 0;
    }
    //item position initialization
    for (t = 0; t < game.path; t++) {
        itemPosition[t] = '-';
    }

    //display table
    do {
        //first line loop
        for (t = 0; t < game.path; t++) {
            if (playerPosition[t] == player.symbol) {
                symCount++;
            }
        } if (symCount == 0) {
            printf("\n");
        } else {
            //indent for new line
            printf("  ");
            //display player symbol
            for (t = 0; t < game.path; t++) {
                if (playerPosition[t] == player.symbol) {
                    printf("%c\n", playerPosition[t]);
                    break;
                } else {
                    printf("%c", playerPosition[t]);
                }
            }
        }
        //clear current position of player
        for (t = 0; t < game.path; t++) {
            playerPosition[t] = ' ';
        }
        //line 2 
        printf("  ");
        for (t = 0; t < game.path; t++) {
            printf("%c", itemPosition[t]);
        }
        printf("\n");
        printf("  ");
        //line 3
        for (i = 1; i <= game.path; i++) {
            if (i % 10 == 0) {
                printf("%d", (int)i / 10);
            } else {
                printf("|");
            }
        }
        printf("\n");
        printf("  ");
        //line 4
        for (i = 0; i <game.path; i += 10) {
            printf("1234567890");
        }
        printf("\n");

        //player statistics
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
        livesLeft, player.treasure, movesLeft);
        printf("+---------------------------------------------------+\n");
        
        if (livesLeft == 0 || movesLeft == 0) {
            break;
        }

        //Players move 
        do {
            //request players input for move
            printf("Next Move [1-%d]: ", game.path);
            scanf("%d", &playerMove);
            //display error if range is invalid
            if (playerMove < 1 || playerMove > game.path) {
                printf("  Out of Range!!!\n");
            }
        } while (playerMove < 1 || playerMove > game.path);
        printf("\n");

        //input players move 
        if (player.pastPositions[playerMove - 1] == 1) {
            printf("===============> Dope! You've been here before!\n\n");
            playerPosition[playerMove - 1] = player.symbol;
            //Reverse the decrementation after move is invalid
            movesLeft++;
            //split line to stay undeer 80 characters
            //player bomb and treasure input
        } else if (game.bombs[playerMove - 1] == 1 
            && game.treasureLocation[playerMove - 1] == 1) {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            printf("\n");
            //represent both bomb and treasure
            itemPosition[playerMove - 1] = '&';
            //player symbol
            playerPosition[playerMove - 1] = player.symbol;
            livesLeft--;
            player.treasure++;
        } else if (game.bombs[playerMove - 1] == 1) {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            //represent bomb
            itemPosition[playerMove - 1] = '!';
            //player symbol
            playerPosition[playerMove - 1] = player.symbol;
            livesLeft--;
        } else if (game.treasureLocation[playerMove - 1] == 1) {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            //represent treasure
            itemPosition[playerMove - 1] = '$';
            playerPosition[playerMove - 1] = player.symbol;
            player.treasure++;
        } else {
            printf("===============> [.] ...Nothing found here... [.]\n\n");
            //represent neither bomb or treasure
            itemPosition[playerMove - 1] = '.';
            //player symbol
            playerPosition[playerMove - 1] = player.symbol;
        }

        //history of positions in array
        player.pastPositions[playerMove - 1] = 1;
        //Decrement moves
        movesLeft--;

        //display no lives remaining
        if (livesLeft == 0) {
            printf("No more LIVES remaining!\n\n");
        }
        //Display no moves remaining
        if (movesLeft == 0) {
            printf("No more MOVES remaining!\n\n");
        }
    //end loop once no lives or moves left
    } while (movesLeft >= 0 && livesLeft >= 0);

    // Display Game over message 
    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");
    printf("\n");

    
    return 0;
}
