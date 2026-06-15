# CMakeList.txt: projekt CMake dla elementu TrafficAnalizer, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.10)

# Włącz przeładowywanie kodu XAML na gorąco dla kompilatorów MSVC, jeśli jest to obsługiwane.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("TrafficAnalizer")

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (TrafficAnalizer "src/TrafficAnalizer.cpp" "include/TrafficAnalizer.h" "include/models/Date.h" "src/models/Date.cpp" "include/models/Time.h" "src/models/Time.cpp" "include/models/TrafficSnapshot.h" "src/models/TrafficSnapshot.cpp" "include/core/AnalizedResults.h" "src/core/AnalizedResults.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TrafficAnalizer PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(TrafficAnalizer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
