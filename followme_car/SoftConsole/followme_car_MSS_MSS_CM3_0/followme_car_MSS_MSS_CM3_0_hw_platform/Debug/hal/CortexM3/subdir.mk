################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/CortexM3/cortex_nvic.c 

OBJS += \
./hal/CortexM3/cortex_nvic.o 

C_DEPS += \
./hal/CortexM3/cortex_nvic.d 


# Each subdirectory must supply rules for building sources it contributes
hal/CortexM3/%.o: ../hal/CortexM3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU C Compiler'
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform\CMSIS -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform\CMSIS\startup_gcc -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform\drivers -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform\drivers\mss_gpio -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform\drivers\mss_nvm -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform\drivers\mss_pdma -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform\drivers\mss_rtc -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform\drivers\mss_timer -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform\hal -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform\hal\CortexM3 -IC:\Users\lstolz\Desktop\FollowMe\FollowMe\followme_car\SoftConsole\followme_car_MSS_MSS_CM3_0\followme_car_MSS_MSS_CM3_0_hw_platform\hal\CortexM3\GNU -O0 -ffunction-sections -fdata-sections -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


