# Webserv
Creating a selfwritten webserver in cpp17

The project involved setting up a HTTP Server that handles  GET/POST/DELETE requests and is able to process CGI scripts using a forked CGI handler.

We used Epoll as the I/O multiplexer to handle 1000s of requests "relatively" efficiently. 
## Siege Test Results (100 Concurrency for 1 Minute)

- **Transactions**: 116,291
- **Availability**: 100.00%
- **Elapsed Time**: 59.76 seconds
- **Data Transferred**: 246.98 MB
- **Response Time**: 0.05 seconds
- **Transaction Rate**: 1,945.97 req/sec
- **Throughput**: 4.13 MB/sec
- **Concurrency**: 99.85
- **Successful Transactions**: 116,291
- **Failed Transactions**: 0
- **Longest Transaction**: 0.22 seconds
- **Shortest Transaction**: 0.00 seconds

 ## Features Include:

 - **Configuration Management**
    - Multiple Server configurations
    - Comprehensive location management (called routes here)
    - Configurable error page directories
    - Upload and download allowance controls
    - Directory listing functionality
    - Default files specifications
    - URL redirects
    - Host and port configuration with error handling
    - server names definitions
    - Configurable max header and body size limits

- **Capabilites:**
* Basic Cookie Management
* Configurable file upload support
* Configurable file download support
* CGI Handling via forked processes
  - Currently supports PHP and Python
  - Extensible CGI Handling Support through Creator Classes (CGICreator files)
  - Robust error handling for CGI script exceptions (e.g. infinite loops etc..)

## Development Environment

*  Build and Deployment
   - Makefile Support
     - Comprehensive build system
     - Cross-platform compatibility
*  Docker Integration
   - Containerized Environment
   - Support for systems beyond Linux
   - Simplified setup and deployment

## Basic Execution Commands

*  Make Start
   - Builds a debian container
   - Starts the debian container
   - Enters the debian container
     
*  Make
   - Builds the project

*  Run
   - ./webserv for standard configuration
   - ./webserv "Path/to/Config" for different configuration files

*  Make end
   - Leave Container
   - Stop Container
   - Clean Container & Image


## Testing
There are some test pages included in the project to check the functionality of the program.
