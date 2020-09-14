#!/bin/bash
# The line above makes your script executable.
# You should write your tutorial in here.
# Include comments inline with your script explaining what is going on.

# You might start out by first saying the purpose of the script and
# demonstrating its usage.

#Problem Statement:

# Often, whenever we need to search for different files or directories within the computer ternimal, 
# we would always use "ls" command to list all the possible files and directories within the currect 
# directory that we are in. By utilize the command "ls", we are able to decided and located the target 
# file or directory, otherwise we would be continuing to search the location of the file or directory. 
# There are also set backs with just using "ls" command depending in how large the directory is.
# When there are a large number of files and directories in the current directory, and the target file 
# is in a nested dictionary which is hard to access in one step simply.

# From time to time, we do need a more visual of an overview of any nested files and it's directories.
# For instance, using a "tree" command line is super useful to address these cases. 
# The "tree" command line used recursive listing directory to program and produces a depth–indented listing.
# The command line lists the files in the current directory. It also produce a complete of listing of all
# the files and directories that were found. "tree" command line would return the total amount of files and
# directories that listed.

# Futhermore, "tree" is probably the most useful command line that visualize any directories structures
# within your computer system. It can also mark and colour coded any files and directories within the system. 
# The command line does this by sort the colour coded files by it types. This command line allows the user
# a more convienience ways to located the files they search for and the type of files they are in.

# Meanwhile, if the target file is exactly in the current directory and within that directory contains 
# lots of other nest directories; it can make it harder to notice the target using 'tree' 
# command. Instead, 'ls' command works better in this case.

# Both command line – "tree" and "ls", can be applies very effectiveky in many different case scenarios. 
# Each command lines have pros and cons. Therefore, both command lines are being utilize for myScript.sh.

# Command name: ls
# its usage:
# -bash-4.2$ ls
# part1  part2  README.md

# Command name: tree
# its usage:
# -bash-4.2$ tree
# .
# ├── part1
# │   ├── myScript.sh
# │   └── Readme.md
# ├── part2
# │   ├── barebones.s
# │   ├── function.s
# │   ├── hello.s
# │   ├── prog1
# │   ├── README.md
# │   └── tool.c
# └── README.md

# 2 directories, 9 files


# Command name: tree -C
# its usage: 
# -bash-4.2$ tree -C
# .
# ├── part1 //colour codes – blue
# │   ├── myScript.sh
# │   └── Readme.md
# ├── part2 //colour codes – blue
# │   ├── barebones.s
# │   ├── function.s
# │   ├── hello.s
# │   ├── prog1
# │   ├── README.md
# │   └── tool.c
# └── README.md

# 2 directories, 9 files
# This command line output a colour coded for the directories.


# Command name: echo
# Its usage:
# -bash-4.2$ echo "Hello World"
# Hello World
# The command displays number or string on standard output in the terminal. 
# In this usage case, the output is in a string format.


# Files: myscript.sh
# Comman name:

ls
echo "Number of directories: "
ls | wc -l
tree -C

# Its usage:

# -bash-4.2$ sh myScript.sh 
# another_test_file  myScript.sh	Readme.md  test_file
 
# Number of directories: 
# 4
# ========================
# .
# -bash-4.2$ sh myScript.sh 
# another_test_file  myScript.sh	Readme.md  test_file

# Number of directories: 
# 4
# .
# ├── another_test_file
# │   ├── test_another.txt
# │   └── test_file2
# │       ├── test_file
# │       └── test_file.c
# ├── myScript.sh
# ├── Readme.md
# └── test_file
    # ├── inside_test_file
    # │   └── another_file.txt
    # ├── test_file.c
    # └── test_print

# 4 directories, 8 files

#Running myscript.sh in command line:

# Firstly, "ls" command line being utilize first because it will executed the list of all the files and directories with in the 
# current directory that the user in. If the target file located in the current directory, then the user can access it easily. 
# Secondly, "echo "Number of directories: "" and "ls | wc -l" being utilize after is allow the output to print out the
# number of the directories located in the file.
# Finally, the execution of "tree -C" command line is use to visualize the file directory structure. It output display all the nested
# files and directories. It colour coded different types of files within the directory.
