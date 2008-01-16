#ifndef CUERPO_H
#define CUERPO_H
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

class Cuerpo
{   private:
        Mix_Music *Sonido;
        char * Nombre;
        int Duracion;
   	public:
		Cuerpo();
		~Cuerpo();
		void SetSonido(Mix_Music*);
		void SetNombre(char *)
		Mix_Music * GetSonido();
        char * GetNombre();
};

#endif // CUERPO_H
