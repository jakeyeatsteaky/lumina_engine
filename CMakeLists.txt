cmake_minimum_required(VERSION 3.10)
if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)  # Prefer GLVND
endif()

set(project_name lumina)
project(${project_name} VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "Project source dir: ${PROJECT_SOURCE_DIR}")
message(STATUS "Building project: ${PROJECT_NAME} ___ ${project_name}")

if(MSVC)
    add_compile_options(/W4 /WX /Zi)
else()
    add_compile_options(-fdiagnostics-color=always -Wall -Wextra -Werror -std=c++17 -pedantic -g)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# Including directories

message(STATUS "Local Include Directories: ${PROJECT_SOURCE_DIR}/include")
message(STATUS "SDL2 Include Directories: ${SDL2_INCLUDE_DIRS}")
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${SDL2_INCLUDE_DIRS} )
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
#find_package(Vulkan REQUIRED)


file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/*.h")

add_executable(lumina main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} OpenGL::GL)
