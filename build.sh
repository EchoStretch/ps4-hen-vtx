#!/bin/bash

# Check if the firmware version is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <FW>"
  exit 1
fi

FW=$1

# Build the kpayload component
pushd kpayload
make clean
make FW=$FW
popd

# Build the installer component
pushd installer
make clean
make FW=$FW
popd

# Copy the built binaries to the appropriate filenames
cp installer/installer.bin ps4-hen-$FW-vtx.bin

