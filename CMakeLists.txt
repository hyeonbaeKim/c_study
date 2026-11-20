cmake_minimum_required(VERSION 4.4)
project(c_study)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-finput-charset=UTF-8)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-fexec-charset=UTF-8)
endif()

if(WIN32)
    set(_utf8_console_source "${CMAKE_CURRENT_BINARY_DIR}/utf8_console.cpp")
    file(WRITE "${_utf8_console_source}"
        "#include <windows.h>\n"
        "namespace {\n"
        "struct Utf8Console {\n"
        "    Utf8Console() { SetConsoleOutputCP(CP_UTF8); }\n"
        "};\n"
        "Utf8Console utf8Console;\n"
        "}\n")
endif()

file(GLOB_RECURSE _cpps CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(cpp IN LISTS _cpps)
    file(RELATIVE_PATH _relative_path "${CMAKE_CURRENT_SOURCE_DIR}" "${cpp}")
    if(_relative_path MATCHES "(^|/)(cmake-build-[^/]*|\\.[^/]+)(/|$)")
        continue()
    endif()

    file(READ "${cpp}" _contents)
    if(NOT _contents MATCHES "(^|[\n\r])[ \t]*(int|auto)[ \t]+main[ \t]*\\(")
        continue()
    endif()

    string(REGEX REPLACE "\\.cpp$" "" _target "${_relative_path}")
    string(REGEX REPLACE "[^A-Za-z0-9_]" "_" _target "${_target}")
    if(_relative_path STREQUAL "access/acesss1/Child.cpp")
        set(_target "access_Child_Child")
    endif()

    set(_sources "${cpp}")
    get_filename_component(_source_dir "${cpp}" DIRECTORY)
    get_filename_component(_source_name "${cpp}" NAME_WE)
    if(EXISTS "${_source_dir}/${_source_name}.h")
        list(APPEND _sources "${_source_dir}/${_source_name}.h")
    endif()

    if(_relative_path STREQUAL "access/acesss1/Child.cpp")
        list(APPEND _sources "access/acesss1/Parent.cpp")
    endif()

    if(_relative_path STREQUAL "poly/casting/CastingMain0.cpp")
        list(APPEND _sources "poly/casting/Parent.cpp" "poly/casting/Child.cpp")
    endif()

    if(_relative_path MATCHES "^poly/casting/CastingMain(1|2|4|4_1)\\.cpp$")
        list(APPEND _sources "poly/casting/Child.cpp")
    endif()

    if(_relative_path STREQUAL "poly/casting/CastingMain3.cpp")
        list(APPEND _sources "poly/casting/Parent.cpp" "poly/casting/Child.cpp")
    endif()

    if(_relative_path MATCHES "^poly/ex1/AnimalSoundMain[12]\\.cpp$")
        list(APPEND _sources
                "poly/ex1/Cat.cpp"
                "poly/ex1/Dog.cpp"
                "poly/ex1/Cow.cpp")
    endif()

    add_executable("${_target}" ${_sources})
    if(WIN32)
        target_sources("${_target}" PRIVATE "${_utf8_console_source}")
    endif()
endforeach()
