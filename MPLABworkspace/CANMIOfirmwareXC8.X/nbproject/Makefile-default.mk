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
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/CANMIOfirmwareXC8.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/CANMIOfirmwareXC8.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../github/CANMIOfirmware/actionQueue.c ../../github/CANMIOfirmware/analogue.c ../../github/CANMIOfirmware/bounce.c ../../github/CANMIOfirmware/digitalOut.c ../../github/CANMIOfirmware/hwsettings.c ../../github/CANMIOfirmware/inputs.c ../../github/CANMIOfirmware/main.c ../../github/CANMIOfirmware/mioEvents.c ../../github/CANMIOfirmware/mioFLiM.c ../../github/CANMIOfirmware/mioNv.c ../../github/CANMIOfirmware/nvCache.c ../../github/CANMIOfirmware/outputs.c ../../github/CANMIOfirmware/queue.c ../../github/CANMIOfirmware/servo.c ../../github/CBUSlib/c018.c ../../github/CBUSlib/can18.c ../../github/CBUSlib/cbus.c ../../github/CBUSlib/events.c ../../github/CBUSlib/FliM.c ../../github/CBUSlib/happeningsActions.c ../../github/CBUSlib/romops.c ../../github/CBUSlib/StatusLeds.c ../../github/CBUSlib/ticktime.c ../../github/CBUSlib/timedResponse.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/579903818/actionQueue.p1 ${OBJECTDIR}/_ext/579903818/analogue.p1 ${OBJECTDIR}/_ext/579903818/bounce.p1 ${OBJECTDIR}/_ext/579903818/digitalOut.p1 ${OBJECTDIR}/_ext/579903818/hwsettings.p1 ${OBJECTDIR}/_ext/579903818/inputs.p1 ${OBJECTDIR}/_ext/579903818/main.p1 ${OBJECTDIR}/_ext/579903818/mioEvents.p1 ${OBJECTDIR}/_ext/579903818/mioFLiM.p1 ${OBJECTDIR}/_ext/579903818/mioNv.p1 ${OBJECTDIR}/_ext/579903818/nvCache.p1 ${OBJECTDIR}/_ext/579903818/outputs.p1 ${OBJECTDIR}/_ext/579903818/queue.p1 ${OBJECTDIR}/_ext/579903818/servo.p1 ${OBJECTDIR}/_ext/1515116132/c018.p1 ${OBJECTDIR}/_ext/1515116132/can18.p1 ${OBJECTDIR}/_ext/1515116132/cbus.p1 ${OBJECTDIR}/_ext/1515116132/events.p1 ${OBJECTDIR}/_ext/1515116132/FliM.p1 ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1 ${OBJECTDIR}/_ext/1515116132/romops.p1 ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1 ${OBJECTDIR}/_ext/1515116132/ticktime.p1 ${OBJECTDIR}/_ext/1515116132/timedResponse.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/579903818/actionQueue.p1.d ${OBJECTDIR}/_ext/579903818/analogue.p1.d ${OBJECTDIR}/_ext/579903818/bounce.p1.d ${OBJECTDIR}/_ext/579903818/digitalOut.p1.d ${OBJECTDIR}/_ext/579903818/hwsettings.p1.d ${OBJECTDIR}/_ext/579903818/inputs.p1.d ${OBJECTDIR}/_ext/579903818/main.p1.d ${OBJECTDIR}/_ext/579903818/mioEvents.p1.d ${OBJECTDIR}/_ext/579903818/mioFLiM.p1.d ${OBJECTDIR}/_ext/579903818/mioNv.p1.d ${OBJECTDIR}/_ext/579903818/nvCache.p1.d ${OBJECTDIR}/_ext/579903818/outputs.p1.d ${OBJECTDIR}/_ext/579903818/queue.p1.d ${OBJECTDIR}/_ext/579903818/servo.p1.d ${OBJECTDIR}/_ext/1515116132/c018.p1.d ${OBJECTDIR}/_ext/1515116132/can18.p1.d ${OBJECTDIR}/_ext/1515116132/cbus.p1.d ${OBJECTDIR}/_ext/1515116132/events.p1.d ${OBJECTDIR}/_ext/1515116132/FliM.p1.d ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1.d ${OBJECTDIR}/_ext/1515116132/romops.p1.d ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1.d ${OBJECTDIR}/_ext/1515116132/ticktime.p1.d ${OBJECTDIR}/_ext/1515116132/timedResponse.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/579903818/actionQueue.p1 ${OBJECTDIR}/_ext/579903818/analogue.p1 ${OBJECTDIR}/_ext/579903818/bounce.p1 ${OBJECTDIR}/_ext/579903818/digitalOut.p1 ${OBJECTDIR}/_ext/579903818/hwsettings.p1 ${OBJECTDIR}/_ext/579903818/inputs.p1 ${OBJECTDIR}/_ext/579903818/main.p1 ${OBJECTDIR}/_ext/579903818/mioEvents.p1 ${OBJECTDIR}/_ext/579903818/mioFLiM.p1 ${OBJECTDIR}/_ext/579903818/mioNv.p1 ${OBJECTDIR}/_ext/579903818/nvCache.p1 ${OBJECTDIR}/_ext/579903818/outputs.p1 ${OBJECTDIR}/_ext/579903818/queue.p1 ${OBJECTDIR}/_ext/579903818/servo.p1 ${OBJECTDIR}/_ext/1515116132/c018.p1 ${OBJECTDIR}/_ext/1515116132/can18.p1 ${OBJECTDIR}/_ext/1515116132/cbus.p1 ${OBJECTDIR}/_ext/1515116132/events.p1 ${OBJECTDIR}/_ext/1515116132/FliM.p1 ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1 ${OBJECTDIR}/_ext/1515116132/romops.p1 ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1 ${OBJECTDIR}/_ext/1515116132/ticktime.p1 ${OBJECTDIR}/_ext/1515116132/timedResponse.p1

