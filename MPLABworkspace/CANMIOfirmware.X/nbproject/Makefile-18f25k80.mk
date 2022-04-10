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
ifeq "$(wildcard nbproject/Makefile-local-18f25k80.mk)" "nbproject/Makefile-local-18f25k80.mk"
include nbproject/Makefile-local-18f25k80.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=18f25k80
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/CANMIOfirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/CANMIOfirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../github/CANMIOfirmware/actionQueue.c ../../github/CANMIOfirmware/bounce.c ../../github/CANMIOfirmware/digitalOut.c ../../github/CANMIOfirmware/inputs.c ../../github/CANMIOfirmware/main.c ../../github/CANMIOfirmware/mioEvents.c ../../github/CANMIOfirmware/mioFLiM.c ../../github/CANMIOfirmware/mioNv.c ../../github/CANMIOfirmware/outputs.c ../../github/CANMIOfirmware/servo.c ../../github/CANMIOfirmware/nvCache.c ../../github/CANMIOfirmware/hwsettings.c ../../github/CANMIOfirmware/analogue.c ../../github/CANMIOfirmware/queue.c ../../github/CBUSlib/can18.c ../../github/CBUSlib/cbus.c ../../github/CBUSlib/events.c ../../github/CBUSlib/FliM.c ../../github/CBUSlib/romops.c ../../github/CBUSlib/StatusLeds.c ../../github/CBUSlib/ticktime.c ../../github/CBUSlib/c018.c ../../github/CBUSlib/Bootloader.asm

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/579903818/actionQueue.o ${OBJECTDIR}/_ext/579903818/bounce.o ${OBJECTDIR}/_ext/579903818/digitalOut.o ${OBJECTDIR}/_ext/579903818/inputs.o ${OBJECTDIR}/_ext/579903818/main.o ${OBJECTDIR}/_ext/579903818/mioEvents.o ${OBJECTDIR}/_ext/579903818/mioFLiM.o ${OBJECTDIR}/_ext/579903818/mioNv.o ${OBJECTDIR}/_ext/579903818/outputs.o ${OBJECTDIR}/_ext/579903818/servo.o ${OBJECTDIR}/_ext/579903818/nvCache.o ${OBJECTDIR}/_ext/579903818/hwsettings.o ${OBJECTDIR}/_ext/579903818/analogue.o ${OBJECTDIR}/_ext/579903818/queue.o ${OBJECTDIR}/_ext/1515116132/can18.o ${OBJECTDIR}/_ext/1515116132/cbus.o ${OBJECTDIR}/_ext/1515116132/events.o ${OBJECTDIR}/_ext/1515116132/FliM.o ${OBJECTDIR}/_ext/1515116132/romops.o ${OBJECTDIR}/_ext/1515116132/StatusLeds.o ${OBJECTDIR}/_ext/1515116132/ticktime.o ${OBJECTDIR}/_ext/1515116132/c018.o ${OBJECTDIR}/_ext/1515116132/Bootloader.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/579903818/actionQueue.o.d ${OBJECTDIR}/_ext/579903818/bounce.o.d ${OBJECTDIR}/_ext/579903818/digitalOut.o.d ${OBJECTDIR}/_ext/579903818/inputs.o.d ${OBJECTDIR}/_ext/579903818/main.o.d ${OBJECTDIR}/_ext/579903818/mioEvents.o.d ${OBJECTDIR}/_ext/579903818/mioFLiM.o.d ${OBJECTDIR}/_ext/579903818/mioNv.o.d ${OBJECTDIR}/_ext/579903818/outputs.o.d ${OBJECTDIR}/_ext/579903818/servo.o.d ${OBJECTDIR}/_ext/579903818/nvCache.o.d ${OBJECTDIR}/_ext/579903818/hwsettings.o.d ${OBJECTDIR}/_ext/579903818/analogue.o.d ${OBJECTDIR}/_ext/579903818/queue.o.d ${OBJECTDIR}/_ext/1515116132/can18.o.d ${OBJECTDIR}/_ext/1515116132/cbus.o.d ${OBJECTDIR}/_ext/1515116132/events.o.d ${OBJECTDIR}/_ext/1515116132/FliM.o.d ${OBJECTDIR}/_ext/1515116132/romops.o.d ${OBJECTDIR}/_ext/1515116132/StatusLeds.o.d ${OBJECTDIR}/_ext/1515116132/ticktime.o.d ${OBJECTDIR}/_ext/1515116132/c018.o.d ${OBJECTDIR}/_ext/1515116132/Bootloader.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/579903818/actionQueue.o ${OBJECTDIR}/_ext/579903818/bounce.o ${OBJECTDIR}/_ext/579903818/digitalOut.o ${OBJECTDIR}/_ext/579903818/inputs.o ${OBJECTDIR}/_ext/579903818/main.o ${OBJECTDIR}/_ext/579903818/mioEvents.o ${OBJECTDIR}/_ext/579903818/mioFLiM.o ${OBJECTDIR}/_ext/579903818/mioNv.o ${OBJECTDIR}/_ext/579903818/outputs.o ${OBJECTDIR}/_ext/579903818/servo.o ${OBJECTDIR}/_ext/579903818/nvCache.o ${OBJECTDIR}/_ext/579903818/hwsettings.o ${OBJECTDIR}/_ext/579903818/analogue.o ${OBJECTDIR}/_ext/579903818/queue.o ${OBJECTDIR}/_ext/1515116132/can18.o ${OBJECTDIR}/_ext/1515116132/cbus.o ${OBJECTDIR}/_ext/1515116132/events.o ${OBJECTDIR}/_ext/1515116132/FliM.o ${OBJECTDIR}/_ext/1515116132/romops.o ${OBJECTDIR}/_ext/1515116132/StatusLeds.o ${OBJECTDIR}/_ext/1515116132/ticktime.o ${OBJECTDIR}/_ext/1515116132/c018.o ${OBJECTDIR}/_ext/1515116132/Bootloader.o

# Source Files
SOURCEFILES=../../github/CANMIOfirmware/actionQueue.c ../../github/CANMIOfirmware/bounce.c ../../github/CANMIOfirmware/digitalOut.c ../../github/CANMIOfirmware/inputs.c ../../github/CANMIOfirmware/main.c ../../github/CANMIOfirmware/mioEvents.c ../../github/CANMIOfirmware/mioFLiM.c ../../github/CANMIOfirmware/mioNv.c ../../github/CANMIOfirmware/outputs.c ../../github/CANMIOfirmware/servo.c ../../github/CANMIOfirmware/nvCache.c ../../github/CANMIOfirmware/hwsettings.c ../../github/CANMIOfirmware/analogue.c ../../github/CANMIOfirmware/queue.c ../../github/CBUSlib/can18.c ../../github/CBUSlib/cbus.c ../../github/CBUSlib/events.c ../../github/CBUSlib/FliM.c ../../github/CBUSlib/romops.c ../../github/CBUSlib/StatusLeds.c ../../github/CBUSlib/ticktime.c ../../github/CBUSlib/c018.c ../../github/CBUSlib/Bootloader.asm


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
	${MAKE}  -f nbproject/Makefile-18f25k80.mk dist/${CND_CONF}/${IMAGE_TYPE}/CANMIOfirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F25K80
