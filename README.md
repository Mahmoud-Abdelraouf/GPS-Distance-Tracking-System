# GPS Distance Tracking System

The GPS Distance Tracking System is an embedded system developed using the TM4C123G LaunchPad. It allows users to track the distance they travel between two points using GPS coordinates. The system provides visual feedback to the user through built-in LEDs, indicating when they are close to their destination or have reached it.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Requirements](#requirements)
- [Contributing](#contributing)
- [License](#license)
- [Credits](#credits)
- [Contact](#contact)
- [Video Demo](#video-demo)
- [Baseline Path](#baseline-path)

## Description

The GPS Distance Tracking System is a project developed as part of the CSE 211 course at the Computer and Systems Engineering Department, Faculty of Engineering, during the Fall 2023 semester. The main objective of the project is to create an embedded system that accurately tracks the distance a user travels between two points using GPS coordinates. The system is implemented on the TM4C123G LaunchPad and provides real-time visual feedback to the user through LEDs.

## Features

The GPS subsystem performs the following tasks:

1. Stores the coordinates of the starting point.
2. Stores the coordinates of the end point and calculates the total distance traveled by the user.
3. Provides visual feedback to the user using built-in LEDs:
   - Stage 1: Green LED turns on when the target destination is reached.
   - Stage 2: Yellow LED turns on when the target destination is about to be reached (less than 5 meters away).
   - Stage 3: Red LED turns on when the target destination is far away (more than 5 meters).

The trajectory of the distance traveled satisfies the following criteria:

1. The total distance between the start and end points should be greater than 100 meters.
2. The path from the start point to the end point should form a non-straight line similar to the provided baseline path.

The system calculates the distance between the starting point and the end point and compares it with the distance obtained from Google Maps. The error margin should be less than or equal to 5%.

## Installation

To use the GPS Distance Tracking System, follow these steps:

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/your-username/GPS-Distance-Tracking-System.git
   ```

2. Connect the TM4C123G LaunchPad to a GPS module and configure it to receive GPS coordinates.

3. Open the project in Code Composer Studio (CMake is also required for building).

## Usage

To use the GPS Distance Tracking System, follow these steps:

1. Power on the GPS Distance Tracking System.

2. Select any starting point on Google Maps and mark it as the starting location.

3. Walk or travel to the destination point.

4. The system will provide visual feedback through the built-in LEDs as follows:
   - Green LED: Target destination reached.
   - Yellow LED: Target destination about to be reached (less than 5 meters away).
   - Red LED: Target destination is far away (more than 5 meters).

5. Ensure that the calculated distance is within an error margin of 5% compared to Google Maps.

## Requirements

To successfully run the GPS Distance Tracking System, you will need the following:

- TM4C123G LaunchPad
- GPS Module
- Code Composer Studio (CCS) or CMake for building
- UART configuration for GPS module communication

## Contributing

Contributions to the GPS Distance Tracking System project are welcome. To contribute, follow these steps:

1. Fork the repository.

2. Create a new branch for your feature or bug fix.

3. Make your changes and commit them with a detailed description.

4. Push to the branch and create a pull request on GitHub.

## License

This project is licensed under the GNU AFFERO GENERAL PUBLIC LICENSE.

## Credits

This project was developed by [Team Work] as part of [Introduction to Embedded Systems/GPS Tracking System]. Special thanks to the faculty and staff at the Computer and Systems Engineering Department, Faculty of Engineering, for their support and guidance throughout the project.

## Contact

For any inquiries or support, please contact:

- [Mahmoud Abdelraouf] - [mahmoud126125@gmail.com]
- [Somay Ayman] - [somaya189ayman@gmail.com]
- [Sara Ashraf] - [.email@example.com]
- [Maya Sharaf] - [.email@example.com]
- [Mahmoud Hamdy] - [mahmoud-mahgoub1@hotmail.com]
- [Nada Mohamed] - [email@example.com]
- [Mohamed Adham] - [mohamed.adhamnagiub@gmail.com]
- [Mennatallah Abdel-Motaleb] - [ail@example.com]
- [Muhammad AbdelKhaleq] - [muhammadabdelkhaleq2@gmail.com]
- [Mohamed Khaled] - [mail@example.com]

## Video Demo

You can find a video demonstration of the GPS Distance Tracking System at the following link: [Link to Video Demo](https://youtu.be/t8TfINgbRjQ)

## Baseline Path

The baseline path that should be followed for the GPS Distance Tracking System is shown below:

![Image 1](https://www.mdpi.com/ijgi/ijgi-11-00186/article_deploy/html/images/ijgi-11-00186-g001.png)


