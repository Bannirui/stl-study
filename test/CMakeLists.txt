# 源文件
file(GLOB_RECURSE HDRS "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB_RECURSE SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach (test_src ${SRCS})
    # file name without extension
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src} ${HDRS})
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach ()