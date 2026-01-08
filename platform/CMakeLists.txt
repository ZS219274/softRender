# CMakeLists.txt for platform module

# Define platform library sources based on the platform
if(WIN32)
    set(PLATFORM_SOURCES
        win_platform.cpp
        win_platform.h
    )
elseif(UNIX)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(SDL2 REQUIRED sdl2)
    
    # Set SDL2 related variables
    set(PLATFORM_CFLAGS ${SDL2_CFLAGS_OTHER})
    set(PLATFORM_LIBRARIES ${SDL2_LIBRARIES})
    set(PLATFORM_DEFINITIONS -DUSE_SDL2)
    
    set(PLATFORM_SOURCES
        linux_platform.cpp
        linux_platform.h
    )
endif()

# Add platform definitions
add_definitions(${PLATFORM_DEFINITIONS})

# Create the platform library
add_library(platformLib
    platform_factory.cpp
    platform_factory.h
    ${PLATFORM_SOURCES}
)

# Link platform-specific libraries
if(UNIX)
    target_link_libraries(platformLib ${PLATFORM_LIBRARIES})
    target_include_directories(platformLib PRIVATE ${SDL2_INCLUDE_DIRS})
endif()

# Make platform headers available
target_include_directories(platformLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})