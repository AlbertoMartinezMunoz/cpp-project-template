project(application CXX)

add_subdirectory("${PROJECT_SOURCE_DIR}/example-lib")

add_executable(application application.cpp)
target_link_libraries(application example-lib)