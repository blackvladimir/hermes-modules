project(01-Poisson)

set(SRC definitions.cpp)

set(HEADERS definitions.h)

add_library(${PROJECT_NAME} SHARED ${SRC} ${HEADERS})

find_package(HERMES REQUIRED)

target_link_libraries(${PROJECT_NAME} ${HERMES_COMMON_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${HERMES_LIBRARY})
