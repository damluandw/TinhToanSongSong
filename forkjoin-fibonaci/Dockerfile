FROM ubuntu:22.04

# Tránh hỏi khi cài
ENV DEBIAN_FRONTEND=noninteractive

# Cài tool cần thiết
RUN apt update && apt install -y \
    build-essential \
    git \
    time \
    vim

# Set thư mục làm việc
WORKDIR /workspace

# Clone PASL
RUN git clone https://github.com/deepsea-inria/pasl.git

# Build PASL
WORKDIR /workspace/pasl
RUN make

# Mở bash khi start
CMD ["bash"]