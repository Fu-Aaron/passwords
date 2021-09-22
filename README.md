# passwords
attempting to do a pwd manager

Using the openssl library, installing the development kit

To install, go to ubuntu/bash terminal and run the following commands:
    `$ sudo apt-get install libssl-dev`

    `sudo apt install -y libssl-dev`

However, if you are anything like me you will get an error, here's what worked:
    ```
    $ sudo apt-get clean

    $ sudo apt-get update
    ```


```
/* OpenSSL headers */

# include  "openssl/bio.h"
# include  "openssl/ssl.h"
# include  "openssl/err.h"

/* Initializing OpenSSL */

SSL_load_error_strings();
ERR_load_BIO_strings();
OpenSSL_add_all_algorithms();
```
@source https://developer.ibm.com/tutorials/l-openssl/