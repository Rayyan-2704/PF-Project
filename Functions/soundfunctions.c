void playWicketSound()
{
    mciSendString("open \"Wicket.wav\" type waveaudio alias sound", NULL, 0, NULL);
    mciSendString("play sound wait", NULL, 0, NULL);
    mciSendString("close sound", NULL, 0, NULL);
}

void playCheerSound()
{
    mciSendString("open \"Cheer.wav\" type waveaudio alias sound", NULL, 0, NULL);
    mciSendString("play sound wait", NULL, 0, NULL);
    mciSendString("close sound", NULL, 0, NULL);
}

void playApplauseSound()
{
    mciSendString("open \"Clapping.wav\" type waveaudio alias sound", NULL, 0, NULL);
    mciSendString("play sound wait", NULL, 0, NULL);
    mciSendString("close sound", NULL, 0, NULL);
}

void playOutSound()
{
    mciSendString("open \"Aww.wav\" type waveaudio alias sound", NULL, 0, NULL);
    mciSendString("play sound wait", NULL, 0, NULL);
    mciSendString("close sound", NULL, 0, NULL);
}
