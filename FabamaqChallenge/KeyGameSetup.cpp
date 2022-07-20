#include "KeyGameSetup.h"

bool KeyGameSetup::init(int width, int height)
{

    //Check if the SDL initiantion went well
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not start correctly! SDL Error: %s\n", SDL_GetError());

        return false;
    }

    //Create the window, with a undefined position but with a pre-defined width and height
    window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    //If the window is not created, print the error
    if (window == NULL)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    //Get the surface inside the window that was created, so it can be used later
    gScreenSurface = SDL_GetWindowSurface(window);

    return true;
}

void KeyGameSetup::startGame(int width,int height) 
{
    bool quit = false;

    SDL_Event events;

    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

    init(width,height);

    loadAllMedia();

    while(!quit) 
    {
        //Handle events on queue
        while (SDL_PollEvent(&events) != 0)
        {
            //User requests quit
            if (events.type == SDL_QUIT)
            {
                quit = true;
            }
            //User presses a key
            else if (events.type == SDL_KEYDOWN)
            {
                //Select surfaces based on key press
                switch (events.key.keysym.sym)
                {
                case SDLK_UP:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                    break;

                case SDLK_DOWN:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                    break;

                case SDLK_LEFT:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                    break;

                case SDLK_RIGHT:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                    break;

                default:
                    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                    break;
                }
            }
        }

        //Apply the current image
        SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);

        //Update the surface
        SDL_UpdateWindowSurface(window);
    }

    close();
}

//Loads individual image
SDL_Surface* KeyGameSetup::loadSurface(std::string path)
{
    //The final optimized surface
    SDL_Surface* optimizedSurface = NULL;

    //Load image at a specific location
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());

    if (loadedSurface == NULL)
    {
        printf("Error loading image at %s ! SDL ERROR:%s\n ", path.c_str(), SDL_GetError());
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
        if (optimizedSurface == NULL)
        {
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return optimizedSurface;
}

bool KeyGameSetup::loadAllMedia()
{
    //Loading success flag
    bool success = true;

    //Load default surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("Resources/press.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
    {
        printf("Failed to load default image!\n");
        success = false;
    }

    //Load up surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("Resources/up.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
    {
        printf("Failed to load up image!\n");
        success = false;
    }

    //Load down surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("Resources/down.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
    {
        printf("Failed to load down image!\n");
        success = false;
    }

    //Load left surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("Resources/left.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
    {
        printf("Failed to load left image!\n");
        success = false;
    }

    //Load right surface
    gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("Resources/right.bmp");
    if (gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
    {
        printf("Failed to load right image!\n");
        success = false;
    }

    return success;
}

void KeyGameSetup::close() 
{
    //Deallocate surfaces
    for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
    {
        SDL_FreeSurface(gKeyPressSurfaces[i]);
        gKeyPressSurfaces[i] = NULL;
    }

    //Destroy window
    SDL_DestroyWindow(window);
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

