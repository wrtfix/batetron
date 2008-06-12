batetron: Main.o Cuerpo.o Bateria.o
	echo "Compilando batetron...\n"
	g++ -lSDL -lSDL_mixer -lSDL_image Main.o Cuerpo.o Bateria.o -o batetron
	
Cuerpo.o: ./src/Cuerpo.cpp ./src/Cuerpo.h
	echo "Compilando Cuerpo...\n"
	g++ -c ./src/Cuerpo.cpp -o Cuerpo.o
	
Bateria.o: ./src/Bateria.cpp ./src/Bateria.h ./src/Cuerpo.h
	echo "Compilando Bateria...\n"
	g++ -c ./src/Bateria.cpp -o Bateria.o

Main.o: ./src/Main.cpp ./src/Bateria.h ./src/Cuerpo.h
	g++ -c -o Main.o ./src/Main.cpp 
