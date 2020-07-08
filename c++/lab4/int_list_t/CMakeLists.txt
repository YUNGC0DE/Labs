project(int_list_t)

set(SOURCES int_list_t.cpp)
set(HEADERS int_list_t.h)

include_directories(../)

add_library(int_list_t ${SOURCES} ${HEADERS})