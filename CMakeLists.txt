cmake_minimum_required(VERSION 3.25)
project(CG_RaytracingModel)

set(CMAKE_CXX_STANDARD 23)
set(SDL_INCLUDE_DIR C:/SDL/include)
set(SDL2_LIB_DIR C:/SDL/lib/x64)
set(SDL2_IMAGE_DIR C:/Users/mague/CLionProjects/CG_Raycasting/SDL2_image-2.6.3/include)
set(SDL2_IMAGE_LIB C:/Users/mague/CLionProjects/CG_Raycasting/SDL2_image-2.6.3/lib/x64/SDL2_image.dll)

include_directories("C:/MinGW/include")
include_directories(${SDL_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_DIR})
link_directories(${SDL2_LIB_DIR})
link_directories(${SDL2_IMAGE_LIB})

add_executable(CG_RaytracingModel main.cpp camera.h camera.cpp color.h intersect.h light.h material.h object.h print.h sphere.h sphere.cpp cube.h cube.cpp)

target_link_libraries(CG_RaytracingModel SDL2main SDL2 ${SDL2_IMAGE_LIB})
