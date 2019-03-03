CPP:=g++
.PHONY: all
all: set-desk-wallpaper
set-desk-wallpaper: set-desk-wallpaper.cpp
	$(CPP) -municode $< -o $@
