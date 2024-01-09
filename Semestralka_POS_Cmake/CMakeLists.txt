# CMakeList.txt : CMake project for Semestralka_POS_Cmake, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Semestralka_POS_Cmake "Semestralka_POS_Cmake.cpp" "Semestralka_POS_Cmake.h" "Hrac.h" "Hrac.cpp" "Panacik.h" "Panacik.cpp" "Server.h" "Klient.h" "Sockety.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Semestralka_POS_Cmake PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
