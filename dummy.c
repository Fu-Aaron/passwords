 #include <openssl/evp.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

char* encrypt(unsigned char *plaintext) {
    //need to initialize a key and an IV
    // EVP_aes_128_ctr is parallelizable both directions
    printf("Pla: ");
    for (int i = 0; i < strlen((char *) plaintext); i++) {
        printf("%x", plaintext[i]);
    }
    printf("\n");    

    unsigned char buf[256];
    unsigned char key[17];
    memset(key, 'A', 16);
    key[16] = '\0';

    unsigned char iv[17];
    memset(iv, 'B', 16);
    iv[16] = '\0';

    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cfb(), NULL, key, iv);
    int outlen, tmplen;

    EVP_EncryptUpdate(ctx, buf, &outlen, plaintext, strlen((char *) plaintext));
    EVP_EncryptFinal_ex(ctx, buf + outlen, &tmplen);
    outlen += tmplen;

    printf("Enc: ");
    for (int i = 0; i < outlen; i++) {
        printf("%x", buf[i]);
    }
    printf("\n");

    EVP_CIPHER_CTX_free(ctx);


    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_128_cfb(), NULL, key, iv);
    outlen = 0;
    tmplen = 0;
    unsigned char buf2[256];

    EVP_DecryptUpdate(ctx, buf2, &outlen, buf, strlen((char *)buf));
    EVP_DecryptFinal_ex(ctx, buf2 + outlen, &tmplen);
    outlen += tmplen;

    printf("Dec: ");
    for (int i = 0; i < outlen; i++) {
        printf("%x", buf2[i]);
    }
    printf("\n");

    EVP_CIPHER_CTX_free(ctx);


    return NULL;
}

int main(int argc, char *argv[]) {
    printf("All good!\n");
    encrypt("abbb0jdf[iasodfhoasidf");
}