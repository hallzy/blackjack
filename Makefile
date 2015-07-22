all:
	gcc -Wall -Werror main.c prints.c prints.h typedefs.h definitions.h prng.c prng.h card_manip.c card_manip.h gameplay.c gameplay.h scoring.c scoring.h -o main
debug:
	gcc -g -Wall -Werror main.c -o main
