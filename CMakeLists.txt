cmake_minimum_required(VERSION 2.8.12.2)
project(blackjack)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(blackjack ${SOURCES})
