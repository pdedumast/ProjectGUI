

set(CMAKE_AUTOMOC ON)

##qt5_wrap_cpp(source_files_moc mainwindow.cxx)
# qt5_wrap_ui(source_files_ui mainwindow.ui)
qt5_wrap_ui(source_files_ui mainwindow.ui newwindow.ui)



file( GLOB_RECURSE
        source_files
        src/*.cxx
)

set(EXECUTABLE_OUTPUT_PATH build)

add_executable(main main.cxx mainwindow.cxx ${source_files_ui} ${source_files_moc})
target_link_libraries(main ${QT_LIBRARIES} ${ITK_LIBRARIES})
