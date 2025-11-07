SRC_DIR = ./src

CFLAGS = -I./third_party/sokol

# Linux
CFLAGS += -pthread -DSOKOL_GLCORE
LDLIBS += -lX11 -lXi -lXcursor -ldl -lm -lGL

basics: $(SRC_DIR)/basics.c
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
