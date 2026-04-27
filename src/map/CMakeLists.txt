#
# src/map/CMakeLists.txt - compilação do map-server
#

set(MAP_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "")

if(BUILD_SERVERS)
    message(STATUS "Creating target map-server")

    # Headers
    file(GLOB_RECURSE MAP_HEADERS "${MAP_SOURCE_DIR}/*.hpp")
    list(FILTER MAP_HEADERS EXCLUDE REGEX ".*/skills/.*")

    # Sources
    file(GLOB_RECURSE MAP_SOURCES "${MAP_SOURCE_DIR}/*.cpp")
    list(FILTER MAP_SOURCES EXCLUDE REGEX ".*/skills/.*")

    # Adiciona explicitamente emundus.cpp (para garantir que linker encontre CheckSetBonus)
    list(APPEND MAP_SOURCES "${MAP_SOURCE_DIR}/emundus.cpp")

    # Dependências e libraries
    set(DEPENDENCIES common ryml)
    set(LIBRARIES ${GLOBAL_LIBRARIES} ${MYSQL_LIBRARIES})
    set(INCLUDE_DIRS ${GLOBAL_INCLUDE_DIRS} ${COMMON_BASE_INCLUDE_DIRS} ${RA_INCLUDE_DIRS} ${MYSQL_INCLUDE_DIRS})
    set(DEFINITIONS "${GLOBAL_DEFINITIONS} ${COMMON_BASE_DEFINITIONS}")

    if(WITH_PCRE)
        message(STATUS "Enabled PCRE code")
        set(LIBRARIES ${LIBRARIES} ${PCRE_LIBRARIES})
        set(INCLUDE_DIRS ${INCLUDE_DIRS} ${PCRE_INCLUDE_DIRS})
        set(DEFINITIONS "${DEFINITIONS} -DPCRE_SUPPORT")
    else()
        message(STATUS "Disabled PCRE code")
    endif()

    # Lista final de arquivos
    set(SOURCE_FILES ${COMMON_BASE_HEADERS} ${COMMON_HEADERS} ${MAP_HEADERS} ${MAP_SOURCES})

    # Grupos para Visual Studio
    source_group(common FILES ${COMMON_BASE_HEADERS} ${COMMON_HEADERS})
    source_group(map FILES ${MAP_HEADERS} ${MAP_SOURCES})

    # Includes
    include_directories(${INCLUDE_DIRS})

    # Cria o executável do map-server
    add_executable(map-server ${SOURCE_FILES})

    # Link e dependências
    add_dependencies(map-server ${DEPENDENCIES})
    target_link_libraries(map-server ${LIBRARIES} ${DEPENDENCIES})
    set_target_properties(map-server PROPERTIES COMPILE_FLAGS "${DEFINITIONS}")

    # Instalação opcional
    if(INSTALL_COMPONENT_RUNTIME)
        cpack_add_component(Runtime_mapserver DESCRIPTION "map-server" DISPLAY_NAME "map-server" GROUP Runtime)
        install(TARGETS map-server DESTINATION "." COMPONENT Runtime_mapserver)
    endif()

    # Atualiza lista de targets
    set(TARGET_LIST ${TARGET_LIST} map-server CACHE INTERNAL "")
    message(STATUS "Creating target map-server - done")
endif(BUILD_SERVERS)