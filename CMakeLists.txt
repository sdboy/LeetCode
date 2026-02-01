cmake_minimum_required(VERSION 3.10.0)
project(LeetCode VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
SET(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# 创建库
add_library(leetcode_lib STATIC
  src/test.c
  src/twoSum.c
)
# 设置库的头文件路径（对链接此库的所有目标公开）
target_include_directories(leetcode_lib PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

# 创建主程序
add_executable(${PROJECT_NAME} main.c)
# 链接库
target_link_libraries(${PROJECT_NAME} PRIVATE leetcode_lib)
# 设置输出目录
# 设置输出目录
set_target_properties(${PROJECT_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out"
)
set_target_properties(leetcode_lib PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out"
)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
