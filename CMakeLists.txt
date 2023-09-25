cmake_minimum_required(VERSION 3.22)
# Global Variables
set(EXERCICE_TARGET exercice_insa)
set(TD_TARGET td_insa)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the etape value
set(ETAPE "1" CACHE STRING "Entrez l'exercice a compiler.")
set(TD "1" CACHE STRING "Entrez le td a compiler.")

# Etapes exercice
file(GLOB SOURCES_EXE "${PROJECT_SOURCE_DIR}/exercice/etape${ETAPE}/*.cpp")
add_executable(${EXERCICE_TARGET} ${SOURCES_EXE})

# TD
file(GLOB SOURCES_TD "${PROJECT_SOURCE_DIR}/td/td${TD}/src/*.cpp")
add_executable(${TD_TARGET} ${SOURCES_TD})
target_include_directories(${TD_TARGET} PUBLIC "${PROJECT_SOURCE_DIR}/td/td${ETAPE}/include")

# Adding compilation option depending on the OS 
if(MSVC)
  target_compile_options(${EXERCICE_TARGET} PUBLIC /W3 /WX /DEBUG )
  target_compile_options(${TD_TARGET} PUBLIC /W3 /WX /DEBUG )
else()
  target_compile_options(${EXERCICE_TARGET} PUBLIC -Wall -Wextra -Wpedantic -Werror -lstdc++)
  target_compile_options(${TD_TARGET} PUBLIC -Wall -Wextra -Wpedantic -Werror -lstdc++)
endif()

