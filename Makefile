# Nom de l'exécutable
EXEC = pendu

# Compileur
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall

# Fichiers source
SOURCES = dictionnaire.cpp \
          interfaceJoueurs.cpp \
          jeuPendu.cpp \
          joueur.cpp \
          main.cpp

# Fichuiers objets
OBJECTS = $(SOURCES:.cpp=.o)

# Executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Compilation des fichiers source
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyeur
clean:
	rm -f $(OBJS) $(EXEC)