#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW_Qt-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/a7e6eb5c/AsyncIO.o \
	${OBJECTDIR}/_ext/a7e6eb5c/AsyncIOSerial.o \
	${OBJECTDIR}/_ext/a7e6eb5c/AsyncIOSocket.o \
	${OBJECTDIR}/_ext/a7e6eb5c/PosixMessageQueueIPC.o \
	${OBJECTDIR}/_ext/b1099c6d/BlockQ.o \
	${OBJECTDIR}/_ext/b1099c6d/PollQ.o \
	${OBJECTDIR}/_ext/b1099c6d/death.o \
	${OBJECTDIR}/_ext/b1099c6d/dynamic.o \
	${OBJECTDIR}/_ext/b1099c6d/events.o \
	${OBJECTDIR}/_ext/b1099c6d/flash.o \
	${OBJECTDIR}/_ext/b1099c6d/flop.o \
	${OBJECTDIR}/_ext/b1099c6d/integer.o \
	${OBJECTDIR}/_ext/b1099c6d/print.o \
	${OBJECTDIR}/_ext/b1099c6d/semtest.o \
	${OBJECTDIR}/_ext/6b605f03/GenQTest.o \
	${OBJECTDIR}/_ext/6b605f03/QPeek.o \
	${OBJECTDIR}/_ext/6b605f03/blocktim.o \
	${OBJECTDIR}/_ext/6b605f03/countsem.o \
	${OBJECTDIR}/_ext/6b605f03/crflash.o \
	${OBJECTDIR}/_ext/6b605f03/crhook.o \
	${OBJECTDIR}/_ext/6b605f03/recmutex.o \
	${OBJECTDIR}/_ext/472e41a8/fileIO.o \
	${OBJECTDIR}/_ext/e57d85e4/croutine.o \
	${OBJECTDIR}/_ext/e57d85e4/list.o \
	${OBJECTDIR}/_ext/23dca792/port.o \
	${OBJECTDIR}/_ext/43bdbdb9/heap_3.o \
	${OBJECTDIR}/_ext/e57d85e4/queue.o \
	${OBJECTDIR}/_ext/e57d85e4/tasks.o \
	${OBJECTDIR}/_ext/a23ebf8d/ParTest.o \
	${OBJECTDIR}/_ext/6d89b2e9/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/freertos_posix_gccsim.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/freertos_posix_gccsim.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/freertos_posix_gccsim ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/a7e6eb5c/AsyncIO.o: ../../FreeRTOS/Posix_GCCSim/AsyncIO/AsyncIO.c
	${MKDIR} -p ${OBJECTDIR}/_ext/a7e6eb5c
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a7e6eb5c/AsyncIO.o ../../FreeRTOS/Posix_GCCSim/AsyncIO/AsyncIO.c

${OBJECTDIR}/_ext/a7e6eb5c/AsyncIOSerial.o: ../../FreeRTOS/Posix_GCCSim/AsyncIO/AsyncIOSerial.c
	${MKDIR} -p ${OBJECTDIR}/_ext/a7e6eb5c
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a7e6eb5c/AsyncIOSerial.o ../../FreeRTOS/Posix_GCCSim/AsyncIO/AsyncIOSerial.c

${OBJECTDIR}/_ext/a7e6eb5c/AsyncIOSocket.o: ../../FreeRTOS/Posix_GCCSim/AsyncIO/AsyncIOSocket.c
	${MKDIR} -p ${OBJECTDIR}/_ext/a7e6eb5c
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a7e6eb5c/AsyncIOSocket.o ../../FreeRTOS/Posix_GCCSim/AsyncIO/AsyncIOSocket.c

${OBJECTDIR}/_ext/a7e6eb5c/PosixMessageQueueIPC.o: ../../FreeRTOS/Posix_GCCSim/AsyncIO/PosixMessageQueueIPC.c
	${MKDIR} -p ${OBJECTDIR}/_ext/a7e6eb5c
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a7e6eb5c/PosixMessageQueueIPC.o ../../FreeRTOS/Posix_GCCSim/AsyncIO/PosixMessageQueueIPC.c

${OBJECTDIR}/_ext/b1099c6d/BlockQ.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/BlockQ.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b1099c6d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b1099c6d/BlockQ.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/BlockQ.c

${OBJECTDIR}/_ext/b1099c6d/PollQ.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/PollQ.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b1099c6d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b1099c6d/PollQ.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/PollQ.c

${OBJECTDIR}/_ext/b1099c6d/death.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/death.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b1099c6d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b1099c6d/death.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/death.c

${OBJECTDIR}/_ext/b1099c6d/dynamic.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/dynamic.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b1099c6d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b1099c6d/dynamic.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/dynamic.c

