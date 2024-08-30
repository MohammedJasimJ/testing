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




{% code title="Encoding in python" fullWidth="true" %}
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
{% endcode %}

{% embed url="https://www.youtube.com/watch?v=aUdKd0IFl34" %}
