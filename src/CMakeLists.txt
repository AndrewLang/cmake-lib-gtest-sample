
add_subdirectory (demo)
add_subdirectory (shared-lib)


add_dependencies(demo shared-lib)