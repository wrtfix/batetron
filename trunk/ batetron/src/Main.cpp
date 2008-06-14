#include <cstdlib>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include "Cuerpo.h"
#include "Bateria.h"

//test modificacion x svn probando jorgito

using namespace std;
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

int main(int argc, char *argv[])
{
    // Iniciamos el subsistema de video

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO|SDL_INIT_JOYSTICK) < 0) {
    	cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
	exit(1);
    }

    SDL_Surface *screen = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE);


	if (screen == NULL) 
	{
		printf("Error: %s\n", SDL_GetError());
		return 1;
	}

    SDL_WM_SetCaption("Batetron", NULL);

    SDL_Surface *ima; 
    ima = IMG_Load("./imagenes/bateria.png");
   
    Uint32 ac = SDL_MapRGB(screen->format, 200, 200, 200);
	SDL_FillRect(screen, NULL, ac);

    SDL_Rect rect = {100, 0, 0, 0};
	SDL_BlitSurface(ima, NULL, screen, &rect);
	
	SDL_Flip(screen);


    // Inicializamos la librería SDL_Mixer

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,\
		     MIX_DEFAULT_CHANNELS, 512) < 0) {

	cerr << "Subsistema de Audio no disponible" << endl;
	exit(1);
    }

    bool running = true;
    int cur_stick=0;
    SDL_Joystick *stick=NULL;
    
    //Cargamos los sonidos de cada cuerpo/boton

	char* cuerpo1= "sonido 1";
	string cuerpo3 = "algun string cualquiera   ";
/*    Cuerpo a("Sonido 1"
    Cuerpo b("Sonido 2"
    Cuerpo c("Sonido 3"
    Cuerpo d("Sonido 4"
    Cuerpo e("Sonido 5"
    Cuerpo f("Sonido 6"
    Cuerpo g("Sonido 7"
    Cuerpo h("Sonido 8"
    Cuerpo i("Sonido 9"
		Sonido 10"*/

    Cuerpo a(cuerpo1, "./sonidos/cym_Rock_b.ogg",100,1);
    Cuerpo b("Sonido 2", "./sonidos/hhp_Dry_a.ogg",100,2);
    Cuerpo c("Sonido 3", "./sonidos/kick_Dry_b.ogg",100,3);
    Cuerpo d("Sonido 4", "./sonidos/808_Tom_Hi.ogg",100,4);
    Cuerpo e("Sonido 5", "./sonidos/808_Shaker.ogg",100,5);
    Cuerpo f("Sonido 6", "./sonidos/808_Cowbell.ogg",100,6);
    Cuerpo g("Sonido 7", "./sonidos/808_Cymbal.ogg",100,7);
    Cuerpo h("Sonido 8", "./sonidos/808_Snare_1.ogg",100,8);
    Cuerpo i("Sonido 9", "./sonidos/808_Kick_Short.ogg",100,9);
    Cuerpo j("Sonido 10", "./sonidos/808_Hat_Pedal.ogg",100,0);

    Bateria bata(MAX_BUTTON);

    bata.addCuerpo(&a);
    bata.addCuerpo(&b);
    bata.addCuerpo(&c);
    bata.addCuerpo(&d);
    bata.addCuerpo(&e);
    bata.addCuerpo(&f);
    bata.addCuerpo(&g);
    bata.addCuerpo(&h);
    bata.addCuerpo(&i);
    bata.addCuerpo(&j);

    // Llamo a la funcion para reconocer el joys
    int joy=SDL_NumJoysticks();

    if(joy<=0)
    {
      fprintf(stderr,"El joystick no esta conectado\n");
      SDL_Quit();
      return(2);
    }
    else
      fprintf(stderr,"Joysticks:  %d\n",joy);

	SDL_Init (SDL_INIT_TIMER | SDL_INIT_NOPARACHUTE);

	SDL_JoystickEventState(SDL_ENABLE);
	stick=OpenStick(cur_stick);
	
	SDL_Event event;
    
	while(running)
	{
		SDL_WaitEvent (& event);
		switch (event.type)
		{        
			case SDL_QUIT:
			{
				running = false;
			} break;
			case SDL_JOYBUTTONDOWN:
            {
                if(event.jbutton.button == 0)
                    bata.reproducirCuerpo(0);
                if(event.jbutton.button == 1)
                    bata.reproducirCuerpo(1);
                if(event.jbutton.button == 2)
                    bata.reproducirCuerpo(2);
                if(event.jbutton.button == 3)
                    bata.reproducirCuerpo(3);
                if(event.jbutton.button == 4)
                    bata.reproducirCuerpo(4);
                if(event.jbutton.button == 5)
                    bata.reproducirCuerpo(5);
                if(event.jbutton.button == 6)
                    bata.reproducirCuerpo(6);
                if(event.jbutton.button == 7)
                    bata.reproducirCuerpo(7);
                if(event.jbutton.button == 8)
                    bata.reproducirCuerpo(8);
                if(event.jbutton.button == 9)
                    bata.reproducirCuerpo(9);
            }break;
            default: {
      	    } break;
         }//Fin del Switch
     }

    if(stick!=NULL)
        SDL_JoystickClose(stick);
	SDL_Quit();    
	return 0;
}
