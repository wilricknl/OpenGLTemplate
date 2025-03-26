cmake_minimum_required(VERSION 3.20)

set(template_VERSION 1.0.0)

project(template
        VERSION ${template_VERSION}
        DESCRIPTION "OpenGL template with CMake and vcpkg"
        HOMEPAGE_URL "https://github.com/wilricknl/OpenGLTemplate"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

## Interpret source as utf-8 on Windows to ensure
## non-ascii characters are read properly.
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

## Static builds on Windows
if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# -----------------------------------------------------------------------------
# DEPENDENCIES
# -----------------------------------------------------------------------------

# external packages
find_package(EnTT CONFIG REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(include)

# -----------------------------------------------------------------------------
# template
# -----------------------------------------------------------------------------

add_executable(
	template 
	src/main.cpp)
target_link_libraries(template PRIVATE
    EnTT::EnTT
    glad::glad
    glm::glm
    glfw
    imgui::imgui
    OpenGL::GL)

# -----------------------------------------------------------------------------
# INSTALLATION
# -----------------------------------------------------------------------------

install(TARGETS template)
