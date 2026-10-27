# origin-pack: STMicroelectronics::joystick_part_drivers@2.0.0
# file-format: 1.0.0
project(STMicroelectronics_joystick_part_drivers_2_0_0)
cmake_minimum_required(VERSION 3.30)
add_library(STMicroelectronics_joystick_part_drivers_2_0_0 INTERFACE)

# List of all CMSIS properties that influence conditions for this package


# Device specific defined symbols








# Enable all components in this package
if(CMSIS_ENTIRE_STMicroelectronics_joystick_part_drivers_2_0_0)
  list(APPEND CMSIS_COMPONENTS_LIST "Cvendor:STMicroelectronics#Cclass:Board Part#Cgroup:Joystick#Csub:ADC#Cversion:1.0.0")
endif()

# All conditions used by this package

# condition: STMicroelectronics.joystick_part_drivers.2.0.0:IO ADC
# description: STMicroelectronics ADC interface
set(STMicroelectronics.joystick_part_drivers.2.0.0_IO_ADC "$<NOT:$<STREQUAL:$<FILTER:${CMSIS_COMPONENTS_LIST},INCLUDE,.*Cclass:Device#.*Cgroup:STM32 HAL#.*Csub:ADC(#.*|$)>,>>")
message(DEBUG "CMSIS condition STMicroelectronics.joystick_part_drivers.2.0.0_IO_ADC enabled")


# condition: STMicroelectronics.joystick_part_drivers.2.0.0:JOYSTICK CFG Condition
# description: 
set(STMicroelectronics.joystick_part_drivers.2.0.0_JOYSTICK_CFG_Condition "1")
message(DEBUG "CMSIS condition STMicroelectronics.joystick_part_drivers.2.0.0_JOYSTICK_CFG_Condition enabled")

# Files and components in this package
if("Cvendor:STMicroelectronics#Cclass:Board Part#Cgroup:Joystick#Csub:ADC#Cversion:1.0.0" IN_LIST CMSIS_COMPONENTS_LIST)  # Driver for joystick driven by ADC based on STM32 HAL
  message(DEBUG "Using component Board_Part_Joystick_ADC_1_0_0")
  target_compile_definitions(STMicroelectronics_joystick_part_drivers_2_0_0 INTERFACE "$<${STMicroelectronics.joystick_part_drivers.2.0.0_IO_ADC}:-DCMSIS_USE_Board_Part_Joystick_ADC_1_0_0=1>")
  target_include_directories(STMicroelectronics_joystick_part_drivers_2_0_0 INTERFACE "$<${STMicroelectronics.joystick_part_drivers.2.0.0_IO_ADC}:${CMAKE_CURRENT_LIST_DIR}/adc>")
  target_sources(STMicroelectronics_joystick_part_drivers_2_0_0 INTERFACE "$<${STMicroelectronics.joystick_part_drivers.2.0.0_IO_ADC}:${CMAKE_CURRENT_LIST_DIR}/adc/joystick_adc.c>")
endif()

