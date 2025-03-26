#!/usr/bin/php-cgi

<?php
// No headers output - let the server handle it
echo "<html><body>\n";
echo "<h1>CGI Test Page</h1>\n";

// Detect and display the request method
$request_method = $_SERVER['REQUEST_METHOD'];
echo "Request Method: " . htmlspecialchars($request_method) . "<br>\n";

// Handle GET parameters
if ($request_method === 'GET' && !empty($_GET)) {
    echo "<h2>GET Parameters:</h2>\n";
    foreach ($_GET as $key => $value) {
        echo htmlspecialchars($key) . " = " . htmlspecialchars($value) . "<br>\n";
    }
}

// Handle POST parameters
if ($request_method === 'POST' && !empty($_POST)) {
    echo "<h2>POST Parameters:</h2>\n";
    foreach ($_POST as $key => $value) {
        echo htmlspecialchars($key) . " = " . htmlspecialchars($value) . "<br>\n";
    }
}

// Additional server information
echo "<h2>Additional Server Information:</h2>\n";
echo "Query string: " . htmlspecialchars($_SERVER['QUERY_STRING']) . "<br>\n";
echo "Script filename: " . htmlspecialchars($_SERVER['SCRIPT_FILENAME']) . "<br>\n";

echo "</body></html>\n";
?>