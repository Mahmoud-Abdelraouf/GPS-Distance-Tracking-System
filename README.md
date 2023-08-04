# GPS Distance Tracking System

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Project Description](#project-description)
4. [Requirements](#requirements)
5. [Setup](#setup)
6. [Usage](#usage)
7. [Tools and Technologies Used](#tools-and-technologies-used)
8. [Team Members](#team-members)
9. [License](#license)

## Introduction
This project involves developing a GPS Distance Tracking System using the TM4C123G LaunchPad. The system tracks the distance a user travels between two points using GPS coordinates and provides visual feedback to the user using built-in LEDs. The project was developed as part of the CSE 211 course at the Faculty of Engineering, Computer and Systems Engineering Department.

## Features
The GPS Distance Tracking System offers the following features:
1. Stores the coordinates of the starting point.
2. Stores the coordinates of the end point and calculates the total distance traveled by the user.
3. Provides visual feedback to the user using built-in LEDs based on distance from the target destination:
   - Stage 1: Green LED turns on when the target destination is reached.
   - Stage 2: Yellow LED turns on when the target destination is about to be reached (less than 5 meters away).
   - Stage 3: Red LED turns on when the target destination is far away by more than 5 meters.
4. Ensures the total distance between the start and end points is greater than 100 meters.
5. The path from the start point to the end point forms a non-straight line similar to the provided baseline path.
6. Compares the calculated distance with Google Maps to ensure the error margin is less than or equal to 5%.

## Project Description
The GPS Distance Tracking System was developed as part of the CSE 211 [Fall 2023] course. The system calculates the distance traveled by the user and provides LED feedback based on the distance to the target destination. The trajectory of the distance satisfies specific criteria, and the system compares the calculated distance with Google Maps data.

![Baseline Path](path_image.png)
_Figure 1: Baseline path that you should follow_

## Requirements
To run the project, you will need the following:
- TM4C123G LaunchPad.
- GPS module configured to provide longitude and latitude coordinates.
- Code Composer Studio for the development environment.
- C programming language.

## Setup
1. Clone the repository or download the project files from [GitHub](https://github.com/your_username/GPS_Distance_Tracking_System).
2. Connect the TM4C123G LaunchPad to the GPS module.
3. Open the project in Code Composer Studio.
4. Build and flash the project to the LaunchPad.

## Usage
1. Power on the GPS Distance Tracking System.
2. The system will store the coordinates of the starting point.
3. Travel to the target destination.
4. Upon reaching the destination, the LED feedback will indicate the distance status:
   - Green LED: Target destination reached.
   - Yellow LED: Target destination is about to be reached (< 5 meters away).
   - Red LED: Target destination is far away (> 5 meters).
5. The system will store the coordinates of the end point and calculate the total distance traveled.

## Tools and Technologies Used
- C Programming Language.
- CMAKE for project build.
- ARM KEIL for microcontroller configuration.
- Code Composer Studio for development.

## Team Members
This project was developed by [Team Work] as part of [Introduction to Embedded Systems/GPS Tracking System].
- Team Member 1: [Name]
- Team Member 2: [Name]
- Team Member 3: [Name]
- Team Member 4: [Name]
- Team Member 5: [Name]

## License
This project is licensed under the [License Name] License - see the [LICENSE](LICENSE) file for details.
