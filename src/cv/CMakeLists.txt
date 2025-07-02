project(cv)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
message("[${PROJECT_NAME}] SRC_LIST: ${SRC_LIST}")

add_library(${PROJECT_NAME} STATIC ${SRC_LIST})