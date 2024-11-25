#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

const int field_width = 50;
const int field_height = 16;
const int batsmanposition_x = 35;
const int batsmanposition_y = 8;
const int ball_initial_x = 0;
const int ball_initial_y = 8;

void welcome(char player_name[]);
void instructions();
void display_arena(char player_name[], int runs, int ball_x, int ball_y);
int handling_player_input(int ball_x, int ball_y, int *runs, int *flag_50runs, int *flag_100runs, int *flag_150runs, int *flag_200runs);
void game_over_message(char player_name[], int runs, char *choice);

int main()
{
    char choice;
    char player_name[30];
    welcome(player_name); // Welcome message and getting the user's name
    instructions();       // Displaying the instructions to the user

    do
    {
        int runs = 0;
        int ball_x = ball_initial_x;
        int ball_y = ball_initial_y;
        float ball_direction = 1; // To move the ball in the rightwards direction
        char player_input;
        int flag_50runs = 0, flag_100runs = 0, flag_150runs = 0, flag_200runs = 0;

        // The loop runs infinitely unless the ball hits the wicket and the user is out
        while (1)
        {
            system("cls"); // Clearing the terminal screen for each frame or every movement of the ball towards the batsman

            display_arena(player_name, runs, ball_x, ball_y); // Displaying the cricket arena for the user

            if (_kbhit()) // Checking the if any key has been entered using _kbhit()
            {
                player_input = _getch(); // The pressed key has been fetched using _getch()
                if (player_input == 's')
                {
                    if (handling_player_input(ball_x, ball_y, &runs, &flag_50runs, &flag_100runs, &flag_150runs, &flag_200runs) == 0)
                    {
                        break; // Exiting the loop if the batsman's out
                    }
                    ball_x = ball_initial_x; // Resetting the ball's position for a new bowl
                    continue;                // The loop repeats, skipping the below lines of code
                }
            }

            ball_x += ball_direction; // The ball moves forward if the user does not swing the bat

            // If the user does not swing the bat at all and the ball reaches the stumps & bails
            if (ball_x == batsmanposition_x + 3 && ball_y == batsmanposition_y)
            {
                printf("Oops! The ball knocked the stumps over. You're OUT!\nThe crowd sighs in disbelief... but don't worry, even legends have bad days!\n");
                break;
            }
            if(flag_50runs == 1 && flag_100runs == 0 && flag_150runs == 0 && flag_200runs == 0){
            	ball_direction = 1.25;
			}
			else if(flag_50runs == 1 && flag_100runs == 1 && flag_150runs == 0 && flag_200runs == 0){
				ball_direction = 1.5;
			}
			else if(flag_50runs == 1 && flag_100runs == 1 && flag_150runs == 1 && flag_200runs == 0){
				ball_direction = 2.25;
			}
			else if(flag_50runs == 1 && flag_100runs == 1 && flag_150runs == 1 && flag_200runs == 1){
				ball_direction = 2.75;
			}
        }
        game_over_message(player_name, runs, &choice);
        
    } while (choice == 'Y' || choice == 'y');

    printf("Thank you for playing :) \nExiting the game.....");
    return 0;
}

void welcome(char player_name[])
{
    printf(BOLD GREEN "\nCricket Strike: Test your timing & Rule the stadium!\n" RESET);
    printf(YELLOW "Designed by Rayyan Aamir, Usaid Khan, Umer Dhedhi and Rafay Mehdi.\n" RESET);
    printf("\nPlease enter your name: ");
    fgets(player_name, 30, stdin);
    player_name[strcspn(player_name, "\n")] = '\0'; // Removing the newline and replacing it with the null character
    printf("\nWelcome " CYAN "%s!\t" RESET, player_name);
}

