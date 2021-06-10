FROM ubuntu:focal

WORKDIR /tmp/woody_woodpacker

COPY srcs ./srcs
COPY libft ./libft
COPY includes ./includes
COPY Makefile ./

RUN apt-get update && apt-get upgrade -y && apt-get install -y zsh wget git gcc make nasm binutils file gcc-multilib
RUN wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | zsh || true

CMD [ "zsh" ]