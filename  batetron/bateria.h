#ifndef BATERIA_H
#define BATERIA_H

/*
 * No description
 */
class Bateria
{   private:
        list<cuerpo*> Cuerpos;
        int Cant_Cuerpos;
	public:
		Bateria();
		~Bateria();
		list<cuerpo> GetCuerpos();
		void AniadirCuerpo(cuerpo*);
		void PlayCuerpo(int);
};

#endif // BATERIA_H
