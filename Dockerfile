FROM ubuntu:focal

RUN apt update && apt install -y \
	git \
	gcc \
