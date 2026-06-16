# CMakeList.txt: projekt CMake dla elementu TrafficAnalizer, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.23)

# Włącz przeładowywanie kodu XAML na gorąco dla kompilatorów MSVC, jeśli jest to obsługiwane.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("TrafficAnalizer")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(TrafficAnalizerLib)

target_sources(TrafficAnalizerLib
  PRIVATE
    "src/models/Date.cpp"
    "src/models/Time.cpp"
    "src/models/TrafficSnapshot.cpp"
    "src/core/AnalizedResults.cpp"

  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      "include/models/Date.h"
      "include/models/Time.h"
      "include/models/TrafficSnapshot.h"
      "include/core/AnalizedResults.h"
)

# Dodaj źródło do pliku wykonywalnego tego projektu.
#add_executable (TrafficAnalizer "src/TrafficAnalizer.cpp" "include/TrafficAnalizer.h" "include/models/Date.h" "src/models/Date.cpp" "include/models/Time.h" "src/models/Time.cpp" "include/models/TrafficSnapshot.h" "src/models/TrafficSnapshot.cpp" "include/core/AnalizedResults.h" "src/core/AnalizedResults.cpp")
add_executable(TrafficAnalizer)

target_sources(TrafficAnalizer
  PRIVATE
    "src/TrafficAnalizer.cpp"
)

target_link_libraries(TrafficAnalizer
  PRIVATE
    TrafficAnalizerLib
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TrafficAnalizer PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
add_subdirectory(tests)