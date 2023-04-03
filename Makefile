#------------------------------------------------------
#
#    Правила сборки кода ядра
#
#------------------------------------------------------

GREY    	=	\033[030m
RED     	=	\033[031m
GREEN   	=	\033[032m
YELLOW  	=	\033[033m
BLUE    	=	\033[034m
MAGENTA 	=	\033[035m
CYAN		=	\033[036m
BOLD		=	\033[1m
RESET   	=	\033[0m

HDIR = headers

HEAD = kernel.h
HEAD += io.h
HEAD += terminal.h
HEAD += types.h
HEAD += utils.h
HEAD += keyboard.h
HEAD += cursor.h

HEADERS = $(addprefix $(HDIR)/,$(HEAD))

# Исходные объектные модули
NAME=kernel

SRC_PATH=src
OBJ_PATH=obj

SRC=main.c
SRC_SOURCES = $(addprefix $(SRC_PATH)/,$(SRC))
SRC_OBJECTS = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

##
ASM_SRC_PATH=$(SRC_PATH)/asm
ASM_OBJ_PATH=$(OBJ_PATH)/asm
ASM_SRC=init.s
ASM_SOURCES = $(addprefix $(ASM_SRC_PATH)/,$(ASM_SRC))
ASM_OBJECTS = $(addprefix $(ASM_OBJ_PATH)/,$(ASM_SRC:.s=.o))

# // TMR
TRM_SRC_PATH=$(SRC_PATH)/terminal
TRM_OBJ_PATH=$(OBJ_PATH)/terminal

TRM_SRC=vga.c
TRM_SRC+=initialize.c
TRM_SOURCES = $(addprefix $(TRM_SRC_PATH)/,$(TRM_SRC))
TRM_OBJECTS = $(addprefix $(TRM_OBJ_PATH)/,$(TRM_SRC:.c=.o))

# UTL
UTL_SRC_PATH=$(SRC_PATH)/utils
UTL_OBJ_PATH=$(OBJ_PATH)/utils
UTL_SRC=kfs_strlen.c
UTL_SRC+=kfs_write.c
UTL_SRC+=kfs_putchar.c
UTL_SRC+=kfs_putstr.c
UTL_SRC+=kfs_strcmp.c
UTL_SRC+=kfs_itoa.c
UTL_SRC+=kfs_memset.c
UTL_SRC+=kfs_intlen.c

UTL_SOURCES = $(addprefix $(UTL_SRC_PATH)/,$(UTL_SRC))
UTL_OBJECTS = $(addprefix $(UTL_OBJ_PATH)/,$(UTL_SRC:.c=.o))

# UTL
IO_SRC_PATH=$(SRC_PATH)/io
IO_OBJ_PATH=$(OBJ_PATH)/io
IO_SRC=inb.c
IO_SRC+=outb.c
IO_SRC+=outw.c

IO_SOURCES = $(addprefix $(IO_SRC_PATH)/,$(IO_SRC))
IO_OBJECTS = $(addprefix $(IO_OBJ_PATH)/,$(IO_SRC:.c=.o))

# CUR
CUR_SRC_PATH=$(SRC_PATH)/cursor
CUR_OBJ_PATH=$(OBJ_PATH)/cursor
CUR_SRC=initialize.c
CUR_SRC+=move.c
CUR_SRC+=position.c

CUR_SOURCES = $(addprefix $(CUR_SRC_PATH)/,$(CUR_SRC))
CUR_OBJECTS = $(addprefix $(CUR_OBJ_PATH)/,$(CUR_SRC:.c=.o))

# KEY
KEY_SRC_PATH=$(SRC_PATH)/keyboard
KEY_OBJ_PATH=$(OBJ_PATH)/keyboard
KEY_SRC=handler.c

KEY_SOURCES = $(addprefix $(KEY_SRC_PATH)/,$(KEY_SRC))
KEY_OBJECTS = $(addprefix $(KEY_OBJ_PATH)/,$(KEY_SRC:.c=.o))

LINK_SRC=link/link.ld

SOURCES=$(addprefix $(SRC_PATH)/,$(SRC_SRC)) \
		$(addprefix $(TRM_SRC_PATH)/,$(TRM_SRC)) \
		$(addprefix $(IO_SRC_PATH)/,$(IO_SRC)) \
		$(addprefix $(UTL_SRC_PATH)/,$(UTL_SRC)) \
		$(addprefix $(CUR_SRC_PATH)/,$(CUR_SRC)) \
		$(addprefix $(KEY_SRC_PATH)/,$(KEY_SRC))

OBJECTS=$(addprefix $(ASM_OBJ_PATH)/,$(ASM_SRC:.s=.o)) \
		$(addprefix $(OBJ_PATH)/,$(SRC:.c=.o)) \
		$(addprefix $(TRM_OBJ_PATH)/,$(TRM_SRC:.c=.o)) \
		$(addprefix $(IO_OBJ_PATH)/,$(IO_SRC:.c=.o)) \
		$(addprefix $(UTL_OBJ_PATH)/,$(UTL_SRC:.c=.o)) \
		$(addprefix $(CUR_OBJ_PATH)/,$(CUR_SRC:.c=.o)) \
		$(addprefix $(KEY_OBJ_PATH)/,$(KEY_SRC:.c=.o))

# Флаги компилятора языка C
CFLAGS=-fno-builtin -fno-exceptions -fno-stack-protector -nostdlib -nodefaultlibs -m32 -g

# Флаги компоновщика
LDFLAGS=-T $(LINK_SRC) -m elf_i386

# Флаги ассемблера
ASFLAGS=--32

# Правило сборки
all: fclean nasm sources link
	@echo "$(BOLD)$(GREEN)done:   kernel: kfs-1 ------------- [🌕]$(RESET)"


nasm:
	@mkdir -p $(ASM_OBJ_PATH)
	@as $(ASFLAGS) $(ASM_SOURCES) -o ${ASM_OBJECTS}
	@echo "$(BOLD)build:  nasm ---------------------- $(GREEN)[🌒]$(RESET)"

sources: $(SRC_OBJECTS) ${IO_OBJECTS} $(TRM_OBJECTS) \
		 $(CUR_OBJECTS) $(KEY_OBJECTS) $(UTL_OBJECTS) Makefile
	@echo "$(BOLD)        kernel, terminal, utils, io $(GREEN)[🌓]$(RESET)"
	@echo "$(BOLD)        cursor, keyboard ---------- $(GREEN)[🌓]$(RESET)"

# /*
# ** ====================== MAKE Terminal ==========================
# */
$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(HEADERS) Makefile
	@mkdir -p $(OBJ_PATH) 2> tmp.log
	@cc -m32 -ffreestanding $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log

# /*
# ** ====================== MAKE Terminal ==========================
# */
$(TRM_OBJ_PATH)/%.o : $(TRM_SRC_PATH)/%.c $(HEADERS) Makefile
	@mkdir -p $(TRM_OBJ_PATH) 2> tmp.log
	@cc -m32 -ffreestanding $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log

# /*
# ** ====================== MAKE Cursor ==========================
# */
$(CUR_OBJ_PATH)/%.o : $(CUR_SRC_PATH)/%.c $(HEADERS) Makefile
	@mkdir -p $(CUR_OBJ_PATH) 2> tmp.log
	@cc -m32 -ffreestanding $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log

# /*
# ** ====================== MAKE Keyboard ==========================
# */
$(KEY_OBJ_PATH)/%.o : $(KEY_SRC_PATH)/%.c $(HEADERS) Makefile
	@mkdir -p $(KEY_OBJ_PATH) 2> tmp.log
	@cc -m32 -ffreestanding $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log

# /*
# ** ====================== MAKE Utils ==========================
# */
$(UTL_OBJ_PATH)/%.o : $(UTL_SRC_PATH)/%.c $(HEADERS) Makefile
	@mkdir -p $(UTL_OBJ_PATH) 2> tmp.log
	@cc -m32 -ffreestanding $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log

# /*
# ** ====================== MAKE IO ===============================
# */
$(IO_OBJ_PATH)/%.o : $(IO_SRC_PATH)/%.c $(HEADERS) Makefile
	@mkdir -p $(IO_OBJ_PATH) 2> tmp.log
	@cc -m32 -ffreestanding $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log




# Правило компоновки
link:
	@ld $(LDFLAGS) -o $(NAME) $(OBJECTS)
		@echo "$(BOLD)link:   --------------------------- $(GREEN)[🌔]$(RESET)"

clean:
	@rm -rf $(NAME)
	@echo "$(BOLD)$(RED)delete: $(NAME)----------------------[🌑] $(RESET)"

fclean: clean
	@rm -rf $(OBJ_PATH)

start:
	qemu-system-i386 -kernel $(NAME)

start_disk:
	qemu-system-x86_64 ./hard_disk.img

re: fclean all
# re_disk:
# 	@mount /dev/loop7p1 /mnt/test
# 	@chmod 777 /mnt/test/boot/$(NAME)
# 	@rm -rf /mnt/test/boot/$(NAME)
# 	@cp $(NAME) /mnt/test/boot
# 	@umount /mnt/test

.PHONY: all link
