################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/Applications/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="/Users/radwanalrefai/Desktop/workspace_v12/Solar-MPPT-2022-2023/Solar MPPT IPEG - 2022-2023" --include_path="/Users/radwanalrefai/Desktop/workspace_v12/Solar-MPPT-2022-2023/Solar MPPT IPEG - 2022-2023/device" --include_path="/Users/radwanalrefai/Desktop/C2000Ware_4_01_00_00/driverlib/f2837xd/driverlib" --include_path="/Applications/ti/ccs1210/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=DEBUG --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="/Users/radwanalrefai/Desktop/workspace_v12/Solar-MPPT-2022-2023/Solar MPPT IPEG - 2022-2023/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


