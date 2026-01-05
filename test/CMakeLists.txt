# 源文件
file(GLOB_RECURSE HDRS "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
set(SRCS "${CMAKE_CURRENT_SOURCE_DIR}/x.cpp")

add_executable(vector_test vector_test.cpp)
add_executable(deque_test deque_test.cpp ${HDRS} ${SRCS})
add_executable(list_test list_test.cpp ${HDRS} ${SRCS})
