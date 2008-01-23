#include <cstdlib>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "cuerpo.h"
#include "bateria.h"


using namespace std;

// Para iniciar el joystick
SDL_Joystick *OpenStick(int index)
{
  SDL_Joystick *stick=SDL_JoystickOpen(index);
  
  if(stick==NULL)
    fprintf(stderr,"No es posible utilizar el puerto%d\n",index);
  else
  {
    fprintf(stderr,"Puerto abierto %d\n",index);
    fprintf(stderr,"Nombre: %s\n", SDL_JoystickName(index));
    fprintf(stderr,"Number of Axes: %d\n", SDL_JoystickNumAxes(stick));
    fprintf(stderr,"Cantidad de Botones: %d\n", SDL_JoystickNumButtons(stick));
    fprintf(stderr,"Number of Balls: %d\n", SDL_JoystickNumBalls(stick));
  }
  return(stick);
}



typedef enum ImgType_e
{
  IMG_WINGMAN=0,
  IMG_ARROW  =1,
  IMG_CROSS  =2,
  IMG_LAST
} ImgType_e;

typedef enum DirType_e
{
  DIR_UP = 0,
  DIR_RIGHT = 1,
  DIR_DOWN = 2,
  DIR_LEFT = 3,
  DIR_END  = 4
} DirType_e;

#define MAX_BUTTON 10

int main(int argc, char *argv[])
{
    int running=1;
    int cur_stick=0;
    SDL_Joystick *stick=NULL;
    SDL_Surface *screen=NULL;
    Mix_Music *c1;

    if(SDL_Init(SDL_INIT_JOYSTICK|SDL_INIT_VIDEO|SDL_INIT_AUDIO)<0)
    {
        fprintf(stderr,"No es posible inicar la libreria SDL!\n");
        return(-1);
    }

// Configuracion de pantalla
    screen=SDL_SetVideoMode(293,196,24,SDL_ANYFORMAT);
    if(screen==NULL)
    {
        fprintf(stderr,"No es posible crear una pantalla 320*240: %s\n",SDL_GetError());
        SDL_Quit();
        return(1);
    }

//Configuracion de audio
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
    {
        printf("No es posible iniciar la libreria de Audio: %s\n", Mix_GetError());
        return 1;
    }


    int joy=SDL_NumJoysticks();
    if(joy<=0)
    {
        fprintf(stderr,"El joystick no esta conectado\n");
        SDL_Quit();
        return(2);
    }
    else
        fprintf(stderr,"Joysticks:  %d\n",joy);

    SDL_JoystickEventState(SDL_ENABLE);

// Llamo a la funcion para reconocer el joys
    stick = OpenStick(cur_stick);

    Bateria a;
    Cuerpo c;
    
    if(stick!=NULL)
        SDL_JoystickClose(stick);

    Mix_CloseAudio();
    SDL_Quit();

    return EXIT_SUCCESS;
}
