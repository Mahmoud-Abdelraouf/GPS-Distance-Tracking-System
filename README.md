<project>
  <title>GPS Distance Tracking System</title>
  <description>
    <p>This project involves developing a system using the TM4C123G LaunchPad that tracks the distance a user travels between two points using GPS coordinates. The system will also provide visual feedback to the user using built-in LEDs, indicating when they are close to their destination or have reached it.</p>
  </description>
  <features>
    <ul>
      <li>Store the coordinates of the starting point.</li>
      <li>Store the coordinates of the end point and calculate the total distance traveled by the user.</li>
      <li>Provide visual feedback to the user using built-in LEDs:
        <ol type="a">
          <li>Stage 1: Turn on the green LED when the target destination is reached.</li>
          <li>Stage 2: Turn on the yellow LED when the target destination is about to be reached (less than 5 meters away).</li>
          <li>Stage 3: Turn on the red LED when the target destination is far away by more than 5 meters.</li>
        </ol>
      </li>
    </ul>
    <p>The trajectory of the distance traveled should satisfy the following criteria:</p>
    <ol>
      <li>The total distance between the start and end point should be greater than 100 meters.</li>
      <li>The path from the start point to the end point should form a non-straight line similar to the provided baseline path.</li>
      <li>The calculated distance should be compared with the distance obtained from Google Maps, and the error margin should be less than or equal to 5%.</li>
    </ol>
  </features>
  <usage>
    <p>To use this system, you will need to connect the TM4C123G LaunchPad to a GPS module and configure it to receive GPS coordinates. Once the system is set up, you can use it to track your distance traveled and receive visual feedback using the built-in LEDs.</p>
  </usage>
  <programming-language>C</programming-language>
  <credits>
    <p>This project was developed by Mahmoud Abdelraouf as part of Introduction to Embedded Systems/GPS Tracking System.</p>
  </credits>
</project>
