cmake_minimum_required(VERSION 4.4)
project(c_study)

set(CMAKE_CXX_STANDARD 20)

# 루트 main.cpp
add_executable(c_study main.cpp)

# 하위 폴더의 .cpp 하나 = 실행 파일 하나 (각 .cpp에 main()이 하나씩 있어야 함)
#   - 타깃 이름은 파일 이름 (예: operatorOverloading/Complex.cpp -> Complex)
#   - 다른 폴더에 같은 이름이 이미 있으면 "폴더_파일" (예: inheritance_Complex)
#   - 같은 이름의 .h가 옆에 있으면 함께 포함 (Complex.cpp + Complex.h)
#   - 새 .cpp를 추가하면 CLion에서 File -> Reload CMake Project 한 번 필요
file(GLOB _subdirs LIST_DIRECTORIES true RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)
foreach(dir IN LISTS _subdirs)
    if(NOT IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${dir} OR dir MATCHES "^(cmake-build-|\\.)")
        continue()
    endif()

    file(GLOB_RECURSE _cpps CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/${dir}/*.cpp)
    foreach(cpp IN LISTS _cpps)
        get_filename_component(_name ${cpp} NAME_WE)
        get_filename_component(_path ${cpp} DIRECTORY)

        set(_target ${_name})
        if(TARGET ${_target})
            set(_target ${dir}_${_name})
        endif()

        set(_srcs ${cpp})
        if(EXISTS ${_path}/${_name}.h)
            list(APPEND _srcs ${_path}/${_name}.h)
        endif()

        add_executable(${_target} ${_srcs})
    endforeach()
endforeach()
