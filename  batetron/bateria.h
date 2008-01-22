#ifndef BATERIA_H
#define BATERIA_H
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <vector>
using namespace std;

class Bateria
{   private:
        vector<cuerpo*> Cuerpos;
        int Cant_Cuerpos;
	public:
		Bateria();
		~Bateria();
		vector<cuerpo> GetCuerpos();
		void AniadirCuerpo(cuerpo*);
		void PlayCuerpo(int);
};

#endif // BATERIA_H
