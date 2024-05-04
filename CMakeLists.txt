cmake_minimum_required(VERSION 3.16)

project(College VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appCollege
    src/main.cpp
    src/App.h
    src/App.cpp
    src/model/StudentsModel.h
    src/model/StudentsModel.cpp
    src/classes/RestApi.h
    src/classes/RestApi.cpp
    src/model/TeachersModel.h
    src/model/TeachersModel.cpp
)

set_target_properties(appCollege PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCollege
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appCollege
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


qt6_add_resources(appCollege "qml"
    FILES
    "src/qml/Main.qml"
    "src/qml/StudentsView.qml"
    "src/qml/MainView.qml"
    "src/qml/TeachersView.qml"
)

qt6_add_resources(appCollege "conf"
    FILES
    "qtquickcontrols2.conf"
)

qt6_add_resources(appCollege "assets"
    FILES
)



