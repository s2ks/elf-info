LIBOBJS = elfchk.o	\
	  elfstr.o	\
	  elf_header.o

OBJECTS = $(LIBOBJS) main.o

DEPENDS = $(OBJECTS:.o=.d)

CFLAGS += -Wall -Wextra

VPATH += elf
VPATH += util

BASE 	= elfdump
EXE 	= $(BASE)
SHARED 	= $(BASE).so
STATIC 	= $(BASE).a


elfdump: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJECTS) -o $(EXE)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(LIBOBJS) -shared -o $(SHARED)
	$(AR) rcs $(STATIC) $(LIBOBJS)

shared: $(OBJECTS)

include $(OBJECTS:.o=.d)

%.d : %.c
	$(CC) $(CFLAGS) -M $< > $@

.PHONY: clean
clean:
	-rm $(OBJECTS) $(DEPENDS)

.PHONY: clean-all
clean-all:
	-rm $(OBJECTS) $(DEPENDS)
	-rm $(EXE) $(SHARED) $(STATIC)
