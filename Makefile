# Nom de l'exécutable
EXECUTABLE = pendu.out

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
	rm -f $(OBJECTS) $(EXECUTABLE)

# Clang-format
CLANG_FORMAT = clang-format
CLANG_FORMAT_STYLE = -style=file
CLANG_FORMAT_FILES = $(SOURCES) $(wildcard $(INCDIR)/*.h)

# Formatage du code avec clang-format
format:
	$(CLANG_FORMAT) -i $(CLANG_FORMAT_FILES)

