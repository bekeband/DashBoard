#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-PIC32MXMIKROE.mk)" "nbproject/Makefile-local-PIC32MXMIKROE.mk"
include nbproject/Makefile-local-PIC32MXMIKROE.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=PIC32MXMIKROE
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DashBoard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DashBoard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/Configs/PIC32MXMIKROE/system.c ../../../../framework/gfx/src/gfx_primitive.c ../../../../framework/gfx/src/gfx_gol.c ../../../../framework/gfx/src/gfx_gol_window.c ../../../../framework/gfx/src/gfx_gol_meter.c ../../../../framework/gfx/src/gfx_gol_button.c ../../../../framework/gfx/src/gfx_gol_static_text.c ../../../../framework/gfx/src/gfx_gol_list_box.c ../../../../framework/gfx/src/gfx_gol_radio_button.c ../../../../framework/gfx/src/gfx_gol_scheme_default.c ../../../../framework/gfx/src/gfx_gol_check_box.c ../../../../framework/gfx/src/gfx_gol_group_box.c ../../../../framework/driver/gfx/src/drv_gfx_tft003.c ../../../../framework/driver/nvm/src/drv_nvm_flash_spi_m25p80.c ../src/gdd_resource.S ../src/gdd_resource_reference.c ../../../../framework/driver/spi/src/drv_spi_16bit.c ../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c ../../../../framework/driver/touch_screen/src/drv_touch_screen.c ../src/delay.c ../src/DashBoard.c ../src/options_screen.c ../src/swreset_screen.c ../src/main_screen.c ../src/error_screen.c ../src/exceptions.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1211495701/system.o ${OBJECTDIR}/_ext/386020355/gfx_primitive.o ${OBJECTDIR}/_ext/386020355/gfx_gol.o ${OBJECTDIR}/_ext/386020355/gfx_gol_window.o ${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o ${OBJECTDIR}/_ext/386020355/gfx_gol_button.o ${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o ${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o ${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o ${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o ${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o ${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o ${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o ${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o ${OBJECTDIR}/_ext/1360937237/gdd_resource.o ${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o ${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o ${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o ${OBJECTDIR}/_ext/200387209/drv_touch_screen.o ${OBJECTDIR}/_ext/1360937237/delay.o ${OBJECTDIR}/_ext/1360937237/DashBoard.o ${OBJECTDIR}/_ext/1360937237/options_screen.o ${OBJECTDIR}/_ext/1360937237/swreset_screen.o ${OBJECTDIR}/_ext/1360937237/main_screen.o ${OBJECTDIR}/_ext/1360937237/error_screen.o ${OBJECTDIR}/_ext/1360937237/exceptions.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1211495701/system.o.d ${OBJECTDIR}/_ext/386020355/gfx_primitive.o.d ${OBJECTDIR}/_ext/386020355/gfx_gol.o.d ${OBJECTDIR}/_ext/386020355/gfx_gol_window.o.d ${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o.d ${OBJECTDIR}/_ext/386020355/gfx_gol_button.o.d ${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o.d ${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o.d ${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o.d ${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o.d ${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o.d ${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o.d ${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o.d ${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o.d ${OBJECTDIR}/_ext/1360937237/gdd_resource.o.d ${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o.d ${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o.d ${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o.d ${OBJECTDIR}/_ext/200387209/drv_touch_screen.o.d ${OBJECTDIR}/_ext/1360937237/delay.o.d ${OBJECTDIR}/_ext/1360937237/DashBoard.o.d ${OBJECTDIR}/_ext/1360937237/options_screen.o.d ${OBJECTDIR}/_ext/1360937237/swreset_screen.o.d ${OBJECTDIR}/_ext/1360937237/main_screen.o.d ${OBJECTDIR}/_ext/1360937237/error_screen.o.d ${OBJECTDIR}/_ext/1360937237/exceptions.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1211495701/system.o ${OBJECTDIR}/_ext/386020355/gfx_primitive.o ${OBJECTDIR}/_ext/386020355/gfx_gol.o ${OBJECTDIR}/_ext/386020355/gfx_gol_window.o ${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o ${OBJECTDIR}/_ext/386020355/gfx_gol_button.o ${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o ${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o ${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o ${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o ${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o ${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o ${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o ${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o ${OBJECTDIR}/_ext/1360937237/gdd_resource.o ${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o ${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o ${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o ${OBJECTDIR}/_ext/200387209/drv_touch_screen.o ${OBJECTDIR}/_ext/1360937237/delay.o ${OBJECTDIR}/_ext/1360937237/DashBoard.o ${OBJECTDIR}/_ext/1360937237/options_screen.o ${OBJECTDIR}/_ext/1360937237/swreset_screen.o ${OBJECTDIR}/_ext/1360937237/main_screen.o ${OBJECTDIR}/_ext/1360937237/error_screen.o ${OBJECTDIR}/_ext/1360937237/exceptions.o

# Source Files
SOURCEFILES=../src/Configs/PIC32MXMIKROE/system.c ../../../../framework/gfx/src/gfx_primitive.c ../../../../framework/gfx/src/gfx_gol.c ../../../../framework/gfx/src/gfx_gol_window.c ../../../../framework/gfx/src/gfx_gol_meter.c ../../../../framework/gfx/src/gfx_gol_button.c ../../../../framework/gfx/src/gfx_gol_static_text.c ../../../../framework/gfx/src/gfx_gol_list_box.c ../../../../framework/gfx/src/gfx_gol_radio_button.c ../../../../framework/gfx/src/gfx_gol_scheme_default.c ../../../../framework/gfx/src/gfx_gol_check_box.c ../../../../framework/gfx/src/gfx_gol_group_box.c ../../../../framework/driver/gfx/src/drv_gfx_tft003.c ../../../../framework/driver/nvm/src/drv_nvm_flash_spi_m25p80.c ../src/gdd_resource.S ../src/gdd_resource_reference.c ../../../../framework/driver/spi/src/drv_spi_16bit.c ../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c ../../../../framework/driver/touch_screen/src/drv_touch_screen.c ../src/delay.c ../src/DashBoard.c ../src/options_screen.c ../src/swreset_screen.c ../src/main_screen.c ../src/error_screen.c ../src/exceptions.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-PIC32MXMIKROE.mk dist/${CND_CONF}/${IMAGE_TYPE}/DashBoard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX460F512L
MP_LINKER_FILE_OPTION=,--script="..\src\options_area.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/gdd_resource.o: ../src/gdd_resource.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gdd_resource.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gdd_resource.o 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gdd_resource.o.ok ${OBJECTDIR}/_ext/1360937237/gdd_resource.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/gdd_resource.o.d" "${OBJECTDIR}/_ext/1360937237/gdd_resource.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/gdd_resource.o.d"  -o ${OBJECTDIR}/_ext/1360937237/gdd_resource.o ../src/gdd_resource.S -save-temps=obj -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1360937237/gdd_resource.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1 -I"../src/Configs/PIC32MXMIKROE" -I"../src",-asd=${OBJECTDIR}/_ext/1360937237/gdd_resource.lst
	
else
${OBJECTDIR}/_ext/1360937237/gdd_resource.o: ../src/gdd_resource.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gdd_resource.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gdd_resource.o 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gdd_resource.o.ok ${OBJECTDIR}/_ext/1360937237/gdd_resource.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/gdd_resource.o.d" "${OBJECTDIR}/_ext/1360937237/gdd_resource.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/gdd_resource.o.d"  -o ${OBJECTDIR}/_ext/1360937237/gdd_resource.o ../src/gdd_resource.S -save-temps=obj -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1360937237/gdd_resource.o.asm.d" -I"../src/Configs/PIC32MXMIKROE" -I"../src",-asd=${OBJECTDIR}/_ext/1360937237/gdd_resource.lst
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1211495701/system.o: ../src/Configs/PIC32MXMIKROE/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1211495701 
	@${RM} ${OBJECTDIR}/_ext/1211495701/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/1211495701/system.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1211495701/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1211495701/system.o.d" -o ${OBJECTDIR}/_ext/1211495701/system.o ../src/Configs/PIC32MXMIKROE/system.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_primitive.o: ../../../../framework/gfx/src/gfx_primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_primitive.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_primitive.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_primitive.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_primitive.o ../../../../framework/gfx/src/gfx_primitive.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol.o: ../../../../framework/gfx/src/gfx_gol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol.o ../../../../framework/gfx/src/gfx_gol.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_window.o: ../../../../framework/gfx/src/gfx_gol_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_window.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_window.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_window.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_window.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_window.o ../../../../framework/gfx/src/gfx_gol_window.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o: ../../../../framework/gfx/src/gfx_gol_meter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o ../../../../framework/gfx/src/gfx_gol_meter.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_button.o: ../../../../framework/gfx/src/gfx_gol_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_button.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_button.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_button.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_button.o ../../../../framework/gfx/src/gfx_gol_button.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o: ../../../../framework/gfx/src/gfx_gol_static_text.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o ../../../../framework/gfx/src/gfx_gol_static_text.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o: ../../../../framework/gfx/src/gfx_gol_list_box.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o ../../../../framework/gfx/src/gfx_gol_list_box.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o: ../../../../framework/gfx/src/gfx_gol_radio_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o ../../../../framework/gfx/src/gfx_gol_radio_button.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o: ../../../../framework/gfx/src/gfx_gol_scheme_default.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o ../../../../framework/gfx/src/gfx_gol_scheme_default.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o: ../../../../framework/gfx/src/gfx_gol_check_box.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o ../../../../framework/gfx/src/gfx_gol_check_box.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o: ../../../../framework/gfx/src/gfx_gol_group_box.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o ../../../../framework/gfx/src/gfx_gol_group_box.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o: ../../../../framework/driver/gfx/src/drv_gfx_tft003.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1867384104 
	@${RM} ${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o.d 
	@${RM} ${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o.d" -o ${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o ../../../../framework/driver/gfx/src/drv_gfx_tft003.c   -save-temps=obj
	
${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o: ../../../../framework/driver/nvm/src/drv_nvm_flash_spi_m25p80.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/498082052 
	@${RM} ${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o.d 
	@${RM} ${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o.d" -o ${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o ../../../../framework/driver/nvm/src/drv_nvm_flash_spi_m25p80.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o: ../src/gdd_resource_reference.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o.d" -o ${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o ../src/gdd_resource_reference.c   -save-temps=obj
	
${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o: ../../../../framework/driver/spi/src/drv_spi_16bit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/465164171 
	@${RM} ${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o.d 
	@${RM} ${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o.d" -o ${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o ../../../../framework/driver/spi/src/drv_spi_16bit.c   -save-temps=obj
	
${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o: ../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/200387209 
	@${RM} ${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o.d" -o ${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o ../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c   -save-temps=obj
	
${OBJECTDIR}/_ext/200387209/drv_touch_screen.o: ../../../../framework/driver/touch_screen/src/drv_touch_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/200387209 
	@${RM} ${OBJECTDIR}/_ext/200387209/drv_touch_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/200387209/drv_touch_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/200387209/drv_touch_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/200387209/drv_touch_screen.o.d" -o ${OBJECTDIR}/_ext/200387209/drv_touch_screen.o ../../../../framework/driver/touch_screen/src/drv_touch_screen.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/delay.o: ../src/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/delay.o.d" -o ${OBJECTDIR}/_ext/1360937237/delay.o ../src/delay.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/DashBoard.o: ../src/DashBoard.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DashBoard.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DashBoard.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/DashBoard.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/DashBoard.o.d" -o ${OBJECTDIR}/_ext/1360937237/DashBoard.o ../src/DashBoard.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/options_screen.o: ../src/options_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/options_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/options_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/options_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/options_screen.o.d" -o ${OBJECTDIR}/_ext/1360937237/options_screen.o ../src/options_screen.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/swreset_screen.o: ../src/swreset_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/swreset_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/swreset_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/swreset_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/swreset_screen.o.d" -o ${OBJECTDIR}/_ext/1360937237/swreset_screen.o ../src/swreset_screen.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/main_screen.o: ../src/main_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main_screen.o.d" -o ${OBJECTDIR}/_ext/1360937237/main_screen.o ../src/main_screen.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/error_screen.o: ../src/error_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/error_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/error_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/error_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/error_screen.o.d" -o ${OBJECTDIR}/_ext/1360937237/error_screen.o ../src/error_screen.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/exceptions.o: ../src/exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/exceptions.o.d" -o ${OBJECTDIR}/_ext/1360937237/exceptions.o ../src/exceptions.c   -save-temps=obj
	
else
${OBJECTDIR}/_ext/1211495701/system.o: ../src/Configs/PIC32MXMIKROE/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1211495701 
	@${RM} ${OBJECTDIR}/_ext/1211495701/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/1211495701/system.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1211495701/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1211495701/system.o.d" -o ${OBJECTDIR}/_ext/1211495701/system.o ../src/Configs/PIC32MXMIKROE/system.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_primitive.o: ../../../../framework/gfx/src/gfx_primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_primitive.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_primitive.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_primitive.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_primitive.o ../../../../framework/gfx/src/gfx_primitive.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol.o: ../../../../framework/gfx/src/gfx_gol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol.o ../../../../framework/gfx/src/gfx_gol.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_window.o: ../../../../framework/gfx/src/gfx_gol_window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_window.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_window.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_window.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_window.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_window.o ../../../../framework/gfx/src/gfx_gol_window.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o: ../../../../framework/gfx/src/gfx_gol_meter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_meter.o ../../../../framework/gfx/src/gfx_gol_meter.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_button.o: ../../../../framework/gfx/src/gfx_gol_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_button.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_button.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_button.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_button.o ../../../../framework/gfx/src/gfx_gol_button.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o: ../../../../framework/gfx/src/gfx_gol_static_text.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_static_text.o ../../../../framework/gfx/src/gfx_gol_static_text.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o: ../../../../framework/gfx/src/gfx_gol_list_box.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_list_box.o ../../../../framework/gfx/src/gfx_gol_list_box.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o: ../../../../framework/gfx/src/gfx_gol_radio_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_radio_button.o ../../../../framework/gfx/src/gfx_gol_radio_button.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o: ../../../../framework/gfx/src/gfx_gol_scheme_default.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_scheme_default.o ../../../../framework/gfx/src/gfx_gol_scheme_default.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o: ../../../../framework/gfx/src/gfx_gol_check_box.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_check_box.o ../../../../framework/gfx/src/gfx_gol_check_box.c   -save-temps=obj
	
${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o: ../../../../framework/gfx/src/gfx_gol_group_box.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/386020355 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o.d 
	@${RM} ${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o.d" -o ${OBJECTDIR}/_ext/386020355/gfx_gol_group_box.o ../../../../framework/gfx/src/gfx_gol_group_box.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o: ../../../../framework/driver/gfx/src/drv_gfx_tft003.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1867384104 
	@${RM} ${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o.d 
	@${RM} ${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o.d" -o ${OBJECTDIR}/_ext/1867384104/drv_gfx_tft003.o ../../../../framework/driver/gfx/src/drv_gfx_tft003.c   -save-temps=obj
	
${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o: ../../../../framework/driver/nvm/src/drv_nvm_flash_spi_m25p80.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/498082052 
	@${RM} ${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o.d 
	@${RM} ${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o.d" -o ${OBJECTDIR}/_ext/498082052/drv_nvm_flash_spi_m25p80.o ../../../../framework/driver/nvm/src/drv_nvm_flash_spi_m25p80.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o: ../src/gdd_resource_reference.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o.d" -o ${OBJECTDIR}/_ext/1360937237/gdd_resource_reference.o ../src/gdd_resource_reference.c   -save-temps=obj
	
${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o: ../../../../framework/driver/spi/src/drv_spi_16bit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/465164171 
	@${RM} ${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o.d 
	@${RM} ${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o.d" -o ${OBJECTDIR}/_ext/465164171/drv_spi_16bit.o ../../../../framework/driver/spi/src/drv_spi_16bit.c   -save-temps=obj
	
${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o: ../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/200387209 
	@${RM} ${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o.d" -o ${OBJECTDIR}/_ext/200387209/drv_touch_resistive_adc.o ../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c   -save-temps=obj
	
${OBJECTDIR}/_ext/200387209/drv_touch_screen.o: ../../../../framework/driver/touch_screen/src/drv_touch_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/200387209 
	@${RM} ${OBJECTDIR}/_ext/200387209/drv_touch_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/200387209/drv_touch_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/200387209/drv_touch_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/200387209/drv_touch_screen.o.d" -o ${OBJECTDIR}/_ext/200387209/drv_touch_screen.o ../../../../framework/driver/touch_screen/src/drv_touch_screen.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/delay.o: ../src/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/delay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/delay.o.d" -o ${OBJECTDIR}/_ext/1360937237/delay.o ../src/delay.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/DashBoard.o: ../src/DashBoard.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DashBoard.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/DashBoard.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/DashBoard.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/DashBoard.o.d" -o ${OBJECTDIR}/_ext/1360937237/DashBoard.o ../src/DashBoard.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/options_screen.o: ../src/options_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/options_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/options_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/options_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/options_screen.o.d" -o ${OBJECTDIR}/_ext/1360937237/options_screen.o ../src/options_screen.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/swreset_screen.o: ../src/swreset_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/swreset_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/swreset_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/swreset_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/swreset_screen.o.d" -o ${OBJECTDIR}/_ext/1360937237/swreset_screen.o ../src/swreset_screen.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/main_screen.o: ../src/main_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main_screen.o.d" -o ${OBJECTDIR}/_ext/1360937237/main_screen.o ../src/main_screen.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/error_screen.o: ../src/error_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/error_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/error_screen.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/error_screen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/error_screen.o.d" -o ${OBJECTDIR}/_ext/1360937237/error_screen.o ../src/error_screen.c   -save-temps=obj
	
${OBJECTDIR}/_ext/1360937237/exceptions.o: ../src/exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../src/Configs/PIC32MXMIKROE" -I"../src" -I"../../../../framework" -MMD -MF "${OBJECTDIR}/_ext/1360937237/exceptions.o.d" -o ${OBJECTDIR}/_ext/1360937237/exceptions.o ../src/exceptions.c   -save-temps=obj
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/DashBoard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/options_area.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/DashBoard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -save-temps=obj  -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=20000,--defsym=_min_stack_size=512,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--cref
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/DashBoard.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/options_area.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/DashBoard.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -save-temps=obj -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=20000,--defsym=_min_stack_size=512,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--cref
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/DashBoard.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/PIC32MXMIKROE
	${RM} -r dist/PIC32MXMIKROE

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
