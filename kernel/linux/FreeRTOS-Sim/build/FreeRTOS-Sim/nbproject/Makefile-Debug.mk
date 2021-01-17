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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/fd184d69/AbortDelay.o \
	${OBJECTDIR}/_ext/fd184d69/BlockQ.o \
	${OBJECTDIR}/_ext/fd184d69/EventGroupsDemo.o \
	${OBJECTDIR}/_ext/fd184d69/GenQTest.o \
	${OBJECTDIR}/_ext/fd184d69/IntSemTest.o \
	${OBJECTDIR}/_ext/fd184d69/PollQ.o \
	${OBJECTDIR}/_ext/fd184d69/QPeek.o \
	${OBJECTDIR}/_ext/fd184d69/QueueOverwrite.o \
	${OBJECTDIR}/_ext/fd184d69/QueueSet.o \
	${OBJECTDIR}/_ext/fd184d69/QueueSetPolling.o \
	${OBJECTDIR}/_ext/fd184d69/TaskNotify.o \
	${OBJECTDIR}/_ext/fd184d69/TimerDemo.o \
	${OBJECTDIR}/_ext/fd184d69/blocktim.o \
	${OBJECTDIR}/_ext/fd184d69/countsem.o \
	${OBJECTDIR}/_ext/fd184d69/death.o \
	${OBJECTDIR}/_ext/fd184d69/dynamic.o \
	${OBJECTDIR}/_ext/fd184d69/flop.o \
	${OBJECTDIR}/_ext/fd184d69/integer.o \
	${OBJECTDIR}/_ext/fd184d69/recmutex.o \
	${OBJECTDIR}/_ext/fd184d69/semtest.o \
	${OBJECTDIR}/_ext/80121959/main.o \
	${OBJECTDIR}/_ext/957bd1db/event_groups.o \
	${OBJECTDIR}/_ext/957bd1db/list.o \
	${OBJECTDIR}/_ext/ae034a3b/port.o \
	${OBJECTDIR}/_ext/357ffea2/heap_1.o \
	${OBJECTDIR}/_ext/957bd1db/queue.o \
	${OBJECTDIR}/_ext/957bd1db/tasks.o \
	${OBJECTDIR}/_ext/957bd1db/timers.o


# C Compiler Flags
CFLAGS=-lpthread -pthread

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/freertos-sim

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/freertos-sim: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/freertos-sim ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/fd184d69/AbortDelay.o: ../../Demo/Common/Minimal/AbortDelay.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/AbortDelay.o ../../Demo/Common/Minimal/AbortDelay.c

${OBJECTDIR}/_ext/fd184d69/BlockQ.o: ../../Demo/Common/Minimal/BlockQ.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/BlockQ.o ../../Demo/Common/Minimal/BlockQ.c

${OBJECTDIR}/_ext/fd184d69/EventGroupsDemo.o: ../../Demo/Common/Minimal/EventGroupsDemo.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/EventGroupsDemo.o ../../Demo/Common/Minimal/EventGroupsDemo.c

${OBJECTDIR}/_ext/fd184d69/GenQTest.o: ../../Demo/Common/Minimal/GenQTest.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/GenQTest.o ../../Demo/Common/Minimal/GenQTest.c

${OBJECTDIR}/_ext/fd184d69/IntSemTest.o: ../../Demo/Common/Minimal/IntSemTest.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/IntSemTest.o ../../Demo/Common/Minimal/IntSemTest.c

${OBJECTDIR}/_ext/fd184d69/PollQ.o: ../../Demo/Common/Minimal/PollQ.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/PollQ.o ../../Demo/Common/Minimal/PollQ.c

${OBJECTDIR}/_ext/fd184d69/QPeek.o: ../../Demo/Common/Minimal/QPeek.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/QPeek.o ../../Demo/Common/Minimal/QPeek.c

${OBJECTDIR}/_ext/fd184d69/QueueOverwrite.o: ../../Demo/Common/Minimal/QueueOverwrite.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/QueueOverwrite.o ../../Demo/Common/Minimal/QueueOverwrite.c

${OBJECTDIR}/_ext/fd184d69/QueueSet.o: ../../Demo/Common/Minimal/QueueSet.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/QueueSet.o ../../Demo/Common/Minimal/QueueSet.c

