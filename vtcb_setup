#! /bin/bash

vtcb_setup=~/vtcb_setup.txt
touch $vtcb_setup
# Programs
subl=subl

# --- Sublime Text 3 Portable Version (tarball)

# Check if already installed
if grep -Fxq "$subl" $vtcb_setup
then
	echo "Sublime is already installed!"
# Installation
else
	subl_link=https://download.sublimetext.com/sublime_text_3_build_3103_x64.tar.bz2
	subl_name=$(basename $subl_link)

	cd ~/Downloads
	
	echo "Downloading..."
	wget $subl_link

	echo "Extracting..."
	tar jxf $subl_name
	
	echo "$subl" >> "$vtcb_setup"
	echo "alias subl=~/Downloads/sublime_text_3/sublime_text" >> ~/.bash_aliases
	alias subl=~/Downloads/sublime_text_3/sublime_text
fi
