#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

SDL_Joystick *OpenStick(int index); /* Open a joystick */


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

SDL_Joystick *OpenStick(int index)
{
  SDL_Joystick *stick=SDL_JoystickOpen(index);

  if(stick==NULL)
    fprintf(stderr,"Couldn't open joystick %d\n",index);
  else
  {
    fprintf(stderr,"Opened Joystick %d\n",index);
    fprintf(stderr,"Name: %s\n", SDL_JoystickName(index));
    fprintf(stderr,"Number of Axes: %d\n", SDL_JoystickNumAxes(stick));
    fprintf(stderr,"Number of Buttons: %d\n", SDL_JoystickNumButtons(stick));
    fprintf(stderr,"Number of Balls: %d\n", SDL_JoystickNumBalls(stick));
  }

  return(stick);
}

int main(int argc, char *argv[])
{
  int running=1;
  int cur_stick=0;
  SDL_Joystick *stick=NULL;
  SDL_Surface *screen=NULL;
  Mix_Music *cancion;

  if(SDL_Init(SDL_INIT_JOYSTICK|SDL_INIT_VIDEO|SDL_INIT_AUDIO)<0)
  {
    fprintf(stderr,"Can't init SDL!\n");
    return(-1);
  }

  screen=SDL_SetVideoMode(293,196,24,SDL_ANYFORMAT);
  if(screen==NULL)
  {
    fprintf(stderr,"Couldn't set 320*240: %s\n",SDL_GetError());
    SDL_Quit();
    return(1);
  }
  
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
  {
      printf("Error en Mix_OpenAudio: %s\n", Mix_GetError());
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
        {
          event.key.keysym.sym=SDLK_KP0;
        }
      
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
            if(stick!=NULL) cur_stick=prevjoy;
          }
        }
        break;

      case SDL_JOYBUTTONUP:
      {
        if(event.jbutton.button<MAX_BUTTON)
            fprintf(stderr,"STICK%1d] Boton que apreto %d \n",cur_stick,event.jbutton.button);
        if(event.jbutton.button == 1)
        {
              cancion = Mix_LoadMUS("H:\\Documents and Settings\\Administrador\\Escritorio\\Bateria Electronica\\Codigo\\Sonidos\\808_Clap.ogg");
              if (!cancion)
                 printf("Error en Mix_LoadMUS: %s\n", Mix_GetError());
              if (cancion)
              {
                 if (Mix_PlayMusic(cancion, -1) == -1)
                    printf("Error en Mix_PlayMusic: %s\n", Mix_GetError());
              }
              SDL_Delay(100);
              if (cancion)
              {
                  Mix_HaltMusic();
                  Mix_FreeMusic(cancion);
              }
        }
        if(event.jbutton.button == 2)
        {
              cancion = Mix_LoadMUS("H:\\Documents and Settings\\Administrador\\Escritorio\\Bateria Electronica\\Codigo\\Sonidos\\tom_Rock_hi.ogg");
              if (!cancion)
                 printf("Error en Mix_LoadMUS: %s\n", Mix_GetError());
              if (cancion)
              {
                 if (Mix_PlayMusic(cancion, -1) == -1)
                    printf("Error en Mix_PlayMusic: %s\n", Mix_GetError());
              }
              SDL_Delay(150);
              if (cancion)
              {
                  Mix_HaltMusic();
                  Mix_FreeMusic(cancion);
              }
        }
        if(event.jbutton.button == 3)
        {
              cancion = Mix_LoadMUS("H:\\Documents and Settings\\Administrador\\Escritorio\\Bateria Electronica\\Codigo\\Sonidos\\tom_Rock_mid.ogg");
              if (!cancion)
                 printf("Error en Mix_LoadMUS: %s\n", Mix_GetError());
              if (cancion)
              {
                 if (Mix_PlayMusic(cancion, -1) == -1)
                    printf("Error en Mix_PlayMusic: %s\n", Mix_GetError());
              }
              SDL_Delay(150);
              if (cancion)
              {
                  Mix_HaltMusic();
                  Mix_FreeMusic(cancion);
              }
        }
        if(event.jbutton.button == 0)
        {
              cancion = Mix_LoadMUS("H:\\Documents and Settings\\Administrador\\Escritorio\\Bateria Electronica\\Codigo\\Sonidos\\cym_Jazz.ogg");
              if (!cancion)
                 printf("Error en Mix_LoadMUS: %s\n", Mix_GetError());
              if (cancion)
              {
                 if (Mix_PlayMusic(cancion, -1) == -1)
                    printf("Error en Mix_PlayMusic: %s\n", Mix_GetError());
              }
              SDL_Delay(150);
              if (cancion)
              {
                  Mix_HaltMusic();
                  Mix_FreeMusic(cancion);
              }
        }
        if(event.jbutton.button == 4)
        {
              cancion = Mix_LoadMUS("H:\\Documents and Settings\\Administrador\\Escritorio\\Bateria Electronica\\Codigo\\Sonidos\\cra_Rock_a.ogg");
              if (!cancion)
                 printf("Error en Mix_LoadMUS: %s\n", Mix_GetError());
              if (cancion)
              {
                 if (Mix_PlayMusic(cancion, -1) == -1)
                    printf("Error en Mix_PlayMusic: %s\n", Mix_GetError());
              }
              SDL_Delay(150);
              if (cancion)
              {
                  Mix_HaltMusic();
                  Mix_FreeMusic(cancion);
              }
        }
        if(event.jbutton.button == 5)
        {
              cancion = Mix_LoadMUS("H:\\Documents and Settings\\Administrador\\Escritorio\\Bateria Electronica\\Codigo\\Sonidos\\clap_Dry_c.ogg");
              if (!cancion)
                 printf("Error en Mix_LoadMUS: %s\n", Mix_GetError());
              if (cancion)
              {
                 if (Mix_PlayMusic(cancion, -1) == -1)
                    printf("Error en Mix_PlayMusic: %s\n", Mix_GetError());
              }
              SDL_Delay(150);
              if (cancion)
              {
                  Mix_HaltMusic();
                  Mix_FreeMusic(cancion);
              }
        }

        if(event.jbutton.button == 6)
        {
              cancion = Mix_LoadMUS("H:\\Documents and Settings\\Administrador\\Escritorio\\Bateria Electronica\\Codigo\\Sonidos\\808_Snare_2.ogg");
              if (!cancion)
                 printf("Error en Mix_LoadMUS: %s\n", Mix_GetError());
              if (cancion)
              {
                 if (Mix_PlayMusic(cancion, -1) == -1)
                    printf("Error en Mix_PlayMusic: %s\n", Mix_GetError());
              }
              SDL_Delay(150);
              if (cancion)
              {
                  Mix_HaltMusic();
                  Mix_FreeMusic(cancion);
              }
        }

        if(event.jbutton.button == 7)
        {
              cancion = Mix_LoadMUS("H:\\Documents and Settings\\Administrador\\Escritorio\\Bateria Electronica\\Codigo\\Sonidos\\808_Shaker.ogg");
              if (!cancion)
                 printf("Error en Mix_LoadMUS: %s\n", Mix_GetError());
              if (cancion)
              {
                 if (Mix_PlayMusic(cancion, -1) == -1)
                    printf("Error en Mix_PlayMusic: %s\n", Mix_GetError());
              }
              SDL_Delay(150);
              if (cancion)
              {
                  Mix_HaltMusic();
                  Mix_FreeMusic(cancion);
              }
        }

        if(event.jbutton.button == 8)
        {
              cancion = Mix_LoadMUS("H:\\Documents and Settings\\Administrador\\Escritorio\\Bateria Electronica\\Codigo\\Sonidos\\808_Kick_Short.ogg");
              if (!cancion)
                 printf("Error en Mix_LoadMUS: %s\n", Mix_GetError());
              if (cancion)
              {
                 if (Mix_PlayMusic(cancion, -1) == -1)
                    printf("Error en Mix_PlayMusic: %s\n", Mix_GetError());
              }
              SDL_Delay(150);
              if (cancion)
              {
                  Mix_HaltMusic();
                  Mix_FreeMusic(cancion);
              }
        }


        if(event.jbutton.button == 9)
        {
              cancion = Mix_LoadMUS("H:\\Documents and Settings\\Administrador\\Escritorio\\Bateria Electronica\\Codigo\\Sonidos\\808_Hat_Pedal.ogg");
              if (!cancion)
                 printf("Error en Mix_LoadMUS: %s\n", Mix_GetError());
              if (cancion)
              {
                 if (Mix_PlayMusic(cancion, -1) == -1)
                    printf("Error en Mix_PlayMusic: %s\n", Mix_GetError());
              }
              SDL_Delay(150);
              if (cancion)
              {
                  Mix_HaltMusic();
                  Mix_FreeMusic(cancion);
              }
        }

      }
      break;
    SDL_Delay(1);
   }
  }
  if(stick!=NULL)
    SDL_JoystickClose(stick);

  Mix_CloseAudio();
  SDL_Quit();

  return(0);
}


