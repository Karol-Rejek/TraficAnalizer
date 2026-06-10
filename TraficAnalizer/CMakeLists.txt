# CMakeList.txt: projekt CMake dla elementu TraficAnalizer, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.10)

# Włącz przeładowywanie kodu XAML na gorąco dla kompilatorów MSVC, jeśli jest to obsługiwane.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("TraficAnalizer")

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (TraficAnalizer "TraficAnalizer.cpp" "TraficAnalizer.h" "src/Analizer/TrafficSnapshot.h" "src/Analizer/TrafficSnapshot.cpp" "src/Analizer/Date.h" "src/Analizer/Date.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TraficAnalizer PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
