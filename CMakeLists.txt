cmake_minimum_required(VERSION 3.27)
project(Compiler C)

set(CMAKE_C_STANDARD 11)

add_executable(Compiler main.c
        include/hashmap.h
        src/hashmap.c
        include/tokentype.h
        src/linkedlist.c
        include/linkedlist.h
        src/token.c
        include/token.h
        include/lexer.h
        src/lexer.c
        src/tokentype.c)
