
#include "Cuerpo.h" // class's header file

// class constructor
Cuerpo::Cuerpo(char *nombre,char *direccion, int volumen, int canal)
{
    this->nombre = nombre;
    this->sonido = Mix_LoadWAV(direccion);
    this->volumen = volumen;
    this->canal = canal;
}

void Cuerpo::setVolumen(int volumen)
{
    this->volumen = volumen;
    Mix_VolumeChunk(sonido, volumen);
}

int Cuerpo::getVolumen()
{
    return this->volumen;
}

void Cuerpo::Reproducir()
{
	Mix_PlayChannel(this->canal, sonido,0);
	printf("%s",this->nombre);
	printf("\n");
}
// class destructor
Cuerpo::~Cuerpo()
{
    Mix_FreeChunk(sonido);
}
