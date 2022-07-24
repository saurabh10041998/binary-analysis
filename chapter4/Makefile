CC= g++
PROG=test_loader
OBJS=loader.o test_loader.o

all: $(PROG)
$(PROG): $(OBJS)
	$(CC) -g -rdynamic -o $(PROG) $(LDFLAGS) $(OBJS) -lbfd -liberty
	rm -f $(OBJS)
clean:
	rm -rf $(PROG) $(OBJS)

