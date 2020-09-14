# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans: It push the pointer old base onthe stack and the pointer save it later.
	pushq %rbp			# After it copys the pointer stack value to its base pointer.
	movq  %rsp, %rbp		# Main base pointer: %rbp

					# (2) What is going on here
					# Ans: The param that we have to pass for the system call.
	movq $1, %rax			# To specify, when we want to call a specific funtion is to write the integer into rax register. 
	movq $1, %rdi			# In this assembly, its 1. By putting 1 in to the rdi register, it points to the standard output.
	leaq .hello.str,%rsi		# It's load the .hello.str address in rsi register. It's also contain contents and strings.


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: the programmatic way in which a computer program requests a service from the kernel
					# of the operating system on which it is executed.
	syscall				# Which syscall is being run?
					# Ans: write

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans: printf

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans:	It calls 60 is exist, while return error code 0.
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:	There are 10 characters in "Hello" and "World".
					# Futhermore, the string also contain a space, "!" and "\n", which also count as 3 special characters.
					# Therefore, there are 13 bytes.
