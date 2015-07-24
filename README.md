Blackjack
=========

A game of blackjack written in C for the console.

```
make
```
builds the program as normal.

```
make lcov
```
builds the program so that lcov can be used (lcov is a coverage program that
produces an html page with the code coverage)

After running `make lcov` run the program as many times as you feel necessary
then:

```
make run-lcov
```
will generate the html webpage and open it in firefox.

The below can also be done, which will do the same thing as lcov but will not be
as visually stimulating. This still requires you to run the program as many
times as you feel necessary.
```
make gcov
make run-gcov
```

```
make clean
```
cleans the working directory.

TODO
----
Cleanup the makefile

