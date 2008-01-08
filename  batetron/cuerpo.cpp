#include "cuerpo.h"

Cuerpo::Cuerpo()
{       Sonido = NULL;
        Nombre = NULL;
        Duracion = 0;    
}
Cuerpo::~Cuerpo()
{
}

void Cuerpo::SetSonido(Mix_Music *Sonido){
    this->Sonido = Sonido;
    Duracion = Sonido->//Obtener duracion
}

void Cuerpo::SetNombre(char* Nombre){
    this->Nombre = Nombre;
}

Mix_Music * Cuerpo::GetSonido(){
    return Sonido;
}

char * Cuerpo::GetNombre(){
    return Nombre;    
}


