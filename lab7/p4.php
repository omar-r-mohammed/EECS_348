<?php

if (isset($_POST['dimensions'])) { 

    $y = intval($_POST['dimensions']);
    $y = $y + 1;
    echo "<table border='1'>";

    for ($i = 0; $i < $y; $i++) {
        echo "<tr>";
        for ($j = 0; $j < $y; $j++) {
            if ($i == 0) {
                echo "<td>" . $j . "</td>";
            }
            else if ($j == 0) {
                echo "<td>" . $i . "</td>";
            }
            else {
                echo "<td>" . ($i*$j) . "</td>";
            }
        }
        echo "</tr>";

    }
    echo "</table>";
}

?>