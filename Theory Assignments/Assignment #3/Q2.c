// Write a program that organizes a digital cricket match, "Cricket Showdown," where two players, Player 1 and Player 2, compete over 12 balls. Each player takes turns to score runs on each ball. Players can enter scores between 0 and 6 for each ball, and if a score outside this range is entered,
// it will be disregarded, but the ball will still be marked. 1. Define a structure Player with the following members:
// a. ballScores[12]: An array to store the score for each ball. b. playerName: A string to hold the player's name. c. totalScore: An integer to store the total score for each player. 2. Define functions:
// a. playGame(struct Player player): This function prompts each player to enter their
// score for each of the 12 balls. b. validateScore(int score): This function checks if the score is between 0 and 6
// (inclusive). If it’s not, the score is disregarded, but the ball is still marked. c. findWinner(struct Player player1,struct Player player2): Determines the winner based
// on the total score. d. displayMatchScoreboard(struct Player player1,struct Player player2): Displays a
// summary of each player’s performance, including each ball’s score, the average score, and total score.

#include <stdio.h>

struct  Player
{
    int ballScores[12];
    char playerName[50];
    int totalScore;
};

void playGame(struct Player *player){
    player->totalScore = 0;
    for(int i=0; i<12; i++){
        int valid = -1;
        while(valid == -1){
            printf("Enter the score for ball %d: ", i+1);
            scanf("%d", &player->ballScores[i]);
            valid = validateScore(player->ballScores[i]);
        }
        player->totalScore += player->ballScores[i];
    }
}

int validateScore(int score){
    if(score >= 0 && score <= 6){
        return score;
    }
    else{
        printf("Invalid score. Please enter a score between 0 and 6\n");
        return -1;
    }
}

void findWinner(struct Player *player1, struct Player *player2){
    int total_score1 = 0;
    int total_score2 = 0;
    for(int i=0; i<12; i++){
        total_score1 += player1->ballScores[i];
        total_score2 += player2->ballScores[i];
    }
    if(total_score1 > total_score2){
        printf("Player 1 wins by %d runs\n", total_score1-total_score2);
    }
    else if(total_score2 > total_score1){
        printf("Player 2 wins by %d runs\n", total_score2-total_score1);
    }
    else{
        printf("The match is a draw\n");
    }
}

void displayMatchScoreboard(struct Player *player1, struct Player *player2){
    printf("Player 1 Summary\n");
    printf("Player Name: %s\n", player1->playerName);
    printf("Total Score: %d\n", player1->totalScore);
    printf("Average Score: %f\n", (float)player1->totalScore/12);

    printf("Player 2 Summary\n");
    printf("Player Name: %s\n", player2->playerName);
    printf("Total Score: %d\n", player2->totalScore);
    printf("Average Score: %f\n", (float)player2->totalScore/12);
}

int main(){
    struct Player player1;
    struct Player player2;
    printf("Enter the name of player 1: ");
    scanf("%s", player1.playerName);
    printf("Enter the name of player 2: ");
    scanf("%s", player2.playerName);
    printf("SCORES FOR Player 1\n");
    playGame(&player1);
    printf("SCORES FOR Player 2\n");
    playGame(&player2);
    findWinner(&player1, &player2);
    displayMatchScoreboard(&player1, &player2);
}