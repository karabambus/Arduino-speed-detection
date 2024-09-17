# Arduino-speed-detection
This repository contains instructions for building laser based speed detection system.
## Table of contents
1. [Introduction](#introduction)
2. [TODO](#todo) 
3. [Components](#components)
4. [Schematics](#schematics)
5. [Instructions](#instructions)

## Introduction
This project aims to detect speed of moving objects that are perpendicular to two lasers (that are aimed at photo resistors). First iteration is simple speed detection device that outputs speed in cm/s on serial monitor. 
It works by calculating time elapsed between photo resistor triggers (#1 -> #2). Main practical function should be detection of volleyball serve speed. Planed additional features for future are - LCD display with buttons, no-sql database, bluetooth connection, etherenet, web app, line laser. 
Current progress - base functionality tested in simulated enviorment. 
### TODO
For next phase (live tests without additional features) - bluetooth connection (practical), battery power source for arduino, laser casing and stand printed (currently only one), photo resistor and arduino stand and casing.
Area of detection for 2 trigger lasers is height of one volleyball, this should be fixed with line lasers and aditional photoresistors.
## Components
- 1x Arduino leonardo 
- 2x 10k resistors 
- 2x 3r laser module (3v)
- 2x LDR 
Additional casing and stands are needed for live tests, currently we have 1 - 3d printed case for laser modules.
## Schematics
![Speed detector](https://github.com/user-attachments/assets/82ec8c28-afb5-4e91-98ad-97d74b265497)
## Instructions
After connecting all components photo resistors should be set apart for desired length and distance constant should be adjusted (18cm is default in code).
