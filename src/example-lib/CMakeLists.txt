project(example-lib CXX)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/example-lib.cpp)

add_library(example-lib ${SOURCES})
set_target_properties(example-lib PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(example-lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

if(UTEST)
    add_subdirectory("test")
endif()
