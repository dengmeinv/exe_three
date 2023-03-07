cmake_minimum_required(VERSION 3.25)

project(finddialog VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(finddialog)

target_sources(finddialog
    PRIVATE
        main.cpp
        finddialog.cpp
        finddialog.h
        
    PUBLIC
        
)

target_compile_features(finddialog PRIVATE cxx_std_20)

target_link_libraries(finddialog 
    PRIVATE 
        Qt6::Widgets
)












































# set_target_properties(finddialog PROPERTIES
#     MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# install(TARGETS finddialog
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(finddialog)
# endif()





#qt_add_executable(finddialog)  //Creates and finalizes an application target of a platform-specific type.
#This command performs the following tasks:

#    1. Create a CMake target of the appropriate type for the target platform.
#    2. Link the target to the Qt::Core library.
#    3. Handle finalization of the CMake target.



# qt_standard_project_setup()     #set(CMAKE_AUTOUIC ON)  set(CMAKE_AUTOMOC ON)  set(CMAKE_AUTORCC ON)

