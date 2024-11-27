void read_scoreboard(Player scoreboard[])
{
    FILE *file = fopen("scoreboard.txt", "r");
    if (file == NULL)
    {
        printf("Error reading scoreboard file!\n");
        exit(1);
    }

    for (int i = 0; i < MAX_SCORES; i++)
    {
        fscanf(file, "%s %d", scoreboard[i].name, &scoreboard[i].score);
    }

    fclose(file);
}
