# le nom de l'exécutable :
TARGET = jeuPendu.out
MAIN = jeuPendu
MODULE = Pendu

# Obtenez la liste des fichiers source .cpp
SRC := $(wildcard *.cpp)
$(info LISTE_SRC : $(SRC))

# Obtenez la liste des fichiers header .h
HEADERS := $(wildcard *.h)
$(info LISTE_HEADERS : $(HEADERS))

# Les variables génériques
CXX = g++
LD = g++ -o # la commande pour l'édition de liens
CFLAGS = -Wall
LDFLAGS = # les options pour l'édition de liens, exemple : -lxxx -Lxxx

# la cible par défaut est la cible de la première règle trouvée par make (ici all)
all: $(TARGET)

$(TARGET): $(SRC:.cpp=.o)
    $(LD) $@ $(LDFLAGS) $^

%.o: %.cpp
    $(CXX) $(CFLAGS) -c $< -o $@

clean:
    rm -f *.o

cleanall: clean
    rm -f $(TARGET)

