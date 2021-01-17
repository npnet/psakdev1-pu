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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/3cd6d2c0/AbortDelay.o \
	${OBJECTDIR}/_ext/3cd6d2c0/BlockQ.o \
	${OBJECTDIR}/_ext/3cd6d2c0/EventGroupsDemo.o \
	${OBJECTDIR}/_ext/3cd6d2c0/GenQTest.o \
	${OBJECTDIR}/_ext/3cd6d2c0/IntSemTest.o \
	${OBJECTDIR}/_ext/3cd6d2c0/PollQ.o \
	${OBJECTDIR}/_ext/3cd6d2c0/QPeek.o \
	${OBJECTDIR}/_ext/3cd6d2c0/QueueOverwrite.o \
	${OBJECTDIR}/_ext/3cd6d2c0/QueueSet.o \
	${OBJECTDIR}/_ext/3cd6d2c0/QueueSetPolling.o \
	${OBJECTDIR}/_ext/3cd6d2c0/TaskNotify.o \
	${OBJECTDIR}/_ext/3cd6d2c0/TimerDemo.o \
	${OBJECTDIR}/_ext/3cd6d2c0/blocktim.o \
	${OBJECTDIR}/_ext/3cd6d2c0/countsem.o \
	${OBJECTDIR}/_ext/3cd6d2c0/death.o \
	${OBJECTDIR}/_ext/3cd6d2c0/dynamic.o \
	${OBJECTDIR}/_ext/3cd6d2c0/flop.o \
	${OBJECTDIR}/_ext/3cd6d2c0/integer.o \
	${OBJECTDIR}/_ext/3cd6d2c0/print.o \
	${OBJECTDIR}/_ext/3cd6d2c0/recmutex.o \
	${OBJECTDIR}/_ext/3cd6d2c0/semtest.o \
	${OBJECTDIR}/_ext/7c4c6d1c/main.o \
	${OBJECTDIR}/_ext/7c9679b8/croutine.o \
	${OBJECTDIR}/_ext/7c9679b8/event_groups.o \
	${OBJECTDIR}/_ext/7c9679b8/list.o \
	${OBJECTDIR}/_ext/b637533e/port.o \
	${OBJECTDIR}/_ext/2186c65/heap_3.o \
	${OBJECTDIR}/_ext/7c9679b8/queue.o \
	${OBJECTDIR}/_ext/7c9679b8/tasks.o \
	${OBJECTDIR}/_ext/7c9679b8/timers.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/freertos_posix_linux

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/freertos_posix_linux: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/freertos_posix_linux ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/3cd6d2c0/AbortDelay.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/AbortDelay.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/AbortDelay.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/AbortDelay.c

${OBJECTDIR}/_ext/3cd6d2c0/BlockQ.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/BlockQ.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/BlockQ.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/BlockQ.c

${OBJECTDIR}/_ext/3cd6d2c0/EventGroupsDemo.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/EventGroupsDemo.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/EventGroupsDemo.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/EventGroupsDemo.c

${OBJECTDIR}/_ext/3cd6d2c0/GenQTest.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/GenQTest.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/GenQTest.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/GenQTest.c

${OBJECTDIR}/_ext/3cd6d2c0/IntSemTest.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/IntSemTest.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/IntSemTest.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/IntSemTest.c

${OBJECTDIR}/_ext/3cd6d2c0/PollQ.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/PollQ.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/PollQ.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/PollQ.c

${OBJECTDIR}/_ext/3cd6d2c0/QPeek.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/QPeek.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/QPeek.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/QPeek.c

${OBJECTDIR}/_ext/3cd6d2c0/QueueOverwrite.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/QueueOverwrite.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/QueueOverwrite.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/QueueOverwrite.c

${OBJECTDIR}/_ext/3cd6d2c0/QueueSet.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/QueueSet.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/QueueSet.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/QueueSet.c

${OBJECTDIR}/_ext/3cd6d2c0/QueueSetPolling.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/QueueSetPolling.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/QueueSetPolling.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/QueueSetPolling.c

${OBJECTDIR}/_ext/3cd6d2c0/TaskNotify.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/TaskNotify.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/TaskNotify.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/TaskNotify.c

