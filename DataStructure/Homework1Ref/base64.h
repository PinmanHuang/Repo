//__BASE64_H__
#ifndef __BASE64_H__
#define __BASE64_H__

//Encoding to base64
char* base64_encode(const char* data, int data_len);
//Decoding from base64 to original
char *base64_decode(const char* data, int data_len);

#endif
