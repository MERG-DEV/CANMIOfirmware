
	; Microchip MPLAB XC8 C Compiler V2.36
	; Copyright (C) 2022 Microchip Technology Inc.

	; Auto-generated runtime startup code for final link stage.

	;
	; Compiler options:
	;
	; -q --opt=none --chip=18f26k80 \
	; -Mdist/default/production/CANMIOfirmwareXC8.X.production.map \
	; -DXPRJ_default=default -L--defsym=__MPLAB_BUILD=1 \
	; --dfp=C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18F-K_DFP/1.5.114/xc8 \
	; --double=24 --float=24 --emi=wordwrite --opt=+2 --opt=+asmfile \
	; --addrqual=ignore -P -I../../ -I../../github/CANMIOfirmware \
	; -I../../github/CBUSlib -I../../github/cbusdefs --warn=-3 --asmlist \
	; --summary=-psect,-class,+mem,-hex,-file --output=+inhx32 \
	; --runtime=+clear --runtime=+init --runtime=+keep --runtime=-download \
	; --runtime=+config --codeoffset=0x840 --std=c90 \
	; --output=+elf:multilocs --stack=compiled:auto:auto:auto \
	; --summary=+xml --summarydir=dist/default/production/memoryfile.xml \
	; -oCANMIOfirmwareXC8.X.production.elf --objdir=dist/default/production \
	; --outdir=dist/default/production \
	; build/default/production/_ext/579903818/actionQueue.p1 \
	; build/default/production/_ext/579903818/analogue.p1 \
	; build/default/production/_ext/579903818/bounce.p1 \
	; build/default/production/_ext/579903818/digitalOut.p1 \
	; build/default/production/_ext/579903818/hwsettings.p1 \
	; build/default/production/_ext/579903818/inputs.p1 \
	; build/default/production/_ext/579903818/main.p1 \
	; build/default/production/_ext/579903818/mioEvents.p1 \
	; build/default/production/_ext/579903818/mioFLiM.p1 \
	; build/default/production/_ext/579903818/mioNv.p1 \
	; build/default/production/_ext/579903818/nvCache.p1 \
	; build/default/production/_ext/579903818/outputs.p1 \
	; build/default/production/_ext/579903818/queue.p1 \
	; build/default/production/_ext/579903818/servo.p1 \
	; build/default/production/_ext/1515116132/c018.p1 \
	; build/default/production/_ext/1515116132/can18.p1 \
	; build/default/production/_ext/1515116132/cbus.p1 \
	; build/default/production/_ext/1515116132/events.p1 \
	; build/default/production/_ext/1515116132/FliM.p1 \
	; build/default/production/_ext/1515116132/happeningsActions.p1 \
	; build/default/production/_ext/1515116132/romops.p1 \
	; build/default/production/_ext/1515116132/StatusLeds.p1 \
	; build/default/production/_ext/1515116132/ticktime.p1 \
	; build/default/production/_ext/1515116132/timedResponse.p1 \
	; --callgraph=none --errformat=%f:%l:%c: error: (%n) %s \
	; --warnformat=%f:%l:%c: warning: (%n) %s \
	; --msgformat=%f:%l:%c: advisory: (%n) %s
	;


	processor	18F26K80
	include "C:/Program Files/Microchip/MPLABX/v6.00/packs/Microchip/PIC18F-K_DFP/1.5.114/xc8\pic\include\proc\18f26k80.cgen.inc"

	GLOBAL	_main,start
	FNROOT	_main

	pic18cxx	equ	1

	psect	const,class=CONST,delta=1,reloc=2,noexec
	psect	smallconst,class=SMALLCONST,delta=1,reloc=2,noexec
	psect	mediumconst,class=MEDIUMCONST,delta=1,reloc=2,noexec
	psect	rbss,class=COMRAM,space=1,noexec
	psect	bss,class=RAM,space=1,noexec
	psect	rdata,class=COMRAM,space=1,noexec
	psect	irdata,class=CODE,space=0,reloc=2,noexec
	psect	bss,class=RAM,space=1,noexec
	psect	data,class=RAM,space=1,noexec
	psect	idata,class=CODE,space=0,reloc=2,noexec
	psect	nvrram,class=COMRAM,space=1,noexec
	psect	nvbit,class=COMRAM,bit,space=1,noexec
	psect	temp,ovrld,class=COMRAM,space=1,noexec
	psect	struct,ovrld,class=COMRAM,space=1,noexec
	psect	rbit,class=COMRAM,bit,space=1,noexec
	psect	bigbss,class=BIGRAM,space=1,noexec
	psect	bigdata,class=BIGRAM,space=1,noexec
	psect	ibigdata,class=CODE,space=0,reloc=2,noexec
	psect	farbss,class=FARRAM,space=0,reloc=2,delta=1,noexec
	psect	nvFARRAM,class=FARRAM,space=0,reloc=2,delta=1,noexec
	psect	fardata,class=FARRAM,space=0,reloc=2,delta=1,noexec
	psect	ifardata,class=CODE,space=0,reloc=2,delta=1,noexec

	psect	reset_vec,class=CODE,delta=1,reloc=2
	psect	powerup,class=CODE,delta=1,reloc=2
	psect	init,class=CODE,delta=1,reloc=2
	psect	text,class=CODE,delta=1,reloc=2
