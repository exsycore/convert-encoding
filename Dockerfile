FROM ubuntu:24.04

RUN dpkg --add-architecture i386 && \
    apt update && \
    apt install -y \
    build-essential \
    gcc-multilib \
    g++-multilib \
    cmake \
    git

WORKDIR /app