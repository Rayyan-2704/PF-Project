/* This file contains the printing of the ground, batsman, ball, stumps and bails using ASCII art */

// #include <stdio.h>
// void display_arena(char player_name[], int runs, int ball_x, int ball_y)
// {
//     for (int i = 0; i < 5; i++)
//     {
//         if (i == 0 || i == 4)
//         {
//             printf("===========================\n");
//         }
//         else if (i == 1 || i == 3)
//         {
//             printf("||                       ||\n");
//         }
//         else
//         {
//             printf("||   THE CRICKET ARENA   ||\n");
//         }
//     }

//     printf("\nPlayer: %s\t Runs Scored: %d\n", player_name, runs);

//     // The Upper Boundary
//     for (int i = 0; i < FIELD_WIDTH; i++)
//     {
//         if (i == 0 || i == (FIELD_WIDTH - 1))
//         {
//             printf("+");
//         }
//         else
//         {
//             printf("-");
//         }
//     }
//     printf("\n"); // Move to the next line after the top boundary

//     // Field with elements
//     for (int i = 0; i < FIELD_HEIGHT; i++)
//     {
//         printf("|");
//         for (int j = 0; j < FIELD_WIDTH - 1; j++)
//         {
//             if (j == ball_x && i == ball_y)
//             {
//                 printf("o"); // Ball
//             }
//             else if (j == BATSMANPOSITION_X && i == BATSMANPOSITION_Y - 1)
//             {
//                 printf("O"); // Stickman's head
//             }
//             else if (j == BATSMANPOSITION_X && i == BATSMANPOSITION_Y)
//             {
//                 printf("|"); // Stickman's body
//             }
//             else if (j == BATSMANPOSITION_X - 1 && i == BATSMANPOSITION_Y)
//             {
//                 printf("/"); // Stickman's left arm
//             }
//             else if (j == BATSMANPOSITION_X + 1 && i == BATSMANPOSITION_Y)
//             {
//                 printf("\\"); // Stickman's right arm
//             }
//             else if (j == BATSMANPOSITION_X - 1 && i == BATSMANPOSITION_Y + 1)
//             {
//                 printf("/"); // Stickman's left leg
//             }
//             else if (j == BATSMANPOSITION_X + 1 && i == BATSMANPOSITION_Y + 1)
//             {
//                 printf("\\"); // Stickman's right leg
//             }
//             else if (j == BATSMANPOSITION_X + 3 && i == BATSMANPOSITION_Y)
//             {
//                 printf("="); // Wicket's bail 1
//             }
//             else if (j == BATSMANPOSITION_X + 4 && i == BATSMANPOSITION_Y)
//             {
//                 printf("="); // Wicket's bail 2
//             }
//             else if (j == BATSMANPOSITION_X + 5 && i == BATSMANPOSITION_Y)
//             {
//                 printf("="); // Wicket's bail 3
//             }
//             else if ((j == BATSMANPOSITION_X + 3 || j == BATSMANPOSITION_X + 4 || j == BATSMANPOSITION_X + 5) && i == BATSMANPOSITION_Y + 1)
//             {
//                 printf("|"); // Wicket's stumps
//             }
//             else
//             {
//                 printf(" "); // Empty field space
//             }
//         }
//         printf("|\n");
//     }

//     // Lower Boundary
//     for (int i = 0; i < FIELD_WIDTH; i++)
//     {
//         if (i == 0 || i == (FIELD_WIDTH - 1))
//         {
//             printf("+");
//         }
//         else
//         {
//             printf("-");
//         }
//     }
//     printf("\n"); // Move to the next line after the bottom boundary
// }
