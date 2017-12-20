cmake_minimum_required(VERSION 3.9)

set(CMAKE_C_STANDARD 99)

project(RT_SDL)

include_directories(includes)

set(SOURCE_FILES src/main.c
        fsdl/fsdl.h
        fsdl/fsdl_button.c
        fsdl/fsdl_button_array.c
        fsdl/fsdl_error_management.c
        fsdl/fsdl_file_read.c
        fsdl/fsdl_loop_prm.c
        fsdl/fsdl_panel.c
        fsdl/fsdl_project.c
        fsdl/fsdl_rect_convert.c
        fsdl/fsdl_rect_set.c
        fsdl/fsdl_sprite_buffer.c
        fsdl/fsdl_sprite_double_create.c
        fsdl/fsdl_sprite_draw.c
        fsdl/fsdl_sprite_int_create.c
        fsdl/fsdl_surface.c
        fsdl/fsdl_text_output.c
        fsdl/fsdl_texture.c
        fsdl/fsdl_timer.c
        fsdl/fsdl_window_create.c
        fsdl/fsdl_window_manage_prm.c
        fsdl/ft_errors.c
        fsdl/ft_errors.h
        src/additional_ft.c
        src/ft_add_light_spot.c
        src/ft_blur.c
        src/ft_cone.c
        src/ft_cylinder.c
        src/ft_error.c
        src/ft_exit.c
        src/ft_init_all.c
        src/ft_init_scene_part1.c
        src/ft_init_scene_part2.c
        src/ft_key_hook.c
        src/ft_light.c
        src/ft_mous_hook.c
        src/ft_phong.c
        src/ft_plane.c
        src/ft_random.c
        src/ft_render.c
        src/ft_sphere.c
        src/ft_vector_math_part1.c
        src/ft_vector_math_part2.c
        src/ft_vector_math_part3.c
        includes/fsdl.h
        includes/rt.h)
add_executable(RT_SDL ${SOURCE_FILES})

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    message("Mac OS X!!!")
    #SDL_HEADER
    set(SDL2_HEADRS /nfs/2016/a/akrotov/Library/Frameworks/SDL2.framework)
    set(SDL2_TTF_HEADRS /nfs/2016/a/akrotov/Library/Frameworks/SDL2_ttf.framework)
    set(SDL_IMAGE_HEADRS //nfs/2016/a/akrotov/Library/Frameworks/SDL2_image.framework)
    #FLAGS
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    #INCLUDES
    include_directories(${SDL2_HEADRS}, ${SDL2_TTF_HEADRS} ${SDL2_IMAGE_HEADRS})
    #SDL_LIBRARY
    find_library(SDL2_LIBRARY SDL2)
    find_library(SDL2_TTF_LIBRARY SDL2_ttf)
    find_library(SDL2_IMAGE_LIBRARY SDL2_image)
    target_link_libraries(RT_SDL ${SDL2_LIBRARY})
    target_link_libraries(RT_SDL ${SDL2_TTF_LIBRARY})
    target_link_libraries(RT_SDL ${SDL2_IMAGE_LIBRARY})
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message("Linux!!!")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lm")
endif()