${OBJECTDIR}/_ext/b1099c6d/events.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/events.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b1099c6d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b1099c6d/events.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/events.c

${OBJECTDIR}/_ext/b1099c6d/flash.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/flash.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b1099c6d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b1099c6d/flash.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/flash.c

${OBJECTDIR}/_ext/b1099c6d/flop.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/flop.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b1099c6d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b1099c6d/flop.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/flop.c

${OBJECTDIR}/_ext/b1099c6d/integer.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/integer.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b1099c6d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b1099c6d/integer.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/integer.c

${OBJECTDIR}/_ext/b1099c6d/print.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/print.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b1099c6d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b1099c6d/print.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/print.c

${OBJECTDIR}/_ext/b1099c6d/semtest.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/semtest.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b1099c6d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b1099c6d/semtest.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Full/semtest.c

${OBJECTDIR}/_ext/6b605f03/GenQTest.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/GenQTest.c
	${MKDIR} -p ${OBJECTDIR}/_ext/6b605f03
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6b605f03/GenQTest.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/GenQTest.c

${OBJECTDIR}/_ext/6b605f03/QPeek.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/QPeek.c
	${MKDIR} -p ${OBJECTDIR}/_ext/6b605f03
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6b605f03/QPeek.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/QPeek.c

${OBJECTDIR}/_ext/6b605f03/blocktim.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/blocktim.c
	${MKDIR} -p ${OBJECTDIR}/_ext/6b605f03
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6b605f03/blocktim.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/blocktim.c

${OBJECTDIR}/_ext/6b605f03/countsem.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/countsem.c
	${MKDIR} -p ${OBJECTDIR}/_ext/6b605f03
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6b605f03/countsem.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/countsem.c

${OBJECTDIR}/_ext/6b605f03/crflash.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/crflash.c
	${MKDIR} -p ${OBJECTDIR}/_ext/6b605f03
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6b605f03/crflash.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/crflash.c

${OBJECTDIR}/_ext/6b605f03/crhook.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/crhook.c
	${MKDIR} -p ${OBJECTDIR}/_ext/6b605f03
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6b605f03/crhook.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/crhook.c

${OBJECTDIR}/_ext/6b605f03/recmutex.o: ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/recmutex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/6b605f03
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6b605f03/recmutex.o ../../FreeRTOS/Posix_GCCSim/Common_Demo/Minimal/recmutex.c

${OBJECTDIR}/_ext/472e41a8/fileIO.o: ../../FreeRTOS/Posix_GCCSim/FileIO/fileIO.c
	${MKDIR} -p ${OBJECTDIR}/_ext/472e41a8
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/472e41a8/fileIO.o ../../FreeRTOS/Posix_GCCSim/FileIO/fileIO.c

${OBJECTDIR}/_ext/e57d85e4/croutine.o: ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/croutine.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e57d85e4
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e57d85e4/croutine.o ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/croutine.c

${OBJECTDIR}/_ext/e57d85e4/list.o: ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/list.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e57d85e4
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e57d85e4/list.o ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/list.c

${OBJECTDIR}/_ext/23dca792/port.o: ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/portable/GCC/Posix/port.c
	${MKDIR} -p ${OBJECTDIR}/_ext/23dca792
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/23dca792/port.o ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/portable/GCC/Posix/port.c

${OBJECTDIR}/_ext/43bdbdb9/heap_3.o: ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/portable/MemMang/heap_3.c
	${MKDIR} -p ${OBJECTDIR}/_ext/43bdbdb9
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/43bdbdb9/heap_3.o ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/portable/MemMang/heap_3.c

${OBJECTDIR}/_ext/e57d85e4/queue.o: ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/queue.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e57d85e4
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e57d85e4/queue.o ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/queue.c

${OBJECTDIR}/_ext/e57d85e4/tasks.o: ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/tasks.c
	${MKDIR} -p ${OBJECTDIR}/_ext/e57d85e4
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/e57d85e4/tasks.o ../../FreeRTOS/Posix_GCCSim/FreeRTOS_Kernel/tasks.c

${OBJECTDIR}/_ext/a23ebf8d/ParTest.o: ../../FreeRTOS/Posix_GCCSim/ParTest/ParTest.c
	${MKDIR} -p ${OBJECTDIR}/_ext/a23ebf8d
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/a23ebf8d/ParTest.o ../../FreeRTOS/Posix_GCCSim/ParTest/ParTest.c

${OBJECTDIR}/_ext/6d89b2e9/main.o: ../../FreeRTOS/Posix_GCCSim/main.c
	${MKDIR} -p ${OBJECTDIR}/_ext/6d89b2e9
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/6d89b2e9/main.o ../../FreeRTOS/Posix_GCCSim/main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
