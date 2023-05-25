<?php
include("config.php");
session_start();
?>
<DOCTYPE html>
<html>
<head>
  <title>ACTIVITIES </title>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway">
<style>
td, th {
  border: 1px solid #ddd;
  padding: 8px;
}

tr:nth-child(even){background-color: #f2f2f2;}

tr:hover {background-color: #ddd;}

th {
  padding-top: 12px;
  padding-bottom: 12px;
  text-align: left;
  background-color: #4CAF50;
  color: white;
}



    body {font-family: Arial, Helvetica, sans-serif;}
* {box-sizing: border-box}

/* Full-width input fields */
input[type=text], input[type=password] {
  width: 100%;
  padding: 15px;
  margin: 5px 0 22px 0;
  display: inline-block;
  border: none;
  background: #f1f1f1;
}

input[type=text]:focus, input[type=password]:focus {
  background-color: #ffff;
  outline: none;
}

hr {
  border: 1px solid #f1f1f1;
  margin-bottom: 25px;
}

/* Set a style for all buttons */
button {
  background-color: #4CAF50;
  color: white;
  padding: 14px 20px;
  margin: 8px 0;
  border: none;
  cursor: pointer;
  width: 100%;
  opacity: 0.9;
}

button:hover {
  opacity:1;
}

/* Extra styles for the cancel button */
.cancelbtn {
  padding: 14px 20px;
  background-color: #f44336;
}

/* Float cancel and signup buttons and add an equal width */
.cancelbtn, .signupbtn {
  float: left;
  width: 50%;
}

/* Add padding to container elements */
.container {
  padding: 16px;

}

/* Clear floats */
.clearfix::after {
  content: "";
  clear: both;
  display: table;
}

/* Change styles for cancel button and signup button on extra small screens */
@media screen and (max-width: 300px) {
  .cancelbtn, .signupbtn {
     width: 100%;
  }
}
.card {
  box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2);
  max-width: 300px;
  margin: auto;
  text-align: center;
  font-family: arial;
}

h2{
    font-weight: bold;
}

.title {
  color: grey;
  font-size: 18px;
}

button {
  border: none;
  outline: 0;
  display: inline-block;
  padding: 8px;
  color: white;
  background-color: #4CAF50;
  text-align: center;
  cursor: pointer;
  width: 100%;
  font-size: 18px;
}

a {
  text-decoration: none;
  font-size: 22px;
  color: black;
}

button:hover, a:hover {
  opacity: 0.7;
}


.button {
  border: none;
  outline: 0;
  display: inline-block;
  padding: 8px;
  color: white;
  background-color: #ddd;
  text-align: center;
  cursor: pointer;
  width: 100%;
}

.button:hover {
  background-color: #ddd;
}
table {
  border-collapse: collapse;
  width: 100%;
}

th, td {
  width:10px;
  padding: 8px;
  text-align: center;
  border-bottom: 1px solid #ddd;
}

tr:hover {background-color:#f5f5f5;}

</style>
</head>


    <body>

      <div class="w3-top">
        <div class="w3-row w3-large w3-black">
          <div class="w3-col s3">
         <a href="welcomea.php" class="w3-button w3-block"> Your Profile</a>
         </div>


          </div>


        </div>

<div>
  <br><br><br>
</body>
</html>
<?php
$sql=" SELECT * FROM activity" ;
echo "<h2>PAST ACTIVITIES:</h2><br>";
$result = $db->query($sql);
if ($result->num_rows > 0) {

   while($row = $result->fetch_assoc())
   {


        echo "<table style='width:100%'><tr>";
        echo "<th> Sr.No.</th>";
        echo "<th> Date</th>";
        echo "<th> Name of Activity</th>";
        echo "<th> Male Volunteers</th>";
        echo "<th> Female Volunteers</th>";
        echo "<th> Total Volunteers</th>";
        echo "<th> No of Work Hours</th>";
        echo "<th> No. of Beneficiaries</th>";
        echo "</tr>";
        echo "<tr>";
        echo "<td>".$row["Sr.no"];
        echo "</td>";
        echo "<td>".$row["Date"];
        echo "</td>";
        echo "<td>".$row["Name of the activity"];
        echo "</td>";
        echo "<td>".$row["Male volunteers"];
        echo "</td>";
        echo "<td>".$row["Female volunteers"];
        echo "</td>";
        echo "<td>".$row["Total volunteers"];
        echo "</td>";
        echo "<td>".$row["No.of work Hours"];
        echo "</td>";
        echo "<td>".$row["No of Beneficiaries"];
        echo "</td>";
        echo "</tr>";
        echo "</table>";

  }}
?>
