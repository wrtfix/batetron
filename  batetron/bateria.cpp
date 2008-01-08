#include "bateria.h" 

Bateria::Bateria()
{
    Cant_Cuerpos = 0;
}
Bateria::~Bateria()
{}

list<cuerpo> Bateria::GetCuerpos(){
        return Cuerpos;
}
void Bateria::AniadirCuerpo(cuerpo* nuevocuerpo){
    Cuerpos.push_back(nuevocuerpo);    
}
void PlayCuerpo(int Numero){
    //ejecutar sonido Numero
}
