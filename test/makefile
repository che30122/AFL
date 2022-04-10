
all: t.ll switch.ll
	
%.ll: ./%.c
	clang -S -emit-llvm $<
