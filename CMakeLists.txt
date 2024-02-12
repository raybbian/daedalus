cmake_minimum_required(VERSION 3.26)
project(daedalus)

FIND_PACKAGE(Boost REQUIRED)
FIND_PACKAGE(PNG REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR} ${PNG_INCLUDE_DIR} include)

set(CMAKE_CXX_STANDARD 20)

add_executable(daedalus
        main.cpp
        include/traversal/image_utils.cpp
)

TARGET_LINK_LIBRARIES(daedalus LINK_PUBLIC ${Boost_LIBRARIES} ${PNG_LIBRARY})