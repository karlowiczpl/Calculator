cmake_minimum_required(VERSION 3.27)
project(calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(widgets
        mainWindow/mainWindow.cpp
        mainWindow/mainWindow.h
        mainWindow/buttons/button.cpp
        mainWindow/buttons/button.h
)
set(source
        mainWindow/math/math.h
        mainWindow/math/math.cpp

)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(${PROJECT_NAME} main.cpp ${widgets} ${source})
target_link_libraries(calculator
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)