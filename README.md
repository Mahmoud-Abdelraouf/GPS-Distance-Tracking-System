<h1>GPS Distance Tracking System</h1>

<p>This project involves developing a system using the TM4C123G LaunchPad that tracks the distance a user travels between two points using GPS coordinates. The system will also provide visual feedback to the user using built-in LEDs, indicating when they are close to their destination or have reached it.</p>

<h2>Features</h2>

<p>The GPS subsystem will perform the following tasks:</p>

<ol>
  <li>Store the coordinates of the starting point.</li>
  <li>Store the coordinates of the end point and calculate the total distance traveled by the user.</li>
  <li>Provide visual feedback to the user using built-in LEDs:
    <ol>
      <li>Stage 1: Turn on the green LED when the target destination is reached.</li>
      <li>Stage 2: Turn on the yellow LED when the target destination is about to be reached (less than 5 meters away).</li>
      <li>Stage 3: Turn on the red LED when the target destination is far away by more than 5 meters.</li>
    </ol>
  </li>
</ol>

<p>The trajectory of the distance traveled should satisfy the following criteria:</p>

<ol>
  <li>The total distance between the start and end point should be greater than 100 meters.</li>
  <li>The path from the start point to the end point should form a non-straight line similar to the provided baseline path.</li>
  <li>The calculated distance should be compared with the distance obtained from Google Maps, and the error margin should be less than or equal to 5%.</li>
</ol>

<h2>Usage</h2>

<p>To use this system, you will need to connect the TM4C123G LaunchPad to a GPS module and configure it to receive GPS coordinates. Once the system is set up, you can use it to track your distance traveled and receive visual feedback using the built-in LEDs.</p>

<h2>Tools and Technologies Used</h2>

<p>This project was developed using C programming language.</p>

<div style="display: flex;">
 <a href="https://www.cprogramming.com"><img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="C Programming Language Icon" width="48" height="48"></a>
<a href="https://cmake.org"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/13/Cmake.svg/1200px-Cmake.svg.png" alt="CMAKE" width="48" height="48"></a>
<a href="https://www.keil.com/"><img src="https://media.digikey.com/Photos/Keil%20Photos/MFG_KEIL.jpg" alt="Code Composer Studio Icon" width="48" height="48"></a>
<a href="https://www.ti.com/tool/CCSTUDIO"><img src="https://www.ti.com/diagrams/ccstudio_ccs_256.jpg" alt="Code Composer Studio Icon" width="48" height="48"></a>
</div>

<h2>Credits</h2>

<p>This project was developed by [Team Work] as part of [Introduction to Embedded
Systems/GPS Tracking System].</p>
<a href="https://www.linkedin.com/in/mahmoud-abdelraouf-mahmoud-80b908222/"><img src="https://developers.google.com/static/maps/images/docs-landing-get-started-hero.png" alt="Google Maps Image"></a>
