cmake_minimum_required(VERSION 3.22)
project(P09_File_Operations C)

set(CMAKE_C_STANDARD 11)

include_directories(personen-verwaltung-persistent/src)

add_executable(P09_File_Operations
        personen-verwaltung-persistent/src/file_io.c
        personen-verwaltung-persistent/src/file_io.h
        personen-verwaltung-persistent/src/list.c
        personen-verwaltung-persistent/src/list.h
        personen-verwaltung-persistent/src/main.c
        personen-verwaltung-persistent/src/person.c
        personen-verwaltung-persistent/src/person.h
        personen-verwaltung-persistent/tests/tests.c)
