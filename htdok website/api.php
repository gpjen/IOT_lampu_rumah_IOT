<?php


include 'config.php';
s
$relay = $conn->query("SELECT * FROM relay");
while ($row = $relay->fetch_assoc()) {
    $data[] = intval($row['logika']);
}
$json = json_encode($data);
echo $json;


?>