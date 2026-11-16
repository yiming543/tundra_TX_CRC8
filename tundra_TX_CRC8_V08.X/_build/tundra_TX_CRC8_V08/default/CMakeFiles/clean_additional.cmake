# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\out\\tundra_TX_CRC8_V08\\default.cmf"
  "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\out\\tundra_TX_CRC8_V08\\default.hex"
  "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\out\\tundra_TX_CRC8_V08\\default.hxl"
  "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\out\\tundra_TX_CRC8_V08\\default.mum"
  "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\out\\tundra_TX_CRC8_V08\\default.o"
  "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\out\\tundra_TX_CRC8_V08\\default.sdb"
  "D:\\yiming\\00work\\tundra_TX_CRC8_V08.X\\out\\tundra_TX_CRC8_V08\\default.sym"
  )
endif()
