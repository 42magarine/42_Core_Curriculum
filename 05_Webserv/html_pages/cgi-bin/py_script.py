#!/usr/bin/env python3
import sys
import os
import cgi

# Print the HTTP headers
print("Content-Type: text/html\r")
print("\r")  # Empty line to separate headers from body

# Print the HTML content
print("<!DOCTYPE html>")
print("<html>")
print("<head><title>Python CGI Test</title></head>")
print("<body>")
print("<h1>Python CGI Test</h1>")

# Access form data if needed
form = cgi.FieldStorage()
if "name" in form:
    print(f"<p>Hello, {form['name'].value}!</p>")

# Access environment variables
print(f"<p>Request Method: {os.environ.get('REQUEST_METHOD', '')}</p>")
print(f"<p>Query String: {os.environ.get('QUERY_STRING', '')}</p>")

print("</body>")
print("</html>")