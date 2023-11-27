
#!/bin/bash

# Function to compile and execute C++ files
compile_cpp() {
    echo "Compiling C++ file: $1"
    base_name=$(basename "$1")
    base_name="${base_name%.cpp}"
    output_file="${base_name}.exe"
    g++ -Wall -g "$1" -o "$output_file"
    if [ $? -eq 0 ]; then
        echo "Compilation successful."
        echo -e "Running $output_file \n\n\n"
        ./"$output_file"
    else
        echo "Compilation failed."
    fi
}

# Function to compile and execute C files
compile_c() {
    echo "Compiling C file: $1"
    base_name=$(basename "$1")
    base_name="${base_name%.c}"
    output_file="${base_name}.exe"
    gcc -Wall -g "$1" -o "$output_file"
    if [ $? -eq 0 ]; then
        echo "Compilation successful."
        echo -e "Running $output_file \n\n\n"
        ./"$output_file"
    else
        echo "Compilation failed."
    fi
}

# Function to compile all C or C++ files in a directory
compile_directory() {
    cd "$1"
    cpp_files=$(ls *.cpp 2> /dev/null | wc -l)
    c_files=$(ls *.c 2> /dev/null | wc -l)

    if [ "$cpp_files" != "0" ]; then
        echo "Compiling all C++ files..."
        g++ -Wall -g *.cpp -o main.exe
        if [ $? -eq 0 ]; then
            echo "Compilation successful."
            echo -e "Running main.exe\n\n\n"
            ./main.exe
        else
            echo "Compilation failed."
        fi
    elif [ "$c_files" != "0" ]; then
        echo "Compiling all C files..."
        gcc -Wall -g *.c -o main.exe
        if [ $? -eq 0 ]; then
            echo "Compilation successful."
            echo -e "Running main.exe\n\n\n"
            ./main.exe
        else
            echo "Compilation failed."
        fi
    else
        echo "No C or C++ files found in the directory $1."
    fi
}

# Check if a specific file or directory is specified as an argument
if [ "$#" -eq 1 ]; then
    path="$1"
    if [ -d "$path" ]; then
        compile_directory "$path"
    elif [ -f "$path" ]; then
        if [[ $path == *.cpp ]]; then
            compile_cpp "$path"
        elif [[ $path == *.c ]]; then
            compile_c "$path"
        else
            echo "Unknown file type specified. Please specify a C or C++ file or directory."
        fi
    else
        echo "Specified path $path does not exist."
    fi
else
    compile_directory "."
fi
