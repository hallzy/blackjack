all:
	gcc -Wall -Werror -Isrc -Iinclude src/main.c src/prints.c include/prints.h include/typedefs.h include/definitions.h src/prng.c include/prng.h src/card_manip.c include/card_manip.h src/gameplay.c include/gameplay.h src/scoring.c include/scoring.h -o blackjack
lcov:
	gcc -coverage -Wall -Werror -Isrc -Iinclude src/main.c src/prints.c include/prints.h include/typedefs.h include/definitions.h src/prng.c include/prng.h src/card_manip.c include/card_manip.h src/gameplay.c include/gameplay.h src/scoring.c include/scoring.h -o blackjack
run-lcov:
	lcov --capture --directory ./ --output-file coverage.info
	genhtml coverage.info --output-directory out
	firefox out/index.html
gcov:
	gcc -fprofile-arcs -ftest-coverage -Wall -Werror -Isrc -Iinclude src/main.c src/prints.c include/prints.h include/typedefs.h include/definitions.h src/prng.c include/prng.h src/card_manip.c include/card_manip.h src/gameplay.c include/gameplay.h src/scoring.c include/scoring.h -o blackjack
run-gcov:
	gcov -bc main.c
	gcov -bc prints.c
	gcov -bc card_manip.c
	gcov -bc gameplay.c
	gcov -bc scoring.c
clean:
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.c.gcov
	rm -rf coverage.info
	rm -rf out/
	rm -rf blackjack
