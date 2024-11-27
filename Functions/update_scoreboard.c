void update_scoreboard(Player scoreboard[], char player_name[], int new_score)
{
    for (int i = 0; i < MAX_SCORES; i++)
    {
        if (new_score > scoreboard[i].score)
        {
            // Adjusting the lower scores by moving them one place down
            for (int j = MAX_SCORES - 1; j > i; j--)
            {
                scoreboard[j] = scoreboard[j - 1];
            }

            // Inserting the new high score
            strncpy(scoreboard[i].name, player_name, 30);
            scoreboard[i].score = new_score;
            break;
        }
    }

    // Write the updated scoreboard back to the file
    FILE *file = fopen("scoreboard.txt", "w");
    if (file == NULL)
    {
        printf("Error writing to scoreboard file!\n");
        exit(1);
    }

    for (int i = 0; i < MAX_SCORES; i++)
    { // Writing one player and his/her score at a time
        fprintf(file, "%s %d\n", scoreboard[i].name, scoreboard[i].score);
    }

    fclose(file);
}
