project(hermes_modulePoisson)

set(SRC definitions.cpp)

set(HEADERS definitions.h)

add_library(${PROJECT_NAME} SHARED ${SRC} ${HEADERS})

find_package(HERMES REQUIRED)

target_link_libraries(${PROJECT_NAME} ${HERMES_COMMON_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${HERMES_LIBRARY})

install(TARGETS ${PROJECT_NAME}
				RUNTIME DESTINATION ${TARGET_ROOT}/bin 
				LIBRARY DESTINATION ${TARGET_ROOT}/lib 
				ARCHIVE DESTINATION ${TARGET_ROOT}/lib)

file(GLOB INC "*.h")

install(FILES ${INC}           DESTINATION ${TARGET_ROOT}/include/hermes_modulePoisson)
