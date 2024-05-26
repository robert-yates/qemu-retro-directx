cmake_minimum_required(VERSION 3.15)
project(wined3d C)

add_library(${PROJECT_NAME} SHARED  src/adapter_gl.c
                                    src/arb_program_shader.c
                                    src/ati_fragment_shader.c
                                    src/buffer.c
                                    src/context.c
                                    src/context_gl.c
                                    src/cs.c
                                    src/device.c
                                    src/directx.c
                                    src/glsl_shader.c
                                    src/gl_compat.c
                                    src/nvidia_texture_shader.c
                                    src/palette.c
                                    src/query.c
                                    src/resource.c
                                    src/sampler.c
                                    src/shader.c
                                    src/shader_sm1.c
                                    src/shader_sm4.c
                                    src/shader_spirv.c
                                    src/state.c
                                    src/stateblock.c
                                    src/surface.c
                                    src/swapchain.c
                                    src/texture.c
                                    src/utils.c
                                    src/vertexdeclaration.c
                                    src/view.c
                                    src/wined3d_main.c

                                    src/wined3d.def
)

if (MSVC)
    set_property(TARGET ${PROJECT_NAME} PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    set_property(TARGET ${PROJECT_NAME} PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Releae>:Release>")
    target_link_options(${PROJECT_NAME} PRIVATE /BASE:0x6AD80000)
    target_link_options(${PROJECT_NAME} PRIVATE /DYNAMICBASE:NO)
endif ()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../general)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../general/wine)
target_link_libraries(${PROJECT_NAME} PRIVATE opengl32 user32 gdi32 advapi32)
