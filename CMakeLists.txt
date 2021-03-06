cmake_minimum_required(VERSION 3.15)
project(doom42 C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-fopenmp -Wall -Werror -Wextra -O -O0 -O1 -O2 -O3 -Os -g")
# SDL2
set(SDL2_INCLUDE_DIR ./include/SDL2/)
set(SDL2_LIBRARY ~/.brew/Cellar/sdl2/2.0.10/lib/)
# SDL2 Mixer
set(SDL_MIXER_INCLUDE_DIR ~/.brew/Cellar/sdl2_mixer/2.0.4/include/SDL2/)
set(SDL_MIXER_LIBRARY ~/.brew/Cellar/sdl2_mixer/2.0.4/lib/)
# SDL2 Image
set(SDL_IMAGE_INCLUDE_DIR ~/.brew/Cellar/sdl2_image/2.0.5/include/SDL2/)
set(SDL_IMAGE_LIBRARY ~/.brew/Cellar/sdl2_image/2.0.5/lib/)
# SDL2 TTF
set(SDL_TTF_INCLUDE_DIR ~/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2/)
set(SDL_TTF_LIBRARY ~/.brew/Cellar/sdl2_ttf/2.0.15/lib/)


set(LIBFT_INCLUDE_DIR ./libft/includes/)
set(LIBFT_LIBRARY ./libft/)

set(SOURCE ./src/)
set(INCLUDE ./includes/)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL_MIXER_INCLUDE_DIR}
        ${SDL_IMAGE_INCLUDE_DIR}
        ${SDL_TTF_INCLUDE_DIR}
        ${LIBFT_INCLUDE_DIR}
        ${SOURCE}
        ${INCLUDE})

link_directories(${SDL2_LIBRARY}
        ${SDL_MIXER_LIBRARY}
        ${SDL_IMAGE_LIBRARY}
        ${SDL_TTF_LIBRARY}
        ${LIBFT_LIBRARY}
        ${SOURCE})



file(GLOB all
        "${INCLUDE}*.h"
        "${SOURCE}*.c")


add_executable(doom42   ${all})

target_link_libraries(doom42 -O3 -lft -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm)