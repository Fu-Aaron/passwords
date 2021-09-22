# passwords
attempting to do a pwd manager

Using the openssl library, installing the development kit

To install, go to ubuntu/bash terminal and run the following commands:
    `sudo apt-get install libssl-dev`

However, if you are anything like me you will get an error, here's what worked:
    ```
    sudo apt-get clean
    sudo apt-get update
    ```