# Source Files
SOURCEFILES=../../github/CANMIOfirmware/actionQueue.c ../../github/CANMIOfirmware/analogue.c ../../github/CANMIOfirmware/bounce.c ../../github/CANMIOfirmware/digitalOut.c ../../github/CANMIOfirmware/hwsettings.c ../../github/CANMIOfirmware/inputs.c ../../github/CANMIOfirmware/main.c ../../github/CANMIOfirmware/mioEvents.c ../../github/CANMIOfirmware/mioFLiM.c ../../github/CANMIOfirmware/mioNv.c ../../github/CANMIOfirmware/nvCache.c ../../github/CANMIOfirmware/outputs.c ../../github/CANMIOfirmware/queue.c ../../github/CANMIOfirmware/servo.c ../../github/CBUSlib/c018.c ../../github/CBUSlib/can18.c ../../github/CBUSlib/cbus.c ../../github/CBUSlib/events.c ../../github/CBUSlib/FliM.c ../../github/CBUSlib/happeningsActions.c ../../github/CBUSlib/romops.c ../../github/CBUSlib/StatusLeds.c ../../github/CBUSlib/ticktime.c ../../github/CBUSlib/timedResponse.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/CANMIOfirmwareXC8.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F26K80
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/579903818/actionQueue.p1: ../../github/CANMIOfirmware/actionQueue.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/actionQueue.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/actionQueue.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/actionQueue.p1 ../../github/CANMIOfirmware/actionQueue.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/actionQueue.d ${OBJECTDIR}/_ext/579903818/actionQueue.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/actionQueue.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/analogue.p1: ../../github/CANMIOfirmware/analogue.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/analogue.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/analogue.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/analogue.p1 ../../github/CANMIOfirmware/analogue.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/analogue.d ${OBJECTDIR}/_ext/579903818/analogue.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/analogue.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/bounce.p1: ../../github/CANMIOfirmware/bounce.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/bounce.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/bounce.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/bounce.p1 ../../github/CANMIOfirmware/bounce.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/bounce.d ${OBJECTDIR}/_ext/579903818/bounce.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/bounce.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/digitalOut.p1: ../../github/CANMIOfirmware/digitalOut.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/digitalOut.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/digitalOut.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/digitalOut.p1 ../../github/CANMIOfirmware/digitalOut.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/digitalOut.d ${OBJECTDIR}/_ext/579903818/digitalOut.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/digitalOut.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/hwsettings.p1: ../../github/CANMIOfirmware/hwsettings.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/hwsettings.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/hwsettings.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/hwsettings.p1 ../../github/CANMIOfirmware/hwsettings.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/hwsettings.d ${OBJECTDIR}/_ext/579903818/hwsettings.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/hwsettings.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/inputs.p1: ../../github/CANMIOfirmware/inputs.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/inputs.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/inputs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/inputs.p1 ../../github/CANMIOfirmware/inputs.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/inputs.d ${OBJECTDIR}/_ext/579903818/inputs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/inputs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/main.p1: ../../github/CANMIOfirmware/main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/main.p1 ../../github/CANMIOfirmware/main.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/main.d ${OBJECTDIR}/_ext/579903818/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/mioEvents.p1: ../../github/CANMIOfirmware/mioEvents.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioEvents.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioEvents.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/mioEvents.p1 ../../github/CANMIOfirmware/mioEvents.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/mioEvents.d ${OBJECTDIR}/_ext/579903818/mioEvents.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/mioEvents.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/mioFLiM.p1: ../../github/CANMIOfirmware/mioFLiM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioFLiM.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioFLiM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/mioFLiM.p1 ../../github/CANMIOfirmware/mioFLiM.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/mioFLiM.d ${OBJECTDIR}/_ext/579903818/mioFLiM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/mioFLiM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/mioNv.p1: ../../github/CANMIOfirmware/mioNv.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioNv.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioNv.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/mioNv.p1 ../../github/CANMIOfirmware/mioNv.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/mioNv.d ${OBJECTDIR}/_ext/579903818/mioNv.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/mioNv.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/nvCache.p1: ../../github/CANMIOfirmware/nvCache.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/nvCache.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/nvCache.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/nvCache.p1 ../../github/CANMIOfirmware/nvCache.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/nvCache.d ${OBJECTDIR}/_ext/579903818/nvCache.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/nvCache.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/outputs.p1: ../../github/CANMIOfirmware/outputs.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/outputs.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/outputs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/outputs.p1 ../../github/CANMIOfirmware/outputs.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/outputs.d ${OBJECTDIR}/_ext/579903818/outputs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/outputs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/queue.p1: ../../github/CANMIOfirmware/queue.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/queue.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/queue.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/queue.p1 ../../github/CANMIOfirmware/queue.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/queue.d ${OBJECTDIR}/_ext/579903818/queue.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/queue.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/servo.p1: ../../github/CANMIOfirmware/servo.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/servo.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/servo.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/servo.p1 ../../github/CANMIOfirmware/servo.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/servo.d ${OBJECTDIR}/_ext/579903818/servo.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/servo.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/c018.p1: ../../github/CBUSlib/c018.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/c018.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/c018.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/c018.p1 ../../github/CBUSlib/c018.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/c018.d ${OBJECTDIR}/_ext/1515116132/c018.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/c018.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/can18.p1: ../../github/CBUSlib/can18.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/can18.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/can18.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/can18.p1 ../../github/CBUSlib/can18.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/can18.d ${OBJECTDIR}/_ext/1515116132/can18.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/can18.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/cbus.p1: ../../github/CBUSlib/cbus.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/cbus.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/cbus.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/cbus.p1 ../../github/CBUSlib/cbus.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/cbus.d ${OBJECTDIR}/_ext/1515116132/cbus.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/cbus.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/events.p1: ../../github/CBUSlib/events.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/events.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/events.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/events.p1 ../../github/CBUSlib/events.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/events.d ${OBJECTDIR}/_ext/1515116132/events.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/events.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/FliM.p1: ../../github/CBUSlib/FliM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/FliM.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/FliM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/FliM.p1 ../../github/CBUSlib/FliM.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/FliM.d ${OBJECTDIR}/_ext/1515116132/FliM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/FliM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/happeningsActions.p1: ../../github/CBUSlib/happeningsActions.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1 ../../github/CBUSlib/happeningsActions.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/happeningsActions.d ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/romops.p1: ../../github/CBUSlib/romops.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/romops.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/romops.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/romops.p1 ../../github/CBUSlib/romops.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/romops.d ${OBJECTDIR}/_ext/1515116132/romops.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/romops.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/StatusLeds.p1: ../../github/CBUSlib/StatusLeds.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1 ../../github/CBUSlib/StatusLeds.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/StatusLeds.d ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/ticktime.p1: ../../github/CBUSlib/ticktime.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/ticktime.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/ticktime.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/ticktime.p1 ../../github/CBUSlib/ticktime.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/ticktime.d ${OBJECTDIR}/_ext/1515116132/ticktime.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/ticktime.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/timedResponse.p1: ../../github/CBUSlib/timedResponse.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/timedResponse.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/timedResponse.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=pickit3   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/timedResponse.p1 ../../github/CBUSlib/timedResponse.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/timedResponse.d ${OBJECTDIR}/_ext/1515116132/timedResponse.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/timedResponse.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/579903818/actionQueue.p1: ../../github/CANMIOfirmware/actionQueue.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/actionQueue.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/actionQueue.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/actionQueue.p1 ../../github/CANMIOfirmware/actionQueue.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/actionQueue.d ${OBJECTDIR}/_ext/579903818/actionQueue.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/actionQueue.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/analogue.p1: ../../github/CANMIOfirmware/analogue.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/analogue.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/analogue.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/analogue.p1 ../../github/CANMIOfirmware/analogue.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/analogue.d ${OBJECTDIR}/_ext/579903818/analogue.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/analogue.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/bounce.p1: ../../github/CANMIOfirmware/bounce.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/bounce.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/bounce.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/bounce.p1 ../../github/CANMIOfirmware/bounce.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/bounce.d ${OBJECTDIR}/_ext/579903818/bounce.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/bounce.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/digitalOut.p1: ../../github/CANMIOfirmware/digitalOut.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/digitalOut.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/digitalOut.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/digitalOut.p1 ../../github/CANMIOfirmware/digitalOut.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/digitalOut.d ${OBJECTDIR}/_ext/579903818/digitalOut.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/digitalOut.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/hwsettings.p1: ../../github/CANMIOfirmware/hwsettings.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/hwsettings.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/hwsettings.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/hwsettings.p1 ../../github/CANMIOfirmware/hwsettings.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/hwsettings.d ${OBJECTDIR}/_ext/579903818/hwsettings.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/hwsettings.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/inputs.p1: ../../github/CANMIOfirmware/inputs.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/inputs.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/inputs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/inputs.p1 ../../github/CANMIOfirmware/inputs.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/inputs.d ${OBJECTDIR}/_ext/579903818/inputs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/inputs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/main.p1: ../../github/CANMIOfirmware/main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/main.p1 ../../github/CANMIOfirmware/main.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/main.d ${OBJECTDIR}/_ext/579903818/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/mioEvents.p1: ../../github/CANMIOfirmware/mioEvents.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioEvents.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioEvents.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/mioEvents.p1 ../../github/CANMIOfirmware/mioEvents.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/mioEvents.d ${OBJECTDIR}/_ext/579903818/mioEvents.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/mioEvents.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/mioFLiM.p1: ../../github/CANMIOfirmware/mioFLiM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioFLiM.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioFLiM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/mioFLiM.p1 ../../github/CANMIOfirmware/mioFLiM.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/mioFLiM.d ${OBJECTDIR}/_ext/579903818/mioFLiM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/mioFLiM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/mioNv.p1: ../../github/CANMIOfirmware/mioNv.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioNv.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/mioNv.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/mioNv.p1 ../../github/CANMIOfirmware/mioNv.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/mioNv.d ${OBJECTDIR}/_ext/579903818/mioNv.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/mioNv.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/nvCache.p1: ../../github/CANMIOfirmware/nvCache.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/nvCache.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/nvCache.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/nvCache.p1 ../../github/CANMIOfirmware/nvCache.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/nvCache.d ${OBJECTDIR}/_ext/579903818/nvCache.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/nvCache.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/outputs.p1: ../../github/CANMIOfirmware/outputs.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/outputs.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/outputs.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/outputs.p1 ../../github/CANMIOfirmware/outputs.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/outputs.d ${OBJECTDIR}/_ext/579903818/outputs.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/outputs.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/queue.p1: ../../github/CANMIOfirmware/queue.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/queue.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/queue.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/queue.p1 ../../github/CANMIOfirmware/queue.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/queue.d ${OBJECTDIR}/_ext/579903818/queue.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/queue.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/579903818/servo.p1: ../../github/CANMIOfirmware/servo.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/579903818" 
	@${RM} ${OBJECTDIR}/_ext/579903818/servo.p1.d 
	@${RM} ${OBJECTDIR}/_ext/579903818/servo.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/579903818/servo.p1 ../../github/CANMIOfirmware/servo.c 
	@-${MV} ${OBJECTDIR}/_ext/579903818/servo.d ${OBJECTDIR}/_ext/579903818/servo.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/579903818/servo.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/c018.p1: ../../github/CBUSlib/c018.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/c018.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/c018.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/c018.p1 ../../github/CBUSlib/c018.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/c018.d ${OBJECTDIR}/_ext/1515116132/c018.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/c018.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/can18.p1: ../../github/CBUSlib/can18.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/can18.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/can18.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/can18.p1 ../../github/CBUSlib/can18.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/can18.d ${OBJECTDIR}/_ext/1515116132/can18.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/can18.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/cbus.p1: ../../github/CBUSlib/cbus.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/cbus.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/cbus.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/cbus.p1 ../../github/CBUSlib/cbus.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/cbus.d ${OBJECTDIR}/_ext/1515116132/cbus.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/cbus.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/events.p1: ../../github/CBUSlib/events.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/events.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/events.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/events.p1 ../../github/CBUSlib/events.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/events.d ${OBJECTDIR}/_ext/1515116132/events.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/events.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/FliM.p1: ../../github/CBUSlib/FliM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/FliM.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/FliM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/FliM.p1 ../../github/CBUSlib/FliM.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/FliM.d ${OBJECTDIR}/_ext/1515116132/FliM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/FliM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/happeningsActions.p1: ../../github/CBUSlib/happeningsActions.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1 ../../github/CBUSlib/happeningsActions.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/happeningsActions.d ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/happeningsActions.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/romops.p1: ../../github/CBUSlib/romops.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/romops.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/romops.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/romops.p1 ../../github/CBUSlib/romops.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/romops.d ${OBJECTDIR}/_ext/1515116132/romops.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/romops.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/StatusLeds.p1: ../../github/CBUSlib/StatusLeds.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1 ../../github/CBUSlib/StatusLeds.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/StatusLeds.d ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/StatusLeds.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/ticktime.p1: ../../github/CBUSlib/ticktime.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/ticktime.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/ticktime.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/ticktime.p1 ../../github/CBUSlib/ticktime.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/ticktime.d ${OBJECTDIR}/_ext/1515116132/ticktime.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/ticktime.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1515116132/timedResponse.p1: ../../github/CBUSlib/timedResponse.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1515116132" 
	@${RM} ${OBJECTDIR}/_ext/1515116132/timedResponse.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1515116132/timedResponse.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto -mcodeoffset=0x840     -o ${OBJECTDIR}/_ext/1515116132/timedResponse.p1 ../../github/CBUSlib/timedResponse.c 
	@-${MV} ${OBJECTDIR}/_ext/1515116132/timedResponse.d ${OBJECTDIR}/_ext/1515116132/timedResponse.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1515116132/timedResponse.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/CANMIOfirmwareXC8.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/CANMIOfirmwareXC8.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=pickit3  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits -mcodeoffset=0x840 -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/CANMIOfirmwareXC8.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/CANMIOfirmwareXC8.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/CANMIOfirmwareXC8.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../CBUS_PIC_Bootloader.X/dist/default/production/CBUS_PIC_Bootloader.X.production.hex
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/CANMIOfirmwareXC8.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -memi=wordwrite -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp -I"../../" -I"../../github/CANMIOfirmware" -I"../../github/CBUSlib" -I"../../github/cbusdefs" -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mkeep-startup -mno-download -mdefault-config-bits -mcodeoffset=0x840 -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/CANMIOfirmwareXC8.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	@echo "Creating unified hex file"
	@"C:/Program Files/Microchip/MPLABX/v6.00/mplab_platform/platform/../mplab_ide/modules/../../bin/hexmate" --edf="C:/Program Files/Microchip/MPLABX/v6.00/mplab_platform/platform/../mplab_ide/modules/../../dat/en_msgs.txt" ${DISTDIR}/CANMIOfirmwareXC8.X.${IMAGE_TYPE}.hex ../CBUS_PIC_Bootloader.X/dist/default/production/CBUS_PIC_Bootloader.X.production.hex -odist/${CND_CONF}/production/CANMIOfirmwareXC8.X.production.unified.hex

endif


# Subprojects
.build-subprojects:
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
	cd ../CBUS_PIC_Bootloader.X && ${MAKE}  -f Makefile CONF=default TYPE_IMAGE=DEBUG_RUN
else
	cd ../CBUS_PIC_Bootloader.X && ${MAKE}  -f Makefile CONF=default
endif


# Subprojects
.clean-subprojects:
	cd ../CBUS_PIC_Bootloader.X && rm -rf "build/default" "dist/default"

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
