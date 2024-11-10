cmake_minimum_required(VERSION 3.10)

if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)  # Prefer GLVND for OpenGL
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
include_directories(${PROJECT_SOURCE_DIR}/include)

# Find required packages
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

# SDL and other dependencies
message(STATUS "SDL2 Include Directories: ${SDL2_INCLUDE_DIRS}")
message(STATUS "SDL2: ${SDL2_LIBRARIES}")
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS} ${SDL2_MIXER_INCLUDE_DIRS})

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp" "include/*.h")

# Create executable
add_executable(${project_name} main.cpp ${SOURCES} ${HEADERS})

# Link libraries to the target
# target_link_libraries(${project_name} 
#     ${SDL2_LIBRARIES} 
#     ${SDL2_IMAGE_LIBRARIES}
#     ${SDL2_TTF_LIBRARIES}
#     ${SDL2_MIXER_LIBRARIES}
#     OpenGL::GL
# )
target_link_libraries(${project_name}
    ${SDL2_LIBRARIES}
    -lSDL2_image
    -lSDL2_ttf
    -lSDL2_mixer
    -lGL
    glm::glm
)
