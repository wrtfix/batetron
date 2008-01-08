#ifndef CUERPO_H
#define CUERPO_H

/*
 * No description
 */
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
