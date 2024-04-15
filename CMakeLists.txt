# CMakeList.txt: проект CMake для RamblerPorject; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 2.8)


# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("RamblerPorject")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (RamblerPorject "RamblerPorject.cpp"   "Banner.h" "Banner.cpp" "Auction.h" "Auction.cpp" "Filter.h" "TESTS.cpp" "TESTS.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RamblerPorject PROPERTY CXX_STANDARD 17)
endif()


set_property(TARGET RamblerPorject PROPERTY CXX_STANDARD 17)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
