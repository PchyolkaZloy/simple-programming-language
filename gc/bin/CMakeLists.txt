add_executable(${PROJECT_NAME} example.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gc)
target_include_directories(${PROJECT_NAME} PUBLIC ../..)