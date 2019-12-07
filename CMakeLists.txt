cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(stream_json_parser)

add_subdirectory(include)
add_executable(stream_json_parser stream_json_parser.cpp)
target_link_libraries(stream_json_parser PUBLIC JsonCons)

target_include_directories(stream_json_parser
       	PUBLIC 
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}/include"
	)

configure_file(data.json data.json COPYONLY)

