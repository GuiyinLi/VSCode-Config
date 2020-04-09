#csdn教程：https://blog.csdn.net/frostime/article/details/86756983
#用于设置最低版本号要求, 需要放在文件最开头位置。
#cmake常用指令讲解：https://cloud.tencent.com/developer/article/1010072
#${varild}:获取varild的值
cmake_minimum_required(VERSION 3.0.0)
STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} )#获取cmakelists所在根目录文件名称,存储在CURRENT_FOLDER中
set(PROJECT_NAME ${CURRENT_FOLDER})#设置工程名变量 这里要与工程文件文件名一致！
project(${PROJECT_NAME})#工程名称

set(CMAKE_CXX_COMPILER "g++")# 显示指定使用的C++编译器
set (CMAKE_CXX_FLAGS  "-g  -fexec-charset=GBK")#保留调试信息

include_directories(${PROJECT_SOURCE_DIR}/include) #根目录/Include
aux_source_directory(./source SrcFiles)#仅加入源文件 .c文件
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)#输出文件 .exe 输出在bin文件夹下 默认输出在build文件下
add_executable(${PROJECT_NAME} ${SrcFiles})   #可执行文件名 生成该可执行文件的源文件
