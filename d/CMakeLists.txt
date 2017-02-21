cmake_minimum_required(VERSION 2.8)

project(d)
add_library(${PROJECT_NAME} SHARED main.cpp disasm-lib/cpu.c disasm-lib/disasm.c disasm-lib/disasm_x86.c disasm-lib/misc.c mhook-lib/mhook.cpp)
target_link_libraries(${PROJECT_NAME} ddraw winmm)
