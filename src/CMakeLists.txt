
add_library(
	lib_name
	SHARED
	function.c
	printer.c
)

install(
	TARGETS lib_name
	DESTINATION lib
)

file(
	GLOB
	headers
	*.h
)

install(
	FILES ${headers}
	DESTINATION include/${CMAKE_PROJECT_NAME}
)


