# Dockerfile for creating container with Segger Embedded Studio 7.10a

FROM ubuntu:18.04

# Install dependencies
RUN apt-get update && \
	apt-get install -y libx11-6 libfreetype6 libxrender1 libfontconfig1 libxext6 xvfb wget curl unzip python-pip python3-pip git zip

RUN mkdir -p /tools/ses
RUN mkdir -p /tools/install

# Install Segger Embedded Studio
RUN cd /tools/install && \
    wget https://www.segger.com/downloads/embedded-studio/Setup_EmbeddedStudio_ARM_v710a_linux_x64.tar.gz && \
    tar -xzvf Setup_EmbeddedStudio_ARM_v710a_linux_x64.tar.gz && \
    cd arm_segger_embedded_studio_v710a_linux_x64 && \
    echo "yes" | ./install_segger_embedded_studio --copy-files-to /tools/ses && \
    cd .. && \
    rm -rf /tools/install

# Add emStudio to PATH
ENV PATH="/tools/ses/bin:$PATH"