GLOBAL	intlevel0,intlevel1,intlevel2
intlevel0:
intlevel1:
intlevel2:
GLOBAL	intlevel3
intlevel3:
	psect	clrtext,class=CODE,delta=1,reloc=2

	psect	config,class=CONFIG,delta=1,space=4,noexec
	psect	idloc,class=IDLOC,delta=1,space=5,noexec
	psect	intcode,class=CODE,delta=1,reloc=2
	psect	intcode_body,class=CODE,delta=1,reloc=2
	psect	intcodelo,class=CODE,delta=1,reloc=2
	psect	intret,class=CODE,delta=1,reloc=2
	psect	intentry,class=CODE,delta=1,reloc=2
	psect	intsave_regs,class=BIGRAM,space=1

	psect	eeprom_data,class=EEDATA,delta=1,noexec
	psect	smallconst
	GLOBAL	__smallconst
__smallconst:
	psect	mediumconst
	GLOBAL	__mediumconst
__mediumconst:
	PSECT	ramtop,class=RAM,noexec
	GLOBAL	__S1			; top of RAM usage
	GLOBAL	__ramtop
	GLOBAL	__LRAM,__HRAM
__ramtop:

	psect	reset_vec
reset_vec:
	; No powerup routine
	global start

; jump to start
	goto start
	GLOBAL __accesstop
__accesstop EQU 96

;Initialize the stack pointer (FSR1)
	global stacklo, stackhi
	stacklo	equ	0
	stackhi	equ	0


	psect	stack,class=STACK,space=2,noexec
	global ___sp,___inthi_sp,___intlo_sp
___sp:
___inthi_sp:
___intlo_sp:

; No heap to be allocated
	psect	heap,class=HEAP,space=7,noexec
	global ___heap_lo
	___heap_lo	equ	0
	global ___heap_hi
	___heap_hi	equ	0



	psect	init
start:
	global start_initialization
	goto start_initialization	;jump to C runtime clear & initialization

psect comram,class=COMRAM,space=1
psect abs1,class=ABS1,space=1
psect bigram,class=BIGRAM,space=1
psect ram,class=RAM,space=1
psect bank0,class=BANK0,space=1
psect bank1,class=BANK1,space=1
psect bank2,class=BANK2,space=1
psect bank3,class=BANK3,space=1
psect bank4,class=BANK4,space=1
psect bank5,class=BANK5,space=1
psect bank6,class=BANK6,space=1
psect bank7,class=BANK7,space=1
psect bank8,class=BANK8,space=1
psect bank9,class=BANK9,space=1
psect bank10,class=BANK10,space=1
psect bank11,class=BANK11,space=1
psect bank12,class=BANK12,space=1
psect bank13,class=BANK13,space=1
psect bank14,class=BANK14,space=1
psect sfr,class=SFR,space=1
psect bigsfr,class=BIGSFR,space=1


	end	start
