include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(tundra_TX_CRC8_V08_default_library_list )

set(OUTPUT_SUFFIX elf)
# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(tundra_TX_CRC8_V08_default_default_XC8_FILE_TYPE_assemble)
add_library(tundra_TX_CRC8_V08_default_default_XC8_assemble OBJECT ${tundra_TX_CRC8_V08_default_default_XC8_FILE_TYPE_assemble})
    tundra_TX_CRC8_V08_default_default_XC8_assemble_rule(tundra_TX_CRC8_V08_default_default_XC8_assemble)
    list(APPEND tundra_TX_CRC8_V08_default_library_list "$<TARGET_OBJECTS:tundra_TX_CRC8_V08_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(tundra_TX_CRC8_V08_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(tundra_TX_CRC8_V08_default_default_XC8_assemblePreprocess OBJECT ${tundra_TX_CRC8_V08_default_default_XC8_FILE_TYPE_assemblePreprocess})
    tundra_TX_CRC8_V08_default_default_XC8_assemblePreprocess_rule(tundra_TX_CRC8_V08_default_default_XC8_assemblePreprocess)
    list(APPEND tundra_TX_CRC8_V08_default_library_list "$<TARGET_OBJECTS:tundra_TX_CRC8_V08_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(tundra_TX_CRC8_V08_default_default_XC8_FILE_TYPE_compile)
add_library(tundra_TX_CRC8_V08_default_default_XC8_compile OBJECT ${tundra_TX_CRC8_V08_default_default_XC8_FILE_TYPE_compile})
    tundra_TX_CRC8_V08_default_default_XC8_compile_rule(tundra_TX_CRC8_V08_default_default_XC8_compile)
    list(APPEND tundra_TX_CRC8_V08_default_library_list "$<TARGET_OBJECTS:tundra_TX_CRC8_V08_default_default_XC8_compile>")

endif()

# Handle files with suffix elf, for group default-XC8
if(tundra_TX_CRC8_V08_default_default_XC8_FILE_TYPE_objcopy_lss)
add_library(tundra_TX_CRC8_V08_default_default_XC8_objcopy_lss OBJECT ${tundra_TX_CRC8_V08_default_default_XC8_FILE_TYPE_objcopy_lss})
    tundra_TX_CRC8_V08_default_default_XC8_objcopy_lss_rule(tundra_TX_CRC8_V08_default_default_XC8_objcopy_lss)
    list(APPEND tundra_TX_CRC8_V08_default_library_list "$<TARGET_OBJECTS:tundra_TX_CRC8_V08_default_default_XC8_objcopy_lss>")

endif()


# Main target for this project
add_executable(tundra_TX_CRC8_V08_default_image_WlwGQWWo ${tundra_TX_CRC8_V08_default_library_list})

set_target_properties(tundra_TX_CRC8_V08_default_image_WlwGQWWo PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${tundra_TX_CRC8_V08_default_output_dir}")
target_link_libraries(tundra_TX_CRC8_V08_default_image_WlwGQWWo PRIVATE ${tundra_TX_CRC8_V08_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
tundra_TX_CRC8_V08_default_link_rule( tundra_TX_CRC8_V08_default_image_WlwGQWWo)


#Add objcopy steps
tundra_TX_CRC8_V08_default_objcopy_lss_rule(tundra_TX_CRC8_V08_default_image_WlwGQWWo)

