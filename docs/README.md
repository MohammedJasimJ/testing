# Encode to Base 64 format

<figure><img src=".gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

Base64 encoding is a method to encode binary data into ASCII text, which is useful for transmitting data over text-based protocols. The process of Base64 encoding involves converting data into a sequence of 6-bit groups, each represented by a corresponding character in the Base64 alphabet.

Here's a step-by-step explanation of the Base64 encoding process:

1. **Convert Data to Binary**: Start by converting the input data (which can be any binary data) into its binary representation. For example, if you're encoding a string, convert each character into its binary form using its ASCII value.
2. **Group Binary Data into 6-bit Chunks**: Divide the binary data into chunks of 6 bits. If the total number of bits isn't a multiple of 6, pad the binary data with zeros to make it fit into 6-bit chunks.
3. **Map 6-bit Chunks to Base64 Characters**: Each 6-bit chunk is then mapped to a corresponding Base64 character. The Base64 alphabet is

```
Some codeA-Z (0-25)
a-z (26-51)
0-9 (52-61)
+ (62)
/ (63)
```

* Each 6-bit chunk corresponds to an index in this alphabet.

4. **Add Padding if Necessary**: If the original data wasn’t a multiple of 3 bytes (24 bits), Base64 encoding will pad the result with one or two `=` characters. This padding ensures the encoded output is a multiple of 4 characters long.

