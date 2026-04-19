cmake_minimum_required(VERSION 3.16)
project(labs_11_12 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    lab11/task1_prices.cpp
    lab11/task2_inventory.cpp
    lab11/task3_journal_editor.cpp
    lab11/task4_data_sync.cpp
    lab11/task5_reverse_output.cpp
    lab12/task1_reverse_history_iterator.cpp
    lab12/task2_time_interval_iterator.cpp
    lab12/task3_filter_iterator.cpp
    lab12/task4_transform_iterator.cpp
    lab12/task5_multi_iterator.cpp
)

foreach(source_file IN LISTS SOURCES)
    get_filename_component(target_name "${source_file}" NAME_WE)
    add_executable("${target_name}" "${source_file}")
endforeach()
