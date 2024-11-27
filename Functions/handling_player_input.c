int handling_player_input(int ball_x, int ball_y, int *runs, int *flag_50runs, int *flag_100runs, int *flag_150runs, int *flag_200runs)
{
    if (ball_x == BATSMANPOSITION_X && ball_y == BATSMANPOSITION_Y)
    {
        printf(GREEN "Sensational Sixer! You scored 6 runs!\n" RESET);
        *runs += 6;
    }
    else if ((ball_x <= BATSMANPOSITION_X - 1 && ball_x >= BATSMANPOSITION_X - 2) && ball_y == BATSMANPOSITION_Y)
    {
        printf(YELLOW "Perfect Placement! You scored 4 runs!\n" RESET);
        *runs += 4;
    }
    else if ((ball_x <= BATSMANPOSITION_X - 3 && ball_x >= BATSMANPOSITION_X - 4) && ball_y == BATSMANPOSITION_Y)
    {
        printf(CYAN "Quick Running! You scored 3 runs!\n" RESET);
        *runs += 3;
    }
    else if ((ball_x <= BATSMANPOSITION_X - 5 && ball_x >= BATSMANPOSITION_X - 7) && ball_y == BATSMANPOSITION_Y)
    {
        printf("Double Trouble! You scored 2 runs!\n");
        *runs += 2;
    }
    else if ((ball_x <= BATSMANPOSITION_X - 8 && ball_x >= BATSMANPOSITION_X - 11) && ball_y == BATSMANPOSITION_Y)
    {
        printf("Just a tap and a run! You scored 1 run!\n");
        *runs += 1;
    }
    else if ((ball_x == BATSMANPOSITION_X + 2 || ball_x == BATSMANPOSITION_X + 1) && ball_y == BATSMANPOSITION_Y)
    {
        printf("Oh no! A fielder has caught the ball. You're OUT! The crowd groans in disappointment.\n");
        return 0; // Returning 0 to end the game
    }
    else if (ball_x == BATSMANPOSITION_X + 3 && ball_y == BATSMANPOSITION_Y)
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
