#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Base64 encoding table
static const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Modulus table to handle padding
static const int mod_table[] = {0, 2, 1};

// Function to encode data in Base64
char *base64_encode(const unsigned char *data, size_t input_length, size_t *output_length) {
    *output_length = 4 * ((input_length + 2) / 3);
    
    char *encoded_data = malloc(*output_length + 1);  // Allocate memory for the encoded string
    if (encoded_data == NULL) return NULL;  // Memory allocation failed

    for (size_t i = 0, j = 0; i < input_length;) {
        uint32_t octet_a = i < input_length ? data[i++] : 0;
        uint32_t octet_b = i < input_length ? data[i++] : 0;
        uint32_t octet_c = i < input_length ? data[i++] : 0;

        uint32_t triple = (octet_a << 16) | (octet_b << 8) | octet_c;

        encoded_data[j++] = base64_table[(triple >> 18) & 0x3F];
        encoded_data[j++] = base64_table[(triple >> 12) & 0x3F];
        encoded_data[j++] = base64_table[(triple >> 6) & 0x3F];
        encoded_data[j++] = base64_table[triple & 0x3F];
    }

    for (size_t i = 0; i < mod_table[input_length % 3]; i++) {
        encoded_data[*output_length - 1 - i] = '=';
    }

    encoded_data[*output_length] = '\0';  // Null-terminate the encoded string
    return encoded_data;
}

int main() {
    // Username and password
    const char *username = "rzp_live_vVxRXte0kqZdwX";
    const char *password = "2GIqXgqNQnoMKyxDCZ7hI4ul";

    // Combine username and password with a colon
    char credentials[256];
    snprintf(credentials, sizeof(credentials), "%s:%s", username, password);

    // Encode the combined string using Base64
    size_t output_length;
    char *encoded_credentials = base64_encode((const unsigned char *)credentials, strlen(credentials), &output_length);

    if (encoded_credentials != NULL) {
        printf("Encoded credentials for HTTP Basic Authentication: %s\n", encoded_credentials);
        free(encoded_credentials);
    } else {
        printf("Failed to encode credentials.\n");
    }

    return 0;
}
