option(PL_HAL_RELIC "PL_HAL_RELIC" OFF)
if(PL_HAL_RELIC OR BUILD_ALL_PLUGINS)
    file(GLOB_RECURSE HAL_RELIC_INC ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
    file(GLOB_RECURSE HAL_RELIC_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
    file(GLOB_RECURSE HAL_RELIC_PYTHON_SRC ${CMAKE_CURRENT_SOURCE_DIR}/python/*.cpp)

    hal_add_plugin(hal_relic
                   SHARED
                   HEADER ${HAL_RELIC_INC}
                   SOURCES ${HAL_RELIC_SRC} ${HAL_RELIC_PYTHON_SRC}
                   )
endif()
