#include <cstdlib>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <iostream>
#include "Cuerpo.h"
#include "Bateria.h"

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



void IniciarLibreria()
{
    // Iniciamos el subsistema de video

    if(SDL_Init(SDL_INIT_JOYSTICK|SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {

	cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
	exit(1);
    }

    atexit(SDL_Quit);

    // Comprobamos que sea compatible el modo de video

    if(SDL_VideoModeOK(640, 480, 24, SDL_HWSURFACE|SDL_DOUBLEBUF) == 0) {

        cerr << "Modo no soportado: " << SDL_GetError() << endl;
        exit(1);

    }

    // Antes de establecer el modo de video
    // Establecemos el nombre de la ventana

    SDL_WM_SetCaption("Batrona Proyecto Libre", NULL);

    // Establecemos el modo

    SDL_Surface *pantalla;

    pantalla = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(pantalla == NULL) {

	cerr << "No se pudo establecer el modo de video: "
	     << SDL_GetError();

	exit(1);
    }

    // Inicializamos la librería SDL_Mixer

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,\
		     MIX_DEFAULT_CHANNELS, 4096) < 0) {

	cerr << "Subsistema de Audio no disponible" << endl;
	exit(1);
    }
   
}


int main(int argc, char *argv[])
{
    int running=1;
    int cur_stick=0;
    SDL_Joystick *stick=NULL;
    
    IniciarLibreria();
    // Cargamos un sonido

    Cuerpo a("a", "C:/Documents and Settings/Pa Todos/Escritorio/Batetron/Sonidos/cym_Rock_b.ogg",100,1);
    Cuerpo b("b", "C:/Documents and Settings/Pa Todos/Escritorio/Batetron/Sonidos/hhc_Rock_b.ogg",100,1);
    Cuerpo c("c", "C:/Documents and Settings/Pa Todos/Escritorio/Batetron/Sonidos/808_Tom_Low.ogg",100,1);
    Cuerpo d("d", "C:/Documents and Settings/Pa Todos/Escritorio/Batetron/Sonidos/808_Tom_Hi.ogg",100,1);
    Cuerpo e("e", "C:/Documents and Settings/Pa Todos/Escritorio/Batetron/Sonidos/808_Conga.ogg",100,1);
    Cuerpo f("f", "C:/Documents and Settings/Pa Todos/Escritorio/Batetron/Sonidos/808_Cowbell.ogg",100,1);
    Cuerpo g("g", "C:/Documents and Settings/Pa Todos/Escritorio/Batetron/Sonidos/808_Cymbal.ogg",100,1);
    Cuerpo h("h", "C:/Documents and Settings/Pa Todos/Escritorio/Batetron/Sonidos/808_Snare_1.ogg",100,1);
    Cuerpo i("i", "C:/Documents and Settings/Pa Todos/Escritorio/Batetron/Sonidos/808_Snare_2.ogg",100,1);
    Cuerpo j("j", "C:/Documents and Settings/Pa Todos/Escritorio/Batetron/Sonidos/808_Hat_Pedal.ogg",100,1);

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


    SDL_JoystickEventState(SDL_ENABLE);
    stick=OpenStick(cur_stick);

    while(running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        switch(event.type)
        {
            case SDL_QUIT:
            running=0;
            break;
            
            case SDL_KEYDOWN:
            if((event.key.keysym.sym>=SDLK_KP0)&&(event.key.keysym.sym<=SDLK_KP9))
                event.key.keysym.sym=SDLK_KP0;

            if((event.key.keysym.sym>='0')&&(event.key.keysym.sym<='9'))
            {
                int prevjoy=-1;
                int newjoy=event.key.keysym.sym-'0';
                if(stick!=NULL)
                {
                    prevjoy=cur_stick;
                    SDL_JoystickClose(stick);
                    stick=NULL;
                }

                stick=OpenStick(newjoy);
                if((stick==NULL)&&(prevjoy>=0))
                {
                    stick=OpenStick(prevjoy);
                    if(stick!=NULL) 
                       cur_stick=prevjoy;
                }
            }
            break;

            case SDL_JOYBUTTONUP:
            {
                if(event.jbutton.button<MAX_BUTTON)
                  fprintf(stderr,"STICK%1d] Boton que apreto %d \n",cur_stick,event.jbutton.button);

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

            }
            break;
        }
    }
    if(stick!=NULL)
        SDL_JoystickClose(stick);

}
