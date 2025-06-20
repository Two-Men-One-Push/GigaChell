-include $(MKIMPROVED)

configure:
	@echo -n "HEADERS =	" > $(MKGENERATED)
	@for i in $$(find $(HEADERS_DIR) -type d);\
	do\
		echo "\\" >> $(MKGENERATED);\
		echo -n "	-I$$i" >> $(MKGENERATED);\
	done;
	@echo >> $(MKGENERATED)
	@echo >> $(MKGENERATED)
	@echo -n "SRCS =	" >> $(MKGENERATED)
	@for i in $$(find $(SRCS_DIR) -type f -name "*.c");\
	do\
		echo "\\" >> $(MKGENERATED);\
		echo -n "	$$i" >> $(MKGENERATED);\
	done;
	@echo >> $(MKGENERATED)
	@echo >> $(MKGENERATED)
	@echo -n "OBJS =	" >> $(MKGENERATED)
	@for i in $$(find $(SRCS_DIR) -type f -name "*.c");\
	do\
		echo "\\" >> $(MKGENERATED);\
		echo -n "	$(BUILD_DIR)$$(basename "$${i%.c}.o")" >> $(MKGENERATED);\
	done;
	@echo >> $(MKGENERATED)
	@echo >> $(MKGENERATED)
	@echo -n "DEPS =	" >> $(MKGENERATED)
	@for i in $$(find $(SRCS_DIR) -type f -name "*.c");\
	do\
		echo "\\" >> $(MKGENERATED);\
		echo -n "	$(BUILD_DIR)$$(basename "$${i%.c}.d")" >> $(MKGENERATED);\
	done;
	@echo >> $(MKGENERATED)
	@echo >> $(MKGENERATED)
	@echo "\$$(BUILD_DIR):" >> $(MKGENERATED)
	@echo "	@mkdir -p \$$@" >> $(MKGENERATED)
	@echo "	@echo -e" >> $(MKGENERATED)
	@echo "	@echo -e \$$(FGREEN)created \$$(BUILD_DIR)\$$(RESET)" >> $(MKGENERATED)
	@for i in $$(find $(SRCS_DIR) -type f -name "*.c");\
	do\
		echo >> $(MKGENERATED);\
		echo $(BUILD_DIR)$$(basename "$${i%.c}.o"): $$i "| \$$(BUILD_DIR)" >> $(MKGENERATED);\
		echo "	@echo -e \$$(FRED)" >> $(MKGENERATED);\
		echo "	@\$$(CC) \$$(CFLAGS) \$$(HEADERS) -MD -MP -o \$$@ -c \$$<" >> $(MKGENERATED);\
		echo "	@echo -e - \$$(FGREEN)compiling \$$<\$$(RESET)" >> $(MKGENERATED);\
	done;
	@echo -e $(FGREEN)Done$(RESET)

.PHONY: configure