# EXAMPLE



Let's go through an example to illustrate the process:

1. **Input**: Let's encode the string "Man".
2.  **Convert to Binary**:

    * "M" = 77 = 01001101
    * "a" = 97 = 01100001
    * "n" = 110 = 01101110

    Combine these binary values: `010011010110000101101110`.
3. **Split into 6-bit Chunks**:
   * `010011` (19)
   * `010110` (22)
   * `000101` (5)
   * `101110` (46)
4.  **Map to Base64 Characters**:

    * 19 -> T
    * 22 -> W
    * 5 -> F
    * 46 -> u

    So "Man" encoded in Base64 is `TWFu`.

#### Formula

While there isn’t a straightforward “formula” per se, you can think of it as these steps:

1. Convert input data to binary.
2. Divide binary into 6-bit chunks.
3. Map each chunk to a Base64 character using the Base64 alphabet.
4. Add padding if necessary.

If you are using a programming language or library, most of them provide built-in methods to handle Base64 encoding, so you often won’t need to manually perform these steps.\


{% tabs %}
{% tab title="Python" %}
```python
import base64

# Your actual username and password
username = "rzp_live_vVxRXte0kqZdwX"
password = "2GIqXgqNQnoMKyxDCZ7hI4ul"

# Combine username and password with a colon
credentials = f"{username}:{password}"

# Encode the combined string using Base64
encoded_credentials = base64.b64encode(credentials.encode("utf-8")).decode("utf-8")

print(f"Encoded credentials for HTTP Basic Authentication: {encoded_credentials}")
```
{% endtab %}

{% tab title="C" %}
```c
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
```
{% endtab %}
{% endtabs %}

{% embed url="https://www.youtube.com/watch?v=aUdKd0IFl34" %}
