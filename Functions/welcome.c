void welcome(char player_name[])
{
    printf(BOLD GREEN "\nCricket Strike: Test your timing & Rule the stadium!\n" RESET);
    printf(YELLOW "Designed by Rayyan Aamir, Usaid Khan, Umer Dhedhi and Rafay Mehdi.\n" RESET);
    printf("\nPlease enter your name: ");
    fgets(player_name, 30, stdin);
    player_name[strcspn(player_name, "\n")] = '\0'; // Removing the newline and replacing it with the null character
    printf("\nWelcome " CYAN "%s!\t" RESET, player_name);
}
