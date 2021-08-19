set(CMAKE_CXX_STANDARD 20) 

find_package( OpenCV REQUIRED )

file(GLOB_RECURSE Foo_SOURCES "src/*.cpp")
file(GLOB_RECURSE Foo_HEADERS "src/*.h")

set (Foo_INCLUDE_DIRS "src/")
foreach (_headerFile ${Foo_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Foo_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Foo_INCLUDE_DIRS)

include_directories( ${OpenCV_INCLUDE_DIRS} src)

add_executable(../tests/bin/bin.app src/main.cpp ${Foo_SOURCES})

#target_link_libraries(bin.app -static stdc++fs)
target_link_libraries(../tests/bin/bin.app  -pthread stdc++fs ${OpenCV_LIBS} )