SRC_DIR = ./src

CFLAGS = -I./third_party/sokol -I./third_party/nuklear

# Linux
CFLAGS += -pthread -DSOKOL_GLCORE
LDLIBS += -lX11 -lXi -lXcursor -ldl -lm -lGL

nuklear: $(SRC_DIR)/nuklear.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@

basics: $(SRC_DIR)/basics.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
