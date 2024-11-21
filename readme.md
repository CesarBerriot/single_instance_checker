```cmake
    include(FetchContent)

    FetchContent_Declare(
        single_instance_checker
        GIT_REPOSITORY https://github.com/CesarBerriot/single_instance_checker.git
        GIT_TAG master
    )
    FetchContent_MakeAvailable(single_instance_checker)

    target_link_libraries(PROJECT_NAME PRIVATE single_instance_checker)
```