cmake_minimum_required(VERSION 3.22)
# Global Variables
set(TARGET_NAME cpp_insa)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the etape value
set(ETAPE "1" CACHE STRING "Entrez un nombre d'etape a compiler.")

#Setting up the sources directory
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/etape${ETAPE}/*.cpp")

# cpp_insa Project (source, header)
add_executable(${TARGET_NAME} ${SOURCES})
# Adding the headers
target_include_directories(${TARGET_NAME} PUBLIC "include")

# Adding compilation option depending on the OS 
if(MSVC)
  target_compile_options(${TARGET_NAME} PUBLIC /W3 /WX /DEBUG )
else()
  target_compile_options(${TARGET_NAME} PUBLIC -Wall -Wextra -Wpedantic -Werror -lstdc++)
endif()