void instructions()
{
    printf(BLUE "Please read the instructions below:\n" RESET);
    printf(WHITE "1. Press 's' to swing the bat and strike the ball.\n");
    printf("2. Time your strike accurately as it determines the number of runs scored.\n");
    printf(GREEN "   -Perfect timing = 6 runs.\n");
    printf(YELLOW "   -Great hit = 4 runs.\n");
    printf(CYAN "   -Good timing = 3 runs.\n");
    printf(WHITE "   -Early hit = 1 or 2 runs.\n");
    printf(RED "   -Complete Mistiming = No runs scored.\n");
    printf("3. If the ball hits the wicket, then you are out and the game's over.\n");
    printf("4. Have fun and score as many runs as you can :) \n");
    printf("Press any key to start...\n");
    getch();
}

void display_arena(char player_name[], int runs, int ball_x, int ball_y)
{
    for (int i = 0; i < 5; i++)
    {
        if (i == 0 || i == 4)
        {
            printf(BOLD MAGENTA "===========================\n" RESET);
        }
        else if (i == 1 || i == 3)
        {
            printf(BOLD MAGENTA "||                       ||\n" RESET);
        }
        else
        {
            printf(BOLD MAGENTA "||   THE CRICKET ARENA   ||\n" RESET);
        }
    }

    printf("\nPlayer: " CYAN "%s\t" RESET "Runs Scored: " GREEN "%d\n" RESET, player_name, runs);

    // The Upper Boundary
    for (int i = 0; i < field_width; i++)
    {
        if (i == 0 || i == (field_width - 1))
        {
            printf(GREEN "+" RESET);
        }
        else
        {
            printf(CYAN "-" RESET);
        }
    }
    printf("\n"); // Move to the next line after the top boundary

    // Field with elements
    for (int i = 0; i < field_height; i++)
    {
        printf(CYAN "|" RESET);
        for (int j = 0; j < field_width - 1; j++)
        {
            if (j == ball_x && i == ball_y)
            {
                printf(RED "o" RESET); // Ball
            }
            else if (j == batsmanposition_x && i == batsmanposition_y - 1)
            {
                printf(BLUE "O" RESET); // Stickman's head
            }
            else if (j == batsmanposition_x && i == batsmanposition_y)
            {
                printf(BLUE "|" RESET); // Stickman's body
            }
            else if (j == batsmanposition_x - 1 && i == batsmanposition_y)
            {
                printf(BLUE "/" RESET); // Stickman's left arm
            }
            else if (j == batsmanposition_x + 1 && i == batsmanposition_y)
            {
                printf(BLUE "\\" RESET); // Stickman's right arm
            }
            else if (j == batsmanposition_x - 1 && i == batsmanposition_y + 1)
            {
                printf(BLUE "/" RESET); // Stickman's left leg
            }
            else if (j == batsmanposition_x + 1 && i == batsmanposition_y + 1)
            {
                printf(BLUE "\\" RESET); // Stickman's right leg
            }
            else if (j == batsmanposition_x + 3 && i == batsmanposition_y)
            {
                printf(YELLOW "=" RESET); // Wicket's bail 1
            }
            else if (j == batsmanposition_x + 4 && i == batsmanposition_y)
            {
                printf(YELLOW "=" RESET); // Wicket's bail 2
            }
            else if (j == batsmanposition_x + 5 && i == batsmanposition_y)
            {
                printf(YELLOW "=" RESET); // Wicket's bail 3
            }
            else if ((j == batsmanposition_x + 3 || j == batsmanposition_x + 4 || j == batsmanposition_x + 5) && i == batsmanposition_y + 1)
            {
                printf(YELLOW "|" RESET); // Wicket's stumps
            }
            else
            {
                printf(" "); // Empty field space
            }
        }
        printf(CYAN "|\n" RESET);
    }

    // Lower Boundary
    for (int i = 0; i < field_width; i++)
    {
        if (i == 0 || i == (field_width - 1))
        {
            printf(GREEN "+" RESET);
        }
        else
        {
            printf(CYAN "-" RESET);
        }
    }
    printf("\n"); // Move to the next line after the bottom boundary
}

