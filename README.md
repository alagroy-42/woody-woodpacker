# woody-woodpacker
School project aiming to code an ELF 64bits packer which will encrypt and compress the binary.

## Subject

[Link](en.subject.pdf)

## Usage

Compile with `make`.

`./woody_woodpacker binary_file` will create a file named `woody` with encrypted and compressed `binary_file`'s code.
Then running `./woody` will decompress and decrypt the code, print `....WOODY....` on stdout as a proof of injection, and finally, the program will run with its normal behaviour.