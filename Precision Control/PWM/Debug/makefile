################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./UART_example.obj" \
"./adc_photodiode.obj" \
"./adc_rgb.obj" \
"./adc_test.obj" \
"./button_based_delay.obj" \
"./button_blink.obj" \
"./button_interrupt.obj" \
"./debouncing.obj" \
"./extra_work_button_based_delay.obj" \
"./extra_work_debouncing.obj" \
"./extra_work_simple_blink.obj" \
"./extra_work_software_pwm.obj" \
"./hardware_pwm.obj" \
"./main.obj" \
"./milestone2.obj" \
"./milestone_1.obj" \
"./multiple_blink.obj" \
"./pwm_2.obj" \
"./r2r.obj" \
"./simple_blink.obj" \
"./software_pwm.obj" \
"./square_wave.obj" \
"./test.obj" \
"./timer_a_blink.obj" \
"../lnk_msp430f5529.cmd" \
$(GEN_CMDS__FLAG) \
-llibmath.a \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
MSP430F5529.out \

EXE_OUTPUTS__QUOTED += \
"MSP430F5529.out" \

BIN_OUTPUTS += \
MSP430F5529.hex \

BIN_OUTPUTS__QUOTED += \
"MSP430F5529.hex" \


# All Target
all: MSP430F5529.out

# Tool invocations
MSP430F5529.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --advice:power=all -g --define=__MSP430F5529__ --diag_wrap=off --display_error_number --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal -z -m"MSP430F5529.map" --stack_size=160 --heap_size=160 --cinit_hold_wdt=on -i"C:/ti/ccsv6/ccs_base/msp430/include" -i"C:/ti/ccsv6/ccs_base/msp430/lib/5xx_6xx_FRxx" -i"C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/lib" -i"C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --reread_libs --display_error_number --warn_sections --diag_wrap=off --xml_link_info="MSP430F5529_linkInfo.xml" --use_hw_mpy=F5 --rom_model -o "MSP430F5529.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

MSP430F5529.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/hex430" --memwidth=8 --romwidth=8 -o "MSP430F5529.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "UART_example.d" "adc_photodiode.d" "adc_rgb.d" "adc_test.d" "button_based_delay.d" "button_blink.d" "button_interrupt.d" "debouncing.d" "extra_work_button_based_delay.d" "extra_work_debouncing.d" "extra_work_simple_blink.d" "extra_work_software_pwm.d" "hardware_pwm.d" "main.d" "milestone2.d" "milestone_1.d" "multiple_blink.d" "pwm_2.d" "r2r.d" "simple_blink.d" "software_pwm.d" "square_wave.d" "test.d" "timer_a_blink.d" 
	-$(RM) "UART_example.obj" "adc_photodiode.obj" "adc_rgb.obj" "adc_test.obj" "button_based_delay.obj" "button_blink.obj" "button_interrupt.obj" "debouncing.obj" "extra_work_button_based_delay.obj" "extra_work_debouncing.obj" "extra_work_simple_blink.obj" "extra_work_software_pwm.obj" "hardware_pwm.obj" "main.obj" "milestone2.obj" "milestone_1.obj" "multiple_blink.obj" "pwm_2.obj" "r2r.obj" "simple_blink.obj" "software_pwm.obj" "square_wave.obj" "test.obj" "timer_a_blink.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

