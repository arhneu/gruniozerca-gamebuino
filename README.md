# Gruniożerca for Gamebuino!
A fully featured port of the "classic" Gruniożerca game, originally for the NES.
Created by Dark Archon (arhn.eu, code, graphics) and Neko (logo). Original concept by Łukasz Kur.

## What is this?
Gruniożerca for Gamebuino (Gruniożerca GBuino) is a simple example project for the classic Gamebuino system. Also compatible with the DIY Makerbuino kit.

The goal of the project was to create a simple Gamebuino game which would utilize most of the common features of the system.

Included are the source files:
1. gruniozerca.ino -- the main source file for the Polish version
2. gruniozerca-en.ino -- same as above but in English
3. arhn.ino -- the custom font file

As well as extra graphics files used in the project and misc. files.

## Game Features

The project aims to showcase most of the basic Gamebuino functions:
- A score counter with a working Hi-score function and score saving
- A secret playable character accessible via a specific series of inputs
- A main manu created using a custom script for bigger flexibility
- Bitmap manipulation (used to move the main character)
- Custom font file (used as "carrot" symbols and to demonstrate the drawChar function)
- Basic sound effects
- drawPixel used to generate Polish "ogonki" characters on the fly
- Game Over and How to Play screens

## How to play?
Move Grunio around with the left and right buttons. White and black carrots will fall from the sky. The goal is to "eat" as many as possible. But there's a catch: Grunio can only eat carrots of the same color as his fur! To change Grunio's fur color press "A". Miss three times and it's game over!
Press "C" to forfeit.

## How do I use the source code?
You can open the "gruniozerca.ino" (Polish version) or "gruniozerca-en.ino" (English version) of the files in the Arduino IDE, to see what the source code looks like. It's fairly tidy, although not extremely effiecent with lots of room for potential memory improvements.

The Arduino IDE will require the Gamebuino libraries to run.

You can also use the precompiled HEX files to play the game on the emulator and/or Gamebuino compatible consoles.

## How do I play it?
For English version: Just copy the GRUNIOEN.HEX and GRUNIOEN.INF files to the SD card used in your Gamebuino. The game should appear on the list!
For Polish version: Copy the GRUNIO.HEX and GRUNIO.INF files instead.

You can also play the game online, in an emulator!
Just visit this page: http://simbuino4web.ppl-pilot.com/ and load the hex file.
Please note: The save feature of the emulator isn't functional and will constantly display 255 as high score.

## I want to learn more!
Gruniożerca Gamebuino was created for an arhn.eu video on building and programming a MAKERbuino console.
Once the video is completed, this readme will be updated with the links.
