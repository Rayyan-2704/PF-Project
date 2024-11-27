void game_over_message(char player_name[], int runs, char *choice)
{
    printf(RED "\nGAME OVER!\n" RESET);
    printf(CYAN "%s has scored %d runs\n" RESET, player_name, runs);
    printf(BLUE "Would you like to play again? (Y/N)" RESET);
    scanf(" %c", choice); // Not using & as choice is already a pointer holding the address of a variable
}
