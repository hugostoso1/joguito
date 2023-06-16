CFLAGS=-Llib -Iinclude -no-pie 
LIBS=-l:libraylib.a -pthread -ldl -lm -lxcb -lX11

# Compilar laboratório
build: main.c ./barrier/barrier.o ./bullet/bullet.o ./enemy/enemy.o ./game/game.o ./hero/hero.o ./maps/maps.o
	gcc main.c ./barrier/barrier.o ./bullet/bullet.o ./maps/maps.o ./game/game.o ./hero/hero.o ./enemy/enemy.o -o jogo -lraylib 


# Quando quiser adicionar um módulo novo, coloque
# sempre $(CFLAGS) e $(LIBS) no final!

jogo: main.c
	gcc main.c -o jogo $(CFLAGS) $(LIBS)

# O comando `make run` vai compilar e rodar seu código!
# Não se esqueca de colocar seu módulo depois de `jogo`
run: jogo
	./jogo

# Se quiser recompilar seu jogo do 0, o comando `make clean` vai
# limpar a pasta de artefatos de compilação, etc.
# Não se esqueça de adicionar seu módulo depois de `jogo`
clean:
	rm jogo

.PHONY: run clean

barrier.o: ./barrier/barrier.c ../game/game.h
	gcc ./barrier/barrier.c -o barrier

bullet.o: ./bullet/bullet.c ../game/game.h
	gcc ./bullet/bullet.c -o bullet

enemy.o: ./enemy/enemy.c ../game/game.h
	gcc ./enemy/enemy.c -o enemy

game.o: ./game/game.c ./game/game.h
	gcc ./game/game.c -o game

hero.o: ./hero/hero.c ../game/game.h
	gcc ./hero/hero.c -o hero

maps.o: ./maps/maps.c ../game/game.h
	gcc ./maps/maps.c -o maps