int handling_player_input(int ball_x, int ball_y, int *runs, int *flag_50runs, int *flag_100runs, int *flag_150runs, int *flag_200runs)
{
    if (ball_x == batsmanposition_x && ball_y == batsmanposition_y)
    {
        printf(GREEN "Sensational Sixer! You scored 6 runs!\n" RESET);
        *runs += 6;
    }
    else if ((ball_x <= batsmanposition_x - 1 && ball_x >= batsmanposition_x - 2) && ball_y == batsmanposition_y)
    {
        printf(YELLOW "Perfect Placement! You scored 4 runs!\n" RESET);
        *runs += 4;
    }
    else if ((ball_x <= batsmanposition_x - 3 && ball_x >= batsmanposition_x - 4) && ball_y == batsmanposition_y)
    {
        printf(CYAN "Quick Running! You scored 3 runs!\n" RESET);
        *runs += 3;
    }
    else if ((ball_x <= batsmanposition_x - 5 && ball_x >= batsmanposition_x - 7) && ball_y == batsmanposition_y)
    {
        printf("Double Trouble! You scored 2 runs!\n");
        *runs += 2;
    }
    else if ((ball_x <= batsmanposition_x - 8 && ball_x >= batsmanposition_x - 11) && ball_y == batsmanposition_y)
    {
        printf("Just a tap and a run! You scored 1 run!\n");
        *runs += 1;
    }
    else if ((ball_x == batsmanposition_x + 2 || ball_x == batsmanposition_x + 1) && ball_y == batsmanposition_y)
    {
        printf("Oh no! A fielder has caught the ball. You're OUT! The crowd groans in disappointment.\n");
        return 0; // Returning 0 to end the game
    }
    else if (ball_x == batsmanposition_x + 3 && ball_y == batsmanposition_y)
    {
        printf("Oops! The ball knocked the stumps over. You're OUT!\nThe crowd sighs in disbelief... but don't worry, even legends have bad days!\n");
        return 0; // Returning 0 to end the game
    }

    else
    {
        printf(RED "Swing and a miss! Dot ball, no runs scored.\n" RESET);
    }

    // Special half-century and century messages.
    if (*runs >= 50 && *flag_50runs == 0) // Only display once when it reaches 50
    {
        printf(YELLOW "The crowd goes wild! You've reached a Half-Century! 50 runs! Keep going, you're on fire!\n" RESET);
        *flag_50runs = 1;
        Sleep(2000); // Pause for 2 seconds to show the special message
    }
    else if (*runs >= 100 && *flag_100runs == 0) // Only display once when it reaches 100
    {
        printf(GREEN "Unbelievable! The stadium is on its feet, cheering for you! You've scored a Full Century! 100 runs!\n" RESET);
        *flag_100runs = 1;
        Sleep(2000); // Pause for 2 seconds to show the special message
    }
    else if (*runs >= 150 && *flag_150runs == 0) // Only display once when it reaches 150
    {
        printf("Incredible! You're unstoppable! A magnificent 150 runs! The crowd is in awe of your skill and timing!\n");
        *flag_150runs = 1;
        Sleep(2000); // Pause for 2 seconds to show the special message
    }
    else if (*runs >= 200 && *flag_200runs == 0) // Only display once when it reaches 200
    {
        printf(RED "History is made! You've scored a Double Century! 200 runs! The world is watching your masterpiece!\n" RESET);
        *flag_200runs = 1;
        Sleep(2000); // Pause for 2 seconds to show the special message
    }

    Sleep(1000); // Pause for 1 second before continuing the game
    return 1;    // Returning 1 to continue the game
}

void game_over_message(char player_name[], int runs, char *choice)
{
    printf(RED "\nGAME OVER!\n" RESET);
    printf(CYAN "%s has scored %d runs\n" RESET, player_name, runs);
    printf(BLUE "Would you like to play again? (Y/N)" RESET);
    scanf(" %c", choice); // Not using & as choice is already a pointer holding the address of a variable
}
