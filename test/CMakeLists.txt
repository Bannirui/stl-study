# 源文件
file(GLOB_RECURSE HDRS "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
set(SRCS "${CMAKE_CURRENT_SOURCE_DIR}/x.cpp")

# 动态数组
add_executable(vector_test vector_test.cpp)

# 双端队列
add_executable(deque_test deque_test.cpp ${HDRS} ${SRCS})

# 双链表
add_executable(list_test list_test.cpp ${HDRS} ${SRCS})

# 单链表
add_executable(forward_list_test forward_list_test.cpp ${HDRS} ${SRCS})

# 有序哈希表
add_executable(map_test map_test.cpp ${HDRS} ${SRCS})
# stack
add_executable(stack_test stack_test.cpp ${HDRS} ${SRCS})
