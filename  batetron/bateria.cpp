#include "bateria.h" 

Bateria::Bateria()
{
    Cant_Cuerpos = 0;
}
Bateria::~Bateria()
{}

vector<cuerpo> Bateria::GetCuerpos(){
        return Cuerpos;
}
void Bateria::AniadirCuerpo(cuerpo* nuevocuerpo){
    Cuerpos.push_back(nuevocuerpo);    
}
void Bateria::PlayCuerpo(int Numero){
    Mix_Music *sonido;
    sonido = Cuerpos[Numero]->GetSonido();
    Mix_PlayMusic(sonido, -1);
}
