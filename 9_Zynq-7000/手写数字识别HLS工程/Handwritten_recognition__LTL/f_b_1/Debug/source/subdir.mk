################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../forw_back_LTL.c 

OBJS += \
./source/forw_back_LTL.o 

C_DEPS += \
./source/forw_back_LTL.d 


# Each subdirectory must supply rules for building sources it contributes
source/forw_back_LTL.o: C:/Users/LTL/Desktop/Handwritten_digit_recognition__LTL_FPGA/f_b_1/forw_back_LTL.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -ID:/Xilinx/Vivado/2019.1/include/etc -ID:/Xilinx/Vivado/2019.1/include/ap_sysc -IC:/Users/LTL/Desktop/Handwritten_digit_recognition__LTL_FPGA -ID:/Xilinx/Vivado/2019.1/win64/tools/auto_cc/include -ID:/Xilinx/Vivado/2019.1/win64/tools/systemc/include -ID:/Xilinx/Vivado/2019.1/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


