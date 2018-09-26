#include <SDL.h>
#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <SDL_render.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>



#define ASSERT(cnd, msg) if (cnd) throw std::exception(&(msg)[0]);

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void Init(SDL_Window* &window, SDL_Renderer* &renderer) {
	ASSERT(SDL_Init(SDL_INIT_VIDEO) < 0, "SDL could not initialize!");
	ASSERT(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"), "Warning: Linear texture filtering not enabled!");
	window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	ASSERT(window == nullptr, "Window could not be created!");
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	ASSERT(renderer == nullptr, "Renderer could not be created!");
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void Close(SDL_Window* &window, SDL_Renderer* &renderer) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;
	SDL_Quit();
}

int main(int argc, char *argv[]) {


	try
	{
		//Keyboard
		std::map<int, bool> keyboard;

		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;

		Init(window, renderer);
		SDL_Event e;

		//SONIDO
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
		Mix_Music *music = Mix_LoadMUS("../../res/music1.mp3");
		Mix_PlayMusic(music, 1);

		//CARGAMOS IMAGEN
		SDL_Surface * image = IMG_Load("../../res/img/bg.jpg");
		SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

		// MOUSE EN EL CENTRO DE LA PANTALLA
		SDL_WarpMouseInWindow(window, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

		//Botones
		TTF_Init();
		TTF_Font *font{ TTF_OpenFont("../../res/ttf/saiyan.ttf",200) };
		SDL_Surface *surPlay{ TTF_RenderText_Blended(font,"Play!",SDL_Color{ 0,0,255,0}) };
		SDL_Texture *textTextPlay{ SDL_CreateTextureFromSurface(renderer,surPlay) };
		SDL_Rect textRectPlay{ 300, 100, 100, 50 };

		
		SDL_Surface *surSound{ TTF_RenderText_Blended(font,"Sound",SDL_Color{ 0,0,255,0 }) };
		SDL_Texture *textTextSound{ SDL_CreateTextureFromSurface(renderer,surSound) };
		SDL_Rect textRectSound{ 300, 200, 100, 50 };

		
		SDL_Surface *surExit{ TTF_RenderText_Blended(font,"Exit",SDL_Color{ 0,0,255,0 }) };
		SDL_Texture *textTextExit{ SDL_CreateTextureFromSurface(renderer,surExit) };
		SDL_Rect textRectExit{ 300, 300, 100, 50 };
		

		bool quit = false;
		while (!quit) 
		{
			//BACKGROUND
			SDL_RenderCopy(renderer, texture, NULL, NULL);

			//RECTANGULOS
			SDL_SetRenderDrawColor(renderer, 150, 150, 150, 10);
			SDL_RenderFillRect(renderer, &textRectPlay);
			SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
			SDL_RenderFillRect(renderer, &textRectSound);
			SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
			SDL_RenderFillRect(renderer, &textRectExit);

			//TEXT
			SDL_RenderCopy(renderer, textTextPlay, nullptr, &textRectPlay);
			SDL_RenderCopy(renderer, textTextSound, nullptr, &textRectSound);
			SDL_RenderCopy(renderer, textTextExit, nullptr, &textRectExit);

			SDL_RenderPresent(renderer);
		}
		
		Close(window, renderer);
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		auto sdlError = SDL_GetError();
		if (strlen(sdlError)) std::cout << "SDL Error: " << sdlError << std::endl;
		std::cin.get();
	}



	return 0;
}