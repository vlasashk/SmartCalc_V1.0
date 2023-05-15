cmake_minimum_required(VERSION 3.5)

project(SmartCalcV1 VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(QCP)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        back/calculator.c
        back/credit.c
        back/parser.c
        back/rpn.c
        back/stack.c
        back/headers/calculator.h
        back/headers/credit.h
        back/headers/includes.h
        back/headers/parser.h
        back/headers/stack.h

        main.cpp

        front/calculator/input.cpp
        front/calculator/mainwindow.cpp
        front/calculator/plot.cpp
        front/calculator/mainwindow.ui
        front/headers/mainwindow.h

        front/headers/creditcalc.h
        front/credit/creditcalc.cpp
        front/credit/creditcalc.ui

        resources.qrc

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartCalcV1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(SmartCalcV1
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(SmartCalcV1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets qcustomplot)

target_compile_definitions(SmartCalcV1 PRIVATE QCUSTOMPLOT_USE_LIBRARY)

set_target_properties(SmartCalcV1 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartCalcV1)
endif()
