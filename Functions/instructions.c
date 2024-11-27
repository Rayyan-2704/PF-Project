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
