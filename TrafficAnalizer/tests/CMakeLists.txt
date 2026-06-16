# tests/CMakeLists.txt

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# Windows: nie nadpisuj ustawień kompilatora projektu nadrzędnego
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(TrafficAnalizerTests)

target_sources(TrafficAnalizerTests
  PRIVATE
    "unit/test_Time.cpp"
    "unit/test_AnalizedResults.cpp"
)

target_link_libraries(TrafficAnalizerTests
  PRIVATE
    TrafficAnalizerLib   # biblioteka z projektu nadrzędnego
    GTest::gtest_main    # runner + automatyczny main() od GoogleTest
)

include(GoogleTest)
gtest_discover_tests(TrafficAnalizerTests)