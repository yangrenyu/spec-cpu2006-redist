OBJSL   = c_code.o buf_for_proc.o rsl_malloc.o
OBJS    = $(OBJSL)
OPTS    =
FFLAGS  =  $(OPTS) -w
LIBS    = 
M4      = m4 -Uinclude -Uindex -Ulen
AR      = ar

.SUFFIXES:      .F90 .F .f .o .code

all : librsl_lite.a

librsl_lite.a:          $(OBJS)
			/bin/rm -f librsl_lite.a
			$(AR) cr librsl_lite.a $(OBJSL)

c_code.o:	        c_code.c
			$(CC) $(CFLAGS) -c c_code.c

rsl_malloc.o:	        rsl_malloc.c
			$(CC) $(CFLAGS) -c rsl_malloc.c

buf_for_proc.o:	        buf_for_proc.c
			$(CC) $(CFLAGS) -c buf_for_proc.c

clean : 
			/bin/rm -f *.f *.o

superclean : clean
			/bin/rm -f *.a
