all:
	gcc -Wall -Werror -Isrc -Iinclude src/main.c src/prints.c include/prints.h include/typedefs.h include/definitions.h src/prng.c include/prng.h src/card_manip.c include/card_manip.h src/gameplay.c include/gameplay.h src/scoring.c include/scoring.h -o blackjack