${OBJECTDIR}/_ext/3cd6d2c0/TimerDemo.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/TimerDemo.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/TimerDemo.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/TimerDemo.c

${OBJECTDIR}/_ext/3cd6d2c0/blocktim.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/blocktim.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/blocktim.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/blocktim.c

${OBJECTDIR}/_ext/3cd6d2c0/countsem.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/countsem.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/countsem.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/countsem.c

${OBJECTDIR}/_ext/3cd6d2c0/death.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/death.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/death.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/death.c

${OBJECTDIR}/_ext/3cd6d2c0/dynamic.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/dynamic.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/dynamic.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/dynamic.c

${OBJECTDIR}/_ext/3cd6d2c0/flop.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/flop.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/flop.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/flop.c

${OBJECTDIR}/_ext/3cd6d2c0/integer.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/integer.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/integer.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/integer.c

${OBJECTDIR}/_ext/3cd6d2c0/print.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/print.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/print.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/print.c

${OBJECTDIR}/_ext/3cd6d2c0/recmutex.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/recmutex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/recmutex.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/recmutex.c

${OBJECTDIR}/_ext/3cd6d2c0/semtest.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/semtest.c
	${MKDIR} -p ${OBJECTDIR}/_ext/3cd6d2c0
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/3cd6d2c0/semtest.o ../../LinuxOS/FreeRTOS/Posix_Linux/Demo/semtest.c

${OBJECTDIR}/_ext/7c4c6d1c/main.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Project/main.c
	${MKDIR} -p ${OBJECTDIR}/_ext/7c4c6d1c
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7c4c6d1c/main.o ../../LinuxOS/FreeRTOS/Posix_Linux/Project/main.c

${OBJECTDIR}/_ext/7c9679b8/croutine.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Source/croutine.c
	${MKDIR} -p ${OBJECTDIR}/_ext/7c9679b8
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7c9679b8/croutine.o ../../LinuxOS/FreeRTOS/Posix_Linux/Source/croutine.c

${OBJECTDIR}/_ext/7c9679b8/event_groups.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Source/event_groups.c
	${MKDIR} -p ${OBJECTDIR}/_ext/7c9679b8
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7c9679b8/event_groups.o ../../LinuxOS/FreeRTOS/Posix_Linux/Source/event_groups.c

${OBJECTDIR}/_ext/7c9679b8/list.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Source/list.c
	${MKDIR} -p ${OBJECTDIR}/_ext/7c9679b8
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7c9679b8/list.o ../../LinuxOS/FreeRTOS/Posix_Linux/Source/list.c

${OBJECTDIR}/_ext/b637533e/port.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Source/portable/GCC/POSIX/port.c
	${MKDIR} -p ${OBJECTDIR}/_ext/b637533e
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/b637533e/port.o ../../LinuxOS/FreeRTOS/Posix_Linux/Source/portable/GCC/POSIX/port.c

${OBJECTDIR}/_ext/2186c65/heap_3.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Source/portable/MemMang/heap_3.c
	${MKDIR} -p ${OBJECTDIR}/_ext/2186c65
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2186c65/heap_3.o ../../LinuxOS/FreeRTOS/Posix_Linux/Source/portable/MemMang/heap_3.c

${OBJECTDIR}/_ext/7c9679b8/queue.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Source/queue.c
	${MKDIR} -p ${OBJECTDIR}/_ext/7c9679b8
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7c9679b8/queue.o ../../LinuxOS/FreeRTOS/Posix_Linux/Source/queue.c

${OBJECTDIR}/_ext/7c9679b8/tasks.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Source/tasks.c
	${MKDIR} -p ${OBJECTDIR}/_ext/7c9679b8
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7c9679b8/tasks.o ../../LinuxOS/FreeRTOS/Posix_Linux/Source/tasks.c

${OBJECTDIR}/_ext/7c9679b8/timers.o: ../../LinuxOS/FreeRTOS/Posix_Linux/Source/timers.c
	${MKDIR} -p ${OBJECTDIR}/_ext/7c9679b8
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7c9679b8/timers.o ../../LinuxOS/FreeRTOS/Posix_Linux/Source/timers.c

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
