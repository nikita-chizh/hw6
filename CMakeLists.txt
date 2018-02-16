cmake_minimum_required(VERSION 3.9)
project(matrix)

set(CMAKE_CXX_STANDARD 14)
include (CTest)
add_library(my_matrix Matrix.cpp Matrix.h Proxy_Node.cpp Proxy_Node.h)

add_executable(matrix main.cpp)
add_executable(TEST test.cpp)
add_test(memtest matrix)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
set(CMAKE_CXX_STANDARD 14)

set(boost_inc /usr/local/Cellar/boost/1.65.1/include)
set(boost_lib /usr/local/Cellar/boost/1.65.1/lib)
INCLUDE_DIRECTORIES(${boost_inc})
LINK_DIRECTORIES(${boost_lib})

set_target_properties(matrix TEST PROPERTIES
        CXX_STANDART 14
        CXX_STANDART_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )

set_target_properties(TEST PROPERTIES
        COMPILE_DEFENITONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

target_link_libraries(TEST my_matrix
        ${Boost_LIBRARIES}
        )

target_link_libraries(matrix my_matrix
        )

install(TARGETS matrix RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set( CPACK_PACKAGE_FILE_NAME matrix)
set(CPACK_PACKAGE_CONTACT nikita1993chizh@gmail.com)
include(CPack)
enable_testing()
