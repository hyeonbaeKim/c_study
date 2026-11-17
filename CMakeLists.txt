cmake_minimum_required(VERSION 4.4)
project(c_study)

set(CMAKE_CXX_STANDARD 20)

# 루트 main.cpp
add_executable(c_study main.cpp)

# main.cpp가 있는 하위 폴더마다 "폴더이름"으로 실행 파일을 자동 생성
file(GLOB _subdirs LIST_DIRECTORIES true RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)
foreach(dir IN LISTS _subdirs)
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${dir}
            AND EXISTS ${CMAKE_SOURCE_DIR}/${dir}/main.cpp
            AND NOT dir MATCHES "^(cmake-build-|\\.)")
        file(GLOB_RECURSE _srcs CONFIGURE_DEPENDS
                ${CMAKE_SOURCE_DIR}/${dir}/*.cpp
                ${CMAKE_SOURCE_DIR}/${dir}/*.h)
        add_executable(${dir} ${_srcs})
    endif()
endforeach()
