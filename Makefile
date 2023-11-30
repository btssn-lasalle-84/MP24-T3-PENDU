test-pendu.out: jeuPendu.o joueur.o
	g++ -o test-pendu.out jeuPendu.o joueur.o

jeuPendu.o: jeuPendu.cpp 
	g++ -c jeuPendu.cpp

joueur.o: joueur.cpp
	g++ -c joueur.cpp

