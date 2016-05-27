#!/bin/bash

## Would be nice to add this to a makefile instead
cwd=${PWD}

function build-release {
  cd "$cwd"
  mkdir -p build/release
  cd build/release
  cmake -DCMAKE_BUILD_TYPE=Release ../../ &&  make
  cd "$cwd"
}

function run-release {
  cd "$cwd"
  cd build/release
  ./blackjack
  cd "$cwd"
}

# Build Release and debug versions
function build-debug {
  cd "$cwd"
  mkdir -p build/debug
  cd build/debug
  cmake -DCMAKE_BUILD_TYPE=Debug ../../ && make
  cd ../
  cd "$cwd"
}

function run-debug {
  cd "$cwd"
  cd build/debug
  ./blackjack
  cd "$cwd"
}

function build {
  build-release
  build-debug
}


function run-valgrind {
  cd "$cwd"
  cd build/release
  valgrind --leak-check=full --show-reachable=yes ./blackjack
  cd "$cwd"
}

function clean {
  cd "$cwd"
  rm -vrf build
  rm -vrf ./*.gcno
  rm -vrf ./*.gcda
  rm -vrf ./*.c.gcov
  rm -vrf coverage.info
  rm -vrf out/
  rm -vrf blackjack
  cd "$cwd"

}

function run_shell_check {
  shellcheck ./*.sh > shellcheck.log

  if [ -s shellcheck.log ]; then
    # File contains something, so execution failed
    echo "shellcheck failed. See shellcheck.log"
    return 0
  fi

  return 1
}

run_shell_check
if (( $? == 0 )); then
  exit
fi

for var in "$@"
do
  $var
done

