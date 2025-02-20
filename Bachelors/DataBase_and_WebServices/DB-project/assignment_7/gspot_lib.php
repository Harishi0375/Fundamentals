<?php

function connect_to_db($servername, $username, $password, $dbname)
{
    $conn = new mysqli($servername, $username, $password, $dbname);
    if ($conn->connect_error) {
        throw new Exception("Connection failed: " . $conn->connect_error);
    }
    return $conn;
}


/**
 * @param string $path 
 * this function checks the directory and loads all of the vars from .env
 * and then places them in the global var $_ENV so that they can be later obtain
 * using getenv()
 */
function loadDotEnv($path): void
{
    if (!file_exists($path)) {
        throw new Exception("The .env file does not exist at the path: " . $path);
    }

    $lines = file($path, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

    foreach ($lines as $line) {
        if (strpos(trim($line), '#') === 0 || empty(trim($line))) {
            continue;
        }

        list($name, $value) = explode('=', $line, 2);
        $name = trim($name);
        $value = trim($value, ' "');
        putenv("$name=$value");
        $_ENV[$name] = $value;
        $_SERVER[$name] = $value;
    }
}


/**
 * @param mysqli $conn 
 * @param string $sql_string
 * @param char $types 
 * @param array  $values
 * 
 * prepares the sql, binds the vars to it and then gets a result table
 * loop through the table and add the results to an array and returnt that to be 
 * enocded as json
 */
function queryDatabase($conn, $sql_string, $types, $values)
{
    $stmt = $conn->prepare($sql_string);

    $stmt->bind_param($types, ...$values);

    $stmt->execute();
    $result = $stmt->get_result();

    $potential_rooms = [];
    while ($row = $result->fetch_assoc()) {
        $potential_rooms[] = array(
            'block_letter' => $row['block_letter'],
            'college' => $row['college']
        );
    }

    return $potential_rooms;
}
