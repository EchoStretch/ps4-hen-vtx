#!/bin/bash

c=$PWD
b=installer/build
mkdir -p $b
cd $b
f=plugins.zip
curl -fLJO https://github.com/illusion0001/ps4-hen-plugins/releases/latest/download/$f
unzip $f
cd bin/plugins/prx_final
for file in *.prx; do xxd -i "$file" > "$c/installer/include/${file}.inc"; done
cd $c
