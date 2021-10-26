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
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/stacey.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/stacey.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/main.c src/drive-control/drive-control.c src/pwm-control/pwm-control.c src/stepper-motor/stepper-motor.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/drive-control/drive-control.o ${OBJECTDIR}/src/pwm-control/pwm-control.o ${OBJECTDIR}/src/stepper-motor/stepper-motor.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/drive-control/drive-control.o.d ${OBJECTDIR}/src/pwm-control/pwm-control.o.d ${OBJECTDIR}/src/stepper-motor/stepper-motor.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/drive-control/drive-control.o ${OBJECTDIR}/src/pwm-control/pwm-control.o ${OBJECTDIR}/src/stepper-motor/stepper-motor.o

# Source Files
SOURCEFILES=src/main.c src/drive-control/drive-control.c src/pwm-control/pwm-control.c src/stepper-motor/stepper-motor.c



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
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/stacey.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24F16KA301
MP_LINKER_FILE_OPTION=,--script=p24F16KA301.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/60e45785febf743f2a55ea059a7d8fcfc1f96466 .generated_files/flags/default/e9ae422dacfdebe7003964861b5b2c920a0998be
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"include" -I"src" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/drive-control/drive-control.o: src/drive-control/drive-control.c  .generated_files/flags/default/c4ec7fe8697f65230095b35401c4ef50f51e81cf .generated_files/flags/default/e9ae422dacfdebe7003964861b5b2c920a0998be
	@${MKDIR} "${OBJECTDIR}/src/drive-control" 
	@${RM} ${OBJECTDIR}/src/drive-control/drive-control.o.d 
	@${RM} ${OBJECTDIR}/src/drive-control/drive-control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/drive-control/drive-control.c  -o ${OBJECTDIR}/src/drive-control/drive-control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/drive-control/drive-control.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"include" -I"src" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm-control/pwm-control.o: src/pwm-control/pwm-control.c  .generated_files/flags/default/c347da17d2bb69a3fce99b2137fcdc2c6302c1e2 .generated_files/flags/default/e9ae422dacfdebe7003964861b5b2c920a0998be
	@${MKDIR} "${OBJECTDIR}/src/pwm-control" 
	@${RM} ${OBJECTDIR}/src/pwm-control/pwm-control.o.d 
	@${RM} ${OBJECTDIR}/src/pwm-control/pwm-control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm-control/pwm-control.c  -o ${OBJECTDIR}/src/pwm-control/pwm-control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm-control/pwm-control.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"include" -I"src" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/stepper-motor/stepper-motor.o: src/stepper-motor/stepper-motor.c  .generated_files/flags/default/17b613134abf85159f834ac3334f208369872d18 .generated_files/flags/default/e9ae422dacfdebe7003964861b5b2c920a0998be
	@${MKDIR} "${OBJECTDIR}/src/stepper-motor" 
	@${RM} ${OBJECTDIR}/src/stepper-motor/stepper-motor.o.d 
	@${RM} ${OBJECTDIR}/src/stepper-motor/stepper-motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/stepper-motor/stepper-motor.c  -o ${OBJECTDIR}/src/stepper-motor/stepper-motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/stepper-motor/stepper-motor.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"include" -I"src" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/8884ca486b25ebdbe79248e655bc09996fa77ba8 .generated_files/flags/default/e9ae422dacfdebe7003964861b5b2c920a0998be
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"include" -I"src" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/drive-control/drive-control.o: src/drive-control/drive-control.c  .generated_files/flags/default/cd38fd52179126f56c70c5abd9f61931c6b2ac83 .generated_files/flags/default/e9ae422dacfdebe7003964861b5b2c920a0998be
	@${MKDIR} "${OBJECTDIR}/src/drive-control" 
	@${RM} ${OBJECTDIR}/src/drive-control/drive-control.o.d 
	@${RM} ${OBJECTDIR}/src/drive-control/drive-control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/drive-control/drive-control.c  -o ${OBJECTDIR}/src/drive-control/drive-control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/drive-control/drive-control.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"include" -I"src" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/pwm-control/pwm-control.o: src/pwm-control/pwm-control.c  .generated_files/flags/default/a282707976a1750040be814b17e4b7b7cf57f7de .generated_files/flags/default/e9ae422dacfdebe7003964861b5b2c920a0998be
	@${MKDIR} "${OBJECTDIR}/src/pwm-control" 
	@${RM} ${OBJECTDIR}/src/pwm-control/pwm-control.o.d 
	@${RM} ${OBJECTDIR}/src/pwm-control/pwm-control.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/pwm-control/pwm-control.c  -o ${OBJECTDIR}/src/pwm-control/pwm-control.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/pwm-control/pwm-control.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"include" -I"src" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/stepper-motor/stepper-motor.o: src/stepper-motor/stepper-motor.c  .generated_files/flags/default/82f0c7afa7d6a91a2d5eeb52ea7334457d532a35 .generated_files/flags/default/e9ae422dacfdebe7003964861b5b2c920a0998be
	@${MKDIR} "${OBJECTDIR}/src/stepper-motor" 
	@${RM} ${OBJECTDIR}/src/stepper-motor/stepper-motor.o.d 
	@${RM} ${OBJECTDIR}/src/stepper-motor/stepper-motor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/stepper-motor/stepper-motor.c  -o ${OBJECTDIR}/src/stepper-motor/stepper-motor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/stepper-motor/stepper-motor.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -I"include" -I"src" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/stacey.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/stacey.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/stacey.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/stacey.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/stacey.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
