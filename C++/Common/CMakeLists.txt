project(hermes_module)

set(SRC hermes_module.cpp)

set(HEADERS hermes_module.h)

add_library(${PROJECT_NAME} SHARED ${SRC} ${HEADERS})

find_package(HERMES REQUIRED)

target_link_libraries(${PROJECT_NAME} ${HERMES_COMMON_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${HERMES_LIBRARY})
