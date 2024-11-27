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
    for (int i = 0; i < FIELD_WIDTH; i++)
    {
        if (i == 0 || i == (FIELD_WIDTH - 1))
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
    for (int i = 0; i < FIELD_HEIGHT; i++)
    {
        printf(CYAN "|" RESET);
        for (int j = 0; j < FIELD_WIDTH - 1; j++)
        {
            if (j == ball_x && i == ball_y)
            {
                printf(RED "o" RESET); // Ball
            }
            else if (j == BATSMANPOSITION_X && i == BATSMANPOSITION_Y - 1)
            {
                printf(BLUE "O" RESET); // Stickman's head
            }
            else if (j == BATSMANPOSITION_X && i == BATSMANPOSITION_Y)
            {
                printf(BLUE "|" RESET); // Stickman's body
            }
            else if (j == BATSMANPOSITION_X - 1 && i == BATSMANPOSITION_Y)
            {
                printf(BLUE "/" RESET); // Stickman's left arm
            }
            else if (j == BATSMANPOSITION_X + 1 && i == BATSMANPOSITION_Y)
            {
                printf(BLUE "\\" RESET); // Stickman's right arm
            }
            else if (j == BATSMANPOSITION_X - 1 && i == BATSMANPOSITION_Y + 1)
            {
                printf(BLUE "/" RESET); // Stickman's left leg
            }
            else if (j == BATSMANPOSITION_X + 1 && i == BATSMANPOSITION_Y + 1)
            {
                printf(BLUE "\\" RESET); // Stickman's right leg
            }
            else if (j == BATSMANPOSITION_X + 3 && i == BATSMANPOSITION_Y)
            {
                printf(YELLOW "=" RESET); // Wicket's bail 1
            }
            else if (j == BATSMANPOSITION_X + 4 && i == BATSMANPOSITION_Y)
            {
                printf(YELLOW "=" RESET); // Wicket's bail 2
            }
            else if (j == BATSMANPOSITION_X + 5 && i == BATSMANPOSITION_Y)
            {
                printf(YELLOW "=" RESET); // Wicket's bail 3
            }
            else if ((j == BATSMANPOSITION_X + 3 || j == BATSMANPOSITION_X + 4 || j == BATSMANPOSITION_X + 5) && i == BATSMANPOSITION_Y + 1)
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
    for (int i = 0; i < FIELD_WIDTH; i++)
    {
        if (i == 0 || i == (FIELD_WIDTH - 1))
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
