# woody-woodpacker
School project aiming to code an ELF 64bits packer which will encrypt the binary.

## Subject

[Link](en.subject.pdf)

## Usage

Compile with `make`.

`./woody_woodpacker binary_file` will create a file named `woody` with encrypted `binary_file`'s code.
Then running `./woody` will decrypt the code, print `....WOODY....` on stdout as a proof of injection, and finally, the program will run with its normal behaviour.

Since this project is working with the ELF file format, it is only working on Linux.
To deploy it on another system : `./run_docker.sh`.