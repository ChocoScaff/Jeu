#include "common.h"
#include <SDL2/SDL_mixer.h>

static Mix_Music *music;
static Mix_Chunk *chunk;

void Sound_Init(void)
{
	Mix_Init(MIX_INIT_OGG);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,1024) == -1)
	{
		printf("Couldn't initialize SDLMixer %s \n",SDL_GetError());
	}
}

void Music_Load(const char file[])
{
	if (file == NULL)
	{
		printf("File audio not found\n");
		return;
	}
    music = Mix_LoadMUS(file);
    if (music == NULL)
    {
        printf("Couldn't play audio %s\n",SDL_GetError());
        return;
    }
}

void Music_Play(void)
{
	if (Mix_PlayMusic(music,-1) != 0)
	{
		printf("Couldn't play audio %s\n",SDL_GetError());
	}
}

void Music_Pause(void)
{
	Mix_PauseMusic();
}

void Music_Resume(void)
{
	Mix_ResumeMusic();
}

void Sound_Quit(void)
{
	Mix_Quit();
}