${OBJECTDIR}/_ext/fd184d69/QueueSetPolling.o: ../../Demo/Common/Minimal/QueueSetPolling.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/QueueSetPolling.o ../../Demo/Common/Minimal/QueueSetPolling.c

${OBJECTDIR}/_ext/fd184d69/TaskNotify.o: ../../Demo/Common/Minimal/TaskNotify.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/TaskNotify.o ../../Demo/Common/Minimal/TaskNotify.c

${OBJECTDIR}/_ext/fd184d69/TimerDemo.o: ../../Demo/Common/Minimal/TimerDemo.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/TimerDemo.o ../../Demo/Common/Minimal/TimerDemo.c

${OBJECTDIR}/_ext/fd184d69/blocktim.o: ../../Demo/Common/Minimal/blocktim.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/blocktim.o ../../Demo/Common/Minimal/blocktim.c

${OBJECTDIR}/_ext/fd184d69/countsem.o: ../../Demo/Common/Minimal/countsem.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/countsem.o ../../Demo/Common/Minimal/countsem.c

${OBJECTDIR}/_ext/fd184d69/death.o: ../../Demo/Common/Minimal/death.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/death.o ../../Demo/Common/Minimal/death.c

${OBJECTDIR}/_ext/fd184d69/dynamic.o: ../../Demo/Common/Minimal/dynamic.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/dynamic.o ../../Demo/Common/Minimal/dynamic.c

${OBJECTDIR}/_ext/fd184d69/flop.o: ../../Demo/Common/Minimal/flop.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/flop.o ../../Demo/Common/Minimal/flop.c

${OBJECTDIR}/_ext/fd184d69/integer.o: ../../Demo/Common/Minimal/integer.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/integer.o ../../Demo/Common/Minimal/integer.c

${OBJECTDIR}/_ext/fd184d69/recmutex.o: ../../Demo/Common/Minimal/recmutex.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/recmutex.o ../../Demo/Common/Minimal/recmutex.c

${OBJECTDIR}/_ext/fd184d69/semtest.o: ../../Demo/Common/Minimal/semtest.c
	${MKDIR} -p ${OBJECTDIR}/_ext/fd184d69
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fd184d69/semtest.o ../../Demo/Common/Minimal/semtest.c

${OBJECTDIR}/_ext/80121959/main.o: ../../Project/main.c
	${MKDIR} -p ${OBJECTDIR}/_ext/80121959
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/80121959/main.o ../../Project/main.c

${OBJECTDIR}/_ext/957bd1db/event_groups.o: ../../Source/event_groups.c
	${MKDIR} -p ${OBJECTDIR}/_ext/957bd1db
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/957bd1db/event_groups.o ../../Source/event_groups.c

${OBJECTDIR}/_ext/957bd1db/list.o: ../../Source/list.c
	${MKDIR} -p ${OBJECTDIR}/_ext/957bd1db
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/957bd1db/list.o ../../Source/list.c

${OBJECTDIR}/_ext/ae034a3b/port.o: ../../Source/portable/GCC/POSIX/port.c
	${MKDIR} -p ${OBJECTDIR}/_ext/ae034a3b
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ae034a3b/port.o ../../Source/portable/GCC/POSIX/port.c

${OBJECTDIR}/_ext/357ffea2/heap_1.o: ../../Source/portable/MemMang/heap_1.c
	${MKDIR} -p ${OBJECTDIR}/_ext/357ffea2
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/357ffea2/heap_1.o ../../Source/portable/MemMang/heap_1.c

${OBJECTDIR}/_ext/957bd1db/queue.o: ../../Source/queue.c
	${MKDIR} -p ${OBJECTDIR}/_ext/957bd1db
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/957bd1db/queue.o ../../Source/queue.c

${OBJECTDIR}/_ext/957bd1db/tasks.o: ../../Source/tasks.c
	${MKDIR} -p ${OBJECTDIR}/_ext/957bd1db
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/957bd1db/tasks.o ../../Source/tasks.c

${OBJECTDIR}/_ext/957bd1db/timers.o: ../../Source/timers.c
	${MKDIR} -p ${OBJECTDIR}/_ext/957bd1db
	${RM} "$@.d"
	$(COMPILE.c) -g -I../../Project -I../../Source/include -I../../Source/portable/GCC/POSIX -I../../Demo/Common/include -I../../Demo/Common/Minimal -I../../Source -I../../Source/portable/MemMang -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/957bd1db/timers.o ../../Source/timers.c

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
