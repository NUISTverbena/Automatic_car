################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1006968225: ../MYPROJECT.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccstheia141/ccs/utils/sysconfig_1.20.0/sysconfig_cli.bat" --script "C:/Users/wangjie/workspace_ccstheia/MY PROJECT/MYPROJECT.syscfg" -o "." -s "C:/ti/mspm0_sdk_2_01_00_03/.metadata/product.json" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1006968225 ../MYPROJECT.syscfg
device.opt: build-1006968225
device.cmd.genlibs: build-1006968225
ti_msp_dl_config.c: build-1006968225
ti_msp_dl_config.h: build-1006968225
Event.dot: build-1006968225

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccstheia141/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/OLED" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/Debug" -I"C:/ti/mspm0_sdk_2_01_00_03/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_01_00_03/source" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/secondquestion" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/hardware" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/Pathfinding_algorithm" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: C:/ti/mspm0_sdk_2_01_00_03/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccstheia141/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/OLED" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/Debug" -I"C:/ti/mspm0_sdk_2_01_00_03/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_01_00_03/source" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/secondquestion" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/hardware" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/Pathfinding_algorithm" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccstheia141/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/OLED" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/Debug" -I"C:/ti/mspm0_sdk_2_01_00_03/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_01_00_03/source" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/secondquestion" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/hardware" -I"C:/Users/wangjie/workspace_ccstheia/MY PROJECT/Pathfinding_algorithm" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