MP_PROCESSOR_OPTION_LD=18f25k80
MP_LINKER_DEBUG_OPTION=  -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1515116132/Bootloader.o: ../../github/CBUSlib/Bootloader.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/Bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/Bootloader.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/_ext/1515116132/Bootloader.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION)  -l\"${OBJECTDIR}/_ext/1515116132/Bootloader.lst\" -e\"${OBJECTDIR}/_ext/1515116132/Bootloader.err\" $(ASM_OPTIONS)  -o\"${OBJECTDIR}/_ext/1515116132/Bootloader.o\" \"../../github/CBUSlib/Bootloader.asm\"
	@${DEP_GEN} -d "${OBJECTDIR}/_ext/1515116132/Bootloader.o"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/Bootloader.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1515116132/Bootloader.o: ../../github/CBUSlib/Bootloader.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/Bootloader.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/Bootloader.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/_ext/1515116132/Bootloader.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION)  -l\"${OBJECTDIR}/_ext/1515116132/Bootloader.lst\" -e\"${OBJECTDIR}/_ext/1515116132/Bootloader.err\" $(ASM_OPTIONS)  -o\"${OBJECTDIR}/_ext/1515116132/Bootloader.o\" \"../../github/CBUSlib/Bootloader.asm\"
	@${DEP_GEN} -d "${OBJECTDIR}/_ext/1515116132/Bootloader.o"
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/Bootloader.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/579903818/actionQueue.o: ../../github/CANMIOfirmware/actionQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/actionQueue.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/actionQueue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/actionQueue.o   ../../github/CANMIOfirmware/actionQueue.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/actionQueue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/actionQueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/bounce.o: ../../github/CANMIOfirmware/bounce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/bounce.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/bounce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/bounce.o   ../../github/CANMIOfirmware/bounce.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/bounce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/bounce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/digitalOut.o: ../../github/CANMIOfirmware/digitalOut.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/digitalOut.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/digitalOut.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/digitalOut.o   ../../github/CANMIOfirmware/digitalOut.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/digitalOut.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/digitalOut.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/inputs.o: ../../github/CANMIOfirmware/inputs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/inputs.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/inputs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/inputs.o   ../../github/CANMIOfirmware/inputs.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/inputs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/inputs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/main.o: ../../github/CANMIOfirmware/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/main.o   ../../github/CANMIOfirmware/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/mioEvents.o: ../../github/CANMIOfirmware/mioEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioEvents.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/mioEvents.o   ../../github/CANMIOfirmware/mioEvents.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/mioEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/mioEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/mioFLiM.o: ../../github/CANMIOfirmware/mioFLiM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioFLiM.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioFLiM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/mioFLiM.o   ../../github/CANMIOfirmware/mioFLiM.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/mioFLiM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/mioFLiM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/mioNv.o: ../../github/CANMIOfirmware/mioNv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioNv.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioNv.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/mioNv.o   ../../github/CANMIOfirmware/mioNv.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/mioNv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/mioNv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/outputs.o: ../../github/CANMIOfirmware/outputs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/outputs.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/outputs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/outputs.o   ../../github/CANMIOfirmware/outputs.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/outputs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/outputs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/servo.o: ../../github/CANMIOfirmware/servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/servo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/servo.o   ../../github/CANMIOfirmware/servo.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/servo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/nvCache.o: ../../github/CANMIOfirmware/nvCache.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/nvCache.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/nvCache.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/nvCache.o   ../../github/CANMIOfirmware/nvCache.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/nvCache.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/nvCache.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/hwsettings.o: ../../github/CANMIOfirmware/hwsettings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/hwsettings.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/hwsettings.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/hwsettings.o   ../../github/CANMIOfirmware/hwsettings.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/hwsettings.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/hwsettings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/analogue.o: ../../github/CANMIOfirmware/analogue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/analogue.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/analogue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/analogue.o   ../../github/CANMIOfirmware/analogue.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/analogue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/analogue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/queue.o: ../../github/CANMIOfirmware/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/queue.o   ../../github/CANMIOfirmware/queue.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/can18.o: ../../github/CBUSlib/can18.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/can18.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/can18.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/can18.o   ../../github/CBUSlib/can18.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/can18.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/can18.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/cbus.o: ../../github/CBUSlib/cbus.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/cbus.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/cbus.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/cbus.o   ../../github/CBUSlib/cbus.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/cbus.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/cbus.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/events.o: ../../github/CBUSlib/events.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/events.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/events.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/events.o   ../../github/CBUSlib/events.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/events.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/events.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/FliM.o: ../../github/CBUSlib/FliM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/FliM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/FliM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/FliM.o   ../../github/CBUSlib/FliM.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/FliM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/FliM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/romops.o: ../../github/CBUSlib/romops.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/romops.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/romops.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/romops.o   ../../github/CBUSlib/romops.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/romops.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/romops.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/StatusLeds.o: ../../github/CBUSlib/StatusLeds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/StatusLeds.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/StatusLeds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/StatusLeds.o   ../../github/CBUSlib/StatusLeds.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/StatusLeds.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/StatusLeds.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/ticktime.o: ../../github/CBUSlib/ticktime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/ticktime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/ticktime.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/ticktime.o   ../../github/CBUSlib/ticktime.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/ticktime.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/ticktime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/c018.o: ../../github/CBUSlib/c018.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/c018.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/c018.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/c018.o   ../../github/CBUSlib/c018.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/c018.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/c018.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/579903818/actionQueue.o: ../../github/CANMIOfirmware/actionQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/actionQueue.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/actionQueue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/actionQueue.o   ../../github/CANMIOfirmware/actionQueue.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/actionQueue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/actionQueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/bounce.o: ../../github/CANMIOfirmware/bounce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/bounce.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/bounce.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/bounce.o   ../../github/CANMIOfirmware/bounce.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/bounce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/bounce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/digitalOut.o: ../../github/CANMIOfirmware/digitalOut.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/digitalOut.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/digitalOut.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/digitalOut.o   ../../github/CANMIOfirmware/digitalOut.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/digitalOut.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/digitalOut.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/inputs.o: ../../github/CANMIOfirmware/inputs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/inputs.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/inputs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/inputs.o   ../../github/CANMIOfirmware/inputs.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/inputs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/inputs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/main.o: ../../github/CANMIOfirmware/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/main.o   ../../github/CANMIOfirmware/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/mioEvents.o: ../../github/CANMIOfirmware/mioEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioEvents.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/mioEvents.o   ../../github/CANMIOfirmware/mioEvents.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/mioEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/mioEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/mioFLiM.o: ../../github/CANMIOfirmware/mioFLiM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioFLiM.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioFLiM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/mioFLiM.o   ../../github/CANMIOfirmware/mioFLiM.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/mioFLiM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/mioFLiM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/mioNv.o: ../../github/CANMIOfirmware/mioNv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioNv.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioNv.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/mioNv.o   ../../github/CANMIOfirmware/mioNv.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/mioNv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/mioNv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/outputs.o: ../../github/CANMIOfirmware/outputs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/outputs.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/outputs.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/outputs.o   ../../github/CANMIOfirmware/outputs.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/outputs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/outputs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/servo.o: ../../github/CANMIOfirmware/servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/servo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/servo.o   ../../github/CANMIOfirmware/servo.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/servo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/nvCache.o: ../../github/CANMIOfirmware/nvCache.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/nvCache.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/nvCache.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/nvCache.o   ../../github/CANMIOfirmware/nvCache.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/nvCache.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/nvCache.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/hwsettings.o: ../../github/CANMIOfirmware/hwsettings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/hwsettings.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/hwsettings.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/hwsettings.o   ../../github/CANMIOfirmware/hwsettings.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/hwsettings.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/hwsettings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/analogue.o: ../../github/CANMIOfirmware/analogue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/analogue.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/analogue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/analogue.o   ../../github/CANMIOfirmware/analogue.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/analogue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/analogue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/579903818/queue.o: ../../github/CANMIOfirmware/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/queue.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/579903818/queue.o   ../../github/CANMIOfirmware/queue.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/579903818/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/579903818/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/can18.o: ../../github/CBUSlib/can18.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/can18.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/can18.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/can18.o   ../../github/CBUSlib/can18.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/can18.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/can18.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/cbus.o: ../../github/CBUSlib/cbus.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/cbus.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/cbus.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/cbus.o   ../../github/CBUSlib/cbus.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/cbus.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/cbus.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/events.o: ../../github/CBUSlib/events.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/events.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/events.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/events.o   ../../github/CBUSlib/events.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/events.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/events.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/FliM.o: ../../github/CBUSlib/FliM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/FliM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/FliM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/FliM.o   ../../github/CBUSlib/FliM.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/FliM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/FliM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/romops.o: ../../github/CBUSlib/romops.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/romops.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/romops.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/romops.o   ../../github/CBUSlib/romops.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/romops.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/romops.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/StatusLeds.o: ../../github/CBUSlib/StatusLeds.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/StatusLeds.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/StatusLeds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/StatusLeds.o   ../../github/CBUSlib/StatusLeds.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/StatusLeds.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/StatusLeds.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/ticktime.o: ../../github/CBUSlib/ticktime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/ticktime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/ticktime.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/ticktime.o   ../../github/CBUSlib/ticktime.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/ticktime.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/ticktime.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1515116132/c018.o: ../../github/CBUSlib/c018.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/c018.o.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/c018.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"../../github/CBUSlib" -I"../../github/CANMIOfirmware" -I"../../github/cbusdefs" -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1515116132/c018.o   ../../github/CBUSlib/c018.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1515116132/c018.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1515116132/c018.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/CANMIOfirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../../github/CANMIOfirmware/18f25k80_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "..\..\github\CANMIOfirmware\18f25k80_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_SIMULATOR=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/CANMIOfirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/CANMIOfirmware.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../../github/CANMIOfirmware/18f25k80_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "..\..\github\CANMIOfirmware\18f25k80_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/CANMIOfirmware.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/18f25k80
	${RM} -r dist/18f25k80

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
